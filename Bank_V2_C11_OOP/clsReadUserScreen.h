#pragma once
#include "clsUser.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsErrors.h"
class clsReadUserScreen
{
	static void _ScreenSettings()
	{
		CurrentScreen.Offset = 0;
	}
	static short _ReadPermission(string userName)
	{
		short permissions = 0;
		string yOrN = "";


		CurrentScreen.AlignWithOffset();
		cout << "Enter Permission : \n";
		CurrentScreen.AlignWithOffset();
		cout << "Do you want to give all the permissions Y/N ? ";
		cin >> yOrN;
		if (clsInputValidate::CheckYesOrNo(yOrN))
			return clsUser::enPermission::enAll;

		CurrentScreen.AlignWithOffset();
		cout << "Do you want to give him permission to show Clients List Y/N ? ";
		cin >> yOrN;
		if (clsInputValidate::CheckYesOrNo(yOrN))
			permissions += clsUser::enPermission::enClientsList;

		CurrentScreen.AlignWithOffset();
		cout << "Do you want to give him permission to Add Client Y/N ? ";
		cin >> yOrN;
		if (clsInputValidate::CheckYesOrNo(yOrN))
			permissions += clsUser::enPermission::enAddClient;

		CurrentScreen.AlignWithOffset();
		cout << "Do you want to give him permission to Delete Client Y/N ? ";
		cin >> yOrN;
		if (clsInputValidate::CheckYesOrNo(yOrN))
			permissions += clsUser::enPermission::enDeleteClient;

		CurrentScreen.AlignWithOffset();
		cout << "Do you want to give him permission to Update Client Y/N ? ";
		cin >> yOrN;
		if (clsInputValidate::CheckYesOrNo(yOrN))
			permissions += clsUser::enPermission::enUpdateClient;

		CurrentScreen.AlignWithOffset();
		cout << "Do you want to give him permission to Find Client Y/N ? ";
		cin >> yOrN;
		if (clsInputValidate::CheckYesOrNo(yOrN))
			permissions += clsUser::enPermission::enFindClient;

		
		CurrentScreen.AlignWithOffset();
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
			CurrentScreen.AlignWithOffset();
			cout << "Do you want to give him permission to Manage Users Y/N ? ";
			cin >> yOrN;
			if (clsInputValidate::CheckYesOrNo(yOrN))
				permissions += clsUser::enPermission::enManageUsers;
		}

		CurrentScreen.AlignWithOffset();
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
		_ScreenSettings();

		

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
		cout << "Enter Password : ";
		Password = clsInputValidate::ReadString();

		Permisstion = _ReadPermission(UserName);



		clsUser Client(Mode, FristName, LastName, Email, Phone, UserName, Password, Permisstion);

		return Client;
	}
};

