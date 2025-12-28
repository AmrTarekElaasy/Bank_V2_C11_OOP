#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "clsPerson.h"
#include "clsString.h"
#include <fstream>
#include "clsUtil.h"

using namespace std;
class clsUser;

string UserNameOfAdmin = "Admin";
extern clsUser CurrentUser;
class clsUser :public clsPerson
{
public:
	enum enMode
	{
		eEmptyMode, eUpdateMode, eAddNewMode
	};
	enum enPermission {
		enAll = -1, enClientsList = 1, enAddClient = 2, enDeleteClient = 4, enUpdateClient = 8
		, enFindClient = 16, enTransactions = 32, enManageUsers = 64, enLoginRegister = 128, enCurrencyExchange = 256
	};


private:
	enMode _Mode;
	string _UserName;
	string _Password;
	short _Permisstion;
	bool _MarkedForDelete = false;

	static clsUser _GetEmptyUser()
	{
		return clsUser(enMode::eEmptyMode, "", "", "", "", "", "", 0);
	}
	static clsUser _ConvertLinetoUserObject(string Line, string Seperator = "#//#")
	{
		vector<string> vUserData;
		vUserData = clsString::Split(Line, Seperator);
		int x = vUserData.size();
		if (vUserData.size() > 6)
		{
			return clsUser(enMode::eUpdateMode, vUserData[0], vUserData[1], vUserData[2], vUserData[3], vUserData[4], vUserData[5], stoi(vUserData[6]));
		}

		else
		{
			return clsUser::_GetEmptyUser();
		}

	}
	static string _ConverUserObjectToLine(clsUser User, string Seperator = "#//#")
	{

		string stUserRecord = "";
		stUserRecord += User.FirstName + Seperator;
		stUserRecord += User.LastName + Seperator;
		stUserRecord += User.Email + Seperator;
		stUserRecord += User.Phone + Seperator;
		stUserRecord += User._UserName + Seperator;
		stUserRecord += User._Password + Seperator;
		stUserRecord += to_string(User._Permisstion);

		return stUserRecord;

	}
	static  vector <clsUser> _LoadUsersDataFromFile()
	{
		vector<clsUser> vUsers;
		fstream UsersFile;
		string pathTheFile = "Users.txt";
		UsersFile.open(pathTheFile, ios::in);
		if (UsersFile.is_open())
		{
			string line;
			clsUser User = clsUser::_GetEmptyUser();
			short i = 0;
			while (getline(UsersFile, line))
			{
				line = clsUtil::DecryptText(line);
				User = _ConvertLinetoUserObject(line);
				i++;
				if (User.IsExist())
				{
					vUsers.push_back(User);
				}
				else {
					string error = "Not Load a Users :" + pathTheFile + "[" + to_string(i);
					error += "]: " + line;

					clsErrors::SaveTheErrorInTheFile(error);
				}
			}
		}
		else
		{
			clsErrors::SaveTheErrorInTheFile("Can not open Users.txt");
		}
		UsersFile.close();

		return vUsers;
	}
	static string UsersFilePath()
	{
		return "Users.txt";
	}

	static void _SaveUsersDataToFile(vector <clsUser> vUsers)
	{

		fstream MyFile;
		remove(UsersFilePath().c_str());//////////
		
		MyFile.open("Users.txt", ios::out);//overwrite
		
		string DataLine;
		
		if (MyFile.is_open())
		{
		
			for (clsUser C : vUsers)
			{
				if (C._MarkedForDelete == false)
				{
					DataLine = _ConverUserObjectToLine(C);
					MyFile << clsUtil::EncryptText(DataLine) << endl;
				}
		
		
			}
		
			MyFile.close();
		
		}

	}
	bool IsEqual(clsUser u1, clsUser u2)
	{
		if (u1.UserName == u2.UserName &&
			u1.Password == u2.Password &&
			u1.FirstName == u2.FirstName &&
			u1.LastName == u2.LastName && 
			u1.Phone == u2.Phone &&
			u1.Email == u2.Email &&
			u1.Permission == u2.Permission)
			return true;
		else 
			return false;
	}
	bool _Update()
	{
		clsUser NewData = *this;
		if ((this->UserName == UserNameOfAdmin) && (CurrentUser.UserName != UserNameOfAdmin))
		{
			clsErrors::SaveTheErrorInTheFile("You can not update the admin account");
			return false;
		}

		vector <clsUser>vUsers = _LoadUsersDataFromFile();

		for (clsUser& C : vUsers)
		{
			if (C._UserName == _UserName)
			{
				C = *this;
				break;
			}
		}
		_SaveUsersDataToFile(vUsers);
		*this = clsUser::Find(this->UserName);
		return (IsEqual(*this, NewData));
	}
	bool _SaveLineUserInFile(string Line)
	{
		fstream UserFile;
		UserFile.open("Users.txt", ios::out | ios::app);
		if (UserFile.is_open())
		{
			clsUser User = clsUser::_ConvertLinetoUserObject(Line);
			if (User._MarkedForDelete == false)
			{
				UserFile << clsUtil::EncryptText(Line) << endl;
				return true;
			}
		}
		UserFile.close();
		return false;
	}
	void _AddNew()
	{
		string UserLine = _ConverUserObjectToLine(*this);
		_SaveLineUserInFile(UserLine);
	}

public:

