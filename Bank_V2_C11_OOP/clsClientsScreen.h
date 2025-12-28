#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include <vector>
using namespace std;

 
class clsClientsScreen 
{
    static void _DrawTheLine()
    {
        cout << "_______________________________________________________";
        cout << "______________________________________________________________\n" << endl;
    }
    static void _ScreenSettings()
    {
        
        CurrentScreen.Offset = -30;
        clsScreen::ColorAllProgram();

    }
public:
    
    static void ShowTotalBalancesScreen()
    {
        _ScreenSettings();

        vector<clsBankClient> vClients = clsBankClient::GetClientsList();
        string strNumOfCLient = "                         ("+to_string(vClients.size())+") Client(s).";
        CurrentScreen.DrawScreenHeader("                         Show Clients List",strNumOfCLient);
                        
                    

        CurrentScreen.AlignWithOffset();
        _DrawTheLine();

        CurrentScreen.AlignWithOffset();
        cout << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(13) << "Phone";
        cout << "| " << left << setw(30) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        CurrentScreen.AlignWithOffset(1);
        _DrawTheLine();
        if (vClients.size() > 0)
        {
            for (clsBankClient& client : vClients)
            {
                CurrentScreen.AlignWithOffset();
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
            CurrentScreen.Print("No Clients Her\n");
   
        }
        CurrentScreen.AlignWithOffset();
        _DrawTheLine();
        CurrentScreen.DrawScreenLine();
        //system("pause>0");
    }
};