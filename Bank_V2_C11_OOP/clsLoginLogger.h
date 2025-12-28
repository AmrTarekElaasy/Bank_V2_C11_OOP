#pragma once
#include <fstream>
#include "clsDate.h"
#include "clsUser.h"
class clsLoginLogger
{
public:
	struct stLoginRegisterRecord
	{
		string Date;
		string UserName;
		string Password;
		short  Permission;
	};
private:
	static stLoginRegisterRecord _ConvertStringToLoginRegister(string stringLine)
	{
		stLoginRegisterRecord LoginRegister;
		vector <string> stringLoginRegister = clsString::Split(stringLine, "#//#");
		if (stringLoginRegister.size() > 3)
		{
			LoginRegister.Date = stringLoginRegister[0];
			LoginRegister.UserName = stringLoginRegister[1];
			LoginRegister.Password = stringLoginRegister[2];
			LoginRegister.Permission = stoi(stringLoginRegister[3]);
		}
		return LoginRegister;
	}
public:
	static vector <stLoginRegisterRecord> LoadLoginRegisterRecordFromFile()
	{
		vector <stLoginRegisterRecord> vLogins;


		fstream LoginFile;
		string pathTheFile = "LoginFile.log";
		LoginFile.open(pathTheFile, ios::in);
		string line;
		while (getline(LoginFile, line))
		{
			vLogins.push_back(_ConvertStringToLoginRegister(clsUtil::DecryptText(line)));
		}
		return vLogins;
	}
	static void SaveToFile(string Seperator = "#//#")
	{
		fstream LoginFile;
		string line = clsDate::DateToString(clsDate::GetCompleteSystemDate());
		line += Seperator + CurrentUser.UserName + Seperator + CurrentUser.Password + Seperator + to_string(CurrentUser.Permission);


		LoginFile.open("LoginFile.log", ios::app | ios::out);
		if (LoginFile.is_open())
		{
			LoginFile << clsUtil::EncryptText(line) << endl;

			LoginFile.close();
		}

	}
};