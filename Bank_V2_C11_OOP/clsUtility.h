#pragma once
#include <iostream>
#include "clsDate.h"
using namespace std;
class clsUtility
{
public:

	static void Srand()
	{
		srand((unsigned)time(NULL));
	}
	static int RandomNumber(int From, int To)
	{


		//Function to generate a random number
		int randNum = rand() % (To - From + 1) + From;
		return randNum;
	}
	static enum enCharType
	{
		SamallLetter = 1, CapitalLetter = 2,
		SpecialCharacter = 3, Digit = 4
	};
	

	static char GetRandomCharacter(enCharType CharType)
	{
		switch (CharType)
		{
		case enCharType::SamallLetter:
		{
			return char(RandomNumber(97, 122));
			break;
		}
		case enCharType::CapitalLetter:
		{
			return char(RandomNumber(65, 90));
			break;
		}
		case enCharType::SpecialCharacter:
		{
			return char(RandomNumber(33, 47));
			break;
		}
		case enCharType::Digit:
		{
			return char(RandomNumber(48, 57));
			break;
		}
		}
	}
	static string GenerateWord(enCharType CharType, short Length)
	{
		string Word;
		for (int i = 1; i <= Length; i++)
		{
			Word = Word + GetRandomCharacter(CharType);
		}
		return Word;
	}
	static string GenerateKey()
	{
		string Key = "";
		Key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
		Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
		Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
		Key = Key + GenerateWord(enCharType::CapitalLetter, 4);
		return Key;
	}

	static void GenerateKeys(short NumberOfKeys)
	{
		for (int i = 1; i <= NumberOfKeys; i++)
		{
			cout << "Key [" << i << "] : ";
			cout << GenerateKey() << endl;
		}
	}

	static void FillArrayWithKeys(string arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = GenerateKey();
	}
	static void Swap(short& A, short& B)
	{
		short Temp = A;
		A = B;
		B = Temp;
	}
	static void Swap(string& A, string& B)
	{
		string Temp = A;
		A = B;
		B = Temp;
	}
	static void Swap(double& A, double& B)
	{
		double Temp = A;
		A = B;
		B = Temp;
	}
	static void Swap(int& A, int& B)
	{
		int Temp = A;
		A = B;
		B = Temp;
	}

	static void Swap(char& A, char& B)
	{
		char Temp = A;
		A = B;
		B = Temp;
	}
	static void  Swap(clsDate& Date1, clsDate& Date2)
	{

		clsDate TempDate;
		TempDate = Date1;
		Date1 = Date2;
		Date2 = TempDate;

	}
	static void ShuffleArray(int arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1],
				arr[RandomNumber(1, arrLength) - 1]);
		}
	}

	static void FillArrayWithRandomNumbers(int arr[100], int arrLength, int RandomFrom, int RandomTo)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = RandomNumber(RandomFrom, RandomTo);
	}
	static void FillArrayWithRandemWords(string arr[100], int arrLength, enCharType CharType, short stringLength)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = GenerateWord(CharType, stringLength);
	}

};

