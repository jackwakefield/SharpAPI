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

using System.Runtime.InteropServices;

namespace SharpAPI.Internal.Native
{
    internal static class User32
    {
        /// <summary>
        /// Translates the specified virtual-key code and keyboard state to the corresponding character or characters.
        /// The function translates the code using the input language and physical keyboard layout identified by the keyboard layout handle.
        /// </summary>
        /// <param name="virtualKey">The virtual-key code to be translated.</param>
        /// <param name="scanCode">The hardware scan code of the key to be translated. The high-order bit of this value is set if the key is up (not pressed).</param>
        /// <param name="keyState">A pointer to a 256-byte array that contains the current keyboard state. Each element (byte) in the array contains the state of one key. If the high-order bit of a byte is set, the key is down (pressed).</param>
        /// <param name="char">The buffer that receives the translated character or characters.</param>
        /// <param name="flags">This parameter must be 1 if a menu is active, or 0 otherwise.</param>
        /// <returns></returns>
        [DllImport("user32.dll")]
        public static extern bool ToAscii(int virtualKey, int scanCode, byte[] keyState, ref uint @char, int flags);

        /// <summary>
        /// Copies the status of the 256 virtual keys to the specified buffer.
        /// </summary>
        /// <param name="keyState">The 256-byte array that receives the status data for each virtual key.</param>
        /// <returns></returns>
        [DllImport("user32.dll")]
        public static extern int GetKeyboardState(byte[] keyState);
    }
}