	enMode GetMode()
	{
		return _Mode;
	}
	clsUser(enMode mode, string fristName, string lastName, string email, string phone, string userName, string password, short permisstion)
		:clsPerson(fristName, lastName, email, phone)
	{
		_Mode = mode;
		_UserName = userName;
		_Password = password;
		_Permisstion = permisstion;
	}
	static bool HasPermission(clsUser User, enPermission Permission)
	{

		if ((User.Permission & Permission) || (User.Permission == -1))
			return true;
		return false;

	}
	bool HasPermission(enPermission Permission)
	{
		return HasPermission(*this, Permission);
	}
	string GetUserName()
	{
		return _UserName;
	}
	void SetUserName(string userName)
	{
		_UserName = userName;
	}

	__declspec(property(get = GetUserName, put = SetUserName))string UserName;

	string GetPassword()
	{
		return _Password;
	}
	void SetPassword(string password)
	{
		_Password = password;
	}

	__declspec(property(get = GetPassword, put = SetPassword))string Password;


	short GetPermisstion()
	{
		return _Permisstion;
	}
	void SetPermisstion(short permisstion)
	{
		_Permisstion = permisstion;
	}

	__declspec(property(get = GetPermisstion, put = SetPermisstion))short Permission;


	static bool IsEmpty(clsUser User)
	{
		return User._Mode == enMode::eEmptyMode;
	}
	bool IsEmpty()
	{
		return IsEmpty(*this);
	}


	static bool IsExist(string userName)
	{

		clsUser user = Find(userName);
		return user._Mode != enMode::eEmptyMode;
	}
	bool IsExist()
	{
		return (_Mode != enMode::eEmptyMode);
	}

	static clsUser Find(string userName)
	{
		clsUser User = clsUser::_GetEmptyUser();
		if (userName == "")
			return User;




		vector <clsUser> vUsers = _LoadUsersDataFromFile();
		for (clsUser& C : vUsers)
		{
			if (C.UserName == userName)
			{
				User = C;
				break;
			}
		}


		if ((userName == UserNameOfAdmin) && (CurrentUser.UserName != UserNameOfAdmin))
		{
			User.Password = "";
		}
		return  User;
	}

	static clsUser Find(string userName, string password)
	{
		clsUser User = clsUser::_GetEmptyUser();

		if (userName == "")
			return User;



		vector <clsUser> vUsers = _LoadUsersDataFromFile();
		for (clsUser& C : vUsers)
		{
			if ((C.UserName == userName) && (C.Password == password))
			{
				User = C;
				break;
			}

		}

		return  User;
	}
	enum enSave { enNotSavedIsEmpty, enSavedSuccessfully, enNotSavedAccountIsExist, enNotHasUserName, enNotSavedAreYouNotAdmin };
	enSave Save()
	{
		bool US=false;
		switch (_Mode)
		{
		case clsUser::enMode::eEmptyMode:
			clsErrors::SaveTheErrorInTheFile("Not Saved Is Empty");
			return enSave::enNotSavedIsEmpty;
			break;


		case clsUser::enMode::eUpdateMode:
		
			
			if (_Update())
				return enSave::enSavedSuccessfully;
			
			else
			{
				return enSave::enNotSavedAreYouNotAdmin;

			}
			break;

		case clsUser::enMode::eAddNewMode:
		{
			if (clsUser::IsExist(this->UserName))
			{
				clsErrors::SaveTheErrorInTheFile("Not Saved User Is Exist");
				return enSave::enNotSavedAccountIsExist;

			}
			else if (clsUser::UserName == "")
			{
				clsErrors::SaveTheErrorInTheFile("Not Has User Name");
				return enSave::enNotHasUserName;
			}
			else
			{
				_AddNew();
				clsUser U = clsUser::Find(this->UserName);
				if (U.IsExist())
					return enSave::enSavedSuccessfully;
				else
					return enSave::enNotSavedIsEmpty;

			}
		}

		}
	}
	//static clsUser GetNewUser(string userName)
	//{
	//	return clsUser(enMode::eAddNewMode, "", "", "", "", userName, "", 0);
	//}
	static clsUser GetNewUser(string fristName, string lastName, string email, string phone, string userName, string password, short permisstion)
	{
		return clsUser(enMode::eAddNewMode, fristName, lastName, email, phone, userName, password, permisstion);
	}
	bool Delete()
	{
		vector <clsUser> vUsers = _LoadUsersDataFromFile();
		if (vUsers.size() == 0)
			return false;
		if (this->UserName == UserNameOfAdmin)
			return false;
		for (clsUser& user : vUsers)
		{
			if (user.UserName == this->UserName)
			{
				user._MarkedForDelete = true;
				break;
			}
		}
		_SaveUsersDataToFile(vUsers);
		*this = Find(this->UserName);
		return this->IsExist() == false;
	}
	static vector <clsUser> GetUsersList()
	{
		return _LoadUsersDataFromFile();
	}
};
clsUser CurrentUser = clsUser::Find("", "");
