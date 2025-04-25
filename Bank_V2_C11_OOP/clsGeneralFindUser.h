#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include"clsUser.h"
#include"clsUserInfoScreen.h"

class clsGeneralFindUser
{
	static void _ClearTransactionsScreenAndPrintHeader(string ScreenName)
	{

		system("cls");
		CurrentScreen.DrawScreenHeader(ScreenName);


	}
public:
	static clsUser GeneralFindUser(string ScreenName, clsScreen ScreenSettings, bool PrintUserInfo)
	{
		_ClearTransactionsScreenAndPrintHeader(ScreenName);

		ScreenSettings.AlignWithOffset();
		cout << "Enter User Name : ";
		string UserName = clsInputValidate::ReadString();
		clsUser User = clsUser::Find(UserName);
		while (!User.IsExist())
		{
			_ClearTransactionsScreenAndPrintHeader(ScreenName);
			ScreenSettings.AlignWithOffset();
			cout << "Not Found \n";
			ScreenSettings.DrawScreenLine();


			ScreenSettings.AlignWithOffset();
			cout << "Do you Need Try Agen Y|N ? ";
			if (clsInputValidate::CheckYesOrNo(clsInputValidate::ReadString()))
			{
				_ClearTransactionsScreenAndPrintHeader(ScreenName);
				ScreenSettings.AlignWithOffset();
				cout << "Enter User Name : ";
				UserName = clsInputValidate::ReadString();
				User = clsUser::Find(UserName);
			}
			else
			{
				return clsUser(clsUser::enMode::eEmptyMode, "", "", "", "", "", "", 0);
			}
		}
		if (PrintUserInfo)
		{
			_ClearTransactionsScreenAndPrintHeader(ScreenName);
			clsUserInfoScreen::PrintUserInfo(User);
			ScreenSettings.DrawScreenLine();
		}
		return User;
	}
};

