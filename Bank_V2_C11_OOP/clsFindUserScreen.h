#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "clsGeneralFindUser.h"
class clsFindUserScreen
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
	static bool FindUserScreen()
	{
		clsScreen Screen = _GetScreenSettings();
		string Header = "                         Find User Screen";
		//_ClearScreenAndPrintHeader(Header);
		clsUser User = clsGeneralFindUser::GeneralFindUser(Header, Screen, true);
		if (User.IsExist())
		{

			return true;
		}
		Screen.DrawScreenLine();
		return false;
	}
};

