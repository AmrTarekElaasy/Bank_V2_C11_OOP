#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsClientInfoScreen.h"
#include "clsGeneralFindClient.h"

class clsFindClientScreen:protected clsGeneralFindClient
{
	
	static void _ScreenSettings()
	{
		clsScreen::ColorAllProgram();

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
		_ScreenSettings();
		string Header = "                        Find Client Screen";
		//_ClearScreenAndPrintHeader(Header);
	
		clsBankClient Client = clsGeneralFindClient::GeneralFindUser(Header, true);

		
		if (Client.IsExist())
		{
			clsScreen::ColorSuccessfulOperation();
			return true;
		}
		clsScreen::ColorFailedOperation();

		CurrentScreen.DrawScreenLine();
		return false;
	}
};

