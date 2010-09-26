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

#include "Dialog.h"
#include "HookList.h"

#pragma unmanaged

void Dialog::Draw(){
	if(!IsVision())	return;
	CTDialog::Draw();

	mDrawCallback();
}

void Dialog::Update(POINT ptMouse){
	if(!IsVision())	return;
	CTDialog::Update(ptMouse);

	mUpdateCallback(ptMouse.x, ptMouse.y);
}

unsigned int Dialog::Process(UINT uiMsg, WPARAM wParam, LPARAM lParam){
	if(!IsVision())	return 0;

	unsigned int controlID = CTDialog::Process(uiMsg, wParam, lParam);
	mProcessCallback(controlID, uiMsg, wParam, lParam);

	return controlID;
}

#pragma managed
using namespace System;
using namespace System::Runtime::InteropServices;
using namespace SharpAPI::Internal;

void __stdcall DelegateDialogMethods(){
	UI::Dialog::New = gcnew UI::Dialog::NewDelegate(NewDialog);
	UI::Dialog::Free = gcnew UI::Dialog::FreeDelegate(FreeDialog);
	UI::Dialog::Create = gcnew UI::Dialog::CreateDelegate(Create);
	UI::Dialog::CreateEmpty = gcnew UI::Dialog::CreateEmptyDelegate(CreateEmpty);
}

RunOnLoad(DelegateDialogMethods);