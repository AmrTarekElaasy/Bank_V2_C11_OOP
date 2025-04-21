#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"
class clsTotalBalancesScreen :clsScreen
{
	static void _PrintTheLine()
	{
		cout << "___________________________________________________________________\n\n";

	}
	static double _GetTotalBalans(vector<clsBankClient>& vClients)
	{
		double totalBalans = 0;
		for (short i = 0;i < vClients.size();i++)
		{
			totalBalans += vClients[i].AccountBalance;
		}
		return totalBalans;
	}
	static clsScreen _GetScreenSettings()
	{
		clsScreen Screen;
		Screen.Offset = -5;
		return Screen;
	}
public:
	static void ShowTotalBalancesScreen()
	{
		system("cls");
		vector<clsBankClient> vClients = clsBankClient::GetClientsList();
		clsScreen Screen= _GetScreenSettings();
		string strNumOfCLient = "                      (" + to_string(vClients.size()) + ") Client(s).";
		DrawScreenHeader(Screen,"                     Total Balances Screen", strNumOfCLient);

		
		



		Screen.AlignWithOffset();
		_PrintTheLine();

		Screen.AlignWithOffset();
		cout << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(30) << "Client Name";
		cout << "| " << left << setw(12) << "Balance";
		cout << "\n";
		Screen.AlignWithOffset();
		_PrintTheLine();

		if (vClients.size() > 0)
		{
			for (clsBankClient& client : vClients)
			{
				Screen.AlignWithOffset();
				cout << "| " << left << setw(15) << client.AccountNumber;
				cout << "| " << left << setw(30) << client.FullName();
				printf("| %.2f \n", client.AccountBalance);

			}
		}
		else
		{
			Screen.AlignWithOffset();
			cout << "No Clients Her\n";
		}
		Screen.AlignWithOffset();
		_PrintTheLine();


		double totalBalans = _GetTotalBalans(vClients);

		Screen.OffsetOFclsScreen();
		printf("Total Balans is : %.2f\n\n", totalBalans);
		clsScreen::DrawScreenLine();


	}
};

