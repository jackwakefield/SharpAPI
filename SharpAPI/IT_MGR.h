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

#ifndef IT_MGR_H
#define IT_MGR_H

#pragma unmanaged
#include "Templates.h"

class CTDialog;

class IT_MGR {
public:
	void AppendDlg(short type, CTDialog* dialog, int id = 0){  
		return CallMemberFunction<IT_MGR, void, short, CTDialog*, int>(0x0048F9D0, this, type, dialog, id);  
	}

	static IT_MGR* Instance(){
		return reinterpret_cast<IT_MGR*>(0x00697AD0);
	}
};

#pragma managed
using namespace System;

static void AppendDlg(short type, IntPtr dialog, int id = 0){ IT_MGR::Instance()->AppendDlg(type, (CTDialog*)dialog.ToPointer(), id); }

#endif