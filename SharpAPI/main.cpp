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

int APIENTRY WinMain(HINSTANCE hInstance,  HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	STARTUPINFO startupInfo = { sizeof( startupInfo ) };
	PROCESS_INFORMATION processInfo;

	if(!CreateProcessA(NULL, "TRose.exe @TRIGGER_SOFT@ _server 127.0.0.1", NULL, NULL, FALSE, NULL, NULL, NULL, &startupInfo, &processInfo)){
		MessageBoxA(NULL, "Failed to start TRose", "Error", MB_ICONERROR);
		return 0;
	}
	
	char* dllName = "SharpAPI.dll";

	LPVOID stringLocation = VirtualAllocEx(processInfo.hProcess, 0, strlen(dllName) + 1, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
	if(!stringLocation){
		MessageBoxA(NULL, "Failed to allocate memory", "Error", MB_ICONERROR);
		return 0;
	}

	DWORD written;
	WriteProcessMemory(processInfo.hProcess, stringLocation, dllName, strlen(dllName) + 1, &written);
	if(written != strlen(dllName) + 1){
		MessageBoxA(NULL, "Failed to write to process memory", "Error", MB_ICONERROR);
		return 0;
	}

	if(!CreateRemoteThread(processInfo.hProcess, 0, 0, (LPTHREAD_START_ROUTINE)GetProcAddress(GetModuleHandleA("kernel32.dll"), "LoadLibraryA"), stringLocation, 0, 0)){
		MessageBoxA(NULL, "Failed to create remote thread", "Error", MB_ICONERROR);
	}

	return 0;
}