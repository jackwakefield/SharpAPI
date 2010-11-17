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

namespace SharpAPI.Internal.ROSE {
    internal static class SoundLIST {
        internal static readonly int[] VolumeLevels = new int[] {
            -10000, -3000, -1000, -500, -100, -50, -10, -5, 0
        };

        internal delegate int GetVolumeDelegate();
        internal delegate void SetVolumeDelegate(int volume);
        internal delegate int AddSoundFileDelegate(string filePath);
        internal delegate bool KeyPlaySoundDelegate(int hashKey);
        internal delegate bool IDPlaySoundDelegate(short id);

        internal static GetVolumeDelegate GetVolume;
        internal static SetVolumeDelegate SetVolume;
        internal static AddSoundFileDelegate AddSoundFile;
        internal static KeyPlaySoundDelegate KeyPlaySound;
        internal static IDPlaySoundDelegate IDPlaySound;
    }
}