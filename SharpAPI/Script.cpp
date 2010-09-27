#include "Script.h"

using namespace System::IO;

bool Script::Execute(String^ filePath){
	try {
		mScript = mEngine->CreateScriptSourceFromFile(filePath);
		mScope = mEngine->CreateScope();

		mScript->Execute(mScope);
	}catch(...){
		::Log(MSG_ERROR, "Failed to execute script (%s)", Path::GetFileName(filePath));
		return false;
	}

	return true;
}