#pragma once
#include "clsUser.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsErrors.h"
class clsReadUserScreen
{
	static clsScreen _GetScreenSettings()
	{
		clsScreen Screen;
		Screen.Offset = 0;
		return Screen;
	}
public:
	static clsUser ReadUser(string UserName, clsUser::enMode Mode)
	{

		string FristName, LastName, Email, Phone, Password;
		short Permisstion;
		clsScreen Screen=_GetScreenSettings();

		

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
		cout << "Enter Password : ";
		Password = clsInputValidate::ReadString();


		Screen.AlignWithOffset();
		cout << "Enter Permisstion : ";
		Permisstion = clsInputValidate::ReadDblNumber(Screen);



		clsUser Client(Mode, FristName, LastName, Email, Phone, UserName, Password, Permisstion);

		return Client;
	}
};

