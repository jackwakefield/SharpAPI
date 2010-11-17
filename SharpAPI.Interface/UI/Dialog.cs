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
using SharpAPI.Internal.ROSE.Interface;
using InternalDialog = SharpAPI.Internal.UI.Dialog;

namespace SharpAPI.UI {
    public class Dialog : Control, IDisposable {
        #region Variables

        private bool external;

        private bool isModal;
        private Image image;
        private int extent;

        #endregion

        #region Properties

        public int DialogType {
            get { return InternalDialog.GetDialogType(handle); }
            set { InternalDialog.SetDialogType(handle, value); }
        }

        public int Extent {
            get { return extent; }
            set { InternalDialog.SetExtent(handle, value); }
        }

        public Caption Caption {
            get { return (Caption)new Control(InternalDialog.GetCaption(handle)); }
            set { InternalDialog.SetCaption(handle, value.Handle); }
        }

        public Rectangle CaptionArea {
            set { InternalDialog.ChangeCaptionRect(handle, value); }
        }

        public Image Image {
            get { return image; }
            set {
                image = value;
                InternalDialog.SetImage(handle, value.Handle);
            }
        }

        public int ChildCount {
            get { return InternalDialog.GetChildCount(handle); }
        }

        public bool IsModal {
            get { return isModal; }
            set {
                isModal = value;

                if(value) {
                    InternalDialog.SetModal(handle);
                } else {
                    InternalDialog.SetModeless(handle);
                }
            }
        }

        #endregion

        #region Constructor

        /// <summary>
        /// Initializes a new instance of the <see cref="Dialog"/> class.
        /// </summary>
        private Dialog(bool external) {
            handle = InternalDialog.New(Draw, Update, Process, external);
            this.external = external;
            extent = 1;
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="Dialog"/> class.
        /// </summary>
        /// <param name="type">The unique dialog identifier.</param>
        /// <param name="name">The Xml file name.</param>
        /// <param name="external">if set to <c>true</c> the dialog will only be shown on external game states (login, channel select, character select, etc.).</param>
        public Dialog(short type, string name, bool external = false)
            : this(external) {
            if(!InternalDialog.Create(handle, name))
                throw new Exception(string.Format("An error occured while creating dialog {0}", name));

            IT_MGR.AppendDlg(type, handle, ControlID);
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="Dialog"/> class.
        /// </summary>
        /// <param name="type">The unique dialog identifier.</param>
        /// <param name="x">The x location.</param>
        /// <param name="y">The y location.</param>
        /// <param name="width">The width.</param>
        /// <param name="height">The height.</param>
        /// <param name="external">if set to <c>true</c> the dialog will only be shown on external game states (login, channel select, character select, etc.).</param>
        public Dialog(short type, int x, int y, int width, int height, bool external = false)
            : this(external) {
            if(!InternalDialog.CreateEmpty(handle, x, y, width, height))
                throw new Exception(string.Format("An error occurred while creating the dialog"));

            IT_MGR.AppendDlg(type, handle, ControlID);
        }

        #endregion

        #region IDispose Methods

        /// <summary>
        /// Performs application-defined tasks associated with freeing, releasing, or resetting unmanaged resources.
        /// </summary>
        public void Dispose() {
            InternalDialog.Free(handle, external);
        }

        #endregion

        public void Add(Control control) {
            InternalDialog.Add(handle, control.Handle);
        }

        public void Remove(Control control) {
            Remove(control.ControlID);
        }

        public void Remove(int id) {
            InternalDialog.Remove(handle, id);
        }

        public Control Find(int id) {
            return new Control(InternalDialog.Find(handle, id));
        }

        public void ShowChild(Control control) {
            ShowChild(control.ControlID);
        }

        public void ShowChild(int id) {
            InternalDialog.ShowChild(handle, id);
        }

        public void HideChild(Control control) {
            HideChild(control.ControlID);
        }

        public void HideChild(int id) {
            InternalDialog.HideChild(handle, id);
        }

        public void EnableChild(Control control, bool enabled = true) {
            EnableChild(control.ControlID, enabled);
        }

        public void EnableChild(int id, bool enabled = true) {
            InternalDialog.SetEnableChild(handle, id, enabled);
        }

        /// <summary>
        /// Called when the game draws the dialog.
        /// Override this method with dialog-specific rendering code;
        /// </summary>
        protected virtual void Draw() {

        }

        /// <summary>
        /// Called when the game updates the dialog.
        /// Override this method with dialog-specific logic;
        /// </summary>
        /// <param name="x">The x position.</param>
        /// <param name="y">The y position.</param>
        protected virtual void Update(int x, int y) {

        }

        /// <summary>
        /// Processes the dialog.
        /// </summary>
        /// <param name="controlID">The control ID.</param>
        /// <param name="message">The message.</param>
        /// <param name="wParameter">The w parameter.</param>
        /// <param name="lParameter">The l parameter.</param>
        private void Process(int controlID, int message, int wParameter, int lParameter) {

        }
    }
}