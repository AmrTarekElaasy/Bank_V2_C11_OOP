#pragma once
#include "clsLoginLogger.h"
#include "clsScreen.h"
#include "clsUser.h"
class clsLoginRegisterScreen
{
	static void _ScreenSettings()
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
		if ((LoginRegisterRecord.UserName == UserNameOfAdmin) && (CurrentUser.UserName != UserNameOfAdmin))
		{
			LoginRegisterRecord.Password = "";
		}
	   
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
	    _ScreenSettings();
		vector <clsLoginLogger::stLoginRegisterRecord> vLogins = clsLoginLogger::LoadLoginRegisterRecordFromFile();


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


		
			
			for (clsLoginLogger::stLoginRegisterRecord & i :vLogins)
			{

				_PrintLoginRegisterRecord(i);

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

