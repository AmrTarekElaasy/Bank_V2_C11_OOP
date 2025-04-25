#pragma once
#include <fstream>
#include "clsDate.h"
#include "clsUser.h"
class clsLoadLoginsFromALogFile
{

public:
	static vector <vector<string>> LoadLoginsFromALogFile()
	{
		vector <vector<string>> vLogins;
		
		
		fstream LoginFile;
		string pathTheFile = "LoginFile.log";
		LoginFile.open(pathTheFile, ios::in);
		string line;
		while (getline(LoginFile, line))
		{
			vLogins.push_back(clsString::Split(line,"#//#"));
		}
		return vLogins;
	}
};

