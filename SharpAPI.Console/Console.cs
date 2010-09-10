/*
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
using System.Drawing;
using System.Drawing.Imaging;
using SharpAPI.Engine;
using SharpAPI.Engine.Events;
using SharpAPI.Plugin;
using SharpAPI.Plugin.Attributes;

namespace SharpAPI
{
    [PluginName("Console")]
    [PluginDescription("Python based interactive console used for development purposes")]
    [PluginAuthor("xadet")]
    [PluginVersion("1.00")]
    public class Console : IPlugin
    {
        #region Variables

        private Texture backgroundTexture;
        private TextInputHandler textInputHandler;
        private PythonConsole pythonConsole;

        #endregion

        #region Properties

        /// <summary>
        /// Gets or sets a value indicating whether this <see cref="Console"/> is enabled.
        /// </summary>
        /// <value><c>true</c> if enabled; otherwise, <c>false</c>.</value>
        public bool Enabled
        {
            get { return textInputHandler.Enabled; }
            set { textInputHandler.Enabled = value; }
        }

        #endregion

        #region Constructor

        /// <summary>
        /// Initializes a new instance of the <see cref="Console"/> class.
        /// </summary>
        public Console()
        {
            pythonConsole = new PythonConsole(Font.NormalOutline);
            pythonConsole.Print("# Welcome to the SharpAPI console", Color.DodgerBlue);
            pythonConsole.Print("# This console is Python based and provides as a simplistic proxy to the interface library", Color.DodgerBlue);
            pythonConsole.Execute("from SharpAPI.ROSE import *");
            pythonConsole.Execute("from SharpAPI.Engine import *");
            pythonConsole.Execute("from SharpAPI.UI import *");
        }

        #endregion

        #region IPlugin Methods

        /// <summary>
        /// Initializes the plugin.
        /// </summary>
        public void Initialize()
        {
            textInputHandler = new TextInputHandler();
            textInputHandler.Enter += new EventHandler(Execute);
            textInputHandler.Backspace += new EventHandler(DecreaseIndentation);
            textInputHandler.Up += new EventHandler(PreviousCommand);
            textInputHandler.Down += new EventHandler(NextCommand);

            using (Bitmap backgroundBitmap = new Bitmap(1, 1))
            {
                backgroundBitmap.SetPixel(0, 0, Color.FromArgb(175, 0, 0, 0));
                backgroundBitmap.Save("background.png", ImageFormat.Png);
            }

            backgroundTexture = new Texture("background.png");

            Scene.RenderOverlay += new RenderHandler(RenderOverlay);
        }

        #endregion

        #region Events

        /// <summary>
        /// Passes the command if enter has been pressed.
        /// </summary>
        /// <param name="sender">The sender.</param>
        /// <param name="e">The <see cref="System.EventArgs"/> instance containing the event data.</param>
        private void Execute(object sender, EventArgs e)
        {
            pythonConsole.Execute(textInputHandler.Text);
        }

        /// <summary>
        /// Decreases idention if backspace has been pressed.
        /// </summary>
        /// <param name="sender">The sender.</param>
        /// <param name="e">The <see cref="System.EventArgs"/> instance containing the event data.</param>
        private void DecreaseIndentation(object sender, EventArgs e)
        {
            if (string.IsNullOrWhiteSpace(textInputHandler.Text))
                pythonConsole.DecreaseIndentation(true);
        }

        /// <summary>
        /// Sets the current text to the previous command if available.
        /// </summary>
        /// <param name="sender">The sender.</param>
        /// <param name="e">The <see cref="System.EventArgs"/> instance containing the event data.</param>
        private void PreviousCommand(object sender, EventArgs e)
        {
            string command = pythonConsole.PreviousCommand();

            if (command != null)
                textInputHandler.Text = command;
        }

        /// <summary>
        /// Sets the current text to the next command if available.
        /// </summary>
        /// <param name="sender">The sender.</param>
        /// <param name="e">The <see cref="System.EventArgs"/> instance containing the event data.</param>
        private void NextCommand(object sender, EventArgs e)
        {
            string command = pythonConsole.NextCommand();

            if (command != null)
                textInputHandler.Text = command;
        }

        /// <summary>
        /// Renders the overlay.
        /// </summary>
        /// <param name="sender">The sender.</param>
        /// <param name="e">The <see cref="System.EventArgs"/> instance containing the event data.</param>
        private void RenderOverlay()
        {
            if (!Enabled)
                return;

            int width = Scene.ScreenWidth;
            int height = (int)(Scene.ScreenHeight / 100.0f * 40.0f);

            Sprite.Begin(true);
            backgroundTexture.Draw(0, 0, width, height);
            pythonConsole.Draw(textInputHandler.Text, textInputHandler.Cursor, height);
            Sprite.End();
        }

        #endregion
    }
}