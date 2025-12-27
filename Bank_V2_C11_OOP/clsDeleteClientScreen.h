
#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsClientInfoScreen.h"
#include "clsGeneralFindClient.h"

class clsDeleteClientScreen :protected clsGeneralFindClient
{

	static void _ScreenSettings()
	{
		
		CurrentScreen.Offset = 0;
	
	}
	static void _Header(string Header)
	{
		 _ScreenSettings();
		CurrentScreen.AlignWithOffset();
		CurrentScreen.DrawScreenHeader(Header);
	}
	static  void _ClearScreenAndPrintHeader(string Header)
	{
		system("cls");
		_Header(Header);

	}

public:
	static bool DeleteUserScreen()
	{
		_ScreenSettings();
		string Header = "                      Delete Client Screen";
		clsBankClient Client = clsGeneralFindClient::GeneralFindUser(Header, true);
		if (Client.IsExist())
		{
			CurrentScreen.AlignWithOffset();
			cout << "Are you sure you want to delete this client Y|N? ";

			switch (clsInputValidate::CheckYesOrNo(clsInputValidate::ReadString()))
			{

			case true:
				if (Client.Delete())
				{
					CurrentScreen.AlignWithOffset(1);
					if(!Client.IsExist())
						cout << "Deleted successfully\n";
					else
						cout<<"Deletion failed\n";

					clsClientInfoScreen::PrintUserInfo(Client);
					CurrentScreen.DrawScreenLine();
					return true;
				}
			default:
				
				_ClearScreenAndPrintHeader(Header);
				CurrentScreen.AlignWithOffset();
				cout << "Not deleted\n";
				break;
			}
			
		}

		cout << "\n";
		CurrentScreen.DrawScreenLine();
		return false;
	}
};

