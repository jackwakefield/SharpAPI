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
using InternalSingleline = SharpAPI.Internal.UI.SinglelineString;

namespace SharpAPI.UI {
    public class SinglelineString : IDisposable {
        #region Variables

        private IntPtr handle;

        #endregion

        #region Properties

        public string Value {
            get { return InternalSingleline.GetString(handle); }
            set { InternalSingleline.SetString(handle, value); }
        }

        public Rectangle Area {
            get { return InternalSingleline.GetRect(handle); }
            set { InternalSingleline.SetRect(handle, value); }
        }

        public Color Colour {
            get { return InternalSingleline.GetColour(handle); }
            set { InternalSingleline.SetColour(handle, value); }
        }

        public FormatStyle Format {
            get { return (FormatStyle)InternalSingleline.GetFormat(handle); }
            set { InternalSingleline.SetFormat(handle, (int)value); }
        }

        public Font Font {
            get { return (Font)InternalSingleline.GetFont(handle); }
            set { InternalSingleline.SetFont(handle, (int)value); }
        }

        public bool IsEllipsis {
            get { return InternalSingleline.IsEllipsis(handle); }
        }

        public bool IsEmpty {
            get { return InternalSingleline.Empty(handle); }
        }

        #endregion

        #region Constructor

        /// <summary>
        /// Initializes a new instance of the <see cref="Dialog"/> class.
        /// </summary>
        public SinglelineString() {
            handle = InternalSingleline.New();
        }

        #endregion

        #region IDispose Methods

        /// <summary>
        /// Performs application-defined tasks associated with freeing, releasing, or resetting unmanaged resources.
        /// </summary>
        public void Dispose() { 
            InternalSingleline.Free(handle);
        }

        #endregion

        public void Clear() {
            InternalSingleline.Clear(handle);
        }

        public void Draw() {
            InternalSingleline.Draw(handle);
        }
    }
}