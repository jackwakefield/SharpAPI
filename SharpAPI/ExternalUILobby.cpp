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

#include "ExternalUILobby.h"
#include "main.h"

vector<CTDialog*> CExternalUILobby::mDialogs;

#pragma managed

void __stdcall DrawExternalUI(){
	for(auto dialog = CExternalUILobby::mDialogs.begin(); dialog != CExternalUILobby::mDialogs.end(); ++dialog)
		(*dialog)->Draw();
}

void __stdcall UpdateExternalUI(POINT mouse){
	for(auto dialog = CExternalUILobby::mDialogs.begin(); dialog != CExternalUILobby::mDialogs.end(); ++dialog)
		(*dialog)->Update(mouse);
}

bool __stdcall ProcessExternalUI(unsigned int uiMsg, WPARAM wParam, LPARAM lParam){
	for(auto dialog = CExternalUILobby::mDialogs.rbegin(); dialog != CExternalUILobby::mDialogs.rend(); ++dialog){
		if((*dialog)->Process(uiMsg, wParam, lParam)){
			if(uiMsg == WM_LBUTTONDOWN){
				CTDialog* dialogItem = *dialog;
				CExternalUILobby::mDialogs.erase(--dialog.base());
				CExternalUILobby::mDialogs.push_back(dialogItem);
			}
			
			return true;
		}
	}

	return false;
}

#pragma unmanaged

__declspec(naked) void HookDrawExternalUI(){
	static int ReturnAddress = 0x0049CE9F;
	_asm {
		PUSHAD
		CALL DrawExternalUI
		POPAD
		MOV EAX, DWORD PTR DS:[ESI+0x4]
		TEST EAX, EAX
		JMP ReturnAddress
	};
}

HookOnLoad(0x0049CE9A, HookDrawExternalUI, 0);

__declspec(naked) void HookUpdateExternalUI(){
	static int ReturnAddress = 0x0049CC9D;
	_asm {
		PUSHAD
		PUSH EBX
		PUSH EDI
		CALL UpdateExternalUI
		POPAD
		MOV ESI, DWORD PTR DS:[ESI]
		MOV EAX, DWORD PTR DS:[ESI+0x20]
		JMP ReturnAddress
	};
}

HookOnLoad(0x0049CC98, HookUpdateExternalUI, 0);

__declspec(naked) void HookProcessExternalUI(){
	static int ReturnAddress = 0x0049CD33;
	static int SkipAddress = 0x0049CD3C;
	_asm {
		PUSHAD
		PUSH EBX
		PUSH EBP
		PUSH EDI
		CALL ProcessExternalUI
		TEST EAX, EAX
		JNE Skip
		POPAD
		MOV ESI, DWORD PTR DS:[ESI]
		MOV EDX, DWORD PTR DS:[ESI+0x20]
		JMP ReturnAddress
Skip:
		POPAD
		JMP SkipAddress
	};
}

HookOnLoad(0x0049CD2E, HookProcessExternalUI, 0);