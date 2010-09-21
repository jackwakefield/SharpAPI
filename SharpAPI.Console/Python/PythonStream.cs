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
using System.IO;

namespace SharpAPI {
    public class PythonStreamEvent : EventArgs {
        #region Properties

        /// <summary>
        /// Gets or sets the text.
        /// </summary>
        /// <value>The text.</value>
        public string Text { get; set; }

        #endregion

        #region Constructor

        /// <summary>
        /// Initializes a new instance of the <see cref="PythonStreamEvent"/> class.
        /// </summary>
        /// <param name="text">The text.</param>
        public PythonStreamEvent(string text) {
            Text = text;
        }

        #endregion
    }

    public class PythonStream : StreamWriter {
        #region Events

        /// <summary>
        /// Occurs when Python writes to the output steam.
        /// </summary>
        public event EventHandler<PythonStreamEvent> Written;

        #endregion

        #region Constructor

        /// <summary>
        /// Initializes a new instance of the <see cref="PythonStream"/> class.
        /// </summary>
        /// <param name="stream">The stream.</param>
        public PythonStream(Stream stream)
            : base(stream) {

        }

        #endregion

        /// <summary>
        /// Writes a string to the stream.
        /// </summary>
        /// <param name="value">The string to write to the stream. If <paramref name="value"/> is null, nothing is written.</param>
        /// <exception cref="T:System.ObjectDisposedException">
        /// 	<see cref="P:System.IO.StreamWriter.AutoFlush"/> is true or the <see cref="T:System.IO.StreamWriter"/> buffer is full, and current writer is closed. </exception>
        /// <exception cref="T:System.NotSupportedException">
        /// 	<see cref="P:System.IO.StreamWriter.AutoFlush"/> is true or the <see cref="T:System.IO.StreamWriter"/> buffer is full, and the contents of the buffer cannot be written to the underlying fixed size stream because the <see cref="T:System.IO.StreamWriter"/> is at the end the stream. </exception>
        /// <exception cref="T:System.IO.IOException">An I/O error occurs. </exception>
        public override void Write(string value) {
            string[] lines = value.Replace("\r\n", "\n").Split(new char[] { '\n' }, StringSplitOptions.RemoveEmptyEntries);

            for(int i = 0; i < lines.Length; i++) {
                if(Written != null)
                    Written(this, new PythonStreamEvent(lines[i]));
            }
        }
    }
}