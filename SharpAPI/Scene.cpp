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
#include "Scene.h"

#pragma managed
using namespace System;
using namespace SharpAPI::Internal::Engine;

void __stdcall RaiseRenderScene(){
	Scene::RaiseRenderEvent();
}

void __stdcall RaiseRenderOverlay(){
	Scene::RaiseRenderOverlayEvent();
}

#pragma unmanaged

__declspec(naked) void HookRenderScene(){
	_asm {
		PUSHAD
		CALL RaiseRenderScene
		POPAD
		JMP DWORD PTR DS:[EDX+0x214]
	};
}

HookOnLoad(0x680226CD, HookRenderScene, 1);

__declspec(naked) void HookEndScene(){
	static int ReturnAddress = 0x68022626;
	_asm {
		PUSHAD
		CALL RaiseRenderOverlay
		POPAD
		MOV ECX, DWORD PTR DS:[0x6822E630]
		JMP ReturnAddress
	};
}

HookOnLoad(0x68022620, HookEndScene, 1);