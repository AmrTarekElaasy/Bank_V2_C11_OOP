#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
class clsListCurrenciesScreen
{
	static void _ScreenSettings()
	{
		system("cls");
		CurrentScreen.Offset = -13;
	}
	static void _PrintTheLine()
	{
		CurrentScreen.Print("___________________________________________________________________________________________\n");

	}
public:
	static void CurrenciesListScreen()
	{
		_ScreenSettings();
		vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();
		string subTitel = "                           (" + to_string(vCurrencies.size()) + ")";
		CurrentScreen.DrawScreenHeader("                     Currencies List Screen", subTitel);
		//Country   Code  Name   Rate / (1$)

		_PrintTheLine();
		CurrentScreen.AlignWithOffset();
		cout << left << setw(30) << "Country" << " |";
		cout << left << setw(4) << "Code" << " |";
		cout << left << setw(40) << "Name" << " |";
		cout << "Rate / (1$)\n";
		_PrintTheLine();
		for (clsCurrency& Currency : vCurrencies)
		{
			CurrentScreen.AlignWithOffset();
			cout << left << setw(30) << Currency.Country() << " |";
			cout << left << setw(4) << Currency.CurrencyCode() << " |";
			cout << left << setw(40) << Currency.CurrencyName() << " |";
			cout << Currency.Rate() << "\n";
		}
		_PrintTheLine();
		CurrentScreen.DrawScreenLine();
	}
};

