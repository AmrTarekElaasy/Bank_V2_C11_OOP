#pragma once
#include <fstream>
#include "Global.h"
#include "clsDate.h"
using namespace std;
class clsSaveLoginsInALogFile
{
public :
	static void Save(string Seperator="#//#")
	{
		fstream LoginFile;
		string line = clsDate::DateToString(clsDate::GetCompleteSystemDate());
		line += Seperator + CurrentUser.UserName + Seperator + CurrentUser.Password + Seperator + to_string(CurrentUser.Permisstion);
		

		LoginFile.open("LoginFile.log", ios::app | ios::out);
		if (LoginFile.is_open())
		{
			LoginFile << line << endl;

			LoginFile.close();
		}
		
	}
};

