#pragma once
#include "clsBankClient.h"
#include "iostream"
#include "clsScreen.h"
#include "clsInputValidate.h"

using namespace std;
class clsReadClientScreen
{
	static void _GetScreenSettings()
	{

		CurrentScreen.Offset = 0;

	}
public:
	static clsBankClient ReadUser(string AccountNumber, clsBankClient::enMode Mode)
	{

		_GetScreenSettings();
	
		string FristName, LastName, Email, Phone, PINCode;
		double AccountBalans;
		

		CurrentScreen.AlignWithOffset();
		cout << "Enter Frist Name : ";
		FristName = clsInputValidate::ReadString();

		CurrentScreen.AlignWithOffset();
		cout << "Enter Last Name : ";
		LastName = clsInputValidate::ReadString();


		CurrentScreen.AlignWithOffset();
		cout << "Enter Email : ";
		Email = clsInputValidate::ReadString();


		CurrentScreen.AlignWithOffset();
		cout << "Enter Phone : ";
		Phone = clsInputValidate::ReadString();


		CurrentScreen.AlignWithOffset();
		cout << "Enter PINCode : ";
		PINCode = clsInputValidate::ReadString();


		CurrentScreen.AlignWithOffset();
		cout << "Enter Account Balans : ";
		AccountBalans = clsInputValidate::ReadDblNumber();



		clsBankClient Client(Mode, FristName, LastName, Email, Phone, AccountNumber, PINCode, AccountBalans);

		return Client;
	}

};

