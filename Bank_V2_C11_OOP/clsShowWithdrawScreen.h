#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsClientInfoScreen.h"
#include "clsGeneralFindClient.h"

class clsShowWithdrawScreen:clsScreen
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


	static bool WithdrawScreen()
	{
		clsScreen Screen = _GetScreenSettings();
		string Header = "                   Withdraw Screen";
		                                     
		_ClearScreenAndPrintHeader(Header);
		clsBankClient Client = clsGeneralFindClient::GeneralFindUser(Header, Screen, true);
		if (Client.IsExist())
		{
			


			
			string MaximumValue = "10000.00";
			double DoubleMaximumValue = stod(MaximumValue);
			if (DoubleMaximumValue > Client.AccountBalance)
			{
				MaximumValue = to_string(Client.AccountBalance);
				DoubleMaximumValue = Client.AccountBalance;
			}

			string mesege = "nter Withdraw Number between 0 to " + MaximumValue + " : ";
			Screen.AlignWithOffset();
			cout << mesege;
			double WithdrawNumber = clsInputValidate::ReadDblNumberBetween(0, DoubleMaximumValue,Screen, mesege);


			Screen.AlignWithOffset();
			cout << "Are you want Withdraw ";clsScreen::PrintDoubleNumber(WithdrawNumber);
			cout << " Y|N ? ";
			if (clsInputValidate::CheckYesOrNo(clsInputValidate::ReadString()))
			{
				Client.AccountBalance -= WithdrawNumber;
				Screen.AlignWithOffset();

				if (Client.Save() == clsBankClient::enSave::enSavedSuccessfully)
				{
					cout << "New Account Balance Is ";clsScreen::PrintDoubleNumber(Client.AccountBalance, true);
					cout << "\n";
					Screen.DrawScreenLine();
					return true;

				}
				else
				{
					cout << "Not Saved\n";

				}
			}



		}
		Screen.DrawScreenLine();
		return false;
	}
};




