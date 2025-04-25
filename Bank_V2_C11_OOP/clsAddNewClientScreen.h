#pragma once
#include"clsScreen.h"
#include "clsClientInfoScreen.h"
#include "clsReadClientScreen.h"

class clsAddNewClientScreen 
{
	static void _ClearScreenAndPrintHeader()
	{
		
		CurrentScreen.Offset = 0;
		system("cls");
		CurrentScreen.DrawScreenHeader("                      Add New Client Screen");
								
		

	}

public:


	short Offset;

	static bool AddNewUserScreen()
	{


		  _ClearScreenAndPrintHeader();
		  CurrentScreen.AlignWithOffset();
		cout << "Enter AccountNumber : ";
		string accountNumber = clsInputValidate::ReadString();
		clsBankClient Client = clsBankClient::Find(accountNumber);

		while (Client.IsExist())
		{
			_ClearScreenAndPrintHeader();
			CurrentScreen.AlignWithOffset();
			cout << "This Client Is Exist \n";
			CurrentScreen.DrawScreenLine();


			CurrentScreen.AlignWithOffset();
			cout << "Do you Need Try Agen Y|N ? ";
			if (clsInputValidate::CheckYesOrNo(clsInputValidate::ReadString()))
			{
				_ClearScreenAndPrintHeader();
				CurrentScreen.AlignWithOffset();
				cout << "Enter Account Number : ";
				accountNumber = clsInputValidate::ReadString();
				Client = clsBankClient::Find(accountNumber);
			}
			else
			{
				CurrentScreen.DrawScreenLine();
				return false;
			}
		}



		if (!Client.IsExist())
		{
			Client = clsReadClientScreen::ReadUser(accountNumber, clsBankClient::enMode::enAddNew);


			_ClearScreenAndPrintHeader();
			CurrentScreen.AlignWithOffset();
			switch (Client.Save())
			{
			case clsBankClient::enSave::enSavedSuccessfully:


				cout << "Saved Successfully\n";
				clsClientInfoScreen::PrintUserInfo(Client);
				CurrentScreen.DrawScreenLine();
				return true;

			case clsBankClient::enSave::enNotHasUserName:
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

		CurrentScreen.DrawScreenLine();
		return false;
	}

};