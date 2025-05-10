#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
class clsListCurrenciesScreen
{
	static void _ScreenSettings()
	{
		system("cls");
		CurrentScreen.Offset = -20;
	}
	static void _PrintTheLine()
	{
		CurrentScreen.Print("_________________________________________________________________________________________________________\n");

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
		cout << left << setw(10) << "Rate / (1$)"<<" |";
		cout << "Last Updated\n";
		_PrintTheLine();
		for (clsCurrency& Currency : vCurrencies)
		{
			CurrentScreen.AlignWithOffset();
			cout << left << setw(30) << Currency.Country() << " |";
			cout << left << setw(4) << Currency.CurrencyCode() << " |";
			cout << left << setw(40) << Currency.CurrencyName() << " |";
			cout << left << setw(11) << Currency.Rate() << " |";
			cout << Currency.DateOfLastUpdated()<<"\n";
		}
		_PrintTheLine();
		CurrentScreen.DrawScreenLine();
	}
};

