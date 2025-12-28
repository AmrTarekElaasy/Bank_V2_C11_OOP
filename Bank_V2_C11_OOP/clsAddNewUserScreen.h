#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsReadUserScreen.h"
#include "clsUserInfoScreen.h"
class clsAddNewUserScreen
{

	static void _ScreenSettings()
	{
		CurrentScreen.Offset = 0;
		clsScreen::ColorAllProgram();

	}
	static void _ClearScreenAndPrintHeader()
	{

		
		system("cls");
		CurrentScreen.DrawScreenHeader("                       Add New User Screen");
		

	}

public:


	

	static bool AddNewUserScreen()
	{


		_ScreenSettings();

		_ClearScreenAndPrintHeader();
		CurrentScreen.AlignWithOffset();
		cout << "Enter User Name : ";

		string userName = clsInputValidate::ReadString();
		clsUser User = clsUser::Find(userName);

		while (User.IsExist())
		{
			_ClearScreenAndPrintHeader();
			CurrentScreen.AlignWithOffset();
			cout << "This User Is Exist \n";
			CurrentScreen.DrawScreenLine();


			CurrentScreen.AlignWithOffset();
			cout << "Do you Need Try Agen Y|N ? ";
			if (clsInputValidate::CheckYesOrNo(clsInputValidate::ReadString()))
			{
				_ClearScreenAndPrintHeader();
				CurrentScreen.AlignWithOffset();
				cout << "Enter Account Number : ";
				userName = clsInputValidate::ReadString();
				User = clsUser::Find(userName);
			}
			else
			{
				CurrentScreen.DrawScreenLine();
				return false;
			}
		}


		
		if (!User.IsExist())
		{
			User = clsReadUserScreen::ReadUser(userName, clsUser::enMode::eAddNewMode);


			_ClearScreenAndPrintHeader();
			CurrentScreen.AlignWithOffset();
			switch (User.Save())
			{
			case clsUser::enSave::enSavedSuccessfully:

				clsScreen::ColorSuccessfulOperation();
				cout << "Saved Successfully\n";

				clsUserInfoScreen::PrintUserInfo(User);
				CurrentScreen.DrawScreenLine();
				return true;

			case clsUser::enSave::enNotHasUserName:
				cout << "Not Has Account Number\n";
				break;
			case clsUser::enNotSavedIsEmpty:
				
				cout << "Not Saved\n";
				break;
			default:
				cout << "Not Saved\n";
				break;
			}

		}
		clsScreen::ColorFailedOperation();
		CurrentScreen.DrawScreenLine();
		return false;
	}
};

