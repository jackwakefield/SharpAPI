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

#include "HookList.h"
#include "Code.h"

list<HookList::Hook*> HookList::mHooks;

void HookList::Add(int address, void* function, int nops){
	Hook* hook = new Hook();
	hook->mAddress = address;
	hook->mFunction = function;
	hook->mNOPs = nops;
	mHooks.push_back(hook);
}

void HookList::Apply(){
	for(auto hook = mHooks.begin(); hook != mHooks.end(); ++hook){
		Code::JmpHook((*hook)->mAddress, (*hook)->mFunction, (*hook)->mNOPs);
	}
}