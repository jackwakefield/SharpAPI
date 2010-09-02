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
using System.Windows.Forms;
using SharpAPI.ROSE;
using SharpAPI.ROSE.Events;

namespace SharpAPI
{
    public class TextInputHandler
    {
        #region Variables

        private string text;

        #endregion

        #region Properties

        /// <summary>
        /// Gets or sets the text.
        /// </summary>
        /// <value>The text.</value>
        public string Text
        {
            get { return text; }
            set
            {
                text = value;

                if (text.Length > MaximumCharacters)
                    text = text.Substring(0, MaximumCharacters);

                Cursor = text.Length;
            }
        }

        /// <summary>
        /// Gets or sets a value indicating whether this <see cref="TextInputHandler"/> is enabled.
        /// </summary>
        /// <value><c>true</c> if enabled; otherwise, <c>false</c>.</value>
        public bool Enabled { get; set; }

        /// <summary>
        /// Gets or sets the toggle key used to enable and disable the input handler.
        /// </summary>
        /// <value>The toggle key used to enable and disable the input handler.</value>
        public Keys ToggleKey { get; set; }

        /// <summary>
        /// Gets or sets the cursor index.
        /// </summary>
        /// <value>The cursor index.</value>
        public int Cursor { get; set; }

        /// <summary>
        /// Gets or sets the maximum amount of characters allowed to be entered.
        /// </summary>
        /// <value>The maximum amount of characters allowed to be entered.</value>
        public int MaximumCharacters { get; set; }

        #endregion

        #region Events

        public event EventHandler Enter;
        public event EventHandler Backspace;
        public event EventHandler Up;
        public event EventHandler Down;

        #endregion

        #region Constructor

        /// <summary>
        /// Initializes a new instance of the <see cref="TextInputHandler"/> class.
        /// </summary>
        public TextInputHandler()
        {
            MaximumCharacters = 255;
            text = string.Empty;
            ToggleKey = Keys.Oem8;

            Game.KeyDown += new KeyboardHandler(KeyDown);
        }

        #endregion

        /// <summary>
        /// Occurs when a key has been pressed.
        /// </summary>
        /// <param name="e">The event parameters.</param>
        private void KeyDown(KeyboardArgs e)
        {
            if (e.Key == ToggleKey)
            {
                Enabled = !Enabled;
                e.Handled = true;

                return;
            }

            if (!Enabled)
                return;

            e.Handled = true;

            switch (e.Key)
            {
                case Keys.Delete:
                    {
                        if (Cursor < text.Length)
                            text = text.Remove(Cursor, 1);
                    }
                    break;
                case Keys.Back:
                    {
                        if (Cursor > 0)
                        {
                            text = text.Remove(Cursor - 1, 1);
                            Cursor--;
                        }

                        if (Backspace != null)
                            Backspace(this, EventArgs.Empty);
                    }
                    break;
                case Keys.Left:
                    {
                        if (Cursor > 0)
                            Cursor--;
                    }
                    break;
                case Keys.Right:
                    {
                        if (Cursor < text.Length)
                            Cursor++;
                    }
                    break;
                case Keys.Up:
                    {
                        if (Up != null)
                            Up(this, EventArgs.Empty);
                    }
                    break;
                case Keys.Down:
                    {
                        if (Down != null)
                            Down(this, EventArgs.Empty);
                    }
                    break;
                case Keys.Enter:
                    {
                        if (Enter != null)
                            Enter(this, EventArgs.Empty);

                        Cursor = 0;
                        text = string.Empty;
                    }
                    break;
                default:
                    {
                        if (!char.IsControl(e.Value) && Cursor < MaximumCharacters)
                        {
                            text = text.Insert(Cursor, e.Value.ToString());
                            Cursor++;
                        }
                    }
                    break;
            }
        }
    }
}