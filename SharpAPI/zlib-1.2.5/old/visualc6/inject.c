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

#include <Windows.h>
#include <Psapi.h>

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved){
	switch(dwReason){
		case DLL_PROCESS_ATTACH:
			{
				char moduleName[256];
				int i;
				GetModuleFileNameEx(GetCurrentProcess(), NULL, moduleName, 255);
				moduleName[255] = 0;

				for(i = strlen(moduleName) - 1; i >= 0; i--){
					if(moduleName[i] == '\\'){
						if(strcmpi(&moduleName[i + 1], "TRose.exe") == 0){
							if(!CreateThread(0, 0, (LPTHREAD_START_ROUTINE)GetProcAddress(GetModuleHandleA("kernel32.dll"), "LoadLibraryA"), "SharpAPI.dll", NULL, NULL)){
								MessageBoxA(NULL, "Failed to create SharpAPI thread", "Error", MB_ICONERROR);
							}
						}

						return 1;
					}
				}
			}
			break;
	}

	return 1;
}