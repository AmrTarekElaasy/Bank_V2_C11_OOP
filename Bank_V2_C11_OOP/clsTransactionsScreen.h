#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsShowWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
class clsTransactionsScreen:protected clsScreen
{
	static void _GetScreenSettings()
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

		_GetScreenSettings();
		CurrentScreen.DrawScreenHeader("                  Transactions Menue Screen");
		CurrentScreen.WriteTheSubLine("[1] Deposit");
		CurrentScreen.WriteTheSubLine("[2] Withdraw");
		CurrentScreen.WriteTheSubLine("[3] Total Balances");
		CurrentScreen.WriteTheSubLine("[4] Main Menue");
		CurrentScreen.DrawScreenLine();

	}
	enum enTransactionsMenue { enDeposit = 1, enWithdraw = 2, enTotalBalances = 3, enTransfer =4, enMainMenue = 5 };
	static enTransactionsMenue _ReadTransactionsMenueOption()
	{
		CurrentScreen.AlignWithOffset(0,CurrentScreen.Offset+5);
		cout << "Choose what do you want to do? [1 to 5]: ";

		short TheChoice = clsInputValidate::ReadIntNumberBetween(1, 5,  "Enter Number between 1 to 5 : ");
		
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
	static void GoBackToTransactionsMenue()
	{
		_GetScreenSettings();
	
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
			//_GetScreenSettings();
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

