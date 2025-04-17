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


using namespace std;



class clsMainScreen :protected clsScreen
{


private:
    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eExit = 8
    };

    static short _ReadMainMenueOption()
    {
        cout << setw(clsScreen::GetMainOffset()+5) << left << "" << "Choose what do you want to do? [1 to 8] :  ";
        short Choice = clsInputValidate::ReadIntNumberBetween(1, 8, "Enter Number between 1 to 8 : ");
        return Choice;
    }

    static  void _GoBackToMainMenue()
    {
        clsScreen::AlignWithOffset(1,0);
        cout << "Press any key to go back to Main Menue...";
        system("pause>0");
        ShowMainMenue();
    }

    static void _ShowAllClientsScreen()
    {
        clsClientsScreen::ShowClientsList();
      
    }

    static void _ShowAddNewClientsScreen()
    {
        clsAddNewClientScreen::AddNewClientScreen();
    }

    static void _ShowDeleteClientScreen()
    {
        clsDeleteClientScreen::DeleteClientScreen();
    }

    static void _ShowUpdateClientScreen()
    {
        clsUpdateClientScreen::UpdateClientInfoScreen();
    }

    static void _ShowFindClientScreen()
    {
        clsFindClientScreen::FindClientScreen();
    }

    static void _ShowTransactionsMenue()
    {
        clsTransactionsScreen::ShowTransactionsMenue();
    }

    static void _ShowManageUsersMenue()
    {
        cout << "\n" << setw(clsScreen::GetMainOffset()) << "" << "Users Menue Will be here...\n";

    }

    static void _ShowEndScreen()
    {
        cout << "\n" << setw(clsScreen::GetMainOffset()) << "" << "End Screen Will be here...\n";

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
            break;

        case enMainMenueOptions::eExit:
            system("cls");
            _ShowEndScreen();
            //Login();

            break;
        }

    }



public:


    static void ShowMainMenue()
    {

        
        system("cls");
        DrawScreenHeader("                      Main Screen");
                         
        WriteTheSubLine("[1] Show Client List");
        WriteTheSubLine("[2] Add New Client");
        WriteTheSubLine("[3] Delete Client");
        WriteTheSubLine("[4] Update Client Info");
        WriteTheSubLine("[5] Find Client");
        WriteTheSubLine("[6] Transactions");
        WriteTheSubLine("[7] Manage Users");
        WriteTheSubLine("[8] Logout");
        clsScreen::DrawScreenLine();
        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
    }

};

