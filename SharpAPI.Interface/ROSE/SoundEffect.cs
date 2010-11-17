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
using SharpAPI.Internal.ROSE;

namespace SharpAPI.ROSE {
    public class SoundEffect {
        #region Variables

        public int id;
        private bool hash;

        #endregion

        #region Properties

        public static int Volume {
            get {
                int volume = SoundLIST.GetVolume();

                for(int i = 0; i < SoundLIST.VolumeLevels.Length; i++) {
                    if(SoundLIST.VolumeLevels[i] == volume)
                        return i;
                }

                throw new Exception(string.Format("Unable to find a matching volume level for value '{0}'", volume));
            }
            set {
                if(value < 0 || value >= SoundLIST.VolumeLevels.Length)
                    throw new Exception("Volume must be between 0 and " + (SoundLIST.VolumeLevels.Length - 1));

                SoundLIST.SetVolume(SoundLIST.VolumeLevels[value]);
            }
        }

        #endregion

        #region Constructor

        private SoundEffect(int id, bool hash = false) {
            this.hash = hash;
            this.id = id;
        }

        #endregion

        public bool Play() {
            if(hash) {
                return SoundLIST.KeyPlaySound(id);
            } else {
                return SoundLIST.IDPlaySound((short)id);
            }
        }

        public static SoundEffect FromFile(string filePath) {
            return new SoundEffect(SoundLIST.AddSoundFile(filePath), true);
        }

        public static SoundEffect FromID(short id) {
            return new SoundEffect(id);
        }
    }
}