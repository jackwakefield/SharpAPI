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

void _stdcall DelegateDialogMethods(){
	UI::Dialog::New = gcnew UI::Dialog::NewDelegate(NewDialog);
	UI::Dialog::Free = gcnew UI::Dialog::FreeDelegate(FreeDialog);
	UI::Dialog::Create = gcnew UI::Dialog::CreateDelegate(Create);
	UI::Dialog::CreateEmpty = gcnew UI::Dialog::CreateEmptyDelegate(CreateEmpty);
	UI::Dialog::Add = gcnew UI::Dialog::AddDelegate(Add);
	UI::Dialog::Remove = gcnew UI::Dialog::RemoveDelegate(Remove);
	UI::Dialog::Find = gcnew UI::Dialog::FindDelegate(Find);
	UI::Dialog::ShowChild = gcnew UI::Dialog::ShowChildDelegate(ShowChild);
	UI::Dialog::HideChild = gcnew UI::Dialog::HideChildDelegate(HideChild);
	UI::Dialog::Push_Back_Cmd = gcnew UI::Dialog::Push_Back_CmdDelegate(Push_Back_Cmd);
	UI::Dialog::Push_Front_Cmd = gcnew UI::Dialog::Push_Front_CmdDelegate(Push_Front_Cmd);
	UI::Dialog::ClearCommandQ = gcnew UI::Dialog::ClearCommandQDelegate(ClearCommandQ);
	UI::Dialog::ChangeCaptionRect = gcnew UI::Dialog::ChangeCaptionRectDelegate(ChangeCaptionRect);
	UI::Dialog::GetCaption = gcnew UI::Dialog::GetCaptionDelegate(GetCaption);
	UI::Dialog::GetChildCount = gcnew UI::Dialog::GetChildCountDelegate(GetChildCount);
	UI::Dialog::GetDefaultAdjustPosX = gcnew UI::Dialog::GetDefaultAdjustPosXDelegate(GetDefaultAdjustPosX);
	UI::Dialog::GetDefaultAdjustPosY = gcnew UI::Dialog::GetDefaultAdjustPosYDelegate(GetDefaultAdjustPosY);
	UI::Dialog::GetDefaultPosX = gcnew UI::Dialog::GetDefaultPosXDelegate(GetDefaultPosX);
	UI::Dialog::GetDefaultPosY = gcnew UI::Dialog::GetDefaultPosYDelegate(GetDefaultPosY);
	UI::Dialog::GetDialogType = gcnew UI::Dialog::GetDialogTypeDelegate(GetDialogType);
	UI::Dialog::GetTCommand = gcnew UI::Dialog::GetTCommandDelegate(GetTCommand);
	UI::Dialog::SetCaption = gcnew UI::Dialog::SetCaptionDelegate(SetCaption);
	UI::Dialog::SetDefaultAdjustPosX = gcnew UI::Dialog::SetDefaultAdjustPosXDelegate(SetDefaultAdjustPosX);
	UI::Dialog::SetDefaultAdjustPosY = gcnew UI::Dialog::SetDefaultAdjustPosYDelegate(SetDefaultAdjustPosY);
	UI::Dialog::SetDefaultPosX = gcnew UI::Dialog::SetDefaultPosXDelegate(SetDefaultPosX);
	UI::Dialog::SetDefaultPosY = gcnew UI::Dialog::SetDefaultPosYDelegate(SetDefaultPosY);
	UI::Dialog::SetDefaultVisible = gcnew UI::Dialog::SetDefaultVisibleDelegate(SetDefaultVisible);
	UI::Dialog::SetDialogType = gcnew UI::Dialog::SetDialogTypeDelegate(SetDialogType);
	UI::Dialog::SetEnableChild = gcnew UI::Dialog::SetEnableChildDelegate(SetEnableChild);
	UI::Dialog::SetExtent = gcnew UI::Dialog::SetExtentDelegate(SetExtent);
	UI::Dialog::SetImage = gcnew UI::Dialog::SetImageDelegate(SetImage);
	UI::Dialog::SetModal = gcnew UI::Dialog::SetModalDelegate(SetModal);
	UI::Dialog::SetModeless = gcnew UI::Dialog::SetModelessDelegate(SetModeless);
	UI::Dialog::SetSoundShowID = gcnew UI::Dialog::SetSoundShowIDDelegate(SetSoundShowID);
	UI::Dialog::SetSoundHideID = gcnew UI::Dialog::SetSoundHideIDDelegate(SetSoundHideID);
	UI::Dialog::SetStatusBar = gcnew UI::Dialog::SetStatusBarDelegate(SetStatusBar);
	UI::Dialog::IsDefaultVisible = gcnew UI::Dialog::IsDefaultVisibleDelegate(IsDefaultVisible);
}

RunOnLoad(DelegateDialogMethods)