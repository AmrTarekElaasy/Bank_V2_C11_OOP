#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsClientInfoScreen.h"
class clsDeleteClientScreen :clsScreen
{
public:
	static bool DeleteClientScreen()
	{
		clsScreen Screen;
		Screen.Offset = 0;
		Screen._DrawScreenHeader("Delete Client Screen");
		Screen.AlignWithOffset();
		cout << "Enter The Account Number : ";
		string AccountNumber = clsInputValidate::ReadString();
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		if (!Client.IsExist())
		{
			Screen.AlignWithOffset();
			cout << "Not Exist\n";
			return false;
		}

		clsClientInfoScreen::PrintClientInfo(Client);
		Screen.AlignWithOffset();
		cout << "Are you sure you want to delete this user Y|N?";

		switch (clsInputValidate::YesOrNo(clsInputValidate::ReadString()))
		{

		case true:
			if (Client.Delete())
			{
				Screen.AlignWithOffset(1);
				cout << "Deleted successfully\n";
				clsClientInfoScreen::PrintClientInfo(Client);
				return true;
			}
		default:
			Screen.AlignWithOffset();
			cout << "Not deleted\n";
			break;
		}
		return false;
	}
};

