#pragma once
#include "clsScreen.h"
#include "clsUser.h"
class clsUserInfoScreen
{
	static void _ScreenSettings()
	{
        clsScreen::ColorAllProgram();

		CurrentScreen.Offset = 0;
	}
	static void _DrawTheLine()
	{
		cout << "________________________________________________";

	}
public:
    static void PrintUserInfo(clsUser User)
    {
        
       // _ScreenSettings();
        CurrentScreen.AlignWithOffset(0);
        _DrawTheLine();
        CurrentScreen.AlignWithOffset(2);
        cout << "User Card:";
        CurrentScreen.AlignWithOffset(1);
        _DrawTheLine();
        CurrentScreen.AlignWithOffset(2);
        cout << "FirstName      : " << User.FirstName;
        CurrentScreen.AlignWithOffset(1);
        cout << "LastName       : " << User.LastName;
        CurrentScreen.AlignWithOffset(1);
        cout << "Full Name      : " << User.FullName();
        CurrentScreen.AlignWithOffset(1);
        cout << "Email          : " << User.Email;
        CurrentScreen.AlignWithOffset(1);
        cout << "Phone          : " << User.Phone;
        CurrentScreen.AlignWithOffset(1);
        cout << "User Name      : " << User.UserName;
        CurrentScreen.AlignWithOffset(1);
        cout << "Password       : " << User.Password;
        CurrentScreen.AlignWithOffset(1);
        cout << "Permisstion    : "<<(User.Permission);
        CurrentScreen.AlignWithOffset(1);
    

        _DrawTheLine();
        cout << "\n";
    }

};

