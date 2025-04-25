#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "Global.h"
#include "clsUser.h"
#include "clsMainScreen.h"
#include "clsSaveLoginsInALogFile.h"
class clsLoginScreen
{
	static clsScreen _GetScreenSettings()
	{
		clsScreen Screen;
		Screen.Offset = 0;
		return Screen;
	}
	static void _Header(string Header)
	{
		clsScreen Screen = _GetScreenSettings();
		Screen.AlignWithOffset();
		Screen.DrawScreenHeader(Header);
	}
	static  void _ClearScreenAndPrintHeader(string Header)
	{
		system("cls");
		_Header(Header);

	}

public:
	static bool ShowLoginScreen()
	{

		string UserName, Password;

		clsScreen Screen = _GetScreenSettings();
		bool LoginFaild = false;
		short Try = 3;

		do {
			_ClearScreenAndPrintHeader("                           Login Screen");

			
			if (LoginFaild)
			{

				Screen.AlignWithOffset();
				cout << "Incorrect username or password\n";
				Try--;
				if (Try == 0)
					return false;
				Screen.AlignWithOffset();
				cout << "You Have "<<Try<<" Try\n";

			}
			LoginFaild = false;
			Screen.AlignWithOffset();
			cout << "Enter User Name : ";
			UserName = clsInputValidate::ReadString();

			Screen.AlignWithOffset();
			cout << "Enter Password : ";
			Password = clsInputValidate::ReadString();

			CurrentUser = clsUser::Find(UserName, Password);
			if (CurrentUser.IsExist() == false)
				LoginFaild = true;

		} while (LoginFaild);

		clsSaveLoginsInALogFile::Save();
		clsMainScreen::ShowMainMenue();

	}
};

