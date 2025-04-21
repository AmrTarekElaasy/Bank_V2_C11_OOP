#pragma once
#include "clsScreen.h"
#include "clsUser.h"
class clsUserInfoScreen
{
	static clsScreen _GetScreenSettings()
	{
		clsScreen Screen;
		Screen.Offset = 0;
		return Screen;
	}
	static void _DrawTheLine()
	{
		cout << "________________________________________________";

	}
public:
    static void PrintUserInfo(clsUser User)
    {
        clsScreen Screen;
        Screen.Offset = 0;
        Screen.AlignWithOffset(0);
        _DrawTheLine();
        Screen.AlignWithOffset(2);
        cout << "User Card:";
        Screen.AlignWithOffset(1);
        _DrawTheLine();
        Screen.AlignWithOffset(2);
        cout << "FirstName      : " << User.FirstName;
        Screen.AlignWithOffset(1);
        cout << "LastName       : " << User.LastName;
        Screen.AlignWithOffset(1);
        cout << "Full Name      : " << User.FullName();
        Screen.AlignWithOffset(1);
        cout << "Email          : " << User.Email;
        Screen.AlignWithOffset(1);
        cout << "Phone          : " << User.Phone;
        Screen.AlignWithOffset(1);
        cout << "User Name      : " << User.UserName;
        Screen.AlignWithOffset(1);
        cout << "Password       : " << User.Password;
        Screen.AlignWithOffset(1);
        cout << "Permisstion    : "<<(User.Permisstion);
        Screen.AlignWithOffset(1);
        _DrawTheLine();
        cout << "\n";
    }

};

