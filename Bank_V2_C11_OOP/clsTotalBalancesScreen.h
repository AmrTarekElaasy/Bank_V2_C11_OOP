#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"
class clsTotalBalancesScreen:clsScreen
{
    static void _PrintTheLine()
    {
        cout << "___________________________________________________________________\n\n";

    }
public:
    static void ShowTotalBalancesScreen()
    {
        system("cls");
        vector<clsBankClient> vClients = clsBankClient::GetClientsList();
        string strNumOfCLient = "                     (" + to_string(vClients.size()) + ") Client(s).";
        DrawScreenHeader("                 Total Balances Screen", strNumOfCLient);

        clsScreen Screen;
        Screen.Offset = -5;
        


        Screen.AlignWithOffset();
        _PrintTheLine();

        Screen.AlignWithOffset();
        cout << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(30) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";
        cout << "\n";
        Screen.AlignWithOffset();
        _PrintTheLine();

        if (vClients.size() > 0)
        {
            for (clsBankClient& client : vClients)
            {
                Screen.AlignWithOffset();
                cout << "| " << left << setw(15) << client.AccountNumber;
                cout << "| " << left << setw(30) << client.FullName();
                cout << "| " << left << setw(12) << client.AccountBalance << "\n";

            }
        }
        else
        {
            Screen.AlignWithOffset();
            cout << "No Clients Her\n";
        }
        Screen.AlignWithOffset();
        _PrintTheLine();

        double totalBalans = 0;
        for (short i = 0;i < vClients.size();i++)
        {
            totalBalans += vClients[i].AccountBalance;
        }
       
        Screen.OffsetOFclsScreen();
        printf("Total Balans is : %.2f\n\n", totalBalans);
        clsScreen::DrawScreenLine();


    }
};

