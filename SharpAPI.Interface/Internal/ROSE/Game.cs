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

using System.Windows.Forms;
using SharpAPI.ROSE.Events;

namespace SharpAPI.Internal.ROSE
{
    internal static class Game
    {
        #region Events

        /// <summary>
        /// Occurs when a key has been pressed.
        /// </summary>
        public static event KeyboardEvent KeyDown;

        /// <summary>
        /// Occurs when a key has been released.
        /// </summary>
        public static event KeyboardEvent KeyUp;
        
        #endregion

        #region Event Raisers

        /// <summary>
        /// Raises the key down event.
        /// </summary>
        /// <param name="key">The key.</param>
        /// <param name="handled">if set to <c>true</c> [handled].</param>
        internal static void RaiseKeyDownEvent(int key, out bool handled)
        {
            KeyboardEventHandler eventHandler = new KeyboardEventHandler((Keys)key);

            if (KeyDown != null)
                KeyDown(eventHandler);

            handled = eventHandler.Handled;
        }

        /// <summary>
        /// Raises the key up event.
        /// </summary>
        /// <param name="key">The key.</param>
        /// <param name="handled">if set to <c>true</c> [handled].</param>
        internal static void RaiseKeyUpEvent(int key, out bool handled)
        {
            KeyboardEventHandler eventHandler = new KeyboardEventHandler((Keys)key);

            if (KeyUp != null)
                KeyUp(eventHandler);

            handled = eventHandler.Handled;
        }

        #endregion
    }
}