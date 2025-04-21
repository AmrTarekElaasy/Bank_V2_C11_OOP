
#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsClientInfoScreen.h"
#include "clsGeneralFindClient.h"

class clsDeleteClientScreen :protected clsGeneralFindClient
{

	static clsScreen _GetScreenSettings()
	{
		clsScreen Screen;
		Screen.Offset = 0;
		return Screen;
	}
	static void _Header(string Header)
	{
		clsScreen Screen = _GetScreenSettings();
		Screen.AlignWithOffset();
		Screen.DrawScreenHeader(Header);
	}
	static  void _ClearScreenAndPrintHeader(string Header)
	{
		system("cls");
		_Header(Header);

	}

public:
	static bool DeleteUserScreen()
	{
		clsScreen Screen = _GetScreenSettings();
		string Header = "                      Delete Client Screen";
		clsBankClient Client = clsGeneralFindClient::GeneralFindUser(Header, Screen, true);
		if (Client.IsExist())
		{
			Screen.AlignWithOffset();
			cout << "Are you sure you want to delete this client Y|N? ";

			switch (clsInputValidate::CheckYesOrNo(clsInputValidate::ReadString()))
			{

			case true:
				if (Client.Delete())
				{
					Screen.AlignWithOffset(1);
					cout << "Deleted successfully\n";
					clsClientInfoScreen::PrintUserInfo(Client);
					Screen.DrawScreenLine();
					return true;
				}
			default:
				
				_ClearScreenAndPrintHeader(Header);
				Screen.AlignWithOffset();
				cout << "Not deleted\n";
				break;
			}
			
		}

		cout << "\n";
		Screen.DrawScreenLine();
		return false;
	}
};

