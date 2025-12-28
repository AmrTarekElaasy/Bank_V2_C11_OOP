#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "clsGeneralFindUser.h"
class clsFindUserScreen
{
	static void _ScreenSettings()
	{
		clsScreen::ColorAllProgram();

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
	static bool FindUserScreen()
	{
		_ScreenSettings();
		string Header = "                         Find User Screen";
		//_ClearScreenAndPrintHeader(Header);
		clsUser User = clsGeneralFindUser::GeneralFindUser(Header, CurrentScreen, true);
		if (User.IsExist())
		{

			return true;
		}
		CurrentScreen.DrawScreenLine();
		return false;
	}
};

