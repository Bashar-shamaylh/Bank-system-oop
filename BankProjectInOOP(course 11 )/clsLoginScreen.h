#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "Global.h"
class clsLoginScreen :protected clsScreen
{
	static bool _Login()
	{
		string userName, Password;
		bool LoginFaild = false;
		short AllowedAttemps = 3;
		do
		{
			if (AllowedAttemps == 1)
			{
				cout << "Your system was Locked!" << endl;
				return false;
			}
			if (LoginFaild)
			{
				AllowedAttemps--;
				cout << "Invalid UserName/Passowrd! " << endl;
				cout << "You have only " << AllowedAttemps << " Trials to Login " << endl;

			}	
			cout << "Enter UserName : ";
			cin >> userName;
			cout << "Enter Password : ";
			cin >> Password;
			CurrentUser = clsUser::Find(userName, Password);
			LoginFaild = CurrentUser.IsUserEmpty();
		} while (LoginFaild);
		clsMainScreen::ShowMainMenu();
		return true;
	}
public:
	static	bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("Login Screen");
		return _Login();
	}


};

