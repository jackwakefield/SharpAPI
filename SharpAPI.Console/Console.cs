/*
 *	This file is a part of SharpAPI.
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
using IronPython.Hosting;
using Microsoft.Scripting.Hosting;
using SharpAPI.Interface.Plugin.Attributes;
using SharpAPI.Plugin;

namespace SharpAPI
{
    [PluginName("Console")]
    [PluginDescription("Python based interactive console used for development purposes")]
    [PluginAuthor("xadet")]
    [PluginVersion("1.00")]
    public class Console : IPlugin
    {
        #region Variables

        private ScriptEngine scriptEngine;
        private ScriptScope scriptScope;

        #endregion

        #region Constructor

        /// <summary>
        /// Initializes a new instance of the <see cref="Console"/> class.
        /// </summary>
        public Console()
        {
            ScriptRuntimeSetup runtimeSetup = Python.CreateRuntimeSetup(null);
            runtimeSetup.DebugMode = true;

            ScriptRuntime scriptRuntime = new ScriptRuntime(runtimeSetup);
            scriptEngine = Python.GetEngine(scriptRuntime);
            scriptScope = scriptEngine.CreateScope();
            scriptRuntime.LoadAssembly(scriptRuntime.Host.PlatformAdaptationLayer.LoadAssembly("mscorlib"));
        }

        #endregion

        #region IPlugin Methods

        /// <summary>
        /// Initializes the plugin.
        /// </summary>
        public void Initialize()
        {
            throw new NotImplementedException();
        }

        #endregion

        /// <summary>
        /// Executes the specified command.
        /// </summary>
        /// <param name="command">The command.</param>
        public void Execute(string command)
        {
            try
            {
                scriptEngine.Execute(command, scriptScope);
            }
            catch (Exception ex)
            {
                //Console.WriteLine("Error: {0}", ex.Message);
            }
        }
    }
}