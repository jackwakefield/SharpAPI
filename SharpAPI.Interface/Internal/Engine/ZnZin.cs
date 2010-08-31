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
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SharpAPI.Internal.Engine
{
    internal static class ZnZin
    {
        internal delegate IntPtr loadTextureDelegate(string textureName, string textureFileName, int mipLevels, int useFilter);
        internal delegate int unloadTextureDelegate(IntPtr texture);
        unsafe internal delegate int drawSpriteDelegate(IntPtr texture, int[] rectangle, float[] center, float[] position, uint color);
        internal delegate int beginSpriteDelegate(int flag);
        internal delegate int endSpriteDelegate();
        internal delegate int drawFontDelegate(IntPtr font, int useSprite, int x, int y, uint colour, string message);
        
        internal static loadTextureDelegate loadTexture;
        internal static unloadTextureDelegate unloadTexture;
        internal static drawSpriteDelegate drawSprite;
        internal static beginSpriteDelegate beginSprite;
        internal static endSpriteDelegate endSprite;
        internal static drawFontDelegate drawFont;
    }
}