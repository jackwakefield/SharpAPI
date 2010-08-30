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
#ifndef RunOnLoad

#include <list>
#include "Code.h"

using namespace std;

typedef void (__stdcall *PF_SVOIDVOID)(void);
typedef void (__cdecl *PF_CVOIDVOID)(void);

class RunList {
public:
	RunList(){}
	~RunList(){}

	static RunList& Instance(){
		static RunList self;
		return self;
	}

	void AddFunction(PF_SVOIDVOID func, char* name){
		mFunctions.push_back(RunFunc(func, name));
	}

	void RunFunctions(){
		for(auto itr = mFunctions.begin(); itr != mFunctions.end(); ++itr){
			PF_SVOIDVOID func = (*itr).mFunction;
			(*func)();
		}
	}

	struct RunFunc {
		RunFunc(PF_SVOIDVOID func, char* name) : mFunction(func), mName(name) {}

		PF_SVOIDVOID mFunction;
		char* mName;
	};

	list<RunFunc> mFunctions;
};

class HookList {
public:
	struct Hook {
		int mAddress;
		PF_CVOIDVOID mFunction;
		int mNOPS;
		char* mName;
	};

public:
	HookList(){}
	~HookList(){}

	static HookList& Instance(){
		static HookList self;
		return self;
	}

	void AddHook(int addr, PF_CVOIDVOID func, int nops, char* name){
		Hook* hook = new Hook();
		hook->mAddress = addr;
		hook->mFunction = func;
		hook->mNOPS = nops;
		hook->mName = name;
		mHooks.push_back(hook);
	}

	void ApplyHooks(){
		for(auto itr = mHooks.begin(); itr != mHooks.end(); ++itr){
			Hook* hook = *itr;
			Code::JmpHook(hook->mAddress, hook->mFunction, hook->mNOPS);
		}
	}

	list<Hook*> mHooks;
};

class WriteList {
public:
	struct Write {
		int mAddress;
		unsigned char* mData;
		int mLength;
	};

public:
	WriteList(){}
	~WriteList(){}

	static WriteList& Instance(){
		static WriteList self;
		return self;
	}

	void AddHook(int addr, unsigned char* data, int length){
		Write* write = new Write();
		write->mAddress = addr;
		write->mData = data;
		write->mLength = length;
		mWrites.push_back(write);
	}

	void ApplyWrites(){
		for(auto itr = mWrites.begin(); itr != mWrites.end(); ++itr){
			Write* write = *itr;
			Code::Write(write->mAddress, write->mData, write->mLength);
		}
	}

	list<Write*> mWrites;
};

#define RunOnLoad(FuncName) \
class FuncRunOnLoadClass_##FuncName {\
public: \
	FuncRunOnLoadClass_##FuncName(){ \
	RunList::Instance().AddFunction(FuncName, #FuncName); \
	}; \
}; \
	FuncRunOnLoadClass_##FuncName gAutoRunner_##FuncName;

#define HookOnLoad(pos, FuncName, nops) \
class FuncHookOnLoadClass_##FuncName {\
public: \
	FuncHookOnLoadClass_##FuncName(){ \
	HookList::Instance().AddHook(pos, (PF_CVOIDVOID)FuncName, nops, #FuncName); \
	}; \
}; \
	FuncHookOnLoadClass_##FuncName gAutoHooker_##FuncName;

#define WriteOnLoad(pos, data, length) \
class FuncWriteOnLoadClass_##FuncName {\
public: \
	FuncWriteOnLoadClass_##FuncName(){ \
	WriteList::Instance().AddHook(pos, data, length); \
	}; \
}; \
	FuncWriteOnLoadClass_##FuncName gAutoWriter_##FuncName;


#endif