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
	static short _ReadPermission(string userName)
	{
		short permissions = 0;
		string yOrN = "";

		clsScreen Screen = _GetScreenSettings();

		Screen.AlignWithOffset();
		cout << "Enter Permission : \n";
		Screen.AlignWithOffset();
		cout << "Do you want to give all the permissions Y/N ? ";
		cin >> yOrN;
		if (clsInputValidate::CheckYesOrNo(yOrN))
			return clsUser::enPermission::enAll;

		Screen.AlignWithOffset();
		cout << "Do you want to give him permission to show Clients List Y/N ? ";
		cin >> yOrN;
		if (clsInputValidate::CheckYesOrNo(yOrN))
			permissions += clsUser::enPermission::enClientsList;

		Screen.AlignWithOffset();
		cout << "Do you want to give him permission to Add Client Y/N ? ";
		cin >> yOrN;
		if (clsInputValidate::CheckYesOrNo(yOrN))
			permissions += clsUser::enPermission::enAddClient;

		Screen.AlignWithOffset();
		cout << "Do you want to give him permission to Delete Client Y/N ? ";
		cin >> yOrN;
		if (clsInputValidate::CheckYesOrNo(yOrN))
			permissions += clsUser::enPermission::enDeleteClient;

		Screen.AlignWithOffset();
		cout << "Do you want to give him permission to Update Client Y/N ? ";
		cin >> yOrN;
		if (clsInputValidate::CheckYesOrNo(yOrN))
			permissions += clsUser::enPermission::enUpdateClient;

		Screen.AlignWithOffset();
		cout << "Do you want to give him permission to Find Client Y/N ? ";
		cin >> yOrN;
		if (clsInputValidate::CheckYesOrNo(yOrN))
			permissions += clsUser::enPermission::enFindClient;

		
		Screen.AlignWithOffset();
		cout << "Do you want to give him permission to Transactions Y/N ? ";
		cin >> yOrN;
		if (clsInputValidate::CheckYesOrNo(yOrN))
			permissions += clsUser::enPermission::enTransactions;

		if (userName == "Admin")
		{
			permissions += clsUser::enPermission::enManageUsers;
		}
		else
		{
			Screen.AlignWithOffset();
			cout << "Do you want to give him permission to Manage Users Y/N ? ";
			cin >> yOrN;
			if (clsInputValidate::CheckYesOrNo(yOrN))
				permissions += clsUser::enPermission::enManageUsers;
		}

		Screen.AlignWithOffset();
		cout << "Do you want to give him permission Login Register Y/N ? ";
		cin >> yOrN;
		if (clsInputValidate::CheckYesOrNo(yOrN))
			permissions += clsUser::enPermission::enLoginRegister;

		return permissions;
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

		Permisstion = _ReadPermission(UserName);



		clsUser Client(Mode, FristName, LastName, Email, Phone, UserName, Password, Permisstion);

		return Client;
	}
};

