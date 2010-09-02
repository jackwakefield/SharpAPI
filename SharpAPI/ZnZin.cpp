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

#pragma managed
using namespace System;
using namespace System::Runtime::InteropServices;
using namespace SharpAPI::Internal::Engine;

void __stdcall DelegateZnZinMethods(){
	HMODULE znzin = GetModuleHandle("znzin.dll");
	ZnZin::loadTexture = (ZnZin::loadTextureDelegate^)Marshal::GetDelegateForFunctionPointer((IntPtr)GetProcAddress(znzin, "loadTexture"), ZnZin::loadTextureDelegate::typeid);
	ZnZin::unloadTexture = (ZnZin::unloadTextureDelegate^)Marshal::GetDelegateForFunctionPointer((IntPtr)GetProcAddress(znzin, "unloadTexture"), ZnZin::unloadTextureDelegate::typeid);
	ZnZin::drawSprite = (ZnZin::drawSpriteDelegate^)Marshal::GetDelegateForFunctionPointer((IntPtr)GetProcAddress(znzin, "drawSprite"), ZnZin::drawSpriteDelegate::typeid);
	ZnZin::beginSprite = (ZnZin::beginSpriteDelegate^)Marshal::GetDelegateForFunctionPointer((IntPtr)GetProcAddress(znzin, "beginSprite"), ZnZin::beginSpriteDelegate::typeid);
	ZnZin::endSprite = (ZnZin::endSpriteDelegate^)Marshal::GetDelegateForFunctionPointer((IntPtr)GetProcAddress(znzin, "endSprite"), ZnZin::endSpriteDelegate::typeid);
	ZnZin::drawFont = (ZnZin::drawFontDelegate^)Marshal::GetDelegateForFunctionPointer((IntPtr)GetProcAddress(znzin, "?drawFont@@YAHIHHHKPBD@Z"), ZnZin::drawFontDelegate::typeid);
	ZnZin::getFontTextExtent = (ZnZin::getFontTextExtentDelegate^)Marshal::GetDelegateForFunctionPointer((IntPtr)GetProcAddress(znzin, "getFontTextExtent"), ZnZin::getFontTextExtentDelegate::typeid);
	ZnZin::getFontHeight = (ZnZin::getFontHeightDelegate^)Marshal::GetDelegateForFunctionPointer((IntPtr)GetProcAddress(znzin, "getFontHeight"), ZnZin::getFontHeightDelegate::typeid);
	ZnZin::getScreenWidth = (ZnZin::getScreenWidthDelegate^)Marshal::GetDelegateForFunctionPointer((IntPtr)GetProcAddress(znzin, "getScreenWidth"), ZnZin::getScreenWidthDelegate::typeid);
	ZnZin::getScreenHeight = (ZnZin::getScreenHeightDelegate^)Marshal::GetDelegateForFunctionPointer((IntPtr)GetProcAddress(znzin, "getScreenHeight"), ZnZin::getScreenHeightDelegate::typeid);
}

RunOnLoad(DelegateZnZinMethods);