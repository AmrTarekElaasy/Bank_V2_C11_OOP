#pragma once
#include "clsScreen.h"
#include "clsUser.h"
class clsListUsersScreen :clsUser
{

    static void _DrawTheLine()
    {
        cout << "_______________________________________________________";
        cout << "______________________________________________________________\n" << endl;
    }

    static clsScreen _GetScreenSettings()
    {
        clsScreen Screen;
        Screen.Offset = -30;
        return Screen;
    }
public:
	static void ShowListUsers()
	{
        vector<clsUser> vUsers = clsUser::GetUsersList();
        string strNumOfUsers =  "                          (" + to_string(vUsers.size()) + ") User(s).";
        clsScreen Screen = _GetScreenSettings();
        Screen.DrawScreenHeader("                         Show Users List", strNumOfUsers);

        
       

        Screen.AlignWithOffset();
        _DrawTheLine();

        Screen.AlignWithOffset();
        cout << "| " << left << setw(15) << "User Name";
        cout << "| " << left << setw(20) << "Full Name";
        cout << "| " << left << setw(13) << "Phone";
        cout << "| " << left << setw(30) << "Email";
        cout << "| " << left << setw(14) << "Password";
        cout << "| " << "Permisstion";
        Screen.AlignWithOffset(1);
        _DrawTheLine();
        if (vUsers.size() > 0)
        {
            for (clsUser& user : vUsers)
            {
                Screen.AlignWithOffset();
                cout << "| " << left << setw(15) << user.UserName;
                cout << "| " << left << setw(20) << user.FullName();
                cout << "| " << left << setw(13) << user.Phone;
                cout << "| " << left << setw(30) << user.Email;
                cout << "| " << left << setw(14) << user.Password;
                cout << "| " << user.Permisstion << "\n";

            }
        }
        else
        {
            Screen.AlignWithOffset();
            cout << "No Users Her\n";
        }
        Screen.AlignWithOffset();
        _DrawTheLine();
        Screen.DrawScreenLine();
	}
};

