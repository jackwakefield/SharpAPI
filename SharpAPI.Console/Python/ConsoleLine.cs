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

namespace SharpAPI {
    /// <summary>
    /// Determines the type of console line.
    /// </summary>
    public enum LineType {
        Command,
        Print,
        Error,
        Custom
    }

    public class ConsoleLine {
        #region Properties

        /// <summary>
        /// Gets or sets the text.
        /// </summary>
        /// <value>The text.</value>
        public string Text { get; set; }

        /// <summary>
        /// Gets or sets the line type.
        /// </summary>
        /// <value>The line type.</value>
        public LineType Type { get; set; }

        /// <summary>
        /// Gets or sets a custom colour.
        /// </summary>
        /// <value>The colour.</value>
        public Color Colour { get; set; }

        #endregion

        #region Constructor

        /// <summary>
        /// Initializes a new instance of the <see cref="ConsoleLine"/> class.
        /// </summary>
        /// <param name="text">The text.</param>
        /// <param name="type">The type.</param>
        public ConsoleLine(string text, LineType type) {
            Text = text;
            Type = type;
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="ConsoleLine"/> class.
        /// </summary>
        /// <param name="text">The text.</param>
        /// <param name="type">The type.</param>
        /// <param name="colour">The colour.</param>
        public ConsoleLine(string text, LineType type, Color colour) {
            Text = text;
            Type = type;
            Colour = colour;
        }

        #endregion
    }
}