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

    static clsScreen _ScreenSettings()
    {
        clsScreen CurrentScreen;
        CurrentScreen.Offset = -30;
        return CurrentScreen;
    }
public:
	static void ShowListUsers()
	{
        vector<clsUser> vUsers = clsUser::GetUsersList();
        string strNumOfUsers =  "                        (" + to_string(vUsers.size()) + ") User(s).";
        clsScreen CurrentScreen = _ScreenSettings();
        CurrentScreen.DrawScreenHeader("                         Show Users List", strNumOfUsers);

        
       

        CurrentScreen.AlignWithOffset();
        _DrawTheLine();

        CurrentScreen.AlignWithOffset();
        cout << "| " << left << setw(15) << "User Name";
        cout << "| " << left << setw(20) << "Full Name";
        cout << "| " << left << setw(13) << "Phone";
        cout << "| " << left << setw(30) << "Email";
        cout << "| " << left << setw(14) << "Password";
        cout << "| " << "Permisstion";
        CurrentScreen.AlignWithOffset(1);
        _DrawTheLine();
        if (vUsers.size() > 0)
        {
            for (clsUser& user : vUsers)
            {
                if ((user.UserName == UserNameOfAdmin) && (CurrentUser.UserName != UserNameOfAdmin))
                {
                    user.Password = "";
                }
                CurrentScreen.AlignWithOffset();
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
            CurrentScreen.AlignWithOffset();
            cout << "No Users Her\n";
        }
        CurrentScreen.AlignWithOffset();
        _DrawTheLine();
        CurrentScreen.DrawScreenLine();
	}
};

