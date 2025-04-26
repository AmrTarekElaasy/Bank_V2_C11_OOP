#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsShowWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"
class clsTransactionsScreen :protected clsScreen
{
	static void _ScreenSettings()
	{
		CurrentScreen.Offset = 0;

	}
	static void _ClearTransactionsScreenAndPrintHeader()
	{

		system("cls");
		CurrentScreen.DrawScreenHeader("              Transactions Menue Screen");

	}

	static void _HeaderAndOptionWhithNoInput()
	{

		_ScreenSettings();
		CurrentScreen.DrawScreenHeader("                  Transactions Menue Screen");
		CurrentScreen.WriteTheSubLine("[1] Deposit");
		CurrentScreen.WriteTheSubLine("[2] Withdraw");
		CurrentScreen.WriteTheSubLine("[3] Total Balances");
		CurrentScreen.WriteTheSubLine("[4] Transfer");
		CurrentScreen.WriteTheSubLine("[5] Transfer Log");
		CurrentScreen.WriteTheSubLine("[6] Main Menue");
		CurrentScreen.DrawScreenLine();

	}
	enum enTransactionsMenue { enDeposit = 1, enWithdraw = 2, enTotalBalances = 3, enTransfer = 4, enTransferLog = 5, enMainMenue = 6 };
	
	static enTransactionsMenue _ReadTransactionsMenueOption()
	{
		CurrentScreen.AlignWithOffset(0, CurrentScreen.Offset + 5);
		cout << "Choose what do you want to do? [1 to 6]: ";

		short TheChoice = clsInputValidate::ReadIntNumberBetween(1, 6, "Enter Number between 1 to 6 : ");

		return (enTransactionsMenue)TheChoice;
	}


	static void _ShowDepositScreen()
	{
		clsDepositScreen::DepositScreen();
	}
	static void _ShowWithdrawScreen()
	{
		clsShowWithdrawScreen::WithdrawScreen();


	}
	static void _ShowTotalBalancesScreen()
	{

		clsTotalBalancesScreen::ShowTotalBalancesScreen();
	}
	static void _ShowTransferScreen()
	{

		clsTransferScreen::ShowTransferScreen();

	}
	static void _ShowTransferLogScreen()
	{
		clsTransferLogScreen::ShowTransferLogScreen();
	}
	static void _GoBackToTransactionsMenue()
	{
		_ScreenSettings();

		CurrentScreen.AlignWithOffset(1);
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
			_GoBackToTransactionsMenue();
			break;
		case clsTransactionsScreen::enWithdraw:
			_ShowWithdrawScreen();
			_GoBackToTransactionsMenue();
			break;
		case clsTransactionsScreen::enTotalBalances:
			_ShowTotalBalancesScreen();
			_GoBackToTransactionsMenue();
			break;
		case clsTransactionsScreen::enTransfer:
			_ShowTransferScreen();
			_GoBackToTransactionsMenue();
			break;
		case clsTransactionsScreen::enTransferLog:
			_ShowTransferLogScreen();
			_GoBackToTransactionsMenue();
			break;
		case clsTransactionsScreen::enMainMenue:

			CurrentScreen.DrawScreenLine(1);
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

