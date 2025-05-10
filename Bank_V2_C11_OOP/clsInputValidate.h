//ProgrammingAdivces.com
//Mohammed Abu-Hadhoud

#pragma once
#include <iostream>
#include <string>
#include "clsString.h"
#include "clsDate.h"
#include "clsScreen.h"
#include <iomanip>

class clsInputValidate
{

public:

	static bool IsNumberBetween(short Number, short From, short To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	static bool IsNumberBetween(int Number, int From, int To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;

	}

	static bool CheckYesOrNo(string input)
	{

		clsString Temp;
		Temp.Value = input;
		Temp.LowerAllString();
		input = Temp.Value;

		if (input == "y" || input == "ye" || input == "yes" || input == "yess" || input == "t" || input == "tru" || input == "true" || input == "1")
			return true;

		return false;


	}

	static bool IsNumberBetween(double Number, double From, double To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
	{
		//Date>=From && Date<=To
		if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
			&&
			(clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
			)
		{
			return true;
		}

		//Date>=To && Date<=From
		if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
			&&
			(clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
			)
		{
			return true;
		}

		return false;
	}


	static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter again : ")
	{

		string input = "";
		getline(cin >> ws, input);
		while (!clsString::IsValidNumber(input) || input.length() > 10)
		{

			CurrentScreen.AlignWithOffset(1);

			if (input.length() > 10)
			{
				clsErrors::SaveTheErrorInTheFile("The value is very large ");
				cout << "The value is very large \n";
			}

			CurrentScreen.AlignWithOffset(1);
			cout << ErrorMessage;
			getline(cin >> ws, input);

		}

		int number = round(stod(input));

		return number;
	}

	static int ReadIntNumberBetween(int From, int To,string ErrorMessage = "Number is not within range, Enter again:")
	{
		int Number = ReadIntNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			CurrentScreen.AlignWithOffset(1);
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}
		return Number;
	}



	static short CountIntPart(string S)
	{
		short countIntPart = S.length();
		if (S.find('.') < S.length())
			countIntPart = S.find('.');
		return countIntPart;
	}
	static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter again : ")
	{


		string input = "";
		getline(cin >> ws, input);



		while (!clsString::IsValidNumber(input) || CountIntPart(input) > 15)
		{
			CurrentScreen.AlignWithOffset(1);

			if (CountIntPart(input) > 15)
			{
				clsErrors::SaveTheErrorInTheFile("The value is very large ");
				cout << "The value is very large \n";
			}

			CurrentScreen.AlignWithOffset(1);
			cout << ErrorMessage;

			getline(cin >> ws, input);

		}

		double number = stod(input);

		return number;
	}
	static double ReadPositiveDblNumber(string ErrorMessage = "Enter Positive Number : ")
	{
		double num = ReadDblNumber();
		while (num<=0)
		{
			CurrentScreen.Print(ErrorMessage);
			num = ReadDblNumber();
		}
		return num;
	}

	static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Enter Number between %.2f to %.2f : ")
	{
		
		double Number = ReadDblNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			CurrentScreen.AlignWithOffset(1);
			//cout << ErrorMessage;
			if (ErrorMessage == "Enter Number between %.2f to %.2f : ")
			{
				printf("Enter Number between %.2f to %.2f : ", From, To);
			}
			else
			{
				cout << ErrorMessage;
			}
			
			Number = ReadDblNumber();
		}
		return Number;
	}

	static bool IsValideDate(clsDate Date)
	{
		return	clsDate::IsValidDate(Date);
	}

	static string ReadString()
	{
		cin.clear();
		string  S1 = "";
		// Usage of std::ws will extract allthe whitespace character
		getline(cin >> ws, S1);
		return S1;
	}
};

