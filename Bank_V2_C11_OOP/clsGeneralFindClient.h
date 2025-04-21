#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
class clsGeneralFindClient:protected clsScreen
{
	static void _ClearTransactionsScreenAndPrintHeader(string ScreenName, clsScreen ScreenSettings)
	{
		
		system("cls");
		ScreenSettings.DrawScreenHeader(ScreenName);
		

	}
public:
	static clsBankClient GeneralFindClient(string ScreenName,clsScreen ScreenSettings,bool PrintCLientInfo)
	{
		_ClearTransactionsScreenAndPrintHeader(ScreenName, ScreenSettings);

		ScreenSettings.AlignWithOffset();
		cout << "Enter Account Number : ";
		string AccountNumber = clsInputValidate::ReadString();
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		while (!Client.IsExist())
		{
			_ClearTransactionsScreenAndPrintHeader(ScreenName,ScreenSettings);
			ScreenSettings.AlignWithOffset();
			cout << "Not Found \n";
			ScreenSettings.DrawScreenLine();


			ScreenSettings.AlignWithOffset();
			cout << "Do you Need Try Agen Y|N ? ";
			if (clsInputValidate::CheckYesOrNo(clsInputValidate::ReadString()))
			{
				_ClearTransactionsScreenAndPrintHeader(ScreenName,ScreenSettings);
				ScreenSettings.AlignWithOffset();
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
			_ClearTransactionsScreenAndPrintHeader(ScreenName, ScreenSettings);
			clsClientInfoScreen::PrintUserInfo(Client);
			ScreenSettings.DrawScreenLine();
		}
		return Client;
	}
};

