#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include "clsDate.h"
#include "clsErrors.h"
#include "clsUtil.h"
#include <filesystem>

using namespace std;

class clsBankClient :public clsPerson
{
private:
	string _AccountNumber;
	double _AccountBalance;
	string _PinCode;

	bool _MarkForDelete = false;
public:
	static string ClientPath()
	{
		 
		 return "Clients.txt";
		
	}

	

	static enum enMode
	{
		enEmptyMode = 0, enUpdateMode = 1, enAddNew = 2
	};

private:
	enMode _Mode;

	static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
	{
		vector<string> vClientData;
		vClientData = clsString::Split(Line, Seperator);
		int x = vClientData.size();
		if (vClientData.size() > 6)
		{
			return clsBankClient(enMode::enUpdateMode, vClientData[0], vClientData[1], vClientData[2],
				vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
		}

		else
		{
			return clsBankClient::_GetEmptyClient();
		}

	}
	static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
	{

		string stClientRecord = "";
		stClientRecord += Client.FirstName + Seperator;
		stClientRecord += Client.LastName + Seperator;
		stClientRecord += Client.Email + Seperator;
		stClientRecord += Client.Phone + Seperator;
		stClientRecord += Client.AccountNumber + Seperator;
		stClientRecord += Client.PinCode + Seperator;
		stClientRecord += to_string(Client.AccountBalance);

		return stClientRecord;

	}
	static clsBankClient _GetEmptyClient()
	{
		return clsBankClient(enMode::enEmptyMode, "", "", "", "", "", "", 0);
	}

	static  vector <clsBankClient> _LoadClientsDataFromFile()
	{
		vector<clsBankClient> vClients;
		fstream ClientsFile;
		string pathTheFile = ClientPath();
		ClientsFile.open(pathTheFile, ios::in);
		if (ClientsFile.is_open())
		{
			string line;
			clsBankClient Client = clsBankClient::_GetEmptyClient();
			short i = 0;
			while (getline(ClientsFile, line))
			{
				line = clsUtil::DecryptText(line);
				
				Client = _ConvertLinetoClientObject(line);
				
				i++;
				if (Client.IsExist())
				{
					vClients.push_back(Client);
				}
				else {
					string error = "Not Load a client :" + pathTheFile + "[" + to_string(i);
					error += "]: " + line;

					clsErrors::SaveTheErrorInTheFile(error);
				}

			
			}
		}
		else
		{
			clsErrors::SaveTheErrorInTheFile("Can not open "+ ClientPath());
		}
		ClientsFile.close();

		return vClients;
	}
	static void _SaveCleintsDataToFile(vector <clsBankClient> vClients)
	{

		fstream MyFile;

		remove(ClientPath().c_str());//////////

		MyFile.open(ClientPath(), ios::out);

		string DataLine;



		if (MyFile.is_open())
		{
			for (clsBankClient C : vClients)
			{
				if (C._MarkForDelete == false)
				{
					DataLine = _ConverClientObjectToLine(C);

					MyFile << clsUtil::EncryptText(DataLine) << endl;
				}
			
					

			}

			MyFile.close();

		}
		else
		{
			clsErrors errore;
			errore.SaveTheErrorInTheFile("Can not open file " + ClientPath());
		}

	}
	void _Update()
	{
		vector <clsBankClient>vClient = _LoadClientsDataFromFile();
		for (clsBankClient& C : vClient)
		{
			if (C.AccountNumber == AccountNumber)
			{
			
				C = *this;
				break;
			}
		}
		_SaveCleintsDataToFile(vClient);
	}
	bool _SaveLineClientInFile(string Line)
	{
		fstream ClientFile;
		ClientFile.open(ClientPath(), ios::out | ios::app);
		if (ClientFile.is_open())
		{
			clsBankClient Client = clsBankClient::_ConvertLinetoClientObject(Line);
			if (Client._MarkForDelete == false)
			{
				ClientFile << clsUtil::EncryptText(Line) << endl;
				return true;
			}
		}
		ClientFile.close();
		return false;
	}
	void _AddNew()
	{
		string ClientLine = _ConverClientObjectToLine(*this);
		_SaveLineClientInFile(ClientLine);
	}

public:


	enMode GetMode()
	{
		return _Mode;
	}
	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone
		, string AccountNamber, string PINCode, double AccountBalance)
		:clsPerson(FirstName, LastName, Email, Phone)
	{
		this->_AccountNumber = AccountNamber;
		this->_PinCode = PINCode;
		this->_AccountBalance = AccountBalance;
		this->_Mode = Mode;
	}
	string GetAccountNumber()
	{
		return _AccountNumber;
	}
	__declspec(property(get = GetAccountNumber))string AccountNumber;

