#pragma once
#include "clsFindCurrency.h"
class clsCurrencyCalculatorScreen:clsFindCurrency
{
	static void _ScreenSettings()
	{
		system("cls");
		CurrentScreen.Offset = 0;
	}
	static void _CleanAndPrintHeader()
	{
		_ScreenSettings();
		CurrentScreen.DrawScreenHeader("                  Currency Calculator Screen");
	}
public:
	static void ShowCurrencyCalculatorScreen()
	{
		_CleanAndPrintHeader();
		clsCurrency Currency1 = _FindCurrency();
		
		if (Currency1.IsCurrencyExist() == false)
		{
			
			CurrentScreen.DrawScreenLine();
			return;
		}
		_CleanAndPrintHeader();
		CurrentScreen.Print("___Currency 1  \n");
		_PrintCurrencyCard(Currency1);

		CurrentScreen.Print("___Currency 2  \n");
		clsCurrency Currency2 = _FindCurrency();
		if (Currency2.IsCurrencyExist() == false)
		{
			CurrentScreen.DrawScreenLine();
			return;
		}
		_CleanAndPrintHeader();

		CurrentScreen.Print("___Currency 1\n");
		_PrintCurrencyCard(Currency1);
		CurrentScreen.Print("___Currency 2\n");
		_PrintCurrencyCard(Currency2);
		
		CurrentScreen.Print("Enter Amount : ");
		double AmountCurrency1 = clsInputValidate::ReadPositiveDblNumber();
		double AmountCurrency2 = Currency1.ConvertToOtherCurrency(AmountCurrency1, Currency2);
		CurrentScreen.Print(""); cout << AmountCurrency1 <<Currency1.CurrencyCode()<<" = " ;
		cout << AmountCurrency2 << Currency2.CurrencyCode() << endl;
		CurrentScreen.DrawScreenLine();
	}
};

