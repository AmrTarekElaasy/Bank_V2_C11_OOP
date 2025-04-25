#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsClientInfoScreen.h"
#include "clsGeneralFindClient.h"

class clsShowWithdrawScreen:clsScreen
{
	static void _ScreenSettings()
	{
		CurrentScreen.Offset = 0;
	}
	static void _Header(string Header)
	{
		CurrentScreen.AlignWithOffset();
		CurrentScreen.DrawScreenHeader(Header);
	}
	static  void _ClearScreenAndPrintHeader(string Header)
	{
		system("cls");
		_Header(Header);

	}

public:


	static bool WithdrawScreen()
	{
		_ScreenSettings();
		string Header = "                       Withdraw Screen";
		                                     
		_ClearScreenAndPrintHeader(Header);
		clsBankClient Client = clsGeneralFindClient::GeneralFindUser(Header, true);
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
			CurrentScreen.AlignWithOffset();
			cout << mesege;
			double WithdrawNumber = clsInputValidate::ReadDblNumberBetween(0, DoubleMaximumValue, mesege);


			CurrentScreen.AlignWithOffset();
			cout << "Are you want Withdraw ";clsScreen::PrintDoubleNumber(WithdrawNumber);
			cout << " Y|N ? ";
			if (clsInputValidate::CheckYesOrNo(clsInputValidate::ReadString()))
			{
				Client.AccountBalance -= WithdrawNumber;
				CurrentScreen.AlignWithOffset();

				if (Client.Save() == clsBankClient::enSave::enSavedSuccessfully)
				{
					cout << "New Account Balance Is ";clsScreen::PrintDoubleNumber(Client.AccountBalance, true);
					cout << "\n";
					CurrentScreen.DrawScreenLine();
					return true;

				}
				else
				{
					cout << "Not Saved\n";

				}
			}



		}
		CurrentScreen.DrawScreenLine();
		return false;
	}
};




