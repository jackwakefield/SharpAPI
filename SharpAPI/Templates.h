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
#ifndef TEMPLATES_H
#define TEMPLATES_H

template <typename T, typename RT> _declspec(naked) RT __stdcall CallMemberFunction(unsigned int func, T* self){
	_asm {
		POP EAX
		ADD ESP, 0x8
		MOV ECX, DWORD PTR DS:[ESP-0x4]
		PUSH EAX
		MOV EAX, DWORD PTR DS:[ESP-0x4]
		JMP EAX
	}
}

template <typename T, typename RT, typename A1> _declspec(naked) RT __stdcall CallMemberFunction(unsigned int func, T* self, A1 arg1){
	_asm {
		POP EAX
		ADD ESP, 0x8
		MOV ECX, DWORD PTR DS:[ESP-0x4]
		PUSH EAX
		MOV EAX, DWORD PTR DS:[ESP-0x4]
		JMP EAX
	}
}

template <typename T, typename RT, typename A1, typename A2> _declspec(naked) RT __stdcall CallMemberFunction(unsigned int func, T* self, A1 arg1, A2 arg2){
	_asm {
		POP EAX
		ADD ESP, 0x8
		MOV ECX, DWORD PTR DS:[ESP-0x4]
		PUSH EAX
		MOV EAX, DWORD PTR DS:[ESP-0x4]
		JMP EAX
	}
}

template <typename T, typename RT, typename A1, typename A2, typename A3> _declspec(naked) RT __stdcall CallMemberFunction(unsigned int func, T* self, A1 arg1, A2 arg2, A3 arg3){
	_asm {
		POP EAX
		ADD ESP, 0x8
		MOV ECX, DWORD PTR DS:[ESP-0x4]
		PUSH EAX
		MOV EAX, DWORD PTR DS:[ESP-0x4]
		JMP EAX
	}
}

template <typename T, typename RT, typename A1, typename A2, typename A3, typename A4> _declspec(naked) RT __stdcall CallMemberFunction(unsigned int func, T* self, A1 arg1, A2 arg2, A3 arg3, A4 arg4){
	_asm {
		POP EAX
		ADD ESP, 0x8
		MOV ECX, DWORD PTR DS:[ESP-0x4]
		PUSH EAX
		MOV EAX, DWORD PTR DS:[ESP-0x4]
		JMP EAX
	}
}

template <typename T, typename RT, typename A1, typename A2, typename A3, typename A4, typename A5> _declspec(naked) RT __stdcall CallMemberFunction(unsigned int func, T* self, A1 arg1, A2 arg2, A3 arg3, A4 arg4, A5 arg5){
	_asm {
		POP EAX
		ADD ESP, 0x8
		MOV ECX, DWORD PTR DS:[ESP-0x4]
		PUSH EAX
		MOV EAX, DWORD PTR DS:[ESP-0x4]
		JMP EAX
	}
}

template <typename T, typename RT, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6> _declspec(naked) RT __stdcall CallMemberFunction(unsigned int func, T* self, A1 arg1, A2 arg2, A3 arg3, A4 arg4, A5 arg5, A6 arg6){
	_asm {
		POP EAX
		ADD ESP, 0x8
		MOV ECX, DWORD PTR DS:[ESP-0x4]
		PUSH EAX
		MOV EAX, DWORD PTR DS:[ESP-0x4]
		JMP EAX
	}
}

template <typename T, typename RT, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7> _declspec(naked) RT __stdcall CallMemberFunction(unsigned int func, T* self, A1 arg1, A2 arg2, A3 arg3, A4 arg4, A5 arg5, A6 arg6, A7 arg7){
	_asm {
		POP EAX
		ADD ESP, 0x8
		MOV ECX, DWORD PTR DS:[ESP-0x4]
		PUSH EAX
		MOV EAX, DWORD PTR DS:[ESP-0x4]
		JMP EAX
	}
}

