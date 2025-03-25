#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>
using namespace std;
void ReadClientInfo(clsBankClient & Client)
{
	cout << "First Name: ";
	Client.FirstName = clsInputValidate::ReadString();

	cout << "Last Name : ";
	Client.LastName = clsInputValidate::ReadString();

	cout << "Phone     : " ;
	Client.Phone = clsInputValidate::ReadString();

	cout << "Email     : ";
	Client.Email = clsInputValidate::ReadString();

	cout << "Password  : " ;
	Client.PinCode = clsInputValidate::ReadString();

	cout << "Balance   : " ;
	Client.AccountBalance = clsInputValidate::ReadFloatNumber();

}
void Update()
{
	cout << "Enter Account Namber : ";
	string AccountNamber = clsInputValidate::ReadString();
	while (!clsBankClient::IsExist(AccountNamber))
	{
		cout << "Not Found Enter Account Namber : ";
		AccountNamber = clsInputValidate::ReadString();
	}
	clsBankClient Client = clsBankClient::Find(AccountNamber);

	Client.Print();
	ReadClientInfo(Client);
	
	switch (Client.Save())
	{
	case clsBankClient::enSave::enNotSavedIsEmpty:
		cout << "Not Saved\n";
		break;

	case clsBankClient::enSave::enSavedSuccessfully:
		cout<<"\nSavedSuccessfully\n";
		Client.Print();
		break;
	}
	
}
void AddNew()
{
	cout << "Enter Account Number : ";
	string AccountNumber = clsInputValidate::ReadString();
	while (clsBankClient::IsExist(AccountNumber))
	{
		cout << "Account Number is Exist Enter Account Number : ";
		AccountNumber = clsInputValidate::ReadString();
	}
	clsBankClient NewClient = clsBankClient::GetNewClient(AccountNumber);
	ReadClientInfo(NewClient);
	switch (NewClient.Save())
	{
	case clsBankClient::enSave::enNotSavedIsEmpty:
		cout << "Not Saved\n";
		break;

	case clsBankClient::enSave::enSavedSuccessfully:
		cout << "\nSavedSuccessfully\n";
		NewClient.Print();
		break;

	case clsBankClient::enSave::enNotSavedAccountIsExist:
		cout << "Not Saved Account Is Exist\n";
		break;
	}

}

void Delete()
{
	
	cout << "Enter Account Namber : ";
	string AccountNamber = clsInputValidate::ReadString();
	while (!clsBankClient::IsExist(AccountNamber))
	{
		cout << "Not Found Enter Account Namber : ";
		AccountNamber = clsInputValidate::ReadString();
	}
	clsBankClient Client = clsBankClient::Find(AccountNamber);

	Client.Print();
	cout << "You nead Delete this client Y/N ? ";
	string YesOrNo = clsInputValidate::ReadString();
	YesOrNo = clsString::LowerAllString(YesOrNo);
	bool chack = (YesOrNo == "y" || YesOrNo == "yes");
	switch (chack)
	{
	case true:
	{
		bool isDeleted=Client.Delete();
		if (isDeleted)
		{
			cout << "\nDeleted Successfully\n";
			Client.Print();
			break;
		}
		else
			cout << "Not Deleted\n";
	}
	case false:
		cout << "Not Deleted\n";
		break;

	}

}
void PrintCLientRecordLine(clsBankClient & Client)
{
	cout << "| " << setw(15) << left << Client.AccountNumber;
	cout << "| " << setw(20) << left << Client.FullName();
	cout << "| " << setw(12) << left << Client.Phone;
	cout << "| " << setw(20) << left << Client.Email;
	cout << "| " << setw(10) << left << Client.PinCode;
	cout << "| " << setw(12) << left <<Client.AccountBalance << "|\n";
}
void PrintClientList()
{
	vector <clsBankClient> vClients = clsBankClient::GetClientsList();
	cout << "\n------------------------------------------------------------------------------------------------------";

	string stringNumOfClient = "("+ to_string( vClients.size());
	stringNumOfClient+= ")";

	cout << "\n|" << setw(52) << right << "Client List"<<left<<setw(5)<< stringNumOfClient <<setw(45) << right<<"| ";
	cout << "\n------------------------------------------------------------------------------------------------------\n";

	cout << "| " << setw(15) <<left << "Account Namber";
	cout << "| " << setw(20) <<left << "Client Name";
	cout << "| " << setw(12) <<left << "Phone";
	cout << "| " << setw(20) <<left << "Email";
	cout << "| " << setw(10) <<left << "Pin Code";
	cout << "| " << setw(12) <<left << "Balance"<<"|";
	cout << "\n------------------------------------------------------------------------------------------------------\n";
	if (vClients.size() ==0)
	{
		cout << "|"<<setw(52)<<right<<"No Clients"<<setw(51)<<"| \n";
	}
	else
	{
		for (clsBankClient Client : vClients)
		{
			PrintCLientRecordLine(Client);
		}
	}

	cout << "------------------------------------------------------------------------------------------------------\n";

}