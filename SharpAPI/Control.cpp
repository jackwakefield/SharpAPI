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

#include "Control.h"
#include "main.h"

#pragma managed
using namespace System;
using namespace System::Runtime::InteropServices;
using namespace SharpAPI::Internal;

void __stdcall DelegateControlMethods(){
	UI::Control::IsInside = gcnew UI::Control::IsInsideDelegate(IsInside);
	UI::Control::SetSelected = gcnew UI::Control::SetSelectedDelegate(SetSelected);
	UI::Control::SetDeselected = gcnew UI::Control::SetDeselectedDelegate(SetDeselected);
	UI::Control::Show = gcnew UI::Control::ShowDelegate(Show);
	UI::Control::Hide = gcnew UI::Control::HideDelegate(Hide);
	UI::Control::SetFocus = gcnew UI::Control::SetFocusDelegate(SetFocus);
	UI::Control::IsVision = gcnew UI::Control::IsVisionDelegate(IsVision);
	UI::Control::SetOffset = gcnew UI::Control::SetOffsetDelegate(SetOffset);
	UI::Control::MoveWindow = gcnew UI::Control::MoveWindowDelegate(MoveWindow);
	UI::Control::SetHeight = gcnew UI::Control::SetHeightDelegate(SetHeight);
	UI::Control::SetWidth = gcnew UI::Control::SetWidthDelegate(SetWidth);
	UI::Control::IsActive = gcnew UI::Control::IsActiveDelegate(IsActive);
	UI::Control::IsEnable = gcnew UI::Control::IsEnableDelegate(IsEnable);
	UI::Control::IsFocus = gcnew UI::Control::IsFocusDelegate(IsFocus);
	UI::Control::IsOwnerDraw = gcnew UI::Control::IsOwnerDrawDelegate(IsOwnerDraw);
	UI::Control::IsSelected = gcnew UI::Control::IsSelectedDelegate(IsSelected);
	UI::Control::GetControlID = gcnew UI::Control::GetControlIDDelegate(GetControlID);
	UI::Control::GetControlType = gcnew UI::Control::GetControlTypeDelegate(GetControlType);
	UI::Control::GetHeight = gcnew UI::Control::GetHeightDelegate(GetHeight);
	UI::Control::GetOffset = gcnew UI::Control::GetOffsetDelegate(GetOffset);
	UI::Control::GetParent = gcnew UI::Control::GetParentDelegate(GetParent);
	UI::Control::GetPosition = gcnew UI::Control::GetPositionDelegate(GetPosition);
	UI::Control::GetWidth = gcnew UI::Control::GetWidthDelegate(GetWidth);
	UI::Control::SetActive = gcnew UI::Control::SetActiveDelegate(SetActive);
	UI::Control::SetAlphaValue = gcnew UI::Control::SetAlphaValueDelegate(SetAlphaValue);
	UI::Control::SetControlID = gcnew UI::Control::SetControlIDDelegate(SetControlID);
	UI::Control::SetControlType = gcnew UI::Control::SetControlTypeDelegate(SetControlType);
	UI::Control::SetCtrlStatus = gcnew UI::Control::SetCtrlStatusDelegate(SetCtrlStatus);
	UI::Control::SetEnable = gcnew UI::Control::SetEnableDelegate(SetEnable);
	UI::Control::SetOwnerDraw = gcnew UI::Control::SetOwnerDrawDelegate(SetOwnerDraw);
	UI::Control::SetParent = gcnew UI::Control::SetParentDelegate(SetParent);
	UI::Control::SetPosition = gcnew UI::Control::SetPositionDelegate(SetPosition);
	UI::Control::SetScaleHeight = gcnew UI::Control::SetScaleHeightDelegate(SetScaleHeight);
	UI::Control::SetScaleWidth = gcnew UI::Control::SetScaleWidthDelegate(SetScaleWidth);
}

RunOnLoad(DelegateControlMethods);