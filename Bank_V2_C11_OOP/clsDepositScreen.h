#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsClientInfoScreen.h"
#include "clsGeneralFindClient.h"
class clsDepositScreen:protected clsScreen
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

	
	static bool DepositScreen()
	{
		_ScreenSettings();
		string Header = "                        Deposit Screen";
		_ClearScreenAndPrintHeader(Header);
		clsBankClient Client = clsGeneralFindClient::GeneralFindUser(Header,true );
		if (Client.IsExist())
		{
			CurrentScreen.AlignWithOffset();
			cout << "Enter Deposit Number : ";


			string MaximumValue = "100000.00";
			string mesege = "Enter Number between 0 to " + MaximumValue + " : ";
			double DepositNumber = clsInputValidate::ReadDblNumberBetween(0, stod(MaximumValue), mesege);
			

			CurrentScreen.AlignWithOffset();
			cout << "Are you want deposit ";clsScreen::PrintDoubleNumber(DepositNumber);
			cout << " Y|N ? ";
			if (clsInputValidate::CheckYesOrNo(clsInputValidate::ReadString()))
			{
				Client.AccountBalance += DepositNumber;
				CurrentScreen.AlignWithOffset();

				if (Client.Save()==clsBankClient::enSave::enSavedSuccessfully)
				{
					cout << "New Account Balance Is ";clsScreen::PrintDoubleNumber(Client.AccountBalance,true);
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

