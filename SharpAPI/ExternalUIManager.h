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

#ifndef EXTERNALUIMANAGER
#define EXTERNALUIMANAGER_H

#pragma unmanaged
#include "Templates.h"
#include "ExternalUILobby.h"

class CTDialog;

class CExternalUIManager {
public:
	CTDialog* GetEUI(int type){
		return CallMemberFunction<CExternalUIManager, CTDialog*, int>(0x004993E0, this, type); 
	}
};

#pragma managed
using namespace System;

static IntPtr GetEUI(int type){ return (IntPtr)(void*)CExternalUILobby::Instance()->GetExternalUIManager()->GetEUI(type); }

#endif