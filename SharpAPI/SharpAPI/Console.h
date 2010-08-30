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
#ifndef CONSOLE_H
#define CONSOLE_H
#pragma unmanaged

#include <windows.h>
#include <stdio.h>
#include <time.h>

typedef enum {
	CC_BLACK,
	CC_BLUE,
	CC_GREEN,
	CC_CYAN,
	CC_RED,
	CC_MAGENTA,
	CC_BROWN,
	CC_LIGHTGRAY,
	CC_DARKGRAY,
	CC_LIGHTBLUE,
	CC_LIGHTGREEN,
	CC_LIGHTCYAN,
	CC_LIGHTRED,
	CC_LIGHTMAGENTA,
	CC_YELLOW,
	CC_WHITE
} CONSOLE_COLORS;

typedef enum
{
	MSG_NONE = CC_WHITE,
	MSG_LOAD = CC_LIGHTMAGENTA,
	MSG_STATUS = CC_LIGHTGREEN,
	MSG_INFO = CC_GREEN,
	MSG_WARNING = CC_YELLOW,
	MSG_ERROR = CC_LIGHTRED,
	MSG_DEBUG = CC_LIGHTBLUE
} LOG_TYPE;

class Console {
public:
	Console(){
		logMutex = CreateMutex(NULL, FALSE, NULL);
	}
	~Console(){}

	HANDLE logMutex;

	static Console& Instance(){
		static Console self;
		return self;
	}

	void SetConsoleColor(unsigned int textcolor, unsigned int backcolor = 0){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), textcolor + (backcolor << 4));
	}

	void Log(LOG_TYPE flag, const char* format, ... ){
		WaitForSingleObject(logMutex, 100);

		SetConsoleColor(flag);
		switch(flag){
				case MSG_NONE:
					printf("[MSG]: ");
					break;
				case MSG_LOAD:
					printf("[LOAD]: ");
					break;
				case MSG_STATUS:
					printf("[STATUS]: ");
					break;
				case MSG_INFO:
					printf("[INFO]: ");
					break;
				case MSG_WARNING:
					printf("[WARNING]: ");
					break;
				case MSG_ERROR:
					printf("[ERROR]: ");
					break;
				case MSG_DEBUG:
					printf("[DEBUG]: ");
					break;
		}
		SetConsoleColor(CC_WHITE);

		va_list arglist;
		va_start(arglist, format);
		vprintf(format, arglist);
		printf("\n");
		va_end(arglist);

		ReleaseMutex(logMutex);
	}

	void CreateConsole(){
		FILE* console;
		AllocConsole();
		SetConsoleTitle("SharpAPI Console");
		freopen_s(&console, "CONOUT$", "wb", stdout);
		freopen_s(&console, "CONOUT$", "wb", stderr);
		Log(MSG_INFO, "Created Console");
		//LockConsoleClose();
	}

	void LockConsoleClose(){
		HWND hConsole;
		hConsole = GetConsoleWindowHandle();
		EnableMenuItem(GetSystemMenu(hConsole, FALSE), SC_CLOSE, MF_BYCOMMAND | MF_GRAYED);
		RemoveMenu(GetSystemMenu(hConsole, FALSE), SC_CLOSE, MF_BYCOMMAND);
	}

	HWND GetConsoleWindowHandle(){
		HWND hWnd = NULL;

		char ConsoleClass  [MAX_PATH] = "";
		char OriginalTitle [MAX_PATH] = "";
		char TempTitle     [MAX_PATH] = "";
		char tty9x[]                  = "tty";
		char ttyNT[]                  = "ConsoleWindowClass";

		if(!GetConsoleTitle (OriginalTitle, sizeof(OriginalTitle)))
			strcpy_s(OriginalTitle, MAX_PATH, "" );

		SYSTEMTIME st;
		GetSystemTime ( &st );
		sprintf_s( TempTitle, MAX_PATH, "___%d-%d-%d_%d:%d:%d:%d___",
		st.wDay, st.wMonth, st.wYear,
		st.wHour, st.wMinute, st.wSecond, st.wMilliseconds );

		OSVERSIONINFO osv;
		osv.dwOSVersionInfoSize = sizeof ( OSVERSIONINFO );

		if(GetVersionEx(&osv)){
			switch(osv.dwPlatformId){
				case VER_PLATFORM_WIN32_NT:
					strcpy_s(ConsoleClass, MAX_PATH, ttyNT);
					break;
				case VER_PLATFORM_WIN32_WINDOWS :
					strcpy_s(ConsoleClass, MAX_PATH, tty9x);
					break;
				default:
					break;
			}
		}

		if(strlen(ConsoleClass) && SetConsoleTitle(TempTitle)){
			hWnd = FindWindow(ConsoleClass, TempTitle);
			SetConsoleTitle(OriginalTitle);
		}

		return hWnd;
	}
};

#define SetConsoleColor Console::Instance().SetConsoleColor
#define CreateConsole Console::Instance().CreateConsole
#define Log Console::Instance().Log

#endif