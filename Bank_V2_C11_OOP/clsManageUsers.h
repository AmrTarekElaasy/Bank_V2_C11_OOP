#pragma once
#include "clsScreen.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

//static clsScreen Screen;
class clsManageUsers 
{


	static void _GetScreenSettings()
	{

		CurrentScreen.Offset = 5;

	}

	enum enManageUsersMenueOptions {
		eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
		eUpdateUser = 4, eFindUser = 5, eMainMenue = 6
	};
	static enManageUsersMenueOptions _ReadManageUsersOption()
	{
		CurrentScreen.AlignWithOffset();
		cout << "Choose what do you want to do? [1 to 6] :  ";
		short Choice = clsInputValidate::ReadIntNumberBetween(1, 6, "Enter Number between 1 to 6 : ");
		return (enManageUsersMenueOptions)Choice;
	}

	static void _ShowListUsers()
	{
		
		system("cls");
		clsListUsersScreen::ShowListUsers();

	}
	static void _ShowAddNewUser()
	{
		system("cls");
		clsAddNewUserScreen::AddNewUserScreen();
		
	}
	static void _ShowDeleteUser()
	{
		system("cls");
		clsDeleteUserScreen::DeleteUserScreen();
	}
	static void _ShowUpdateUser()
	{
		system("cls");
		clsUpdateUserScreen::UpdateUserInfoScreen();
	}
	static void _ShowFindUser()
	{
		system("cls");
		clsFindUserScreen::FindUserScreen();
	}
	static void _GoBackToManageUsersScreen()
	{
		CurrentScreen.AlignWithOffset();
		cout << "Press any key to go back to Manage Users menue...";
		system("pause>0");


		ManageUsersScreen();

	}
	static void _PerfromManageUsersMenueOption(enManageUsersMenueOptions ManageUsersMenueOption)
	{
		
		switch (ManageUsersMenueOption)
		{
		case clsManageUsers::eListUsers:
			_ShowListUsers();
			_GoBackToManageUsersScreen();
			break;
		case clsManageUsers::eAddNewUser:
			_ShowAddNewUser();
			_GoBackToManageUsersScreen();
			break;
		case clsManageUsers::eDeleteUser:
			_ShowDeleteUser();
			_GoBackToManageUsersScreen();
			break;
		case clsManageUsers::eUpdateUser:
			_ShowUpdateUser();
			_GoBackToManageUsersScreen();
			break;
		case clsManageUsers::eFindUser:
			_ShowFindUser();
			_GoBackToManageUsersScreen();
			break;
		case clsManageUsers::eMainMenue:
			CurrentScreen.DrawScreenLine(1);
			break;
		default:
			break;
		}
	}
public:
	static void ManageUsersScreen()
	{
		_GetScreenSettings();
		system("cls");
		CurrentScreen.DrawScreenHeader("                      Manage Users Screen");
		
		CurrentScreen.AlignWithOffset();
		cout << "[1] List Users.\n";
		CurrentScreen.AlignWithOffset();
		cout << "[2] Add New User.\n";
		CurrentScreen.AlignWithOffset();
		cout << "[3] Delete User.\n";
		CurrentScreen.AlignWithOffset();
		cout << "[4] Update User.\n";
		CurrentScreen.AlignWithOffset();
		cout << "[5] Find User.\n";
		CurrentScreen.AlignWithOffset();
		cout << "[6] Main Menue.\n";
		CurrentScreen.DrawScreenLine();
		_PerfromManageUsersMenueOption(_ReadManageUsersOption());
	}
};

