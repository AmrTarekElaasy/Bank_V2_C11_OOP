#pragma once
#include "clsUser.h"
#include "clsUserInfoScreen.h"
class clsUpdateUserScreen
{

	static void _ScreenSettings()
	{
		clsScreen::ColorAllProgram();

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
		if ((User.UserName == UserNameOfAdmin) && (CurrentUser.UserName != UserNameOfAdmin))
		{
			CurrentScreen.Print("You can not update Admin Info.\n");
			CurrentScreen.DrawScreenLine();
			return false;
		}
		else if (User.IsExist())
		{
			clsUserInfoScreen::PrintUserInfo(User);
			CurrentScreen.DrawScreenLine();

			CurrentScreen.AlignWithOffset();
			cout << "Are you sure you want to Update this user Y|N?";
			if (clsInputValidate::CheckYesOrNo(clsInputValidate::ReadString()))
			{

				User = clsReadUserScreen::ReadUser(UserName, clsUser::enMode::eUpdateMode);
				if (User.Save() == clsUser::enSave::enSavedSuccessfully)
				{
					CurrentScreen.AlignWithOffset(1);
					clsScreen::ColorSuccessfulOperation();
					cout << "Updated Successfully\n";
					clsUserInfoScreen::PrintUserInfo(User);
					CurrentScreen.DrawScreenLine();
					return true;
				}

			}
		}

		clsScreen::ColorFailedOperation();
		CurrentScreen.AlignWithOffset();
		cout << "Not Updated \n";
		CurrentScreen.DrawScreenLine();

		return false;
	}

};

