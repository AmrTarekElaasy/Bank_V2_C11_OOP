#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include <vector>
using namespace std;

class clsClientsScreen : protected clsScreen
{
    static void _DrawTheLine()
    {
        cout << "_______________________________________________________";
        cout << "______________________________________________________________\n" << endl;
    }

public:
    
    static void ShowTotalBalancesScreen()
    {
        vector<clsBankClient> vClients = clsBankClient::GetClientsList();
        string strNumOfCLient = "                     ("+to_string(vClients.size())+") Client(s).";
        DrawScreenHeader("                    Show Clients List",strNumOfCLient);
                        
        clsScreen Screen;
        Screen.Offset = -30;

        Screen.AlignWithOffset();
        _DrawTheLine();

        Screen.AlignWithOffset();
        cout << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(13) << "Phone";
        cout << "| " << left << setw(30) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        Screen.AlignWithOffset(1);
        _DrawTheLine();
        if (vClients.size() > 0)
        {
            for (clsBankClient& client : vClients)
            {
                Screen.AlignWithOffset();
                cout << "| " << left << setw(15) << client.AccountNumber;
                cout << "| " << left << setw(20) << client.FullName();
                cout << "| " << left << setw(13) << client.Phone;
                cout << "| " << left << setw(30) << client.Email;
                cout << "| " << left << setw(10) << client.PinCode;
                //cout << "| " << left << setw(12) << client.AccountBalance << "\n";
                printf("| %.2f \n", client.AccountBalance);

            }
        }
        else
        {
            Screen.AlignWithOffset();
            cout << "No Clients Her\n";
        }
        Screen.AlignWithOffset();
        _DrawTheLine();
        Screen.DrawScreenLine();
    }
};