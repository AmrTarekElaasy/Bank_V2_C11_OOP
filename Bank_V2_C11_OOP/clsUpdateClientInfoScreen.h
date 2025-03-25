#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsReadClientScreen.h"
#include "clsBankClient.h"
#include "clsClientInfoScreen.h"
class clsUpdateClientInfoScreen :clsScreen
{
public:
	static bool UpdateClientInfoScreen()
	{
		clsScreen Screen;
		Screen.Offset = 0;

		Screen.DrawScreenHeader("              Update Client Info Screen");
		                        
		Screen.AlignWithOffset();
		cout << "Enter Account Number : ";
		string accountNumber = clsInputValidate::ReadString();
		clsBankClient Client = clsBankClient::Find(accountNumber);
		if (Client.IsExist())
		{
			clsClientInfoScreen::PrintClientInfo(Client);
			Screen.DrawScreenLine();
			
			Screen.AlignWithOffset();
			cout << "Are you sure you want to Update this client Y|N?";
			switch (clsInputValidate::CheckYesOrNo(clsInputValidate::ReadString()))
			{
			case true:
				Client = clsReadClientScreen::ReadClient(accountNumber,clsBankClient::enMode::enUpdateMode);
				Client.Save();

				Screen.AlignWithOffset(1);
				cout << "Updated Successfully\n";
				clsClientInfoScreen::PrintClientInfo(Client);
				Screen.DrawScreenLine();
				return true;
				
			default:
				Screen.AlignWithOffset();
				cout << "Not Updated \n";
				Screen.DrawScreenLine();
				break;
			}
		}
		else
		{
			Screen.AlignWithOffset();
			cout << "Not Exist \n";
			Screen.DrawScreenLine();
		}
		return false;
	}

};

