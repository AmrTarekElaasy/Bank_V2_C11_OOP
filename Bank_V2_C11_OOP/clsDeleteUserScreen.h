#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include"clsUserInfoScreen.h"
#include "clsInputValidate.h"
#include "clsGeneralFindUser.h"
class clsDeleteUserScreen
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
	static bool DeleteUserScreen()
	{
		clsScreen Screen = _GetScreenSettings();
		string Header = "                      Delete User Screen";
		clsUser User = clsGeneralFindUser::GeneralFindUser(Header, Screen, true);
		if (User.IsExist())
		{
			Screen.AlignWithOffset();
			cout << "Are you sure you want to delete this user Y|N? ";

			switch (clsInputValidate::CheckYesOrNo(clsInputValidate::ReadString()))
			{

			case true:
				if (User.Delete())
				{
					Screen.AlignWithOffset(1);
					cout << "Deleted successfully\n";
					clsUserInfoScreen::PrintUserInfo(User);
					Screen.DrawScreenLine();
					return true;
				}
			default:

				_ClearScreenAndPrintHeader(Header);
				Screen.AlignWithOffset();
				cout << "Not deleted\n";
				break;
			}

		}
		cout << "\n";
		Screen.DrawScreenLine();
		return false;
	}
};

