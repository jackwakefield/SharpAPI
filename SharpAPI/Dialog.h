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
#include "Interop.h"

#pragma managed
using namespace System;

static void* NewDialog(){ return new CTDialog(); }
static void Create(IntPtr dialog, String^ name){ ((CTDialog*)dialog.ToPointer())->Create(Interop::mMarshalContext->marshal_as<const char*>(name)); }
static int GetControlID(IntPtr dialog){ return ((CTDialog*)dialog.ToPointer())->GetControlID(); }
static void SetControlID(IntPtr dialog, int id){ ((CTDialog*)dialog.ToPointer())->SetControlID(id); }
static int GetWidth(IntPtr dialog){ return ((CTDialog*)dialog.ToPointer())->GetWidth(); }
static void SetWidth(IntPtr dialog, int width){ ((CTDialog*)dialog.ToPointer())->SetWidth(width); }
static int GetHeight(IntPtr dialog){ return ((CTDialog*)dialog.ToPointer())->GetHeight(); }
static void SetHeight(IntPtr dialog, int height){ ((CTDialog*)dialog.ToPointer())->SetHeight(height); }
static void Show(IntPtr dialog){ ((CTDialog*)dialog.ToPointer())->Show(); }
static void Hide(IntPtr dialog){ ((CTDialog*)dialog.ToPointer())->Hide(); }

#endif