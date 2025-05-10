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

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		
		while (Currency.IsCurrencyExist() == false)
		{
			CurrentScreen.Print("Not Exist\n");
			CurrentScreen.Print("Do you Need Try Agen Y|N ? ");
			if (clsInputValidate::CheckYesOrNo(clsInputValidate::ReadString()) == false)
				return Currency;
			CurrentScreen.Print("Please Enter Currency Code : ");
			string CurrencyCode = clsInputValidate::ReadString();
			Currency = clsCurrency::FindByCode(CurrencyCode);
		}
		return Currency;

	}
	static clsCurrency _FindCurrencyByCountry()
	{
		CurrentScreen.Print("Please Enter Currency Country : ");
		string CurrencyCode = clsInputValidate::ReadString();

		clsCurrency Currency = clsCurrency::FindByCountry(CurrencyCode);

		while (Currency.IsCurrencyExist() == false)
		{
			CurrentScreen.Print("Not Exist\n");
			CurrentScreen.Print("Do you Need Try Agen Y|N ? ");
			if (clsInputValidate::CheckYesOrNo(clsInputValidate::ReadString()) == false)
				return Currency;
			CurrentScreen.Print("Please Enter Currency Country : ");
			string CurrencyCode = clsInputValidate::ReadString();
			Currency = clsCurrency::FindByCountry(CurrencyCode);
		}
		return Currency;
	}
	static clsCurrency _FindCurrency()
	{
		clsCurrency Currency = clsCurrency::FindByCode("");

		CurrentScreen.Print("Find By: [1] Code  |  [2] Country  |  Any other key to cancel: ");
		string Choice = clsInputValidate::ReadString();
		if (Choice != "1" && Choice != "2")
		{
			return Currency;
		}


		
		if (Choice == "1")
			Currency = _FindCurrencyByCode();
		else if (Choice == "2")
			Currency = _FindCurrencyByCountry();

		return Currency;

	}
	static void _PrintCurrencyCard(clsCurrency Currency)
	{
		CurrentScreen.Print("Currency Card : \n");
		CurrentScreen.Print("__________________________________________________\n");
		CurrentScreen.Print("Country    : ");cout << Currency.Country() << "\n";
		CurrentScreen.Print("Code       : ");cout << Currency.CurrencyCode() << "\n";
		CurrentScreen.Print("Name       : ");cout << Currency.CurrencyName() << "\n";
		CurrentScreen.Print("Rate(1$)   : ");cout << Currency.Rate() << "\n";
		CurrentScreen.Print("Updated On : ");cout << Currency.DateOfLastUpdated() << "\n";
		CurrentScreen.Print("__________________________________________________\n");

	}
	static void _CleanAndPrintHeader()
	{
		_ScreenSettings();
		CurrentScreen.DrawScreenHeader("                      Find Currency Screen");
	}
public:
	static void ShowFindCurrencyScreen()
	{
		
		_CleanAndPrintHeader();
		
		clsCurrency Currency = _FindCurrency();
		if (Currency.IsCurrencyExist())
		{
			_CleanAndPrintHeader();
			_PrintCurrencyCard(Currency);
		}

		CurrentScreen.DrawScreenLine();


	}
};

