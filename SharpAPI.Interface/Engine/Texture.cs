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
using SharpAPI.Internal.Engine;

namespace SharpAPI.Engine {
    public class Texture : IDisposable {
        #region Variables

        private IntPtr handle;

        #endregion

        #region Constructor

        /// <summary>
        /// Initializes a new instance of the <see cref="Texture"/> class.
        /// </summary>
        /// <param name="filePath">The file path.</param>
        public Texture(string filePath) {
            handle = ZnZin.loadTexture(filePath, filePath, 1, 0);
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="Texture"/> class.
        /// </summary>
        /// <param name="handle">The handle.</param>
        internal Texture(IntPtr handle) {
            this.handle = handle;
        }

        #endregion

        #region IDisposable Methods

        /// <summary>
        /// Performs application-defined tasks associated with freeing, releasing, or resetting unmanaged resources.
        /// </summary>
        public void Dispose() {
            if(handle != IntPtr.Zero)
                ZnZin.unloadTexture(handle);
        }

        #endregion

        /// <summary>
        /// Draws the texture to the specified screen location.
        /// Sprite.Begin must be called before calling Texture.Draw.
        /// </summary>
        /// <param name="x">X.</param>
        /// <param name="y">Y.</param>
        public void Draw(int x, int y) {
            ZnZin.drawSprite(handle, null, null, new float[] { x, y, 0 }, 0xFFFFFFFF);
        }

        /// <summary>
        /// Draws the texture to the specified screen location
        /// and scaling to the specified width and height.
        /// Sprite.Begin must be called before calling Texture.Draw.
        /// </summary>
        /// <param name="x">X.</param>
        /// <param name="y">Y.</param>
        /// <param name="width">Width.</param>
        /// <param name="height">Height.</param>
        public void Draw(int x, int y, int width, int height) {
            ZnZin.drawSprite(handle, new int[] { 0, 0, width, height }, null, new float[] { x, y, 0 }, 0xFFFFFFFF);
        }
    }
}