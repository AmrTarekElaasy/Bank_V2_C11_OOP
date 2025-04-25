#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsReadClientScreen.h"
#include "clsBankClient.h"
#include "clsClientInfoScreen.h"


class clsUpdateClientScreen :clsScreen
{
	static void _ScreenSettings()
	{

		CurrentScreen.Offset = 0;

	}
public:
	static bool UpdateUserInfoScreen()
	{
		_ScreenSettings();

		CurrentScreen.DrawScreenHeader("                  Update Client Info Screen");

		CurrentScreen.AlignWithOffset();
		cout << "Enter Account Number : ";
		string accountNumber = clsInputValidate::ReadString();
		clsBankClient Client = clsBankClient::Find(accountNumber);
		if (Client.IsExist())
		{
			clsClientInfoScreen::PrintUserInfo(Client);
			CurrentScreen.DrawScreenLine();

			CurrentScreen.AlignWithOffset();
			cout << "Are you sure you want to Update this client Y|N?";
			switch (clsInputValidate::CheckYesOrNo(clsInputValidate::ReadString()))
			{
			case true:
				Client = clsReadClientScreen::ReadUser(accountNumber, clsBankClient::enMode::enUpdateMode);
				Client.Save();

				CurrentScreen.AlignWithOffset(1);
				cout << "Updated Successfully\n";
				clsClientInfoScreen::PrintUserInfo(Client);
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