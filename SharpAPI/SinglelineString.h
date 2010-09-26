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

#ifndef SINGLELINESTRING_H
#define SINGLELINESTRING_H

#include <SinglelineString.h>
#include "SharpAPI.h"
#include "Interop.h"

#pragma managed
using namespace System;
using namespace System::Drawing;
using namespace System::Runtime::InteropServices;
using namespace SharpAPI::Internal;

static IntPtr NewSinglelineString(){
	return (IntPtr)(void*)new CSinglelineString();
}

static void FreeSinglelineString(IntPtr stringHandle){
	CSinglelineString* singlelineString = (CSinglelineString*)stringHandle.ToPointer();
	delete singlelineString;
}

static void SetString(IntPtr stringHandle, String^ value){ ((CSinglelineString*)stringHandle.ToPointer())->set_string(Interop::mMarshalContext->marshal_as<const char*>(value), ((CSinglelineString*)stringHandle.ToPointer())->get_rect(), ((CSinglelineString*)stringHandle.ToPointer())->mFont); }
static void SetRect(IntPtr stringHandle, System::Drawing::Rectangle rectangle){ RECT rect = { rectangle.Left, rectangle.Top, rectangle.Right, rectangle.Bottom }; ((CSinglelineString*)stringHandle.ToPointer())->set_rect(rect); }
static void SetColour(IntPtr stringHandle, Color colour){ ((CSinglelineString*)stringHandle.ToPointer())->set_color(colour.ToArgb()); }
static void SetFormat(IntPtr stringHandle, int format){ ((CSinglelineString*)stringHandle.ToPointer())->set_format(format); }
static void SetFont(IntPtr stringHandle, int font){ ((CSinglelineString*)stringHandle.ToPointer())->mFont = font; }
static String^ GetString(IntPtr stringHandle){ return Interop::mMarshalContext->marshal_as<String^>(((CSinglelineString*)stringHandle.ToPointer())->get_string()); }
static System::Drawing::Rectangle GetRect(IntPtr stringHandle){ RECT rect = ((CSinglelineString*)stringHandle.ToPointer())->get_rect(); return System::Drawing::Rectangle(rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top); }
static Color GetColour(IntPtr stringHandle){ return Color::FromArgb(((CSinglelineString*)stringHandle.ToPointer())->mColour); }
static int GetFormat(IntPtr stringHandle){ return ((CSinglelineString*)stringHandle.ToPointer())->mFormat; }
static int GetFont(IntPtr stringHandle){ return ((CSinglelineString*)stringHandle.ToPointer())->mFont; }
static void Draw(IntPtr stringHandle){ ((CSinglelineString*)stringHandle.ToPointer())->draw(); }
static bool IsEllipsis(IntPtr stringHandle){ return ((CSinglelineString*)stringHandle.ToPointer())->is_ellipsis(); }
static bool Empty(IntPtr stringHandle){ return ((CSinglelineString*)stringHandle.ToPointer())->empty(); }
static void Clear(IntPtr stringHandle){ ((CSinglelineString*)stringHandle.ToPointer())->clear(); }

#endif