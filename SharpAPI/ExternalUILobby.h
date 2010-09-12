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

#ifndef EXTERNALUILOBBY_H
#define EXTERNALUILOBBY_H

#include "Templates.h"
#include <vector>
#include <algorithm>
#include <TDialog.h>

using namespace std;
class CExternalUIManager;

class CExternalUILobby {
public:
	CExternalUIManager* GetExternalUIManager(){ 
		return CallMemberFunction<CExternalUILobby, CExternalUIManager*>(0x0049CE30, this); 
	}

	static CExternalUILobby* Instance(){
		return reinterpret_cast<CExternalUILobby*>(0x00697FE4);
	}

	static void RemoveDialog(CTDialog* dialog){
		mDialogs.erase(remove(mDialogs.begin(), mDialogs.end(), dialog), mDialogs.end());
	}
	
public:
	static vector<CTDialog*> mDialogs;
};

#endif