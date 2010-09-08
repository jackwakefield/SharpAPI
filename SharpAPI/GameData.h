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

#ifndef GAMEDATA_H
#define GAMEDATA_H

#include "main.h"

enum {
	FONT_NORMAL	= 0,
	FONT_LARGE,
	FONT_SMALL,
	FONT_NORMAL_BOLD,
	FONT_LARGE_BOLD,
	FONT_SMALL_BOLD,
	FONT_TITLE,
	FONT_DESCRIPTION,
	FONT_NORMAL_OUTLINE,
	FONT_OUTLINE_18_BOLD,
	FONT_OUTLINE_14_BOLD,
	FONT_OUTLINE_24_BOLD,
	FONT_OUTLINE_16_BOLD,
	FONT_OUTLINE_11_BOLD,
	MAX_FONT,
};

class GameData
{
public:
	static GameData* Instance(){
		return *reinterpret_cast<GameData**>(0x00693504);
	}

public:
	bool mWireMode;
	bool mDrawBoundingVolume;
	HNODE mShaderNoLitSkin;
	HNODE mShaderNoLit;
	HNODE mShaderTerrain;
	HNODE mShaderTerrainRough;
	HNODE mShaderLightmap;
	HNODE mShaderOcean;
	HNODE mShaderSpecular;
	HNODE mShaderSpecularSkin;
	HNODE mShaderLitSkin;
	HNODE mShaderLit;
	HNODE mShaderSky;
	bool mNoUI;
	bool mNoWeight;
	bool mFilmingMode;
	bool mShowCursor;
	bool mShowDropItemInfo;
	int mPvPState;
	SYSTEMTIME mSystemTime;
	bool mDisplayDebugInfo;
	float mTestValue;
	bool mDirectLogin;
	bool mTestServer;
	int mTemp;
	bool mUnknown;
	HNODE mLight;
	HNODE mCharacterLight;
	CStrVAR mTrailTexture;
	HNODE mFonts[MAX_FONT];
};

#pragma managed
using namespace System;

static IntPtr GetFont(int index){
	return (IntPtr)(void*)GameData::Instance()->mFonts[index];
}

#endif