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

#include "SoundLIST.h"
#include "main.h"

#pragma managed
using namespace System::Runtime::InteropServices;
using namespace SharpAPI::Internal::ROSE;

void __stdcall DelegateSoundListMethods(){
	SoundLIST::GetVolume = gcnew SoundLIST::GetVolumeDelegate(GetVolume);
	SoundLIST::SetVolume = gcnew SoundLIST::SetVolumeDelegate(SetVolume);
	SoundLIST::AddSoundFile = gcnew SoundLIST::AddSoundFileDelegate(AddSoundFile);
	SoundLIST::KeyPlaySound = gcnew SoundLIST::KeyPlaySoundDelegate(KeyPlaySound);
	SoundLIST::IDPlaySound = gcnew SoundLIST::IDPlaySoundDelegate(IDPlaySound);
}

RunOnLoad(DelegateSoundListMethods);