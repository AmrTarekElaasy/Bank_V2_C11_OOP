#pragma once
#include "clsScreen.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
class clsManageUsers :clsScreen
{


	static clsScreen _GetScreenSettings()
	{
		clsScreen Screen;
		Screen.Offset = 5;
		
		return Screen;
	}

	enum enManageUsersMenueOptions {
		eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
		eUpdateUser = 4, eFindUser = 5, eMainMenue = 6
	};
	static enManageUsersMenueOptions _ReadManageUsersOption()
	{
		clsScreen Screen = _GetScreenSettings();
		Screen.AlignWithOffset();
		cout << "Choose what do you want to do? [1 to 6] :  ";
		short Choice = clsInputValidate::ReadIntNumberBetween(1, 6,Screen, "Enter Number between 1 to 6 : ");
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
		cout << "Find user screen will be here.\n";
	}
	static void _GoBackToManageUsersScreen()
	{
		clsScreen Screen = _GetScreenSettings();
		Screen.AlignWithOffset();
		cout << "Press any key to go back to Manage Users menue...";
		system("pause>0");


		ManageUsersScreen();

	}
	static void _PerfromManageUsersMenueOption(enManageUsersMenueOptions ManageUsersMenueOption)
	{
		clsScreen Screen = _GetScreenSettings();
		
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
			Screen.DrawScreenLine(1);
			break;
		default:
			break;
		}
	}
public:
	static void ManageUsersScreen()
	{
		clsScreen Screen = _GetScreenSettings();
		system("cls");
		DrawScreenHeader("                  Manage Users Screen");
		
		Screen.AlignWithOffset();
		cout << "[1] List Users.\n";
		Screen.AlignWithOffset();
		cout << "[2] Add New User.\n";
		Screen.AlignWithOffset();
		cout << "[3] Delete User.\n";
		Screen.AlignWithOffset();
		cout << "[4] Update User.\n";
		Screen.AlignWithOffset();
		cout << "[5] Find User.\n";
		Screen.AlignWithOffset();
		cout << "[6] Main Menue.\n";
		Screen.DrawScreenLine();
		_PerfromManageUsersMenueOption(_ReadManageUsersOption());
	}
};

