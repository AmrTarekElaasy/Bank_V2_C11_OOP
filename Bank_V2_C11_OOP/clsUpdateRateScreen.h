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
		                          
		clsCurrency Currency = _FindCurrency();
		if (Currency.IsCurrencyExist())
		{
			_PrintCurrencyCard(Currency);

			CurrentScreen.Print("Are you sure you want to update this currency Y|N?");
			if (clsInputValidate::CheckYesOrNo(clsInputValidate::ReadString()))
			{
				CurrentScreen.Print("Enter New Rate : ");
				double rate =clsInputValidate::ReadPositiveDblNumber();
				Currency.UpdateRate(rate);
				CurrentScreen.Print("Updated successfully.\n");
				_PrintCurrencyCard(Currency);
			}
		}
		CurrentScreen.DrawScreenLine();

	}
};

