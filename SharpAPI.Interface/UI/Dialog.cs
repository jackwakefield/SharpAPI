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
using SharpAPI.Internal.ROSE.Interface;
using InternalDialog = SharpAPI.Internal.UI.Dialog;

namespace SharpAPI.UI
{
    public class Dialog
    {
        #region Variables

        private IntPtr handle;

        #endregion

        #region Properties

        /// <summary>
        /// Gets or sets the width.
        /// </summary>
        /// <value>The width.</value>
        public int Width
        {
            get { return InternalDialog.GetWidth(handle); }
            set { InternalDialog.SetWidth(handle, value); }
        }

        /// <summary>
        /// Gets or sets the height.
        /// </summary>
        /// <value>The height.</value>
        public int Height
        {
            get { return InternalDialog.GetHeight(handle); }
            set { InternalDialog.SetHeight(handle, value); }
        }

        /// <summary>
        /// Gets or sets the control ID.
        /// </summary>
        /// <value>The control ID.</value>
        public int ControlID
        {
            get { return InternalDialog.GetControlID(handle); }
            set { InternalDialog.SetControlID(handle, value); }
        }

        #endregion

        #region Constructor

        /// <summary>
        /// Initializes a new instance of the <see cref="Dialog"/> class.
        /// </summary>
        /// <param name="type">The unique dialog identifier.</param>
        /// <param name="name">The optional Xml file name.</param>
        public Dialog(short type, string name = null)
        {
            handle = InternalDialog.SafeNew();

            if (!string.IsNullOrWhiteSpace(name))
                InternalDialog.Create(handle, name);

            IT_MGR.AppendDlg(type, handle, ControlID);
        }
        
        #endregion

        /// <summary>
        /// Shows the dialog.
        /// </summary>
        public void Show()
        {
            InternalDialog.Show(handle);
        }

        /// <summary>
        /// Hides the dialog.
        /// </summary>
        public void Hide()
        {
            InternalDialog.Hide(handle);
        }
    }
}