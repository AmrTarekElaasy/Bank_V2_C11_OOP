#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"
class clsFindCurrency
{
	static void _ScreenSettings()
	{
		system("cls");
		CurrentScreen.Offset = 0;
	}


protected:
	static clsCurrency _FindCurrencyByCode()
	{
		CurrentScreen.Print("Please Enter Currency Code : ");
		string CurrencyCode = clsInputValidate::ReadString();

		return clsCurrency::FindByCode(CurrencyCode);
	}
	static clsCurrency _FindCurrencyByCountry()
	{
		CurrentScreen.Print("Please Enter Currency Country : ");
		string CurrencyCountry = clsInputValidate::ReadString();

		return clsCurrency::FindByCountry(CurrencyCountry);
	}
	static void _PrintCurrencyCard(clsCurrency Currency)
	{
		CurrentScreen.Print("Currency Card : \n");
		CurrentScreen.Print("__________________________________________________\n");
		CurrentScreen.Print("Country  : ");cout << Currency.Country() << "\n";
		CurrentScreen.Print("Code     : ");cout << Currency.CurrencyCode() << "\n";
		CurrentScreen.Print("Name     : ");cout << Currency.CurrencyName() << "\n";
		CurrentScreen.Print("Rate(1$) : ");cout << Currency.Rate() << "\n";
		CurrentScreen.Print("__________________________________________________\n");

	}
public:
	static void ShowFindCurrencyScreen()
	{
		_ScreenSettings();
		CurrentScreen.DrawScreenHeader("                      Find Currency Screen");
		CurrentScreen.Print("Find By: [1] Code  |  [2] Country  |  Any other key to cancel: ");
		string Choice = clsInputValidate::ReadString();
		if (Choice != "1" && Choice != "2")
		{
			CurrentScreen.DrawScreenLine();
			return;
		}
			

		clsCurrency Currency = clsCurrency::FindByCode("");
		if (Choice == "1")
			Currency = _FindCurrencyByCode();
		else if (Choice == "2")
			Currency = _FindCurrencyByCountry();

		if (Currency.IsCurrencyExist())
		{
			_PrintCurrencyCard(Currency);
		}
		else
		{
			CurrentScreen.Print("Not Exist\n");
		}

		CurrentScreen.DrawScreenLine();


	}
};

