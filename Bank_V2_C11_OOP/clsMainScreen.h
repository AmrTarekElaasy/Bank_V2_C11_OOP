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
#include "clsLoginRegisterScreen.h"
#include "clsCurrencyExchangeScreen.h"

using namespace std;


class clsMainScreen :protected clsScreen
{


private:

    static void _ScreenSettings()
    {
        clsScreen::ColorAllProgram();

        CurrentScreen.Offset = 5;

    }
   
    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eLoginRegister = 8, eCurrencyExchange = 9, eExit = 10
    };

    static short _ReadMainMenueOption()
    {
        
        CurrentScreen.AlignWithOffset(1);
        cout << "Choose what do you want to do? [1 to 10] :  ";


        short Choice = clsInputValidate::ReadIntNumberBetween(1, 10, "Enter Number between 1 to 10 : ");
        return Choice;
    }

    static  void _GoBackToMainMenue()
    {
        
		_ScreenSettings();
        CurrentScreen.AlignWithOffset(1);
        cout << "Press any key to go back to Main Menue...";

        cin.sync();
        cin.get();
        ShowMainMenue();
    }

    static void _ShowAllClientsScreen()
    {
        
        if (CurrentScreen.CheckPermission(clsUser::enPermission::enClientsList))
        clsClientsScreen::ShowTotalBalancesScreen();
      
    }

    static void _ShowAddNewClientsScreen()
    {
        
        if (CurrentScreen.CheckPermission(clsUser::enPermission::enAddClient))
        clsAddNewClientScreen::AddNewUserScreen();
    }

    static void _ShowDeleteClientScreen()
    {
       
        if (CurrentScreen.CheckPermission(clsUser::enPermission::enDeleteClient))
        clsDeleteClientScreen::DeleteUserScreen();
    }

    static void _ShowUpdateClientScreen()
    {
        
        if (CurrentScreen.CheckPermission(clsUser::enPermission::enUpdateClient))
        clsUpdateClientScreen::UpdateUserInfoScreen();
    }

    static void _ShowFindClientScreen()
    {
        
        if (CurrentScreen.CheckPermission(clsUser::enPermission::enFindClient))
        clsFindClientScreen::FindClientScreen();
    }

    static void _ShowTransactionsMenue()
    {
        
        if (CurrentScreen.CheckPermission(clsUser::enPermission::enTransactions))
        clsTransactionsScreen::ShowTransactionsMenue();
    }

    static void _ShowManageUsersMenue()
    {
        
        if (CurrentScreen.CheckPermission(clsUser::enPermission::enManageUsers))
        clsManageUsers::ManageUsersScreen();
    }
	static void _ShowCurrencyExchangeScreen()
	{

		if (CurrentScreen.CheckPermission(clsUser::enPermission::enCurrencyExchange))
			clsCurrencyExchangeScreen::ShowCurrencyExchangeScreen();
	}
    static void _Logout()
    {
        CurrentUser = clsUser::Find("", "");
    }
  
    static void _ShowLoginRegisterScreen()
    {
       
        if (CurrentScreen.CheckPermission(clsUser::enPermission::enLoginRegister))
        clsLoginRegisterScreen::ShowLoginRegisterScreen();

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
        case enMainMenueOptions::eAddNewClient://U2512
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eDeleteClient://U2512
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

        case enMainMenueOptions::eLoginRegister:
            system("cls");
            _ShowLoginRegisterScreen();
            _GoBackToMainMenue();
            break;
		case enMainMenueOptions::eCurrencyExchange:
            _ShowCurrencyExchangeScreen();
            _GoBackToMainMenue();
        case enMainMenueOptions::eExit:
            system("cls");
            _Logout();
            

            break;
        }

    }



public:


    static void ShowMainMenue()
    {

        _ScreenSettings();
        system("cls");
       // string SubTitel = "Welcome "+ CurrentUser.UserName + " (" + CurrentUser.FullName() + ")";
        CurrentScreen.DrawScreenHeader("                            Main Screen");
                         
        CurrentScreen.WriteTheSubLine("[1] Show Client List");
        CurrentScreen.WriteTheSubLine("[2] Add New Client");
        CurrentScreen.WriteTheSubLine("[3] Delete Client");
        CurrentScreen.WriteTheSubLine("[4] Update Client Info");
        CurrentScreen.WriteTheSubLine("[5] Find Client");
        CurrentScreen.WriteTheSubLine("[6] Transactions");
        CurrentScreen.WriteTheSubLine("[7] Manage Users");
        CurrentScreen.WriteTheSubLine("[8] Login Register");
        CurrentScreen.WriteTheSubLine("[9] Currency Exchange");
        CurrentScreen.WriteTheSubLine("[10] Logout");
        clsScreen::DrawScreenLine();
        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
    }

};

