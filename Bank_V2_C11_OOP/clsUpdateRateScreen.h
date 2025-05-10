#pragma once
#include "clsScreen.h"
#include "clsFindCurrency.h"

class clsUpdateRateScreen:clsFindCurrency
{	
	static void _ScreenSettings()
	{
		system("cls");
		CurrentScreen.Offset = 0;
	}
public:
	static void ShowUpdateRateScreen()
	{
		_ScreenSettings();
		CurrentScreen.DrawScreenHeader("                       Update Rate Screen");
		                          
		clsCurrency Currency = _FindCurrencyByCode();
		if (Currency.IsCurrencyExist())
		{
			_PrintCurrencyCard(Currency);
		}
		else
		{
			CurrentScreen.Print("Not Exist\n");
			CurrentScreen.DrawScreenLine();
			return;
		}
		CurrentScreen.Print("Enter New Rate : ");
		double rate = abs(clsInputValidate::ReadDblNumber());
		Currency.UpdateRate(rate);
		CurrentScreen.Print("Updated successfully.\n");
		_PrintCurrencyCard(Currency);
		CurrentScreen.DrawScreenLine();

	}
};

