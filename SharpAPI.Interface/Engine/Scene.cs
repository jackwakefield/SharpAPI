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

using SharpAPI.Engine.Events;
using SharpAPI.Internal.Engine;

namespace SharpAPI.Engine {
    public static class Scene {
        #region Properties

        /// <summary>
        /// Gets the width of the screen.
        /// </summary>
        /// <value>The width of the screen.</value>
        public static int ScreenWidth {
            get { return ZnZin.getScreenWidth(); }
        }

        /// <summary>
        /// Gets the height of the screen.
        /// </summary>
        /// <value>The height of the screen.</value>
        public static int ScreenHeight {
            get { return ZnZin.getScreenHeight(); }
        }

        #endregion

        #region Events

        /// <summary>
        /// Occurs when the engine calls renderScene.
        /// </summary>
        public static event RenderHandler Render {
            add { Internal.Engine.Scene.Render += value; }
            remove { Internal.Engine.Scene.Render -= value; }
        }

        /// <summary>
        /// Occurs before the engine calls endScene.
        /// Allows rendering on top of the user interface.
        /// </summary>
        public static event RenderHandler RenderOverlay {
            add { Internal.Engine.Scene.RenderOverlay += value; }
            remove { Internal.Engine.Scene.RenderOverlay -= value; }
        }

        #endregion
    }
}