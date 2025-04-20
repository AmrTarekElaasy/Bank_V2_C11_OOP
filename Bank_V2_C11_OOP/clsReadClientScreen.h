#pragma once
#include "clsBankClient.h"
#include "iostream"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;
class clsReadClientScreen
{
public:
	static clsBankClient ReadClient(string AccountNumber, clsBankClient::enMode Mode)
	{
	
		string FristName, LastName, Email, Phone, PINCode;
		double AccountBalans;
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
		AccountBalans = clsInputValidate::ReadDblNumber(Screen);



		clsBankClient Client(Mode, FristName, LastName, Email, Phone, AccountNumber, PINCode, AccountBalans);

		return Client;
	}

};

