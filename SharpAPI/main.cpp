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

#include "main.h"
#include "Interop.h"

DWORD gManagedThread;

#pragma managed
using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;

DWORD WINAPI ManagedThread(LPVOID lpThreadParameter){
	Interop::mMarshalContext = gcnew marshal_context();

	HookList::Instance().ApplyHooks();
	WriteList::Instance().ApplyWrites();

	return 0;
}

#pragma unmanaged

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved){
	switch(dwReason){
		case DLL_PROCESS_ATTACH:
			{
#ifdef ENABLE_CONSOLE
				::CreateConsole();
#endif
				CreateThread(NULL, 0, ManagedThread, NULL, 0, &gManagedThread);
			}
			break;
		case DLL_PROCESS_DETACH:
			ExitThread(gManagedThread);
			break;
	}
	
	return true;
}