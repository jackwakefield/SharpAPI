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

namespace SharpAPI.Internal.UI {
    internal static class SinglelineString {
        internal delegate IntPtr NewDelegate();
        internal delegate void FreeDelegate(IntPtr singlineString);
        internal delegate void SetStringDelegate(IntPtr singlineString, string value);
        internal delegate void SetRectDelegate(IntPtr singlineString, Rectangle rectangle);
        internal delegate void SetColourDelegate(IntPtr singlineString, Color colour);
        internal delegate void SetFormatDelegate(IntPtr singlineString, int format);
        internal delegate void SetFontDelegate(IntPtr singlineString, int font);
        internal delegate string GetStringDelegate(IntPtr singlineString);
        internal delegate Rectangle GetRectDelegate(IntPtr singlineString);
        internal delegate Color GetColourDelegate(IntPtr singlineString);
        internal delegate int GetFormatDelegate(IntPtr singlineString);
        internal delegate int GetFontDelegate(IntPtr singlineString);
        internal delegate void DrawDelegate(IntPtr singlineString);
        internal delegate bool IsEllipsisDelegate(IntPtr singlineString);
        internal delegate bool EmptyDelegate(IntPtr singlineString);
        internal delegate void ClearDelegate(IntPtr singlineString);

        internal static NewDelegate New;
        internal static FreeDelegate Free;
        internal static SetStringDelegate SetString;
        internal static SetRectDelegate SetRect;
        internal static SetColourDelegate SetColour;
        internal static SetFormatDelegate SetFormat;
        internal static SetFontDelegate SetFont;
        internal static GetStringDelegate GetString;
        internal static GetRectDelegate GetRect;
        internal static GetColourDelegate GetColour;
        internal static GetFormatDelegate GetFormat;
        internal static GetFontDelegate GetFont;
        internal static DrawDelegate Draw;
        internal static IsEllipsisDelegate IsEllipsis;
        internal static EmptyDelegate Empty;
        internal static ClearDelegate Clear;
    }
}