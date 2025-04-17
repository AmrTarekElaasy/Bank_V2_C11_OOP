#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

class clsScreen
{
    short _MainOffset =31;
    short _SecondOffset = 0;

public:

    static short GetMainOffset()
    {
        clsScreen Screen;
        return Screen._MainOffset;
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
    static void DrawScreenHeader(string Title, string SubTitle = "")
    {
        DrawScreenLine(1,1);
        cout << setw(GetMainOffset())<<" " << Title;
        if (SubTitle != "")
        {
            cout << "\n" <<setw(GetMainOffset())<<"" << SubTitle;
        }
        
        DrawScreenLine(1);
    }
    static void DrawScreenLine(short NumberOfEndlLineBeforeTXT=0,short NumberOfEndlLineAfterTXT=2)
    {
        while (NumberOfEndlLineBeforeTXT > 0)
        {
            cout << "\n";
            NumberOfEndlLineBeforeTXT--;
        }
        cout << setw(GetMainOffset())<<" " << "=========================================================";
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



};

