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
	static void _ScreenSettings()
	{
		CurrentScreen.Offset = -1;
	}
public:
	static void ShowTotalBalancesScreen()
	{
		system("cls");
		vector<clsBankClient> vClients = clsBankClient::GetClientsList();
		 _ScreenSettings();
		string strNumOfCLient = "                      (" + to_string(vClients.size()) + ") Client(s).";
		DrawScreenHeader(CurrentScreen,"                     Total Balances Screen", strNumOfCLient);

		
		



		CurrentScreen.AlignWithOffset();
		_PrintTheLine();

		CurrentScreen.AlignWithOffset();
		cout << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(30) << "Client Name";
		cout << "| " << left << setw(12) << "Balance";
		cout << "\n";
		CurrentScreen.AlignWithOffset();
		_PrintTheLine();

		if (vClients.size() > 0)
		{
			for (clsBankClient& client : vClients)
			{
				CurrentScreen.AlignWithOffset();
				cout << "| " << left << setw(15) << client.AccountNumber;
				cout << "| " << left << setw(30) << client.FullName();
				printf("| %.2f \n", client.AccountBalance);

			}
		}
		else
		{
			CurrentScreen.AlignWithOffset();
			cout << "No Clients Her\n";
		}
		CurrentScreen.AlignWithOffset();
		_PrintTheLine();


		double totalBalans = _GetTotalBalans(vClients);

		CurrentScreen.OffsetOFclsScreen();
		printf("Total Balans is : %.2f\n\n", totalBalans);
		clsScreen::DrawScreenLine();


	}
};

