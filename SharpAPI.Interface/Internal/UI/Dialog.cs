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

namespace SharpAPI.Internal.UI {
    internal static class Dialog {
        internal delegate void DrawCallback();
        internal delegate void UpdateCallback(int x, int y);
        internal delegate void ProcessCallback(int controlID, int message, int wParameter, int lParameter);

        internal delegate IntPtr NewDelegate(DrawCallback drawCallback, UpdateCallback updateDelegate, ProcessCallback processCallback, bool external);
        internal delegate void FreeDelegate(IntPtr dialog, bool external);
        internal delegate bool CreateDelegate(IntPtr dialog, string name);
        internal delegate bool CreateEmptyDelegate(IntPtr dialog, int x, int y, int width, int height);
        internal delegate void AddDelegate(IntPtr dialog, IntPtr control);
        internal delegate bool RemoveDelegate(IntPtr dialog, int id);
        internal delegate IntPtr FindDelegate(IntPtr dialog, int id);
        internal delegate bool ShowChildDelegate(IntPtr dialog, int id);
        internal delegate bool HideChildDelegate(IntPtr dialog, int id);
        internal delegate void Push_Back_CmdDelegate(IntPtr dialog, IntPtr command);
        internal delegate void Push_Front_CmdDelegate(IntPtr dialog, IntPtr command);
        internal delegate void ClearCommandQDelegate(IntPtr dialog);
        internal delegate void ChangeCaptionRectDelegate(IntPtr dialog, Rectangle rectangle);
        internal delegate IntPtr GetCaptionDelegate(IntPtr dialog);
        internal delegate int GetChildCountDelegate(IntPtr dialog);
        internal delegate int GetDefaultAdjustPosXDelegate(IntPtr dialog);
        internal delegate int GetDefaultAdjustPosYDelegate(IntPtr dialog);
        internal delegate int GetDefaultPosXDelegate(IntPtr dialog);
        internal delegate int GetDefaultPosYDelegate(IntPtr dialog);
        internal delegate int GetDialogTypeDelegate(IntPtr dialog);
        internal delegate IntPtr GetTCommandDelegate(IntPtr dialog);
        internal delegate void SetCaptionDelegate(IntPtr dialog, IntPtr caption);
        internal delegate void SetDefaultAdjustPosXDelegate(IntPtr dialog, int x);
        internal delegate void SetDefaultAdjustPosYDelegate(IntPtr dialog, int y);
        internal delegate void SetDefaultPosXDelegate(IntPtr dialog, int x);
        internal delegate void SetDefaultPosYDelegate(IntPtr dialog, int y);
        internal delegate void SetDefaultVisibleDelegate(IntPtr dialog, bool visible);
        internal delegate void SetDialogTypeDelegate(IntPtr dialog, int type);
        internal delegate bool SetEnableChildDelegate(IntPtr dialog, int id, bool enable);
        internal delegate void SetExtentDelegate(IntPtr dialog, int extent);
        internal delegate void SetImageDelegate(IntPtr dialog, IntPtr image);
        internal delegate void SetModalDelegate(IntPtr dialog);
        internal delegate void SetModelessDelegate(IntPtr dialog);
        internal delegate void SetSoundShowIDDelegate(IntPtr dialog, int id);
        internal delegate void SetSoundHideIDDelegate(IntPtr dialog, int id);
        internal delegate void SetStatusBarDelegate(IntPtr dialog, IntPtr statusBar);
        internal delegate bool IsDefaultVisibleDelegate(IntPtr dialog);

        internal static NewDelegate New;
        internal static FreeDelegate Free;
        internal static CreateDelegate Create;
        internal static CreateEmptyDelegate CreateEmpty;
        internal static AddDelegate Add;
        internal static RemoveDelegate Remove;
        internal static FindDelegate Find;
        internal static ShowChildDelegate ShowChild;
        internal static HideChildDelegate HideChild;
        internal static Push_Back_CmdDelegate Push_Back_Cmd;
        internal static Push_Front_CmdDelegate Push_Front_Cmd;
        internal static ClearCommandQDelegate ClearCommandQ;
        internal static ChangeCaptionRectDelegate ChangeCaptionRect;
        internal static GetCaptionDelegate GetCaption;
        internal static GetChildCountDelegate GetChildCount;
        internal static GetDefaultAdjustPosXDelegate GetDefaultAdjustPosX;
        internal static GetDefaultAdjustPosYDelegate GetDefaultAdjustPosY;
        internal static GetDefaultPosXDelegate GetDefaultPosX;
        internal static GetDefaultPosYDelegate GetDefaultPosY;
        internal static GetDialogTypeDelegate GetDialogType;
        internal static GetTCommandDelegate GetTCommand;
        internal static SetCaptionDelegate SetCaption;
        internal static SetDefaultAdjustPosXDelegate SetDefaultAdjustPosX;
        internal static SetDefaultAdjustPosYDelegate SetDefaultAdjustPosY;
        internal static SetDefaultPosXDelegate SetDefaultPosX;
        internal static SetDefaultPosYDelegate SetDefaultPosY;
        internal static SetDefaultVisibleDelegate SetDefaultVisible;
        internal static SetDialogTypeDelegate SetDialogType;
        internal static SetEnableChildDelegate SetEnableChild;
        internal static SetExtentDelegate SetExtent;
        internal static SetImageDelegate SetImage;
        internal static SetModalDelegate SetModal;
        internal static SetModelessDelegate SetModeless;
        internal static SetSoundShowIDDelegate SetSoundShowID;
        internal static SetSoundHideIDDelegate SetSoundHideID;
        internal static SetStatusBarDelegate SetStatusBar;
        internal static IsDefaultVisibleDelegate IsDefaultVisible;
    }
}