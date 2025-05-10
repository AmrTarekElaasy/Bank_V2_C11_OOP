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
		double Amount = Currency1.ConvertToOtherCurrency(clsInputValidate::ReadDblNumber(), Currency2);
		CurrentScreen.Print("");
		CurrentScreen.DrawScreenLine();
	}
};

