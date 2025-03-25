#pragma once
#include "clsScreen.h"
#include"clsBankClient.h"
class clsClientInfoScreen:clsScreen
{
public:
	static void PrintClientInfo(clsBankClient Client)
	{
        clsScreen Screen;
        Screen.Offset = 0;
        Screen.AlignWithOffset(1);
        cout << "Client Card:";
        Screen.AlignWithOffset(1);
        cout << "________________________________________________";
        Screen.AlignWithOffset(1);
        cout << "FirstName      : " << Client.FirstName;
        Screen.AlignWithOffset(1);
        cout << "LastName       : " << Client.LastName;
        Screen.AlignWithOffset(1);
        cout << "Full Name      : " << Client.FullName();
        Screen.AlignWithOffset(1);
        cout << "Email          : " << Client.Email;
        Screen.AlignWithOffset(1);
        cout << "Phone          : " << Client.Phone;        
        Screen.AlignWithOffset(1);
        cout << "Account Number : " << Client.AccountNumber;        
        Screen.AlignWithOffset(1);
        cout << "Password       : " << Client.PinCode;
        Screen.AlignWithOffset(1);
        cout << "Balance        : " << Client.AccountBalance;
        Screen.AlignWithOffset(1);
        cout << "________________________________________________\n";
    }
};

