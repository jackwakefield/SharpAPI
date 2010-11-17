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

#ifndef SOUNDLIST_H
#define SOUNDLIST_H

#pragma unmanaged
#include "Templates.h"
#include "Interop.h"

class CSoundLIST {
public:
	int GetVolume(){
		return *(int*)(this + 156);
	}

	void SetVolume(int volume){
		*(int*)(this + 156) = volume;
	}

	int AddSoundFile(const char* filePath, short mixCount = 1, short index = -1){
		return CallMemberFunction<CSoundLIST, int, const char*, short, short>(0x0047C850, this, filePath, mixCount, index); 
	}

	bool KeyPlaySound(int hashKey){
		return CallMemberFunction<CSoundLIST, bool, int>(0x0047CFF0, this, hashKey); 
	}

	bool IDPlaySound(short id){
		return CallMemberFunction<CSoundLIST, bool, short>(0x0047D3B0, this, id); 
	}

	static CSoundLIST* Instance(){
		return *reinterpret_cast<CSoundLIST**>(0x00695B3C);
	}
};

#pragma managed
using namespace System;

static int GetVolume(){ return CSoundLIST::Instance()->GetVolume(); }
static void SetVolume(int volume){ CSoundLIST::Instance()->SetVolume(volume); }
static int AddSoundFile(String^ filePath){ return CSoundLIST::Instance()->AddSoundFile(Interop::mMarshalContext->marshal_as<const char*>(filePath)); }
static bool KeyPlaySound(int hashKey){ return CSoundLIST::Instance()->KeyPlaySound(hashKey); }
static bool IDPlaySound(short id){ return CSoundLIST::Instance()->IDPlaySound(id); }

#endif