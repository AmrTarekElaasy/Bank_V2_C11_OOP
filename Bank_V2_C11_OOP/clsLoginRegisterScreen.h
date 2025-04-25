#pragma once
#include "clsLoadLoginsFromALogFile.h"
#include "clsScreen.h"
class clsLoginRegisterScreen
{
	static clsScreen _GetScreenSettings()
	{
		system("cls");
		clsScreen Screen;
		Screen.Offset = 0;
		return Screen;
	}
	static void _DrawTheLine()
	{

		cout << "_______________________________________________________";
		cout << "__________\n" << endl;
	}
public:

	static void ShowLoginRegisterScreen()
	{
		clsScreen Screen = _GetScreenSettings();
		vector <vector<string>> vLogins = clsLoadLoginsFromALogFile::LoadLoginsFromALogFile();


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



			for (vector <string> line : vLogins)
			{


				Screen.AlignWithOffset();
				cout << setw(21) << left << line[0] << "|";
				cout << setw(15) << left << line[1] << "|";;
				cout << setw(15) << left << line[2] << "|";;
				cout << setw(15) << left << line[3] << "\n";

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

