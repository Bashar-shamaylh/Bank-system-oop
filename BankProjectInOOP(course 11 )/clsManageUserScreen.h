#pragma once
#include "clsScreen.h"
#include "clsUtility.h"
#include "clsInputValidate.h"
#include "clsShowUsersListScreen.h"
#include "clsAddNewUser.h"
#include"clsDeleteUserScreen1.h"
#include "clsUpdateUserInfo.h"
#include "clsFindUserScreen.h"
class clsManageUserScreen :protected clsScreen
{
public :
	static void ShowManageUserScreen()
	{
		system("cls");
		if (!CheckAccsessRights(clsUser::enPermissions::pManageUsers))
		{
			return;
		}
		_DrawScreenHeader("Manage Users Screen");
		clsUtility::PrintSpaces(37); cout << "==================================================================" << endl;
		clsUtility::PrintTaps(5); clsUtility::PrintSpaces(26); cout << "Manage Users" << endl;
		clsUtility::PrintSpaces(37); cout << "==================================================================" << endl;

		clsUtility::PrintTaps(5); cout << "[1] Show Users List." << endl;
		clsUtility::PrintTaps(5); cout << "[2] Add New User." << endl;
		clsUtility::PrintTaps(5); cout << "[3] Delete User." << endl;
		clsUtility::PrintTaps(5); cout << "[4] Update User Info." << endl;
		clsUtility::PrintTaps(5); cout << "[5] Find User." << endl;
		clsUtility::PrintTaps(5); cout << "[6] Go Back to Main Screen." << endl;
		clsUtility::PrintSpaces(37); cout << "==================================================================" << endl;
		_PerformManageUserOption(enManageUserOption(_ReadUserInput()));
	}
	static enum enManageUserOption{enListUsers=1,enAddNewUser=2,enDeleteUser=3,enUpdateUser=4,enFindUser=5,enMainMenu=6};
private:
	static void _ShowUsersList()
	{
		system("cls");
		clsShowUsersListScreen::ShowUsersList();
	}
	static void _AddNewUser()
	{
		system("cls");
		clsAddNewUser::showAddNewUserScreen();
	}
	static void _DeleteUser()
	{
		system("cls");
		//cout << "Opps,nothing here yet!" << endl;
		clsDeleteUserScreen1::ShowDeleteUserScreen();
	}
	static void _UpdateUserInfo()
	{
		system("cls");
		//cout << "Opps,nothing here yet!" << endl;
		clsUpdateUserInfo::ShowUpdateUserScreen();
	}
	static void _FindUser()
	{
		system("cls");
		//cout << "Opps,nothing here yet!" << endl;
		clsFindUserScreen::ShowFindClientScreen();
	}
	
	static void _PerformManageUserOption(enManageUserOption option)
	{
		switch (option)
		{
		case clsManageUserScreen::enListUsers:
			system("cls");
			_ShowUsersList();
			_GoBackManageUsersScreen();
			break;
		case clsManageUserScreen::enAddNewUser:
			system("cls");
			_AddNewUser();

			_GoBackManageUsersScreen();
			break;
		case clsManageUserScreen::enDeleteUser:
			system("cls");
			_DeleteUser();
			_GoBackManageUsersScreen();
			break;
		case clsManageUserScreen::enUpdateUser:
			system("cls");
			_UpdateUserInfo();
			_GoBackManageUsersScreen();
			break;
		case clsManageUserScreen::enFindUser:
			system("cls");
			_FindUser();

			_GoBackManageUsersScreen();
			break;
		case clsManageUserScreen::enMainMenu:
			break;
		default:
			break;
		}
	}
	static short _ReadUserInput()
	{
		clsUtility::PrintTaps(5); cout << "Choose What do you want to do from [1] to [6]. ";
		return clsInputValidate::ReadIntNumberBetween(1, 6);
	}
	static void _GoBackManageUsersScreen()
	{
		cout << "Press any key to go back to the Manage Users screen..." << endl;
		system("pause>0");
		ShowManageUserScreen();
	}
};

