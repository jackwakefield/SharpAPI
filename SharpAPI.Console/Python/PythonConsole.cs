﻿/*
 *  This file is a part of SharpAPI.
 *
 *  Copyright (C) 2010 Jack Wakefield
 *  
 *  SharpAPI is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  SharpAPI is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with SharpAPI.  If not, see <http://www.gnu.org/licenses/>.
 */

using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using IronPython.Hosting;
using Microsoft.Scripting.Hosting;
using SharpAPI.Engine;
using SharpAPI.Plugin;

namespace SharpAPI
{
    public class PythonConsole
    {
        #region Properties

        /// <summary>
        /// Gets or sets the indentation.
        /// </summary>
        /// <value>The indentation.</value>
        public int Indentation
        {
            get { return definitionIndentation; }
            set { definitionIndentation = value; }
        }

        #endregion

        #region Variables

        private ScriptEngine scriptEngine;
        private ScriptScope scriptScope;

        private List<ConsoleLine> lines;
        private int currentCommand;

        private Font font;
        private int fontHeight;

        private bool definingType;
        private string definition;
        private int definitionIndentation;

        #endregion

        #region Constructor

        /// <summary>
        /// Initializes a new instance of the <see cref="PythonConsole"/> class.
        /// </summary>
        public PythonConsole(Font font)
        {
            lines = new List<ConsoleLine>();

            this.font = font;
            fontHeight = Sprite.FontHeight(font);

            ScriptRuntimeSetup runtimeSetup = Python.CreateRuntimeSetup(null);
            runtimeSetup.DebugMode = true;

            ScriptRuntime scriptRuntime = new ScriptRuntime(runtimeSetup);
            scriptEngine = Python.GetEngine(scriptRuntime);
            scriptScope = scriptEngine.CreateScope();
            scriptRuntime.LoadAssembly(scriptRuntime.Host.PlatformAdaptationLayer.LoadAssembly("mscorlib"));
            scriptRuntime.LoadAssembly(typeof(IPlugin).Assembly);
            scriptRuntime.LoadAssembly(typeof(Color).Assembly);
            scriptRuntime.LoadAssembly(typeof(string).Assembly);

            MemoryStream memoryStream = new MemoryStream();
            PythonStream pythonStream = new PythonStream(memoryStream);
            pythonStream.Written += new EventHandler<PythonStreamEvent>(pythonStream_Write);
            scriptRuntime.IO.SetOutput(memoryStream, pythonStream);
        }

        #endregion

        #region Events

        /// <summary>
        /// Writes python output to the console.
        /// </summary>
        /// <param name="sender">The sender.</param>
        /// <param name="e">The event arguments.</param>
        private void pythonStream_Write(object sender, PythonStreamEvent e)
        {
            lines.Add(new ConsoleLine(e.Text, LineType.Print));
        }

        #endregion

        /// <summary>
        /// Decreases the indentation if a type is being defined.
        /// </summary>
        public void DecreaseIndentation()
        {
            if (!definingType)
                return;

            definitionIndentation--;

            if (definitionIndentation == 0)
            {
                definingType = false;
                Execute(definition, false);
                definition = string.Empty;
            }
        }

        /// <summary>
        /// Gets the previous command from the history.
        /// </summary>
        /// <returns></returns>
        public string PreviousCommand()
        {
            if (lines.Count == 0)
                return null;

            for (int i = currentCommand - 1; i >= 0; i--)
            {
                if (lines[i].Type == LineType.Command)
                {
                    currentCommand = i;
                    return lines[i].Text.Substring(2);
                }
            }

            return null;
        }

        /// <summary>
        /// Gets the next command from the history.
        /// </summary>
        /// <returns></returns>
        public string NextCommand()
        {
            for (int i = currentCommand + 1; i < lines.Count; i++)
            {
                if (lines[i].Type == LineType.Command)
                {
                    currentCommand = i;
                    return lines[i].Text.Substring(2);
                }
            }

            currentCommand = lines.Count;
            return string.Empty;
        }

        /// <summary>
        /// Executes the specified command.
        /// </summary>
        /// <param name="command">The command.</param>
        public void Execute(string command, bool print = true)
        {
            if (command.EndsWith(":"))
                definingType = true;

            if (definingType)
            {
                if (string.IsNullOrWhiteSpace(command))
                {
                    DecreaseIndentation();
                    return;
                }

                definition += "\r\n";
                string commandLine = "> ";

                for (int i = 0; i < definitionIndentation; i++)
                {
                    definition += "\t";
                    commandLine += "    ";
                }

                definition += command;
                commandLine += command;

                lines.Add(new ConsoleLine(commandLine, LineType.Command));
                currentCommand = lines.Count;

                if (command.EndsWith(":"))
                    definitionIndentation++;
            }
            else
            {
                if (print)
                {
                    lines.Add(new ConsoleLine(string.Format("> {0}", command), LineType.Command));
                    currentCommand = lines.Count;
                }

                try
                {
                    scriptEngine.Execute(command, scriptScope);
                }
                catch (Exception ex)
                {
                    lines.Add(new ConsoleLine(string.Format("Error: {0}", ex.Message), LineType.Error));
                }
            }
        }

        /// <summary>
        /// Draws the console and the specified command.
        /// </summary>
        /// <param name="text">The text.</param>
        /// <param name="cursor">The cursor.</param>
        /// <param name="height">The height.</param>
        public void Draw(string text, int cursor, int height)
        {
            int y = 5;
            int limit = height / fontHeight - 1;

            for (int i = lines.Count < limit - 1 ? 0 : lines.Count - limit; i < lines.Count; i++)
            {
                Color colour = Color.FromArgb(255, 236, 236, 236);

                if (lines[i].Type == LineType.Error)
                    colour = Color.Red;

                Sprite.DrawText(lines[i].Text, font, 5, y, colour);
                y += fontHeight;
            }

            int commandStart = 2;
            string commandLine = "> ";

            if (definingType)
            {
                commandLine = "> ";

                for (int i = 0; i < definitionIndentation; i++)
                    commandLine += "    ";

                commandStart = commandLine.Length;
            }

            commandLine += text;
            Sprite.DrawText(commandLine, font, 5, y, Color.White);

            int cursorPosition = Sprite.TextWidth(commandLine.Substring(0, cursor + commandStart), font);
            Sprite.DrawText("_", font, 5 + cursorPosition, y + 1, Color.White);
        }
    }
}