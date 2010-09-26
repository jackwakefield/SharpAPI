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

#include "SinglelineString.h"
#include "HookList.h"

#pragma managed
using namespace System;
using namespace System::Runtime::InteropServices;
using namespace SharpAPI::Internal;

void __stdcall DelegateSinglineStringMethods(){
	UI::SinglelineString::New = gcnew UI::SinglelineString::NewDelegate(NewSinglelineString);
	UI::SinglelineString::Free = gcnew UI::SinglelineString::FreeDelegate(FreeSinglelineString);
	UI::SinglelineString::SetString = gcnew UI::SinglelineString::SetStringDelegate(SetString);
	UI::SinglelineString::SetRect = gcnew UI::SinglelineString::SetRectDelegate(SetRect);
	UI::SinglelineString::SetColour = gcnew UI::SinglelineString::SetColourDelegate(SetColour);
	UI::SinglelineString::SetFormat = gcnew UI::SinglelineString::SetFormatDelegate(SetFormat);
	UI::SinglelineString::SetFont = gcnew UI::SinglelineString::SetFontDelegate(SetFont);
	UI::SinglelineString::GetString = gcnew UI::SinglelineString::GetStringDelegate(GetString);
	UI::SinglelineString::GetRect = gcnew UI::SinglelineString::GetRectDelegate(GetRect);
	UI::SinglelineString::GetColour = gcnew UI::SinglelineString::GetColourDelegate(GetColour);
	UI::SinglelineString::GetFormat = gcnew UI::SinglelineString::GetFormatDelegate(GetFormat);
	UI::SinglelineString::GetFont = gcnew UI::SinglelineString::GetFontDelegate(GetFont);
	UI::SinglelineString::Draw = gcnew UI::SinglelineString::DrawDelegate(Draw);
	UI::SinglelineString::IsEllipsis = gcnew UI::SinglelineString::IsEllipsisDelegate(IsEllipsis);
	UI::SinglelineString::Empty = gcnew UI::SinglelineString::EmptyDelegate(Empty);
	UI::SinglelineString::Clear = gcnew UI::SinglelineString::ClearDelegate(Clear);
}

RunOnLoad(DelegateSinglineStringMethods);