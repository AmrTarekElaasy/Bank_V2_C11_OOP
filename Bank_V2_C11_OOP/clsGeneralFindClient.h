#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"


class clsGeneralFindClient:protected clsScreen
{
	static void _ClearTransactionsScreenAndPrintHeader(string ScreenName)
	{
		
		system("cls");
		CurrentScreen.DrawScreenHeader(ScreenName);
		

	}
public:
	static clsBankClient GeneralFindUser(string ScreenName,bool PrintCLientInfo)
	{
		_ClearTransactionsScreenAndPrintHeader(ScreenName);

		CurrentScreen.AlignWithOffset();
		cout << "Enter Account Number : ";
		string AccountNumber = clsInputValidate::ReadString();
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		while (!Client.IsExist())
		{
			_ClearTransactionsScreenAndPrintHeader(ScreenName);
			CurrentScreen.AlignWithOffset();
			cout << "Not Found \n";
			CurrentScreen.DrawScreenLine();


			CurrentScreen.AlignWithOffset();
			cout << "Do you Need Try Agen Y|N ? ";
			if (clsInputValidate::CheckYesOrNo(clsInputValidate::ReadString()))
			{
				_ClearTransactionsScreenAndPrintHeader(ScreenName);
				CurrentScreen.AlignWithOffset();
				cout << "Enter Account Number : ";
				AccountNumber = clsInputValidate::ReadString();
				Client = clsBankClient::Find(AccountNumber);
			}
			else
			{
				return clsBankClient(clsBankClient::enMode::enEmptyMode, "", "", "", "", "", "", 0);
			}
		}
		if (PrintCLientInfo)
		{
			_ClearTransactionsScreenAndPrintHeader(ScreenName);
			clsClientInfoScreen::PrintUserInfo(Client);
			CurrentScreen.DrawScreenLine();
		}
		return Client;
	}
};

