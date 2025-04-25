#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsClientInfoScreen.h"
#include "clsGeneralFindClient.h"

class clsFindClientScreen:protected clsGeneralFindClient
{
	
	static void _GetScreenSettings()
	{
		CurrentScreen.Offset = 0;
	}
	static void _Header(string Header)
	{
		CurrentScreen.AlignWithOffset();
		CurrentScreen.DrawScreenHeader(Header);
	}
	static  void _ClearScreenAndPrintHeader(string Header)
	{
		system("cls");
		_Header(Header);

	}

public:
	static bool FindClientScreen()
	{
		_GetScreenSettings();
		string Header = "                        Find Client Screen";
		//_ClearScreenAndPrintHeader(Header);
		clsBankClient Client = clsGeneralFindClient::GeneralFindUser(Header, true);

		
		if (Client.IsExist())
		{

			return true;
		}
		CurrentScreen.DrawScreenLine();
		return false;
	}
};

