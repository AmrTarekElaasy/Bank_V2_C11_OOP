#pragma once
#include "clsUser.h"
#include "clsUserInfoScreen.h"
class clsUpdateUserScreen
{

	static clsScreen _GetScreenSettings()
	{
		clsScreen Screen;
		Screen.Offset = 0;

		return Screen;
	}
public:
	static bool UpdateUserInfoScreen()
	{
		clsScreen Screen=_GetScreenSettings();
		

		Screen.DrawScreenHeader("               Update User Info Screen");

		Screen.AlignWithOffset();
		cout << "Enter User Name : ";
		string UserName = clsInputValidate::ReadString();
		clsUser User = clsUser::Find(UserName);
		if (User.IsExist())
		{
			clsUserInfoScreen::PrintUserInfo(User);
			Screen.DrawScreenLine();

			Screen.AlignWithOffset();
			cout << "Are you sure you want to Update this user Y|N?";
			switch (clsInputValidate::CheckYesOrNo(clsInputValidate::ReadString()))
			{
			case true:
				User = clsReadUserScreen::ReadUser(UserName, clsUser::enMode::eUpdateMode);
				User.Save();

				Screen.AlignWithOffset(1);
				cout << "Updated Successfully\n";
				clsUserInfoScreen::PrintUserInfo(User);
				Screen.DrawScreenLine();
				return true;

			default:
				Screen.AlignWithOffset();
				cout << "Not Updated \n";
				Screen.DrawScreenLine();
				break;
			}
		}
		else
		{
			Screen.AlignWithOffset();
			cout << "Not Exist \n";
			Screen.DrawScreenLine();
		}
		return false;
	}

};

