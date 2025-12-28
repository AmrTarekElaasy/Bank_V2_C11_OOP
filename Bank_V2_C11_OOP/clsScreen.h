#pragma once
#include <iostream>
#include <iomanip>
#include "clsDate.h"
#include "clsUser.h"
#include <windows.h>

using namespace std;
class clsScreen
{
    short _MainOffset =31; //31
    short _SecondOffset = 0;

 
public:
 
    static void SetColor(int color) {
        
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, color);
    }
    static void Pause(string messege, bool AddPause=false)
    {
        cout << messege;
        if(AddPause)
            system("pause>0");
        cin.clear();
        while (cin.peek() != '\n' && cin.peek() != EOF)
        {
            cin.ignore();
        }

      

        cin.get();
    }
    static short GetMainOffset()
    {
        clsScreen CurrentScreen;
        return CurrentScreen._MainOffset;
    }
    static void ColorSuccessfulOperation()
    {
        system("color 02");
    }
    static void ColorFailedOperation()
    {
        system("color 04");
    }
    static void ColorAllProgram()
    {
        system("color 0F");
    }

    _declspec (property (get = GetMainOffset)) short MainOffset;

    void SetSecondOffset(short offset) {
        _SecondOffset = offset;
    }
    short GetSecondOffset() {
        return _SecondOffset;
    }
    _declspec (property (put=SetSecondOffset, get = GetSecondOffset)) short Offset;


    
    static void OffsetOFclsScreen()
    {
        cout << setw(GetMainOffset())<<"";
    }
    static void AlignWithOffset(short numberOfNewLine , short theOffset )
    {
        while (numberOfNewLine > 0)
        {
            cout << "\n";
            numberOfNewLine--;

        }
        theOffset *= -1;
        theOffset = clsScreen::GetMainOffset() - theOffset;
        cout << setw(theOffset) << "";

    }
    void AlignWithOffset(short numberOfNewLine = 0)
    {
        AlignWithOffset(numberOfNewLine,_SecondOffset);
    }
    static void DrawScreenHeader(clsScreen CurrentScreen,string Title, string SubTitle = "")
    {
        DrawScreenLine(1,1);
        CurrentScreen.AlignWithOffset(0,0);       
        cout << Title;

        if (SubTitle != "")
        {
            
            CurrentScreen.AlignWithOffset(1,2);
             cout << SubTitle;
        }
        
        
 


        DrawScreenLine(1,1);
        string UserName = "User: ";
        if (CurrentUser.IsExist())
        {
            
            UserName += CurrentUser.UserName + " (" + CurrentUser.FullName() + ") ";
            
        }
        CurrentScreen.AlignWithOffset(0, 0);
        cout << setw(49) << left << UserName<<"";

        string Date = "Date: ";
        Date+= clsDate::DateToString(clsDate::GetSystemDate());
        cout <<setw(16)<<right<< Date << "\n";
        DrawScreenLine(0, 1);
    }
    void DrawScreenHeader(string Title, string SubTitle = "")
    {
        DrawScreenHeader(*this,Title,SubTitle);
    }
    static void DrawScreenLine(short NumberOfEndlLineBeforeTXT=0,short NumberOfEndlLineAfterTXT=1)
    {
        while (NumberOfEndlLineBeforeTXT > 0)
        {
            cout << "\n";
            NumberOfEndlLineBeforeTXT--;
        }
        cout << setw(GetMainOffset())<<" " << "=================================================================";
        while (NumberOfEndlLineAfterTXT > 0)
        {
            cout << "\n";
            NumberOfEndlLineAfterTXT--;
        }
            
    }
    static void PrintDoubleNumber(double Number,bool endl=false)
    {
        printf("%.2f", Number);
        if (endl)
            cout << endl;
    }
    static void WriteTheSubLine(string lineTXT,bool endLine=true)
    {
        std::cout << setw(GetMainOffset()+5) <<"" << lineTXT;
        if(endLine)
        cout<<".\n";

    }

    static bool CheckPermission(clsScreen CurrentScreen,clsUser::enPermission Permission)
    {

        if (CurrentUser.HasPermission(Permission))
        {
            return true;
        }
        DrawScreenHeader(CurrentScreen,"                  Access Denied! Contact Your Admin.");

        return false;
    }
    bool CheckPermission(clsUser::enPermission Permission)
    {
        return CheckPermission(*this,Permission);
    }

    static void Print(clsScreen CurrentScreen,string Messege)
    {
        CurrentScreen.AlignWithOffset();
        cout << Messege;
    }
    void Print(string Messege)
    {
        Print(*this, Messege);
    }


};
clsScreen CurrentScreen;

 
