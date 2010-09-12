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

namespace SharpAPI.Internal.UI
{
    internal static class Control
    {
        internal delegate bool IsInsideDelegate(IntPtr dialog, int x, int y);
        internal delegate void SetSelectedDelegate(IntPtr dialog);
        internal delegate void SetDeselectedDelegate(IntPtr dialog);
        internal delegate void ShowDelegate(IntPtr dialog);
        internal delegate void HideDelegate(IntPtr dialog);
        internal delegate void SetFocusDelegate(IntPtr dialog, bool focus);
        internal delegate bool IsVisionDelegate(IntPtr dialog);
        internal delegate void SetOffsetDelegate(IntPtr dialog, Point point);
        internal delegate void MoveWindowDelegate(IntPtr dialog, Point point);
        internal delegate void SetHeightDelegate(IntPtr dialog, int height);
        internal delegate void SetWidthDelegate(IntPtr dialog, int width);
        internal delegate bool IsActiveDelegate(IntPtr dialog);
        internal delegate bool IsEnableDelegate(IntPtr dialog);
        internal delegate bool IsFocusDelegate(IntPtr dialog);
        internal delegate bool IsOwnerDrawDelegate(IntPtr dialog);
        internal delegate bool IsSelectedDelegate(IntPtr dialog);
        internal delegate int GetControlIDDelegate(IntPtr dialog);
        internal delegate int GetControlTypeDelegate(IntPtr dialog);
        internal delegate int GetHeightDelegate(IntPtr dialog);
        internal delegate Point GetOffsetDelegate(IntPtr dialog);
        internal delegate IntPtr GetParentDelegate(IntPtr dialog);
        internal delegate Point GetPositionDelegate(IntPtr dialog);
        internal delegate int GetWidthDelegate(IntPtr dialog);
        internal delegate void SetActiveDelegate(IntPtr dialog, bool active);
        internal delegate void SetAlphaValueDelegate(IntPtr dialog, byte alpha);
        internal delegate void SetControlIDDelegate(IntPtr dialog, int id);
        internal delegate void SetControlTypeDelegate(IntPtr dialog, int type);
        internal delegate void SetCtrlStatusDelegate(IntPtr dialog, int status);
        internal delegate void SetEnableDelegate(IntPtr dialog, bool enabled);
        internal delegate void SetOwnerDrawDelegate(IntPtr dialog, bool ownedDraw);
        internal delegate void SetParentDelegate(IntPtr dialog, IntPtr parent);
        internal delegate void SetPositionDelegate(IntPtr dialog, Point point);
        internal delegate void SetScaleHeightDelegate(IntPtr dialog, float scaleHeight);
        internal delegate void SetScaleWidthDelegate(IntPtr dialog, float scaleWidth);

        internal static IsInsideDelegate IsInside;
        internal static SetSelectedDelegate SetSelected;
        internal static SetDeselectedDelegate SetDeselected;
        internal static ShowDelegate Show;
        internal static HideDelegate Hide;
        internal static SetFocusDelegate SetFocus;
        internal static IsVisionDelegate IsVision;
        internal static SetOffsetDelegate SetOffset;
        internal static MoveWindowDelegate MoveWindow;
        internal static SetHeightDelegate SetHeight;
        internal static SetWidthDelegate SetWidth;
        internal static IsActiveDelegate IsActive;
        internal static IsEnableDelegate IsEnable;
        internal static IsFocusDelegate IsFocus;
        internal static IsOwnerDrawDelegate IsOwnerDraw;
        internal static IsSelectedDelegate IsSelected;
        internal static GetControlIDDelegate GetControlID;
        internal static GetControlTypeDelegate GetControlType;
        internal static GetHeightDelegate GetHeight;
        internal static GetOffsetDelegate GetOffset;
        internal static GetParentDelegate GetParent;
        internal static GetPositionDelegate GetPosition;
        internal static GetWidthDelegate GetWidth;
        internal static SetActiveDelegate SetActive;
        internal static SetAlphaValueDelegate SetAlphaValue;
        internal static SetControlIDDelegate SetControlID;
        internal static SetControlTypeDelegate SetControlType;
        internal static SetCtrlStatusDelegate SetCtrlStatus;
        internal static SetEnableDelegate SetEnable;
        internal static SetOwnerDrawDelegate SetOwnerDraw;
        internal static SetParentDelegate SetParent;
        internal static SetPositionDelegate SetPosition;
        internal static SetScaleHeightDelegate SetScaleHeight;
        internal static SetScaleWidthDelegate SetScaleWidth;
    }
}