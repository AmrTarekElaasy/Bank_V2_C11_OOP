#pragma once
#include"clsScreen.h"
#include "clsClientInfoScreen.h"

class clsAddNewClientScreen
{

	static clsBankClient ReadClient(string AccountNumber)
	{
		string FristName, LastName,Email,Phone,PINCode;
		float AccountBalans;
		clsScreen Screen;
		
		Screen.Offset = 0;

		Screen.AlignWithOffset();
		cout << "Enter Frist Name : ";
		FristName = clsInputValidate::ReadString();

		Screen.AlignWithOffset();
		cout << "Enter Last Name : ";
		LastName = clsInputValidate::ReadString();


		Screen.AlignWithOffset();
		cout << "Enter Email : ";
		Email = clsInputValidate::ReadString();


		Screen.AlignWithOffset();
		cout << "Enter Phone : ";
		Phone = clsInputValidate::ReadString();


		Screen.AlignWithOffset();
		cout << "Enter PINCode : ";
		PINCode = clsInputValidate::ReadString();


		Screen.AlignWithOffset();
		cout << "Enter Account Balans : ";
		AccountBalans = clsInputValidate::ReadFloatNumber();



		clsBankClient Client(clsBankClient::enMode::enAddNew, FristName, LastName, Email, Phone, AccountNumber, PINCode, AccountBalans);
		
		return Client;
	}
	
public:

	
	short Offset;

	static bool AddNewClientScreen()
	{
		clsScreen::_DrawScreenHeader("Add New Client Screen");
		clsScreen Screen;
		Screen.Offset = 0;
		Screen.AlignWithOffset();
		cout << "Enter AccountNumber : ";
		string accountNumber = clsInputValidate::ReadString();
		clsBankClient Client = clsBankClient::Find(accountNumber);
		if (!Client.IsExist())
		{
			Client=ReadClient(accountNumber);
			
			Screen.AlignWithOffset();
			switch (Client.Save())
			{
			case clsBankClient::enSave::enSavedSuccessfully:
				cout << "Saved Successfully\n";
					clsClientInfoScreen::PrintClientInfo(Client);
					return true;
					
			case clsBankClient::enSave::enNotHasAccountNumber:
				cout << "Not Has Account Number\n";
				break;
			case clsBankClient::enNotSavedIsEmpty:
				cout << "Not Saved Is Empty\n";
				break;
			default:
				cout << "Not Saved\n";
				break;
			}
			
		}
		else
		{
			clsScreen::OffsetOFclsScreen();
			cout << "This Client Is Exist\n";

		}
		return false;
	}
	
};

