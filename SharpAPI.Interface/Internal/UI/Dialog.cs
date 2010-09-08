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

namespace SharpAPI.Internal.UI
{
    internal unsafe static class Dialog
    {
        internal delegate void* NewDelegate();
        internal delegate void CreateDelegate(IntPtr dialog, string name);
        internal delegate int GetControlIDDelegate(IntPtr dialog);
        internal delegate void SetControlIDDelegate(IntPtr dialog, int id);
        internal delegate int GetWidthDelegate(IntPtr dialog);
        internal delegate void SetWidthDelegate(IntPtr dialog, int width);
        internal delegate int GetHeightDelegate(IntPtr dialog);
        internal delegate void SetHeightDelegate(IntPtr dialog, int height);
        internal delegate void ShowDelegate(IntPtr dialog);
        internal delegate void HideDelegate(IntPtr dialog);

        internal static NewDelegate New;
        internal static CreateDelegate Create;
        internal static GetControlIDDelegate GetControlID;
        internal static SetControlIDDelegate SetControlID;
        internal static GetWidthDelegate GetWidth;
        internal static SetWidthDelegate SetWidth;
        internal static GetHeightDelegate GetHeight;
        internal static SetHeightDelegate SetHeight;
        internal static ShowDelegate Show;
        internal static HideDelegate Hide;

        /// <summary>
        /// Creates a new dialog safely.
        /// </summary>
        /// <returns></returns>
        internal static IntPtr SafeNew()
        {
            return new IntPtr(New());
        }
    }
}