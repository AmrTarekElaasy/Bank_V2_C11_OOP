#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
class clsTransferScreen
{
	static void _ScreenSettings()
	{
		//clsScreen::ColorAllProgram();
		system("cls");

		CurrentScreen.Offset = 0;
	}
	static void _DrawScreenLine()
	{
		CurrentScreen.Print("_________________________________\n");
	}
	static void _PrintClientCard(clsBankClient Client)
	{
		_DrawScreenLine();
		cout << "\n";
		CurrentScreen.Print("Client Card :\n");
		_DrawScreenLine();

		CurrentScreen.Print("Full Name       : ");
		cout << Client.FullName() << "\n";
		CurrentScreen.Print("Account Number  : ");
		cout << Client.AccountNumber << "\n";
		CurrentScreen.Print("Balance         : ");
		cout << Client.AccountBalance << "\n";
		_DrawScreenLine();
		cout << "\n";


	}



	static clsBankClient _ReadClient(string Mesege, string ScondAcountNumber = "")
	{
		string AccountNumbr = "";
		bool FailSaveTransferInLog = false;
		clsBankClient Client = clsBankClient::Find("");
		do {

			if (FailSaveTransferInLog)
			{
				if (!Client.IsExist())
					CurrentScreen.Print("Not Exist\n");
				else if (Client.AccountNumber == ScondAcountNumber)
					CurrentScreen.Print("You can not transfer to the same account\n");
				else
					CurrentScreen.Print("Not Exist or Account Number is the same\n");


				FailSaveTransferInLog = false;
				CurrentScreen.Print("Do you want to find another account? [Y/N] : ");
				if (clsInputValidate::CheckYesOrNo(clsInputValidate::ReadString()) == false)
					return clsBankClient::Find("");
			}

			CurrentScreen.Print(Mesege);
			AccountNumbr = clsInputValidate::ReadString();
			Client = clsBankClient::Find(AccountNumbr);


			if (!(Client.IsExist()) || Client.AccountNumber == ScondAcountNumber)
				FailSaveTransferInLog = true;


		} while (FailSaveTransferInLog);
		return Client;
	}
	static void _Header()
	{
		_ScreenSettings();
		CurrentScreen.DrawScreenHeader( "                         Transfer Screen");
	}


public:
	static void ShowTransferScreen()
	{
		double BalanceOfClient1 = 0, BalanceOfClient2 = 0;

		_Header();
		clsBankClient Client1 = _ReadClient("Enter Account Number To Transfer From : ");
		if (Client1.IsExist() == false)
		{
			clsScreen::ColorFailedOperation();
			CurrentScreen.DrawScreenLine();
			return;
		}
		else if (Client1.AccountBalance == 0)
		{
			clsScreen::ColorFailedOperation();
			CurrentScreen.Print("You have no balance to transfer\n");
			CurrentScreen.DrawScreenLine();
			return;
		}
		

		BalanceOfClient1 = Client1.AccountBalance;
		_PrintClientCard(Client1);
	

		clsBankClient Client2 = _ReadClient("Enter Account Number To Transfer To : ", Client1.AccountNumber);
		if (Client2.IsExist() == false)
		{
			clsScreen::ColorFailedOperation();
			CurrentScreen.DrawScreenLine();
			return;
		}

		
		BalanceOfClient2 = Client2.AccountBalance;
		_PrintClientCard(Client2);


		CurrentScreen.Print("Enter Amount To Transfer : ");
		string mesege = "Enter Amount To Transfer [0:" + to_string(Client1.AccountBalance) + "] : ";
		double Amount = clsInputValidate::ReadDblNumberBetween(0, Client1.AccountBalance, mesege);

		CurrentScreen.AlignWithOffset();
		printf("Are you sure to transfer %.2f ", Amount);
		cout << "from " << Client1.AccountNumber << " to " << Client2.AccountNumber << " ? [Y/N] : ";

		if (clsInputValidate::CheckYesOrNo(clsInputValidate::ReadString()))
		{
			
			_Header();
			if (Client1.Transfer(Amount, Client2))
			{
				clsScreen::ColorSuccessfulOperation();
				clsScreen::ColorSuccessfulOperation();

				CurrentScreen.Print("Transfer Done Successfully\n");
			}

			else
			{	
				
				clsScreen::ColorFailedOperation();
				CurrentScreen.Print("Transfer Failed\n");
				Client1.AccountBalance = BalanceOfClient1;
				Client2.AccountBalance = BalanceOfClient2;
				Client1.Save();
				Client2.Save();

			}

		}
		else
		{
			_Header();
			clsScreen::ColorFailedOperation();
			CurrentScreen.Print("Transfer Cancelled\n");

		}

		
		_PrintClientCard(Client1);
		_PrintClientCard(Client2);
		CurrentScreen.DrawScreenLine();
	}
};

