#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsClientInfoScreen.h"
class clsDeleteClientScreen :clsScreen
{
	static clsScreen _ClearDeleteClientScreen()
	{
		clsScreen Screen;
		Screen.Offset = 0;
		system("cls");
		Screen.DrawScreenHeader("                  Delete Client Screen");
		return Screen;

	}
public:
	static bool DeleteClientScreen()
	{
		clsScreen Screen = _ClearDeleteClientScreen();
		
		    
		Screen.AlignWithOffset();
		cout << "Enter The Account Number : ";
		string AccountNumber = clsInputValidate::ReadString();
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		if (!Client.IsExist())
		{
			_ClearDeleteClientScreen();
			Screen.AlignWithOffset();
			
			cout << "Not Exist\n";
			Screen.DrawScreenLine();
			return false;
		}
		
		_ClearDeleteClientScreen();
		clsClientInfoScreen::PrintClientInfo(Client);
		Screen.DrawScreenLine();

		Screen.AlignWithOffset();
		cout << "Are you sure you want to delete this client Y|N?";

		switch (clsInputValidate::CheckYesOrNo(clsInputValidate::ReadString()))
		{

		case true:
			if (Client.Delete())
			{
				Screen.AlignWithOffset(1);
				cout << "Deleted successfully\n";
				clsClientInfoScreen::PrintClientInfo(Client);
				Screen.DrawScreenLine();
				return true;
			}
		default:
			_ClearDeleteClientScreen();
			Screen.AlignWithOffset();
			cout << "Not deleted\n";
			Screen.DrawScreenLine();
			break;
		}
		return false;
	}
};

