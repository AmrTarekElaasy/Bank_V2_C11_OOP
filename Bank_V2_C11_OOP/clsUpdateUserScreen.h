#pragma once
#include "clsUser.h"
#include "clsUserInfoScreen.h"
class clsUpdateUserScreen
{

	static void _ScreenSettings()
	{
		CurrentScreen.Offset = 0;

		
	}
public:
	static bool UpdateUserInfoScreen()
	{
		_ScreenSettings();
		

		CurrentScreen.DrawScreenHeader("                   Update User Info Screen");

		CurrentScreen.AlignWithOffset();
		cout << "Enter User Name : ";
		string UserName = clsInputValidate::ReadString();
		clsUser User = clsUser::Find(UserName);
		if (User.IsExist())
		{
			clsUserInfoScreen::PrintUserInfo(User);
			CurrentScreen.DrawScreenLine();

			CurrentScreen.AlignWithOffset();
			cout << "Are you sure you want to Update this user Y|N?";
			switch (clsInputValidate::CheckYesOrNo(clsInputValidate::ReadString()))
			{
			case true:
				User = clsReadUserScreen::ReadUser(UserName, clsUser::enMode::eUpdateMode);
				User.Save();

				CurrentScreen.AlignWithOffset(1);
				cout << "Updated Successfully\n";
				clsUserInfoScreen::PrintUserInfo(User);
				CurrentScreen.DrawScreenLine();
				return true;

			default:
				CurrentScreen.AlignWithOffset();
				cout << "Not Updated \n";
				CurrentScreen.DrawScreenLine();
				break;
			}
		}
		else
		{
			CurrentScreen.AlignWithOffset();
			cout << "Not Exist \n";
			CurrentScreen.DrawScreenLine();
		}
		return false;
	}

};

