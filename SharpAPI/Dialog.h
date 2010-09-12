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
	GC::Collect();	
}

static bool Create(IntPtr dialog, String^ name){ return ((CTDialog*)dialog.ToPointer())->Create(Interop::mMarshalContext->marshal_as<const char*>(name)); }
static bool CreateEmpty(IntPtr dialog, int x, int y, int width, int height){ return ((CTDialog*)dialog.ToPointer())->Create(x, y, width, height); }

#endif