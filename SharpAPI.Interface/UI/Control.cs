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
using System.Drawing;
using InternalControl = SharpAPI.Internal.UI.Control;

namespace SharpAPI.UI
{
    #region Enumerations

    /// <summary>
    /// The control type.
    /// </summary>
    public enum ControlType
    {
        Image = 0x0100,
        Button = 0x0200,
        EditBox = 0x0300,
        ListBox = 0x0400,
        ScrollBar = 0x0500,
        ComboBox = 0x0600,
        Dialog = 0x0700,
        Static = 0x0800,
        ScrollBox = 0x0900,
        Caption = 0x0A00,
        RadioBox = 0x0B00,
        RadioButton = 0x0C00,
        MessageBox = 0x0D00,
        PushButton = 0x0E00,
        Tree = 0x0F00,
        Guage = 0x1000,
        JComboBox = 0x1100,
        JListBox = 0x1200,
        TabbedPane = 0x1300,
        StatusBar = 0x1400,
        ZListBox = 0x1500,
        CheckBox = 0x1600,
        Pane = 0x1700,
        Slot = 0x1800,
        Table = 0x1900
    }

    #endregion

    public class Control
    {
        #region Variables

        protected IntPtr handle;

        #endregion

        #region Properties

        /// <summary>
        /// Gets or sets the control ID.
        /// </summary>
        /// <value>The control ID.</value>
        public int ControlID
        {
            get { return InternalControl.GetControlID(handle); }
            set { InternalControl.SetControlID(handle, value); }
        }

        /// <summary>
        /// Gets or sets the type of the control.
        /// </summary>
        /// <value>The type of the control.</value>
        public ControlType ControlType
        {
            get { return (ControlType)InternalControl.GetControlType(handle); }
            set { InternalControl.SetControlType(handle, (int)value); }
        }

        /// <summary>
        /// Gets or sets the control's parent.
        /// </summary>
        /// <value>The control's parent.</value>
        public Control Parent
        {
            get { return new Control(InternalControl.GetParent(handle)); }
            set { InternalControl.SetParent(handle, value.handle); }
        }

        /// <summary>
        /// Gets or sets the width.
        /// </summary>
        /// <value>The width.</value>
        public int Width
        {
            get { return InternalControl.GetWidth(handle); }
            set { InternalControl.SetWidth(handle, value); }
        }

        /// <summary>
        /// Gets or sets the height.
        /// </summary>
        /// <value>The height.</value>
        public int Height
        {
            get { return InternalControl.GetHeight(handle); }
            set { InternalControl.SetHeight(handle, value); }
        }

        /// <summary>
        /// Gets or sets the position.
        /// </summary>
        /// <value>The position.</value>
        public Point Position
        {
            get { return InternalControl.GetPosition(handle); }
            set { InternalControl.SetPosition(handle, value); }
        }

        /// <summary>
        /// Gets or sets the offset.
        /// </summary>
        /// <value>The offset.</value>
        public Point Offset
        {
            get { return InternalControl.GetOffset(handle); }
            set { InternalControl.SetOffset(handle, value); }
        }

        /// <summary>
        /// Gets or sets a value indicating whether this instance is selected.
        /// </summary>
        /// <value>
        /// 	<c>true</c> if this instance is selected; otherwise, <c>false</c>.
        /// </value>
        public bool IsSelected
        {
            get { return InternalControl.IsSelected(handle); }
            set
            {
                if (value)
                    InternalControl.SetSelected(handle);
                else
                    InternalControl.SetDeselected(handle);
            }
        }

        /// <summary>
        /// Gets or sets a value indicating whether this instance is focused.
        /// </summary>
        /// <value>
        /// 	<c>true</c> if this instance is focused; otherwise, <c>false</c>.
        /// </value>
        public bool IsFocused
        {
            get { return InternalControl.IsFocus(handle); }
            set { InternalControl.SetFocus(handle, value); }
        }

        /// <summary>
        /// Gets or sets a value indicating whether this instance is active.
        /// </summary>
        /// <value><c>true</c> if this instance is active; otherwise, <c>false</c>.</value>
        public bool IsActive
        {
            get { return InternalControl.IsActive(handle); }
            set { InternalControl.SetActive(handle, true); }
        }

        /// <summary>
        /// Gets or sets a value indicating whether this instance is enabled.
        /// </summary>
        /// <value>
        /// 	<c>true</c> if this instance is enabled; otherwise, <c>false</c>.
        /// </value>
        public bool IsEnabled
        {
            get { return InternalControl.IsEnable(handle); }
            set { InternalControl.SetEnable(handle, value); }
        }

        /// <summary>
        /// Gets a value indicating whether this instance is visible.
        /// </summary>
        /// <value>
        /// 	<c>true</c> if this instance is visible; otherwise, <c>false</c>.
        /// </value>
        public bool IsVisible
        {
            get { return InternalControl.IsVision(handle); }
        }

        #endregion

        #region Constructor

        /// <summary>
        /// Initializes a new instance of the <see cref="Control"/> class.
        /// </summary>
        internal Control()
        {

        }

        /// <summary>
        /// Initializes a new instance of the <see cref="Control"/> class.
        /// </summary>
        /// <param name="handle">The handle.</param>
        internal Control(IntPtr handle)
        {
            this.handle = handle;
        }

        #endregion

        /// <summary>
        /// Shows the control.
        /// </summary>
        public void Show()
        {
            InternalControl.Show(handle);
        }

        /// <summary>
        /// Hides the control.
        /// </summary>
        public void Hide()
        {
            InternalControl.Hide(handle);
        }

        /// <summary>
        /// Determines whether the specified position is inside the control.
        /// </summary>
        /// <param name="x">The x position.</param>
        /// <param name="y">The y position.</param>
        /// <returns>
        /// 	<c>true</c> if the specified position is inside the control; otherwise, <c>false</c>.
        /// </returns>
        public bool IsInside(int x, int y)
        {
            return InternalControl.IsInside(handle, x, y);
        }

        #region Overrides

        /// <summary>
        /// Determines whether the specified <see cref="System.Object"/> is equal to this instance.
        /// </summary>
        /// <param name="obj">The <see cref="System.Object"/> to compare with this instance.</param>
        /// <returns>
        /// 	<c>true</c> if the specified <see cref="System.Object"/> is equal to this instance; otherwise, <c>false</c>.
        /// </returns>
        public override bool Equals(object obj)
        {
            if (obj == null)
                return false;

            return handle == ((Control)obj).handle;
        }

        /// <summary>
        /// Returns a hash code for this instance.
        /// </summary>
        /// <returns>
        /// A hash code for this instance, suitable for use in hashing algorithms and data structures like a hash table. 
        /// </returns>
        public override int GetHashCode()
        {
            return handle.ToInt32();
        }

        #endregion
    }
}