template <typename T, typename RT, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8> _declspec(naked) RT __stdcall CallMemberFunction(unsigned int func, T* self, A1 arg1, A2 arg2, A3 arg3, A4 arg4, A5 arg5, A6 arg6, A7 arg7, A8 arg8){
	_asm {
		POP EAX
		ADD ESP, 0x8
		MOV ECX, DWORD PTR DS:[ESP-0x4]
		PUSH EAX
		MOV EAX, DWORD PTR DS:[ESP-0x4]
		JMP EAX
	}
}

template <typename T, typename RT, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9> _declspec(naked) RT __stdcall CallMemberFunction(unsigned int func, T* self, A1 arg1, A2 arg2, A3 arg3, A4 arg4, A5 arg5, A6 arg6, A7 arg7, A8 arg8, A9 arg9){
	_asm {
		POP EAX
		ADD ESP, 0x8
		MOV ECX, DWORD PTR DS:[ESP-0x4]
		PUSH EAX
		MOV EAX, DWORD PTR DS:[ESP-0x4]
		JMP EAX
	}
}

template <typename T, typename RT, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10> _declspec(naked) RT __stdcall CallMemberFunction(unsigned int func, T* self, A1 arg1, A2 arg2, A3 arg3, A4 arg4, A5 arg5, A6 arg6, A7 arg7, A8 arg8, A9 arg9, A10 arg10){
	_asm {
		POP EAX
		ADD ESP, 0x8
		MOV ECX, DWORD PTR DS:[ESP-0x4]
		PUSH EAX
		MOV EAX, DWORD PTR DS:[ESP-0x4]
		JMP EAX
	}
}

template <typename T, typename RT, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11> _declspec(naked) RT __stdcall CallMemberFunction(unsigned int func, T* self, A1 arg1, A2 arg2, A3 arg3, A4 arg4, A5 arg5, A6 arg6, A7 arg7, A8 arg8, A9 arg9, A10 arg10, A11 arg11){
	_asm {
		POP EAX
		ADD ESP, 0x8
		MOV ECX, DWORD PTR DS:[ESP-0x4]
		PUSH EAX
		MOV EAX, DWORD PTR DS:[ESP-0x4]
		JMP EAX
	}
}

template <typename T, typename RT, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12> _declspec(naked) RT __stdcall CallMemberFunction(unsigned int func, T* self, A1 arg1, A2 arg2, A3 arg3, A4 arg4, A5 arg5, A6 arg6, A7 arg7, A8 arg8, A9 arg9, A10 arg10, A11 arg11, A12 arg12){
	_asm {
		POP EAX
		ADD ESP, 0x8
		MOV ECX, DWORD PTR DS:[ESP-0x4]
		PUSH EAX
		MOV EAX, DWORD PTR DS:[ESP-0x4]
		JMP EAX
	}
}

template <typename T, typename RT, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13> _declspec(naked) RT __stdcall CallMemberFunction(unsigned int func, T* self, A1 arg1, A2 arg2, A3 arg3, A4 arg4, A5 arg5, A6 arg6, A7 arg7, A8 arg8, A9 arg9, A10 arg10, A11 arg11, A12 arg12, A13 arg13){
	_asm {
		POP EAX
		ADD ESP, 0x8
		MOV ECX, DWORD PTR DS:[ESP-0x4]
		PUSH EAX
		MOV EAX, DWORD PTR DS:[ESP-0x4]
		JMP EAX
	}
}

