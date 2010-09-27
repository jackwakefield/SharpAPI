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

#ifndef DIALOG_H
#define DIALOG_H

#include <TDialog.h>
#include "SharpAPI.h"
#include "Interop.h"
#include "ExternalUILobby.h"

#pragma unmanaged

typedef void (__stdcall *DIALOG_DRAW)();
typedef void (__stdcall *DIALOG_UPDATE)(int x, int y);
typedef void (__stdcall *DIALOG_PROCESS)(UINT controlID, UINT uiMsg, WPARAM wParam, LPARAM lParam);

class Dialog : public CTDialog {
public:
	virtual void Draw();
	virtual void Update(POINT ptMouse);
	virtual unsigned int Process(UINT uiMsg, WPARAM wParam, LPARAM lParam);
	
public:
	DIALOG_DRAW mDrawCallback;
	DIALOG_UPDATE mUpdateCallback;
	DIALOG_PROCESS mProcessCallback;

	void* mDrawHandle;
	void* mUpdateHandle;
	void* mProcessHandle;
};

#pragma managed
using namespace System;
using namespace System::Runtime::InteropServices;
using namespace SharpAPI::Internal;

static IntPtr NewDialog(UI::Dialog::DrawCallback^ drawCallback, UI::Dialog::UpdateCallback^ updateCallback, UI::Dialog::ProcessCallback^ processCallback, bool external){
	Dialog* dialog = new Dialog();
	if(external) CExternalUILobby::mDialogs.push_back(dialog);

	dialog->mDrawHandle = GCHandle::ToIntPtr(GCHandle::Alloc(drawCallback)).ToPointer();
	dialog->mUpdateHandle = GCHandle::ToIntPtr(GCHandle::Alloc(updateCallback)).ToPointer();
	dialog->mProcessHandle = GCHandle::ToIntPtr(GCHandle::Alloc(processCallback)).ToPointer();

	dialog->mDrawCallback = (DIALOG_DRAW)Marshal::GetFunctionPointerForDelegate(drawCallback).ToPointer();
	dialog->mUpdateCallback = (DIALOG_UPDATE)Marshal::GetFunctionPointerForDelegate(updateCallback).ToPointer();
	dialog->mProcessCallback = (DIALOG_PROCESS)Marshal::GetFunctionPointerForDelegate(processCallback).ToPointer();

	return (IntPtr)(void*)dialog;
}

static void FreeDialog(IntPtr dialogHandle, bool external){
	Dialog* dialog = (Dialog*)dialogHandle.ToPointer();
	CExternalUILobby::RemoveDialog(dialog);

	((GCHandle)(IntPtr)dialog->mDrawHandle).Free();
	((GCHandle)(IntPtr)dialog->mUpdateHandle).Free();
	((GCHandle)(IntPtr)dialog->mProcessHandle).Free();
	
	delete dialog;
}

