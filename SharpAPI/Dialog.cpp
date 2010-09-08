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
#include "main.h"

#pragma managed
using namespace System;
using namespace System::Runtime::InteropServices;
using namespace SharpAPI::Internal::UI;

void __stdcall DelegateDialogMethods(){
	Dialog::New = gcnew Dialog::NewDelegate(NewDialog);
	Dialog::Create = gcnew Dialog::CreateDelegate(Create);
	Dialog::GetControlID = gcnew Dialog::GetControlIDDelegate(GetControlID);
	Dialog::SetControlID = gcnew Dialog::SetControlIDDelegate(SetControlID);
	Dialog::GetWidth = gcnew Dialog::GetWidthDelegate(GetWidth);
	Dialog::SetWidth = gcnew Dialog::SetWidthDelegate(SetWidth);
	Dialog::GetHeight = gcnew Dialog::GetHeightDelegate(GetHeight);
	Dialog::SetHeight = gcnew Dialog::SetHeightDelegate(SetHeight);
	Dialog::Show = gcnew Dialog::ShowDelegate(Show);
	Dialog::Hide = gcnew Dialog::HideDelegate(Hide);
}

RunOnLoad(DelegateDialogMethods);