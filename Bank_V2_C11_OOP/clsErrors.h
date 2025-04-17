#pragma once
#include <fstream>

using namespace std;
class clsErrors
{
	static struct _strDate
	{
		short Day = 1;
		short Month = 1;
		short Year = 1900;
		short Hour = 0;
		short Minute = 0;
		short Second = 0;
	};

	static string _DateToString(_strDate Date)
	{
		if (Date.Hour == 0 && Date.Minute == 0 && Date.Second == 0)
			return  to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
		else
		{
			return  to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year) + "|" + to_string(Date.Hour) + ":" + to_string(Date.Minute) + ":" + to_string(Date.Second);
		}
	}
	
	static _strDate _GetCompleteSystemDate()
	{
		//system date
		time_t t = time(0);
		tm now;
		localtime_s(&now, &t);

		_strDate Date;
		Date.Year = now.tm_year + 1900;
		Date.Month = now.tm_mon + 1;
		Date.Day = now.tm_mday;
		Date.Hour = now.tm_hour;
		Date.Minute = now.tm_min;
		Date.Second = now.tm_sec;

		return Date;
	}
public:
	static void SaveTheErrorInTheFile(string Error)
	{
		fstream ErrorFile;
		ErrorFile.open("ErrorFile.log", ios::out | ios::app);
		if (ErrorFile.is_open())
		{
			string OutError = "[" + _DateToString(_GetCompleteSystemDate()) + "] ";
			OutError += Error;
			ErrorFile << OutError << endl;
			ErrorFile.close();
		}

	}
};