static bool Create(IntPtr dialog, String^ name){ return ((CTDialog*)dialog.ToPointer())->Create(Interop::mMarshalContext->marshal_as<const char*>(name)); }
static bool CreateEmpty(IntPtr dialog, int x, int y, int width, int height){ return ((CTDialog*)dialog.ToPointer())->Create(x, y, width, height); }
static void Add(IntPtr dialog, IntPtr control){ ((CTDialog*)dialog.ToPointer())->Add((CWinCtrl*)control.ToPointer()); }
static bool Remove(IntPtr dialog, int id){ return ((CTDialog*)dialog.ToPointer())->Remove(id); }
static IntPtr Find(IntPtr dialog, int id){ return (IntPtr)(void*)((CTDialog*)dialog.ToPointer())->Find(id); }
static bool ShowChild(IntPtr dialog, int id){ return ((CTDialog*)dialog.ToPointer())->ShowChild(id); }
static bool HideChild(IntPtr dialog, int id){ return ((CTDialog*)dialog.ToPointer())->HideChild(id); }
static void Push_Back_Cmd(IntPtr dialog, IntPtr command){ ((CTDialog*)dialog.ToPointer())->Push_Back_Cmd((CTCommand*)command.ToPointer()); }
static void Push_Front_Cmd(IntPtr dialog, IntPtr command){ ((CTDialog*)dialog.ToPointer())->Push_Front_Cmd((CTCommand*)command.ToPointer()); }
static void ClearCommandQ(IntPtr dialog){ ((CTDialog*)dialog.ToPointer())->ClearCommandQ(); }
static void ChangeCaptionRect(IntPtr dialog, System::Drawing::Rectangle rectangle){ RECT rect = { rectangle.Left, rectangle.Top, rectangle.Right, rectangle.Bottom }; ((CTDialog*)dialog.ToPointer())->ChangeCaptionRect(rect); }
static IntPtr GetCaption(IntPtr dialog){ return (IntPtr)(void*)((CTDialog*)dialog.ToPointer())->GetCaption(); }
static int GetChildCount(IntPtr dialog){ return ((CTDialog*)dialog.ToPointer())->GetChildCount(); }
static int GetDefaultAdjustPosX(IntPtr dialog){ return ((CTDialog*)dialog.ToPointer())->GetDefaultAdjustPosX(); }
static int GetDefaultAdjustPosY(IntPtr dialog){ return ((CTDialog*)dialog.ToPointer())->GetDefaultAdjustPosY(); }
static int GetDefaultPosX(IntPtr dialog){ return ((CTDialog*)dialog.ToPointer())->GetDefaultPosX(); }
static int GetDefaultPosY(IntPtr dialog){ return ((CTDialog*)dialog.ToPointer())->GetDefaultPosY(); }
static int GetDialogType(IntPtr dialog){ return ((CTDialog*)dialog.ToPointer())->GetDialogType(); }
static IntPtr GetTCommand(IntPtr dialog){ return (IntPtr)(void*)((CTDialog*)dialog.ToPointer())->GetTCommand(); }
static void SetCaption(IntPtr dialog, IntPtr caption){ ((CTDialog*)dialog.ToPointer())->SetCaption((CTCaption*)caption.ToPointer()); }
static void SetDefaultAdjustPosX(IntPtr dialog, int x){ ((CTDialog*)dialog.ToPointer())->SetDefaultAdjustPosX(x); }
static void SetDefaultAdjustPosY(IntPtr dialog, int y){ ((CTDialog*)dialog.ToPointer())->SetDefaultAdjustPosY(y); }
static void SetDefaultPosX(IntPtr dialog, int x){ ((CTDialog*)dialog.ToPointer())->SetDefaultPosX(x); }
static void SetDefaultPosY(IntPtr dialog, int y){ ((CTDialog*)dialog.ToPointer())->SetDefaultPosY(y); }
static void SetDefaultVisible(IntPtr dialog, bool visible){ ((CTDialog*)dialog.ToPointer())->SetDefaultVisible(visible); }
static void SetDialogType(IntPtr dialog, int type){ ((CTDialog*)dialog.ToPointer())->SetDialogType(type); }
static bool SetEnableChild(IntPtr dialog, int id, bool enable){ return ((CTDialog*)dialog.ToPointer())->SetEnableChild(id, enable); }
static void SetExtent(IntPtr dialog, int extent){ ((CTDialog*)dialog.ToPointer())->SetExtent(extent); }
static void SetImage(IntPtr dialog, IntPtr image){ ((CTDialog*)dialog.ToPointer())->SetImage((CTImage*)image.ToPointer()); }
static void SetModal(IntPtr dialog){ ((CTDialog*)dialog.ToPointer())->SetModal(); }
static void SetModeless(IntPtr dialog){ ((CTDialog*)dialog.ToPointer())->SetModeless(); }
static void SetSoundShowID(IntPtr dialog, int id){ ((CTDialog*)dialog.ToPointer())->SetSoundShowID(id); }
static void SetSoundHideID(IntPtr dialog, int id){ ((CTDialog*)dialog.ToPointer())->SetSoundHideID(id); }
static void SetStatusBar(IntPtr dialog, IntPtr statusBar){ ((CTDialog*)dialog.ToPointer())->SetStatusBar((CTStatusBar*)statusBar.ToPointer()); }
static bool IsDefaultVisible(IntPtr dialog){ return ((CTDialog*)dialog.ToPointer())->IsDefaultVisible(); }
static void MoveCtrl2ListEnd(IntPtr dialog, int id){ ((CTDialog*)dialog.ToPointer())->MoveCtrl2ListEnd(id); }
static void ProcessLButtonDown(IntPtr dialog){ ((CTDialog*)dialog.ToPointer())->ProcessLButtonDown(); }

#endif