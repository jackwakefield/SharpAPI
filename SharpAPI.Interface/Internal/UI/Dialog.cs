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
    internal static class Dialog
    {
        internal delegate void DrawCallback();
        internal delegate void UpdateCallback(int x, int y);
        internal delegate void ProcessCallback(int controlID, int message, int wParameter, int lParameter);

        internal delegate IntPtr NewDelegate(DrawCallback drawCallback, UpdateCallback updateDelegate, ProcessCallback processCallback, bool external);
        internal delegate void FreeDelegate(IntPtr dialog, bool external);
        internal delegate bool CreateDelegate(IntPtr dialog, string name);
        internal delegate bool CreateEmptyDelegate(IntPtr dialog, int x, int y, int width, int height);
        
        internal static NewDelegate New;
        internal static FreeDelegate Free;
        internal static CreateDelegate Create;
        internal static CreateEmptyDelegate CreateEmpty;
    }
}