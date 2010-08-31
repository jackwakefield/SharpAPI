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

namespace SharpAPI.ROSE.Events
{
    public delegate void KeyboardEvent(KeyboardEventHandler e);

    public class KeyboardEventHandler
    {
        #region Properties

        /// <summary>
        /// Gets or sets the key associated with the keyboard event.
        /// </summary>
        /// <value>The key.</value>
        public Keys Key { get; set; }

        /// <summary>
        /// Gets or sets a value indicating whether this <see cref="KeyboardEventHandler"/> has been handled.
        /// </summary>
        /// <value><c>true</c> if handled; otherwise, <c>false</c>.</value>
        public bool Handled { get; set; }

        #endregion

        #region Constructor

        /// <summary>
        /// Initializes a new instance of the <see cref="KeyboardEventHandler"/> class.
        /// </summary>
        /// <param name="key">The key associated with the keyboard event.</param>
        public KeyboardEventHandler(Keys key)
        {
            Key = key;
        }

        #endregion
    }
}