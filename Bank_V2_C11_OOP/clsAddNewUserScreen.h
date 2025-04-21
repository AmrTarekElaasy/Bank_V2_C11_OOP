#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsReadUserScreen.h"
#include "clsUserInfoScreen.h"
class clsAddNewUserScreen
{

	static clsScreen _GetScreenSettings()
	{
		clsScreen Screen;
		Screen.Offset = 0;
		return Screen;
	}
	static void _ClearScreenAndPrintHeader()
	{
		clsScreen Screen= _GetScreenSettings();
		
		system("cls");
		Screen.DrawScreenHeader("                       Add New User Screen");
		

	}

public:


	

	static bool AddNewUserScreen()
	{


		clsScreen Screen = _GetScreenSettings();

		_ClearScreenAndPrintHeader();
		Screen.AlignWithOffset();
		cout << "Enter User Name : ";

		string userName = clsInputValidate::ReadString();
		clsUser User = clsUser::Find(userName);

		while (User.IsExist())
		{
			_ClearScreenAndPrintHeader();
			Screen.AlignWithOffset();
			cout << "This User Is Exist \n";
			Screen.DrawScreenLine();


			Screen.AlignWithOffset();
			cout << "Do you Need Try Agen Y|N ? ";
			if (clsInputValidate::CheckYesOrNo(clsInputValidate::ReadString()))
			{
				_ClearScreenAndPrintHeader();
				Screen.AlignWithOffset();
				cout << "Enter Account Number : ";
				userName = clsInputValidate::ReadString();
				User = clsUser::Find(userName);
			}
			else
			{
				Screen.DrawScreenLine();
				return false;
			}
		}



		if (!User.IsExist())
		{
			User = clsReadUserScreen::ReadUser(userName, clsUser::enMode::eAddNewMode);


			_ClearScreenAndPrintHeader();
			Screen.AlignWithOffset();
			switch (User.Save())
			{
			case clsUser::enSave::enSavedSuccessfully:


				cout << "Saved Successfully\n";
				clsUserInfoScreen::PrintUserInfo(User);
				Screen.DrawScreenLine();
				return true;

			case clsUser::enSave::enNotHasUserName:
				cout << "Not Has Account Number\n";
				break;
			case clsUser::enNotSavedIsEmpty:
				cout << "Not Saved Is Empty\n";
				break;
			default:
				cout << "Not Saved\n";
				break;
			}

		}

		Screen.DrawScreenLine();
		return false;
	}
};

