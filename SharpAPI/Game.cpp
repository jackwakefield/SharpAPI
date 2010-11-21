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
#include "Game.h"

#pragma managed
using namespace SharpAPI::Internal::ROSE;

void _stdcall ChangeState(int state){
	switch(state){
		case GS_TITLE:
			{
				RunList::Instance().RunFunctions();

				Script::mEngine = Python::CreateEngine();
				Script::mEngine->Runtime->LoadAssembly(IPlugin::typeid->Assembly);

				array<String^>^ scriptFiles = Directory::GetFiles("Plugins", "*.py");

				for(int i = 0; i < scriptFiles->Length; i++){
					PluginManager::AddScript(scriptFiles[i]);
				}

				array<String^>^ dllFiles = Directory::GetFiles("Plugins", "*.dll");

				for(int i = 0; i < dllFiles->Length; i++){
					PluginManager::Add(dllFiles[i]);
				}

				for(int i = 0; i < PluginManager::mPlugins.Count; i++){
					PluginManager::mPlugins[i]->Run();
				}
			}
			break;
	}
}

bool _stdcall WndProc(UINT uiMsg, WPARAM wParam, LPARAM lParam){
	static bool handled;
	switch(uiMsg){
		case WM_SYSKEYDOWN:
		case WM_KEYDOWN:
			{
				Game::RaiseKeyDownEvent(wParam & 0xFF, handled, GetAsyncKeyState(VK_CONTROL) & 0x8000 ? true : false, GetAsyncKeyState(VK_MENU) & 0x8000 ? true : false, GetAsyncKeyState(VK_SHIFT) & 0x8000 ? true : false);
				return handled;
			}
			break;
		case WM_SYSKEYUP:
		case WM_KEYUP:
			{
				Game::RaiseKeyUpEvent(wParam & 0xFF, handled, GetAsyncKeyState(VK_CONTROL) & 0x8000 ? true : false, GetAsyncKeyState(VK_MENU) & 0x8000 ? true : false, GetAsyncKeyState(VK_SHIFT) & 0x8000 ? true : false);
				return handled;
			}
			break;
		case WM_CHAR:
			return handled;
	}

	return false;
}

#pragma unmanaged

void _declspec(naked) HookChangeState(){
	static int JmpReturn = 0x0041BC11;
	_asm {
		PUSHAD
		PUSH EDI
		CALL ChangeState
		POPAD
		MOV EAX, DWORD PTR DS:[EDI*0x4+ESI+0x0A2C]
		TEST EAX, EAX
		JMP JmpReturn
	}
}

HookOnLoad(0x0041BC08, HookChangeState, 4)

void _declspec(naked) HookWndProc(){
	static int JmpReturn = 0x004388BB;
	static int JmpHandled = 0x00438912;
	_asm {
		PUSHAD
		PUSH EAX
		PUSH EBX
		PUSH ESI
		CALL WndProc
		TEST EAX, EAX
		JNE Handled
		POPAD
		CALL DWORD PTR DS:[0x0062E6AC]
		JMP JmpReturn
Handled:
		POPAD
		ADD ESP, 0x10
		JMP JmpHandled
	}
}

HookOnLoad(0x004388B5, HookWndProc, 1)