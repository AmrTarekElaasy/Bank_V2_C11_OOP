#pragma once
#include "clsScreen.h"
#include"clsBankClient.h"
class clsClientInfoScreen:clsScreen
{
    static void _ScreenSettings()
    {
        CurrentScreen.Offset = 0;
        clsScreen::ColorAllProgram();

    }
    static void _DrawTheLine()
    {
        cout << "________________________________________________";

    }
public:
	static void PrintUserInfo(clsBankClient Client)
	{
       
        

        _ScreenSettings();

        CurrentScreen.AlignWithOffset(0);
        _DrawTheLine();
        CurrentScreen.AlignWithOffset(2);
        cout << "Client Card:";
        CurrentScreen.AlignWithOffset(1);
        _DrawTheLine();
        CurrentScreen.AlignWithOffset(2);
        cout << "FirstName      : " << Client.FirstName;
        CurrentScreen.AlignWithOffset(1);
        cout << "LastName       : " << Client.LastName;
        CurrentScreen.AlignWithOffset(1);
        cout << "Full Name      : " << Client.FullName();
        CurrentScreen.AlignWithOffset(1);
        cout << "Email          : " << Client.Email;
        CurrentScreen.AlignWithOffset(1);
        cout << "Phone          : " << Client.Phone;        
        CurrentScreen.AlignWithOffset(1);
        cout << "Account Number : " << Client.AccountNumber;        
        CurrentScreen.AlignWithOffset(1);
        cout << "PINCode        : " << Client.PinCode;
        CurrentScreen.AlignWithOffset(1);
        cout << "Balance        : ";clsScreen::PrintDoubleNumber(Client.AccountBalance);
        CurrentScreen.AlignWithOffset(1);
        _DrawTheLine();
        cout << "\n";
        
    }
};

