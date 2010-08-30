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

#include "Plugin.h"

bool Plugin::Load(String^ filePath){
	::Log(MSG_LOAD, "Loading Plugin %s", filePath);
	mAssembly = Assembly::LoadFrom(filePath);

	array<Type^>^ assemblyTypes = mAssembly->GetTypes();
	for(int i = 0; i < assemblyTypes->Length; i++){
		if(!assemblyTypes[i]->IsClass || assemblyTypes[i]->IsNotPublic)
			continue;
		
		array<Type^>^ typeInterfaces = assemblyTypes[i]->GetInterfaces();

		for(int j = 0; j < typeInterfaces->Length; j++){
			if (typeInterfaces[j]->Name == "IPlugin"){
				array<Object^>^ interfaceAttributes = assemblyTypes[i]->GetCustomAttributes(false);

				for (int k = 0; k < interfaceAttributes->Length; k++){
					String^ attributeName = interfaceAttributes[k]->GetType()->Name;
					
					if(attributeName == "PluginName"){
						mAttributes.Add("Name", ((PluginName^)interfaceAttributes[k])->Name);
					}else if(attributeName == "PluginDescription"){
						mAttributes.Add("Description", ((PluginDescription^)interfaceAttributes[k])->Description);
					}else if(attributeName == "PluginAuthor"){
						mAttributes.Add("Author", ((PluginAuthor^)interfaceAttributes[k])->Author);
					}else if(attributeName == "PluginVersion"){
						mAttributes.Add("Version", ((PluginVersion^)interfaceAttributes[k])->Version);
					}
				}

				if (!mAttributes.ContainsKey("Name")){
					::Log(MSG_ERROR, "- PluginName attribute missing", filePath);
					MessageBox::Show("Failed to load plugin: PluginName attribute missing", Path::GetFileName(mAssembly->Location), MessageBoxButtons::OK, MessageBoxIcon::Error);
					return false;
				}
				
				mInstance = (IPlugin^)mAssembly->CreateInstance(assemblyTypes[i]->FullName);
				::Log(MSG_INFO, "- Instance created", filePath);
				return true;
			}
		}
	}
	
	::Log(MSG_ERROR, "- No class was found inheriting IPlugin", filePath);
	MessageBox::Show("Failed to load plugin: unable to locate entry-point", Path::GetFileName(mAssembly->Location), MessageBoxButtons::OK, MessageBoxIcon::Error);
	return false;
}

void Plugin::Run(){
	try{
		mInstance->Initialize();
	}catch(...){
		::Log(MSG_ERROR, "Failed to initialize plugin '%s' (%s)", mAttributes["Name"], Path::GetFileName(mAssembly->Location));
		MessageBox::Show(String::Format("An error occured while trying to initialize plugin '{0}'", mAttributes["Name"]), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}