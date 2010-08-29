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

// From TitanProtect
// Created by ExJam
#ifndef HOOKLIST_H
#define HOOKLIST_H

#include <list>
using namespace std;

class HookList {
public:
	struct Hook {
		int mAddress;
		void* mFunction;
		int mNOPs;
	};

	static void Add(int address, void* function, int nops = 0);
	static void Apply();

private:
	static list<Hook*> mHooks;
};

#endif

#define HookOnLoad(pos, FuncName, nops) \
class FuncHookOnLoadClass_##FuncName {\
public: \
	FuncHookOnLoadClass_##FuncName(){ \
	HookList::Instance().AddHook(pos, FuncName, nops); \
	}; \
}; \
	FuncHookOnLoadClass_##FuncName gAutoHooker_##FuncName;