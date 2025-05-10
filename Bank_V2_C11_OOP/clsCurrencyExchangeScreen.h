#pragma once
#include "clsScreen.h"
#include "clsListCurrenciesScreen.h"
#include "clsFindCurrency.h"
#include "clsUpdateRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"
class clsCurrencyExchangeScreen
{
private:
	static void _ScreenSettings()
	{
		system("cls");
		CurrentScreen.Offset = 0;
	}
	enum enCurrencyExchangeOptions {
		eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3,
		eCurrencyCalculator = 4, eMainMenue = 5
	};
	static enCurrencyExchangeOptions ReadOption()
	{
		CurrentScreen.AlignWithOffset(1);
		cout << "Choose what do you want to do? [1 to 5] :  ";
		return (enCurrencyExchangeOptions) clsInputValidate::ReadIntNumberBetween(1, 5, "Enter Number between 1 to 5 : ");
	}
	static void  _ShowListCurrencies()
	{
		clsListCurrenciesScreen::CurrenciesListScreen();
	}
	static void  _ShowFindCurrency()
	{
		clsFindCurrency::ShowFindCurrencyScreen();
	}
	static void  _ShowUpdateRate()
	{
		clsUpdateRateScreen::ShowUpdateRateScreen();
	}static void  _ShowCurrencyCalculator()
	{
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}
	static void _GoBackToCurrencyExchangeScreen() 
	{
		
		CurrentScreen.Print("Press any key to go back to Currency Exchange Screen...");
		system("pause>0");
		ShowCurrencyExchangeScreen();
	}
	static void PerfromOption(enCurrencyExchangeOptions Option)
	{
		switch (Option)
		{
		case clsCurrencyExchangeScreen::eListCurrencies:
			_ShowListCurrencies();
			_GoBackToCurrencyExchangeScreen();
			break;
		case clsCurrencyExchangeScreen::eFindCurrency:
			_ShowFindCurrency();
			_GoBackToCurrencyExchangeScreen();
			break;
		case clsCurrencyExchangeScreen::eUpdateRate:
			_ShowUpdateRate();
			_GoBackToCurrencyExchangeScreen();
			break;
		case clsCurrencyExchangeScreen::eCurrencyCalculator:
			_ShowCurrencyCalculator();
			_GoBackToCurrencyExchangeScreen();
			break;
		case clsCurrencyExchangeScreen::eMainMenue:
			break;
		
		}
	}
	static  void _PrintOptions()
	{
		CurrentScreen.DrawScreenHeader("                      Currency Exchange Screen");
		CurrentScreen.WriteTheSubLine("[1] List Currencies", true);
		CurrentScreen.WriteTheSubLine("[2] Find Currency", true);
		CurrentScreen.WriteTheSubLine("[3] Update Rate", true);
		CurrentScreen.WriteTheSubLine("[4] Currency Calculator", true);
		CurrentScreen.WriteTheSubLine("[5] Main Menue", true);
		CurrentScreen.DrawScreenLine();
		

	}
public:
	
	static void ShowCurrencyExchangeScreen()
	{
		_ScreenSettings();
		_PrintOptions();
		enCurrencyExchangeOptions option = ReadOption();
		CurrentScreen.DrawScreenLine(1);
		PerfromOption(option);
		
	}
};

