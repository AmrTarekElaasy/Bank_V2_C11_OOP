#pragma once
class clsTransferLogScreen
{
private:
	static void _ScreenSettings()
	{
		clsScreen::ColorAllProgram();
		system("cls");

		CurrentScreen.Offset = -32;
	}
	static void _DrawScreenLine()
	{
		CurrentScreen.Print(" ________________________________________________________________________________________________________________________________________________\n");
	}
	static void _PrintRecord(clsBankClient::stTransferLog& Record)
	{
		CurrentScreen.AlignWithOffset();
		cout << " " << setw(21) << left << Record.transferDateAndTime << " |";
		if(Record.SuccessfulOperation)
			cout << setw(16) << left << "Successful"<< " |";
		else
			cout << setw(16) << left << "Failed" << " |";

		cout << setw(19) << left << Record.fromAccountNumber << " |";
		cout << setw(17) << left << Record.toAccountNumber << " |";
		cout << setw(10) << left << Record.amount << " |";
		cout << setw(20) << left << Record.fromAccountBalanceAfterTheTransfer << " |";
		cout << setw(18) << left << Record.toAccountBalanceTransfer << " |";
		cout << setw(5) << left << Record.UserName << "\n";
	}

public:
	static void ShowTransferLogScreen()
	{
		_ScreenSettings();
		vector<clsBankClient::stTransferLog> vTransferLog = clsBankClient::GetTransferLogList();
		string subTitel = "                       (" + to_string(vTransferLog.size()) + ")Record(s).";
		CurrentScreen.DrawScreenHeader("                      Transfer Log Screen", subTitel);

		_DrawScreenLine();
		cout << "\n";
		CurrentScreen.AlignWithOffset();
		cout << " " << setw(21) << left << "Date And Time" << " |";
		cout << setw(16) << left << "Transfer Status" << " |";
		cout << setw(19) << left << "From Account Number" << " |";
		cout << setw(17) << left << "To Account Number" << " |";
		cout << setw(10) << left << "Amount" << " |";
		cout << setw(20) << left << "From Account Balance" << " |";
		cout << setw(18) << left << "To Account Balance" << " |";
		cout << setw(5) << left << "User Name\n";
		_DrawScreenLine();
		clsScreen::ColorSuccessfulOperation();

		for (clsBankClient::stTransferLog& Record : vTransferLog)
		{
			if(Record.SuccessfulOperation == false)
				clsScreen::SetColor(4);
			_PrintRecord(Record);
			clsScreen::SetColor(2);
		}
		_DrawScreenLine();
		CurrentScreen.DrawScreenLine();
	}
};