	void  SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}
	string GetPinCode()
	{
		return _PinCode;
	}
	__declspec(property(put = SetPinCode, get = GetPinCode))string PinCode;

	void SetAccountBalance(double AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}
	double GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(put = SetAccountBalance, get = GetAccountBalance)) double AccountBalance;

	static bool IsEmpty(clsBankClient BankClient)
	{
		return BankClient._Mode == enMode::enEmptyMode;
	}
	bool IsEmpty()
	{
		return IsEmpty(*this);
	}



	static bool IsExist(string AccountNumber)
	{

		clsBankClient Client = Find(AccountNumber);
		return Client._Mode != enMode::enEmptyMode;
	}
	bool IsExist()
	{
		return (_Mode != enMode::enEmptyMode);
	}
	static clsBankClient Find(string AccountNumber)
	{
		vector <clsBankClient> vClients = _LoadClientsDataFromFile();
		for (clsBankClient& C : vClients)
		{
			if (C.AccountNumber == AccountNumber)
				return C;
		}

		return  clsBankClient::_GetEmptyClient();
	}
	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		vector <clsBankClient> vClients = _LoadClientsDataFromFile();
		for (clsBankClient& C : vClients)
		{
			if (C.AccountNumber == AccountNumber && C.PinCode == PinCode)
				return C;
		}

		return clsBankClient::_GetEmptyClient();
	}
	enum enSave { enNotSavedIsEmpty, enSavedSuccessfully, enNotSavedAccountIsExist, enNotHasUserName };
	enSave Save()
	{
		switch (_Mode)
		{
		case clsBankClient::enMode::enEmptyMode:
			clsErrors::SaveTheErrorInTheFile("Not Saved Is Empty");
			return enSave::enNotSavedIsEmpty;
			break;


		case clsBankClient::enMode::enUpdateMode:
			_Update();
			return enSave::enSavedSuccessfully;
			break;

		case clsBankClient::enMode::enAddNew:
		{
			if (clsBankClient::IsExist(this->AccountNumber))
			{
				clsErrors::SaveTheErrorInTheFile("Not Saved Account Is Exist");
				return enSave::enNotSavedAccountIsExist;

			}
			else if (clsBankClient::AccountNumber == "")
			{
				clsErrors::SaveTheErrorInTheFile("Not Has Account Number");
				return enSave::enNotHasUserName;
			}
			else
			{
				_AddNew();
				return enSave::enSavedSuccessfully;

			}
		}

		}
	}
	static clsBankClient GetNewClient(string AccountNamber)
	{
		return clsBankClient(enMode::enAddNew, "", "", "", "", AccountNamber, "", 0);
	}
	bool Delete()
	{
		vector <clsBankClient> vClients = _LoadClientsDataFromFile();
		for (clsBankClient& Client : vClients)
		{
			if (Client.AccountNumber == this->AccountNumber)
			{
				Client._MarkForDelete = true;
				break;
			}
		}
		_SaveCleintsDataToFile(vClients);
		clsBankClient client = Find(this->AccountNumber);
		 if (!client.IsExist())
		*this = _GetEmptyClient();
		return true;
	}
	static vector <clsBankClient> GetClientsList()
	{
		return _LoadClientsDataFromFile();
	}

	bool Transfer(double Amount, clsBankClient& DestinationClient)
	{

		bool CanTransfer = (this->AccountNumber != DestinationClient.AccountNumber)
			&& Amount > 0 && (this->AccountBalance > 0)
			&& (this->AccountBalance >= Amount);

		if (CanTransfer == false)
		{
			return false;
		}

		this->AccountBalance -= Amount;
		DestinationClient.AccountBalance += Amount;
		this->Save();
		DestinationClient.Save();
		SaveTransferLog(*this, DestinationClient, CurrentUser.UserName, Amount);
		return true;



	}
	struct stTransferLog
	{
		string transferDateAndTime;
		string fromAccountNumber;
		string toAccountNumber;	
		string UserName;
		double amount;
		double fromAccountBalanceAfterTheTransfer;
		double toAccountBalanceTransfer;
		bool Fail = false;

	}; 

	static stTransferLog GetTransferLog(clsBankClient& FromClient, clsBankClient& ToClient,string UserName, double Amount)
	{
		stTransferLog TransferLog;
		TransferLog.transferDateAndTime = clsDate::DateToString(clsDate::GetCompleteSystemDate());
		TransferLog.fromAccountNumber = FromClient.AccountNumber;
		TransferLog.toAccountNumber = ToClient.AccountNumber;
		TransferLog.amount = Amount;
		TransferLog.fromAccountBalanceAfterTheTransfer = FromClient.AccountBalance;
		TransferLog.toAccountBalanceTransfer = ToClient.AccountBalance;
		TransferLog.UserName = UserName;
		return TransferLog;
	}
	static string GetTransferLogAsString(stTransferLog TransferLog, string seperator = "#//#")
	{
		string TransferLogAsString = "";
		TransferLogAsString += TransferLog.transferDateAndTime + seperator;
		TransferLogAsString += TransferLog.fromAccountNumber + seperator;
		TransferLogAsString += TransferLog.toAccountNumber + seperator;
		TransferLogAsString += to_string(TransferLog.amount) + seperator;
		TransferLogAsString += to_string(TransferLog.fromAccountBalanceAfterTheTransfer) + seperator;
		TransferLogAsString += to_string(TransferLog.toAccountBalanceTransfer) + seperator;
		TransferLogAsString += TransferLog.UserName;


		return TransferLogAsString;
	}
	static void SaveTransferLog(stTransferLog TransferLog)
	{
		fstream TransferLogFile;
		TransferLogFile.open("TransferLog.txt", ios::out | ios::app);
		if (TransferLogFile.is_open())
		{
			string TransferLogAsString = GetTransferLogAsString(TransferLog);
			TransferLogFile <<clsUtil::EncryptText(TransferLogAsString) << endl;

			TransferLogFile.close();
		}
		else
		{
			clsErrors::SaveTheErrorInTheFile("Can not open TransferLog.txt");
		}
	}
	static void SaveTransferLog(clsBankClient& FromClient, clsBankClient& ToClient,string UserName, double Amount)
	{
		stTransferLog TransferLog = GetTransferLog(FromClient, ToClient, UserName, Amount);
		SaveTransferLog(TransferLog);
		
	}
	static stTransferLog GetTransferLogFromString(string TransferLogAsString, string seperator = "#//#")
	{
		vector<string> vTransferLogData;
		vTransferLogData = clsString::Split(TransferLogAsString, seperator);
		stTransferLog TransferLog;
		if (vTransferLogData.size() > 6)
		{
			TransferLog.transferDateAndTime = vTransferLogData[0];
			TransferLog.fromAccountNumber = vTransferLogData[1];
			TransferLog.toAccountNumber = vTransferLogData[2];
			TransferLog.amount = stod(vTransferLogData[3]);
			TransferLog.fromAccountBalanceAfterTheTransfer = stod(vTransferLogData[4]);
			TransferLog.toAccountBalanceTransfer = stod(vTransferLogData[5]);
			TransferLog.UserName = vTransferLogData[6];
		}
		else
		{
			TransferLog.Fail = true;
			string error = "Not Load a Transfer Log : " + TransferLogAsString;
			clsErrors::SaveTheErrorInTheFile(error);
		}
		return TransferLog;
	}
	static vector<stTransferLog> GetTransferLogList(string seperator = "#//#")
	{
		vector <stTransferLog> vTransferLog;
		stTransferLog tempTransferLog;

		fstream TransferLogFile;
		string pathTheFile = "TransferLog.txt";
		TransferLogFile.open(pathTheFile, ios::in);
		if (TransferLogFile.is_open())
		{
			string line;
			stTransferLog TransferLog;
		
			while (getline(TransferLogFile, line))
			{
				line = clsUtil::DecryptText(line);
				tempTransferLog = GetTransferLogFromString(line, seperator);
				if (tempTransferLog.Fail == false)
				{
					vTransferLog.push_back(tempTransferLog);
				}
				
			}
			TransferLogFile.close();
		}
		else
		{
			clsErrors::SaveTheErrorInTheFile("Can not open "+pathTheFile);
		}

		return vTransferLog;

	}
};


