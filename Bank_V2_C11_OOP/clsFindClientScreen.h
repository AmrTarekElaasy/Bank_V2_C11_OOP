#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsClientInfoScreen.h"

class clsFindClientScreen
{
	
	static clsScreen _ClearFindClientScreen()
	{
		clsScreen Screen;
		Screen.Offset = 0;
		system("cls");
		Screen.DrawScreenHeader("                    Find Client Screen");
		return Screen;

	}
public:
	 
	static bool FindClientScreen()
	{
		clsScreen Screen = _ClearFindClientScreen();
		

		Screen.AlignWithOffset();
		cout << "Enter Account Number : ";
		string accountNumber = clsInputValidate::ReadString();
		clsBankClient Client = clsBankClient::Find(accountNumber);
		while (!Client.IsExist())
		{
			_ClearFindClientScreen();
			Screen.AlignWithOffset();
			cout << "Not Found \n";
			Screen.DrawScreenLine();


			Screen.AlignWithOffset();
			cout << "Do you Need Try Agen Y|N ? ";
			if (clsInputValidate::CheckYesOrNo(clsInputValidate::ReadString()))
			{
				_ClearFindClientScreen();
				Screen.AlignWithOffset();
				cout << "Enter Account Number : ";
				 accountNumber = clsInputValidate::ReadString();
				 Client = clsBankClient::Find(accountNumber);
			}
			else
			{
				return false;
			}
		}
		_ClearFindClientScreen();
		clsClientInfoScreen::PrintClientInfo(Client);
		Screen.DrawScreenLine();

		return true;


	}

};