#pragma once
#include "clsLoginLogger.h"
#include "clsScreen.h"
class clsLoginRegisterScreen
{
	static clsScreen _GetScreenSettings()
	{
		
		clsScreen Screen;
		Screen.Offset = 0;
		return Screen;
	}
	static void _DrawTheLine()
	{

		cout << "_______________________________________________________";
		cout << "__________\n" << endl;
	}
	static void _PrintLoginRegisterRecord(clsLoginLogger::stLoginRegisterRecord LoginRegisterRecord)
	{
		clsScreen Screen = _GetScreenSettings();
		Screen.AlignWithOffset();
		cout << setw(21) << left << LoginRegisterRecord.Date << "|";
		cout << setw(15) << left << LoginRegisterRecord.UserName << "|";;
		cout << setw(15) << left << LoginRegisterRecord.Password << "|";;
		cout << setw(15) << left << LoginRegisterRecord.Permission << "\n";
	}
public:

	static void ShowLoginRegisterScreen()
	{
		system("cls");
		clsScreen Screen = _GetScreenSettings();
		vector <clsLoginLogger::stLoginRegisterRecord> vLogins = clsLoginLogger::LoadFromFile();


		string SubTitel = "                      (" + to_string(vLogins.size()) + ") Record(s).";

		Screen.DrawScreenHeader("                  Login Register List Screen", SubTitel);



		Screen.AlignWithOffset();
		_DrawTheLine();
		if (vLogins.size() > 0)
		{
			Screen.AlignWithOffset();
			cout << setw(21) << left << "Date And Time" << "|";
			cout << setw(15) << left << "User Name" << "|";;
			cout << setw(15) << left << "Password" << "|";;
			cout << "Permission \n";


			Screen.AlignWithOffset();
			_DrawTheLine();


		
			
			for (short i = vLogins.size() - 1;i >= 0;i--)
			{

				_PrintLoginRegisterRecord(vLogins[i]);

			}
		}
		else
		{

			Screen.Print("                          No Login Here\n");
		

		}

		Screen.AlignWithOffset();
		_DrawTheLine();
		Screen.DrawScreenLine();

	}


};

