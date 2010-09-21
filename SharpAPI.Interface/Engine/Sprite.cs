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

using System.Drawing;
using SharpAPI.Internal.Engine;
using SharpAPI.Internal.ROSE;
using SharpAPI.Math;

namespace SharpAPI.Engine {
    public static class Sprite {
        /// <summary>
        /// Begins sprite mode.
        /// Sprite.Begin must be called before using any sprite related
        /// function (such as Texture.Draw or Sprite.DrawText).
        /// </summary>
        /// <param name="alphaBlendEnable">if set to <c>true</c> [alpha blend enable].</param>
        /// <param name="sortMode">The sort mode.</param>
        public static void Begin(bool alphaBlendEnable = false, SortMode sortMode = SortMode.None) {
            SpriteFlags spriteFlags = SpriteFlags.None;

            if(alphaBlendEnable) spriteFlags |= SpriteFlags.AlphaBlend;
            if(sortMode != SortMode.None) spriteFlags |= (SpriteFlags)sortMode;

            ZnZin.beginSprite((int)spriteFlags);
        }

        /// <summary>
        /// Ends sprite mode.
        /// Sprite.End must be called after using any sprite related
        /// function (such as Texture.Draw or Sprite.DrawText).
        /// </summary>
        public static void End() {
            ZnZin.endSprite();
        }

        /// <summary>
        /// Draws text onto the screen.
        /// Sprite.Begin must be called before calling Sprite.DrawText.
        /// </summary>
        /// <param name="text">The text.</param>
        /// <param name="font">The font.</param>
        /// <param name="x">The x.</param>
        /// <param name="y">The y.</param>
        /// <param name="colour">The colour.</param>
        public static void DrawText(string text, Font font, int x, int y, Color colour) {
            ZnZin.drawFont(GameData.GetFont((int)font), 1, x, y, (uint)colour.ToArgb(), text);
        }

        /// <summary>
        /// Calculates the width of the text using the specified font.
        /// </summary>
        /// <param name="text">The text.</param>
        /// <param name="font">The font.</param>
        /// <returns></returns>
        public static int TextWidth(string text, Font font) {
            return ZnZin.getFontTextExtent(GameData.GetFont((int)font), text).Width;
        }

        /// <summary>
        /// Calculates the height of the specified font.
        /// </summary>
        /// <param name="font">The font.</param>
        /// <returns></returns>
        public static int FontHeight(Font font) {
            return ZnZin.getFontHeight(GameData.GetFont((int)font));
        }

        /// <summary>
        /// Sets the sprite transformation.
        /// </summary>
        /// <param name="matrix">The matrix.</param>
        public static void Transform(Matrix matrix) {
            ZnZin.setTransformSprite(matrix.ToArray());
        }
    }
}