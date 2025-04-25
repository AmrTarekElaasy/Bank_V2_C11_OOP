#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
#include "clsMainScreen.h"
#include "clsLoginLogger.h"
class clsLoginScreen
{
	static void _ScreenSettings()
	{
		CurrentScreen.Offset = 0;
	}
	static void _Header(string Header)
	{
		CurrentScreen.AlignWithOffset();
		CurrentScreen.DrawScreenHeader(Header);
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

		_ScreenSettings();
		bool LoginFaild = false;
		short Try = 3;

		do {
			_ClearScreenAndPrintHeader("                           Login Screen");

			
			if (LoginFaild)
			{

				CurrentScreen.AlignWithOffset();
				cout << "Incorrect username or password\n";
				Try--;
				if (Try == 0)
					return false;
				CurrentScreen.AlignWithOffset();
				cout << "You Have "<<Try<<" Try\n";

			}
			LoginFaild = false;
			CurrentScreen.AlignWithOffset();
			cout << "Enter User Name : ";
			UserName = clsInputValidate::ReadString();

			CurrentScreen.AlignWithOffset();
			cout << "Enter Password : ";
			Password = clsInputValidate::ReadString();

			CurrentUser = clsUser::Find(UserName, Password);
			if (CurrentUser.IsExist() == false)
				LoginFaild = true;

		} while (LoginFaild);

		clsLoginLogger::SaveToFile();
		clsMainScreen::ShowMainMenue();

	}
};

