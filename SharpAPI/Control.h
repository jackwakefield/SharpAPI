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

#ifndef CONTROL_H
#define CONTROL_H

#include <WinCtrl.h>
#include "SharpAPI.h"
#include "Interop.h"

#pragma managed
using namespace System;
using namespace System::Drawing;
using namespace System::Runtime::InteropServices;
using namespace SharpAPI::Internal;

static bool IsInside(IntPtr control, int x, int y){ return ((CWinCtrl*)control.ToPointer())->IsInside(x, y); }
static void SetSelected(IntPtr control){ ((CWinCtrl*)control.ToPointer())->SetSelected(); }
static void SetDeselected(IntPtr control){ ((CWinCtrl*)control.ToPointer())->SetDeselected(); }
static void Show(IntPtr control){ ((CWinCtrl*)control.ToPointer())->Show(); }
static void Hide(IntPtr control){ ((CWinCtrl*)control.ToPointer())->Hide(); }
static void SetFocus(IntPtr control, bool focus){ ((CWinCtrl*)control.ToPointer())->SetFocus(focus); }
static bool IsVision(IntPtr control){ return ((CWinCtrl*)control.ToPointer())->IsVision(); }
static void SetOffset(IntPtr control, Point point){ tagPOINT tag; tag.x = point.X; tag.y = point.Y; ((CWinCtrl*)control.ToPointer())->SetOffset(tag); }
static void MoveWindow(IntPtr control, Point point){ tagPOINT tag; tag.x = point.X; tag.y = point.Y; ((CWinCtrl*)control.ToPointer())->MoveWindow(tag); }
static void SetHeight(IntPtr control, int height){ ((CWinCtrl*)control.ToPointer())->SetHeight(height); }
static void SetWidth(IntPtr control, int width){ ((CWinCtrl*)control.ToPointer())->SetWidth(width); }
static bool IsActive(IntPtr control){ return ((CWinCtrl*)control.ToPointer())->IsActive(); }
static bool IsEnable(IntPtr control){ return ((CWinCtrl*)control.ToPointer())->IsEnable(); }
static bool IsFocus(IntPtr control){ return ((CWinCtrl*)control.ToPointer())->IsFocus(); }
static bool IsOwnerDraw(IntPtr control){ return ((CWinCtrl*)control.ToPointer())->IsOwnerDraw(); }
static bool IsSelected(IntPtr control){ return ((CWinCtrl*)control.ToPointer())->IsSelected(); }
static int GetControlID(IntPtr control){ return ((CWinCtrl*)control.ToPointer())->GetControlID(); }
static int GetControlType(IntPtr control){ return ((CWinCtrl*)control.ToPointer())->GetControlType(); }
static int GetHeight(IntPtr control){ return ((CWinCtrl*)control.ToPointer())->GetHeight(); }
static Point GetOffset(IntPtr control){ tagPOINT tag = ((CWinCtrl*)control.ToPointer())->GetOffset(); return Point(tag.x, tag.y); }
static IntPtr GetParent(IntPtr control){ return (IntPtr)(void*)((CWinCtrl*)control.ToPointer())->GetParent(); }
static Point GetPosition(IntPtr control){ tagPOINT tag = ((CWinCtrl*)control.ToPointer())->GetPosition(); return Point(tag.x, tag.y); }
static int GetWidth(IntPtr control){ return ((CWinCtrl*)control.ToPointer())->GetWidth(); }
static void SetActive(IntPtr control, bool active){ ((CWinCtrl*)control.ToPointer())->SetActive(active); }
static void SetAlphaValue(IntPtr control, unsigned char alpha){ ((CWinCtrl*)control.ToPointer())->SetAlphaValue(alpha); }
static void SetControlID(IntPtr control, int id){ ((CWinCtrl*)control.ToPointer())->SetControlID(id); }
static void SetControlType(IntPtr control, int type){ ((CWinCtrl*)control.ToPointer())->SetControlType(type); }
static void SetCtrlStatus(IntPtr control, int status){ ((CWinCtrl*)control.ToPointer())->SetCtrlStatus(status); }
static void SetEnable(IntPtr control, bool enabled){ ((CWinCtrl*)control.ToPointer())->SetEnable(enabled); }
static void SetOwnerDraw(IntPtr control, bool ownerDraw){ ((CWinCtrl*)control.ToPointer())->SetOwnerDraw(ownerDraw); }
static void SetParent(IntPtr control, IntPtr parent){ ((CWinCtrl*)control.ToPointer())->SetParent((CWinCtrl*)parent.ToPointer()); }
static void SetPosition(IntPtr control, Point point){ tagPOINT tag; tag.x = point.X; tag.y = point.Y; ((CWinCtrl*)control.ToPointer())->SetPosition(tag); }
static void SetScaleHeight(IntPtr control, float scaleHeight){ ((CWinCtrl*)control.ToPointer())->SetScaleHeight(scaleHeight); }
static void SetScaleWidth(IntPtr control, float scaleWidth){ ((CWinCtrl*)control.ToPointer())->SetScaleWidth(scaleWidth); }

#endif