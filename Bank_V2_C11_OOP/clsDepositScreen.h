#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsClientInfoScreen.h"
#include "clsGeneralFindClient.h"
class clsDepositScreen:protected clsScreen
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

	
	static bool DepositScreen()
	{
		clsScreen Screen = _GetScreenSettings();
		string Header = "                        Deposit Screen";
		_ClearScreenAndPrintHeader(Header);
		clsBankClient Client = clsGeneralFindClient::GeneralFindUser(Header,Screen,true );
		if (Client.IsExist())
		{
			Screen.AlignWithOffset();
			cout << "Enter Deposit Number : ";


			string MaximumValue = "100000.00";
			string mesege = "Enter Number between 0 to " + MaximumValue + " : ";
			double DepositNumber = clsInputValidate::ReadDblNumberBetween(0, stod(MaximumValue),Screen, mesege);
			

			Screen.AlignWithOffset();
			cout << "Are you want deposit ";clsScreen::PrintDoubleNumber(DepositNumber);
			cout << " Y|N ? ";
			if (clsInputValidate::CheckYesOrNo(clsInputValidate::ReadString()))
			{
				Client.AccountBalance += DepositNumber;
				Screen.AlignWithOffset();

				if (Client.Save()==clsBankClient::enSave::enSavedSuccessfully)
				{
					cout << "New Account Balance Is ";clsScreen::PrintDoubleNumber(Client.AccountBalance,true);
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

