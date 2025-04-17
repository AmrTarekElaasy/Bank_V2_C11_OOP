#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
class clsTransactionsScreen:protected clsScreen
{
	static clsScreen _GetScreenSettings()
	{
		clsScreen Screen;
		Screen.Offset = 0;
		
		return Screen;
	}
	static clsScreen _ClearTransactionsScreenAndPrintHeader()
	{
		clsScreen Screen;
		Screen.Offset = 0;
		system("cls");
		Screen.DrawScreenHeader("              Transactions Menue Screen");
		return Screen;

	}
	
	static void _HeaderAndOptionWhithNoInput()
	{

		clsScreen Screen = _GetScreenSettings();

		Screen.DrawScreenHeader("              Transactions Menue Screen");
		Screen.WriteTheSubLine("[1] Deposit");
		Screen.WriteTheSubLine("[2] Withdraw");
		Screen.WriteTheSubLine("[3] Total Balances");
		Screen.WriteTheSubLine("[4] Main Menue");
		Screen.DrawScreenLine();

	}
	enum enTransactionsMenue { enDeposit = 1, enWithdraw = 2, enTotalBalances = 3, enMainMenue = 4 };
	static enTransactionsMenue _ReadTransactionsMenueOption()
	{
		clsScreen Screen = _GetScreenSettings();
		Screen.AlignWithOffset(0,Screen.Offset+5);
		cout << "Choose what do you want to do? [1 to 4]? ";

		switch (clsInputValidate::ReadIntNumberBetween(1, 4, "Enter Number between 1 to 4 : "))
		{
		case 1:
			return enTransactionsMenue::enDeposit;
		case 2:
			return enTransactionsMenue::enWithdraw;
		case 3:
			return enTransactionsMenue::enTotalBalances;
		case 4:
			return enTransactionsMenue::enMainMenue;

		};
	}
	static void _ShowDepositScreen()
	{
		clsDepositScreen::DepositScreen();
	}
	static void _ShowWithdrawScreen()
	{
		cout << "Well be her\n";

	}
	static void _ShowTotalBalancesScreen()
	{
		cout << "Well be her\n";

	}
	static void GoBackToTransactionsMenue()
	{
		clsScreen Screen = _GetScreenSettings();
	
		Screen.AlignWithOffset(1);
		cout << "Press any key to go back to transactions menue...";
		system("pause>0");
		ShowTransactionsMenue();
	}
	static void _PerformTransactionsMenue(enTransactionsMenue enOption)
	{
		switch (enOption)
		{
		case clsTransactionsScreen::enDeposit:
			_ShowDepositScreen();
			GoBackToTransactionsMenue();
			break;
		case clsTransactionsScreen::enWithdraw:
			_ShowWithdrawScreen();
			GoBackToTransactionsMenue();
			break;
		case clsTransactionsScreen::enTotalBalances:
			_ShowTotalBalancesScreen();
			GoBackToTransactionsMenue();
			break;
		case clsTransactionsScreen::enMainMenue:
			clsScreen Screen = _GetScreenSettings();
			Screen.DrawScreenLine(1);
			break;
		
		}
	}

public:
	static void ShowTransactionsMenue()
	{
		system("cls");
		_HeaderAndOptionWhithNoInput();
		_PerformTransactionsMenue(_ReadTransactionsMenueOption());
	}
};

