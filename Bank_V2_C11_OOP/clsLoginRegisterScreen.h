#pragma once
#include "clsLoginLogger.h"
#include "clsScreen.h"
class clsLoginRegisterScreen
{
	static void _GetScreenSettings()
	{
		CurrentScreen.Offset = 0;
		
	}
	static void _DrawTheLine()
	{

		cout << "_______________________________________________________";
		cout << "__________\n" << endl;
	}
	static void _PrintLoginRegisterRecord(clsLoginLogger::stLoginRegisterRecord LoginRegisterRecord)
	{
	   
		CurrentScreen.AlignWithOffset();
		cout << setw(21) << left << LoginRegisterRecord.Date << "|";
		cout << setw(15) << left << LoginRegisterRecord.UserName << "|";;
		cout << setw(15) << left << LoginRegisterRecord.Password << "|";;
		cout << setw(15) << left << LoginRegisterRecord.Permission << "\n";
	}
public:

	static void ShowLoginRegisterScreen()
	{
		system("cls");
	    _GetScreenSettings();
		vector <clsLoginLogger::stLoginRegisterRecord> vLogins = clsLoginLogger::LoadFromFile();


		string SubTitel = "                      (" + to_string(vLogins.size()) + ") Record(s).";

		CurrentScreen.DrawScreenHeader("                  Login Register List Screen", SubTitel);



		CurrentScreen.AlignWithOffset();
		_DrawTheLine();
		if (vLogins.size() > 0)
		{
			CurrentScreen.AlignWithOffset();
			cout << setw(21) << left << "Date And Time" << "|";
			cout << setw(15) << left << "User Name" << "|";;
			cout << setw(15) << left << "Password" << "|";;
			cout << "Permission \n";


			CurrentScreen.AlignWithOffset();
			_DrawTheLine();


		
			
			for (short i = vLogins.size() - 1;i >= 0;i--)
			{

				_PrintLoginRegisterRecord(vLogins[i]);

			}
		}
		else
		{

			CurrentScreen.Print("                          No Login Here\n");
		

		}

		CurrentScreen.AlignWithOffset();
		_DrawTheLine();
		CurrentScreen.DrawScreenLine();

	}


};

