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
#ifndef CODE_H
#define CODE_H
#pragma unmanaged

#include <windows.h>

class Code {
public:
	static void NOP(unsigned char* code, int nops){
		DWORD oldProtect;
		VirtualProtect(code, nops, PAGE_EXECUTE_READWRITE, &oldProtect);
		memset(code, 0x90, nops);
		VirtualProtect(code, nops, oldProtect, &oldProtect);
	}

	template <class T> static void JmpHook(int location, T cfunc, int nops = 0){
		DWORD oldProtect;
		unsigned char* code = (unsigned char*)location;
		VirtualProtect(code, 5 + nops, PAGE_EXECUTE_READWRITE, &oldProtect);
		code[0] = 0xE9;
		*reinterpret_cast<int*>(code+1) = (int)cfunc - ((int)code + 5);
		if(nops > 0) memset(code + 5, 0x90, nops);
		VirtualProtect(code, 5 + nops, oldProtect, &oldProtect);
	}

	static void Write(int location, unsigned char* data, int length){
		DWORD oldProtect;
		unsigned char* code = (unsigned char*)location;
		VirtualProtect(code, length, PAGE_EXECUTE_READWRITE, &oldProtect);
		for(int i = 0; i < length; ++i)
			code[i] = data[i];
		VirtualProtect(code, length, oldProtect, &oldProtect);
	}

	template<class T> static void Write(int location, T data){
		DWORD oldProtect;
		unsigned char* code = (unsigned char*)location;
		VirtualProtect(code, sizeof(T), PAGE_EXECUTE_READWRITE, &oldProtect);
		*((T*)code) = data;
		VirtualProtect(code, sizeof(T), oldProtect, &oldProtect);
	}
};

#endif