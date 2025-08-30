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
		SaveLoginData();
		clsMainScreen::ShowMainMenu();
		return true;
	}
	static void SaveLoginData()
	{
		string date = clsDate::fromDateToString(clsDate::GetCurrentDate());
		string time = clsUtility::CurrentTime();
		string LoginRecord = CreateLoginRecord(date, time, CurrentUser.UserName, CurrentUser.Password, CurrentUser.Permissions);
		fstream myfile;
		myfile.open("Logs.txt", ios::out | ios::app);
		if (myfile.is_open())
		{
			myfile << LoginRecord;
			myfile << endl;
			myfile.close();
		}
	}
	static string CreateLoginRecord(string date, string time, string username, string password, int permissions, string seprator = "/##/")
	{
		return date + "-" + time + seprator + username + seprator + password + seprator + to_string(permissions);
	}
public:
	static	bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("Login Screen");
		return _Login();
	}


};

