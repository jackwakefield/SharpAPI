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

#ifndef GAME_H
#define GAME_H

enum eGAME_STATE{
	GS_NULL,
	GS_TITLE,
	GS_LOGIN,
	GS_WARNING,
	GS_SELECTSVR,
	GS_PREPARESELECTAVATAR,
	GS_SELECTAVATAR,
	GS_LOGINVIRTUAL,
	GS_CREATEAVATAR,
	GS_MOVEMAIN,
	GS_PREPAREMAIN,
	GS_MAIN,
	GS_WARP,
	GS_EXITMAIN,
	GS_MOVEPLANET,
	GS_RELOGIN,
	GS_MAX
};

#endif