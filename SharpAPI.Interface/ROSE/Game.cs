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

using SharpAPI.ROSE.Events;

namespace SharpAPI.ROSE {
    public static class Game {
        #region Events

        /// <summary>
        /// Occurs when a key has been pressed.
        /// </summary>
        public static event KeyboardHandler KeyDown {
            add { Internal.ROSE.Game.KeyDown += value; }
            remove { Internal.ROSE.Game.KeyDown -= value; }
        }

        /// <summary>
        /// Occurs when a key has been released.
        /// </summary>
        public static event KeyboardHandler KeyUp {
            add { Internal.ROSE.Game.KeyUp += value; }
            remove { Internal.ROSE.Game.KeyUp -= value; }
        }

        #endregion
    }
}