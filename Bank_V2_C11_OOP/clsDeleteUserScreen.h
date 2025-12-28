#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include"clsUserInfoScreen.h"
#include "clsInputValidate.h"
#include "clsGeneralFindUser.h"

class clsDeleteUserScreen
{
	static void _ScreenSettings()
	{
		clsScreen::ColorAllProgram();

		CurrentScreen.Offset = 0;
		
	}
	static void _Header(string Header)
	{
		 _ScreenSettings();
		CurrentScreen.AlignWithOffset();
		CurrentScreen.DrawScreenHeader(Header);
	}
	static  void _ClearScreenAndPrintHeader(string Header)
	{
		system("cls");
		_Header(Header);

	}

public:
	static bool DeleteUserScreen()
	{
		_ScreenSettings();
		string Header = "                      Delete User Screen";
		clsUser User = clsGeneralFindUser::GeneralFindUser(Header, CurrentScreen, true);
		if (User.IsExist())
		{
			CurrentScreen.AlignWithOffset();
			cout << "Are you sure you want to delete this user Y|N? ";

			switch (clsInputValidate::CheckYesOrNo(clsInputValidate::ReadString()))
			{

			case true:
				if (User.Delete())
				{
					CurrentScreen.AlignWithOffset(1);
					cout << "Deleted successfully\n";
					clsUserInfoScreen::PrintUserInfo(User);
					CurrentScreen.DrawScreenLine();
					return true;
				}
			default:

				_ClearScreenAndPrintHeader(Header);
				CurrentScreen.AlignWithOffset();
				cout << "Not deleted\n";
				break;
			}

		}
		cout << "\n";
		CurrentScreen.DrawScreenLine();
		return false;
	}
};