template <typename RT> _declspec(naked) RT __stdcall CallStaticFunction(unsigned int func){
	_asm {
		POP EAX
		POP ECX
		PUSH EAX
		JMP ECX
	}
}
template <typename RT, typename A1> _declspec(naked) RT __stdcall CallStaticFunction(unsigned int func, A1 arg1){
	_asm {
		POP EAX
		POP ECX
		PUSH EAX
		JMP ECX
	}
}
template <typename RT, typename A1, typename A2> _declspec(naked) RT __stdcall CallStaticFunction(unsigned int func, A1 arg1, A2 arg2){
	_asm {
		POP EAX
		POP ECX
		PUSH EAX
		JMP ECX
	}
}
template <typename RT, typename A1, typename A2, typename A3> _declspec(naked) RT __stdcall CallStaticFunction(unsigned int func, A1 arg1, A2 arg2, A3 arg3){
	_asm {
		POP EAX
		POP ECX
		PUSH EAX
		JMP ECX
	}
}
template <typename RT, typename A1, typename A2, typename A3, typename A4> _declspec(naked) RT __stdcall CallStaticFunction(unsigned int func, A1 arg1, A2 arg2, A3 arg3, A4 arg4){
	_asm {
		POP EAX
		POP ECX
		PUSH EAX
		JMP ECX
	}
}
template <typename RT, typename A1, typename A2, typename A3, typename A4, typename A5> _declspec(naked) RT __stdcall CallStaticFunction(unsigned int func, A1 arg1, A2 arg2, A3 arg3, A4 arg4, A5 arg5){
	_asm {
		POP EAX
		POP ECX
		PUSH EAX
		JMP ECX
	}
}
template <typename RT, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6> _declspec(naked) RT __stdcall CallStaticFunction(unsigned int func, A1 arg1, A2 arg2, A3 arg3, A4 arg4, A5 arg5, A6 arg6){
	_asm {
		POP EAX
		POP ECX
		PUSH EAX
		JMP ECX
	}
}
template <typename RT, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7> _declspec(naked) RT __stdcall CallStaticFunction(unsigned int func, A1 arg1, A2 arg2, A3 arg3, A4 arg4, A5 arg5, A6 arg6, A7 arg7){
	_asm {
		POP EAX
		POP ECX
		PUSH EAX
		JMP ECX
	}
}
template <typename RT, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8> _declspec(naked) RT __stdcall CallStaticFunction(unsigned int func, A1 arg1, A2 arg2, A3 arg3, A4 arg4, A5 arg5, A6 arg6, A7 arg7, A8 arg8){
	_asm {
		POP EAX
		POP ECX
		PUSH EAX
		JMP ECX
	}
}
template <typename RT, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9> _declspec(naked) RT __stdcall CallStaticFunction(unsigned int func, A1 arg1, A2 arg2, A3 arg3, A4 arg4, A5 arg5, A6 arg6, A7 arg7, A8 arg8, A9 arg9){
	_asm {
		POP EAX
		POP ECX
		PUSH EAX
		JMP ECX
	}
}
template <typename RT, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10> _declspec(naked) RT __stdcall CallStaticFunction(unsigned int func, A1 arg1, A2 arg2, A3 arg3, A4 arg4, A5 arg5, A6 arg6, A7 arg7, A8 arg8, A9 arg9, A10 arg10){
	_asm {
		POP EAX
		POP ECX
		PUSH EAX
		JMP ECX
	}
}
template <typename RT, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11> _declspec(naked) RT __stdcall CallStaticFunction(unsigned int func, A1 arg1, A2 arg2, A3 arg3, A4 arg4, A5 arg5, A6 arg6, A7 arg7, A8 arg8, A9 arg9, A10 arg10, A11 arg11){
	_asm {
		POP EAX
		POP ECX
		PUSH EAX
		JMP ECX
	}
}
template <typename RT, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12> _declspec(naked) RT __stdcall CallStaticFunction(unsigned int func, A1 arg1, A2 arg2, A3 arg3, A4 arg4, A5 arg5, A6 arg6, A7 arg7, A8 arg8, A9 arg9, A10 arg10, A11 arg11, A12 arg12){
	_asm {
		POP EAX
		POP ECX
		PUSH EAX
		JMP ECX
	}
}

#endif