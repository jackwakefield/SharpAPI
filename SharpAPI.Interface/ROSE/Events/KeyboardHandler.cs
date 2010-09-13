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

using SharpAPI.Internal.Native;

namespace SharpAPI.ROSE.Events
{
    public delegate void KeyboardHandler(KeyboardArgs e);

    public class KeyboardArgs
    {
        #region Variables

        private char? value;

        #endregion

        #region Properties

        /// <summary>
        /// Gets the key associated with the keyboard event.
        /// </summary>
        /// <value>The key.</value>
        public Keys Key { get; private set; }

        /// <summary>
        /// Gets or sets the value.
        /// </summary>
        /// <value>The value.</value>
        public char Value
        {
            get
            {
                if (value.HasValue)
                    return value.Value;

                byte[] keyboardState = new byte[256];
                User32.GetKeyboardState(keyboardState);

                uint characterValue = 0;
                User32.ToAscii((int)Key, 0, keyboardState, ref characterValue, 0);
                value = (char)characterValue;

                return value.Value;
            }
        }

        /// <summary>
        /// Gets or sets a value indicating whether this <see cref="KeyboardArgs"/> has been handled.
        /// </summary>
        /// <value><c>true</c> if handled; otherwise, <c>false</c>.</value>
        public bool Handled { get; set; }

        public bool Ctrl { get; private set; }

        public bool Alt { get; private set; }

        public bool Shift { get; private set; }

        #endregion

        #region Constructor

        /// <summary>
        /// Initializes a new instance of the <see cref="KeyboardArgs"/> class.
        /// </summary>
        /// <param name="key">The key associated with the keyboard event.</param>
        public KeyboardArgs(Keys key, bool ctrl, bool alt, bool shift)
        {
            Key = key;
            Ctrl = ctrl;
            Alt = alt;
            Shift = shift;
        }

        #endregion
    }
}