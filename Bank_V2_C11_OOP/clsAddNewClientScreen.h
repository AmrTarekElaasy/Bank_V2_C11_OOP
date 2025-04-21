#pragma once
#include"clsScreen.h"
#include "clsClientInfoScreen.h"
#include "clsReadClientScreen.h"

class clsAddNewClientScreen :clsScreen
{
	static clsScreen _ClearScreenAndPrintHeader()
	{
		clsScreen Screen;
		Screen.Offset = 0;
		system("cls");
		Screen.DrawScreenHeader("                      Add New Client Screen");
								
		return Screen;

	}

public:


	short Offset;

	static bool AddNewUserScreen()
	{


		clsScreen Screen = _ClearScreenAndPrintHeader();
		Screen.AlignWithOffset();
		cout << "Enter AccountNumber : ";
		string accountNumber = clsInputValidate::ReadString();
		clsBankClient Client = clsBankClient::Find(accountNumber);

		while (Client.IsExist())
		{
			_ClearScreenAndPrintHeader();
			Screen.AlignWithOffset();
			cout << "This Client Is Exist \n";
			Screen.DrawScreenLine();


			Screen.AlignWithOffset();
			cout << "Do you Need Try Agen Y|N ? ";
			if (clsInputValidate::CheckYesOrNo(clsInputValidate::ReadString()))
			{
				_ClearScreenAndPrintHeader();
				Screen.AlignWithOffset();
				cout << "Enter Account Number : ";
				accountNumber = clsInputValidate::ReadString();
				Client = clsBankClient::Find(accountNumber);
			}
			else
			{
				Screen.DrawScreenLine();
				return false;
			}
		}



		if (!Client.IsExist())
		{
			Client = clsReadClientScreen::ReadUser(accountNumber, clsBankClient::enMode::enAddNew);


			_ClearScreenAndPrintHeader();
			Screen.AlignWithOffset();
			switch (Client.Save())
			{
			case clsBankClient::enSave::enSavedSuccessfully:


				cout << "Saved Successfully\n";
				clsClientInfoScreen::PrintUserInfo(Client);
				Screen.DrawScreenLine();
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

		Screen.DrawScreenLine();
		return false;
	}

};