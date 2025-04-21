#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsClientsScreen.h" 
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsers.h"
#include "Global.h"


using namespace std;



class clsMainScreen :protected clsScreen
{


private:

    static clsScreen _GetScreenSettings()
    {
        clsScreen Screen;
        Screen.Offset = 5;

        return Screen;
    }
    static bool _CheckPermission(clsUser::enPermission Permission)
    {
        clsScreen Screen=_GetScreenSettings();
        if (CurrentUser.HasPermission(Permission))
        {
            return true;
        }
        Screen.DrawScreenHeader("                  Access Denied! Contact Your Admin.");

        return false;
    }
    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eExit = 8
    };

    static short _ReadMainMenueOption()
    {
        clsScreen Screen = _GetScreenSettings();
        Screen.AlignWithOffset(1);
        cout << "Choose what do you want to do? [1 to 8] :  ";


        short Choice = clsInputValidate::ReadIntNumberBetween(1, 8, Screen,"Enter Number between 1 to 8 : ");
        return Choice;
    }

    static  void _GoBackToMainMenue()
    {
        
        clsScreen Screen = _GetScreenSettings();
        Screen.AlignWithOffset(1);
        cout << "Press any key to go back to Main Menue...";
        system("pause>0");
        ShowMainMenue();
    }

    static void _ShowAllClientsScreen()
    {
        if (_CheckPermission(clsUser::enPermission::enClientsList))
        clsClientsScreen::ShowTotalBalancesScreen();
      
    }

    static void _ShowAddNewClientsScreen()
    {
        if (_CheckPermission(clsUser::enPermission::enAddClient))
        clsAddNewClientScreen::AddNewUserScreen();
    }

    static void _ShowDeleteClientScreen()
    {
        if (_CheckPermission(clsUser::enPermission::enDeleteClient))
        clsDeleteClientScreen::DeleteUserScreen();
    }

    static void _ShowUpdateClientScreen()
    {
        if (_CheckPermission(clsUser::enPermission::enUpdateClient))
        clsUpdateClientScreen::UpdateUserInfoScreen();
    }

    static void _ShowFindClientScreen()
    {
        if (_CheckPermission(clsUser::enPermission::enFindClient))
        clsFindClientScreen::FindClientScreen();
    }

    static void _ShowTransactionsMenue()
    {
        if (_CheckPermission(clsUser::enPermission::enTransactions))
        clsTransactionsScreen::ShowTransactionsMenue();
    }

    static void _ShowManageUsersMenue()
    {
        if (_CheckPermission(clsUser::enPermission::enManageUsers))
        clsManageUsers::ManageUsersScreen();
    }

    static void _Logout()
    {
        CurrentUser = clsUser::Find("", "");
    }
  

    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenueOptions::eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eExit:
            system("cls");
            _Logout();
            

            break;
        }

    }



public:


    static void ShowMainMenue()
    {

        clsScreen Screen= _GetScreenSettings();
        system("cls");
       // string SubTitel = "Welcome "+ CurrentUser.UserName + " (" + CurrentUser.FullName() + ")";
        Screen.DrawScreenHeader("                            Main Screen");
                         
        Screen.WriteTheSubLine("[1] Show Client List");
        Screen.WriteTheSubLine("[2] Add New Client");
        Screen.WriteTheSubLine("[3] Delete Client");
        Screen.WriteTheSubLine("[4] Update Client Info");
        Screen.WriteTheSubLine("[5] Find Client");
        Screen.WriteTheSubLine("[6] Transactions");
        Screen.WriteTheSubLine("[7] Manage Users");
        Screen.WriteTheSubLine("[8] Logout");
        clsScreen::DrawScreenLine();
        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
    }

};

