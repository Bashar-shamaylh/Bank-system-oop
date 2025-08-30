#pragma once
#include <iostream>
#include "clsUtility.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include"clsListClientScreen.h"
#include "clsAddNewScreen.h"
#include"clsDeleteUserScreen.h"
#include "clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionsScreen.h"
#include "clsManageUserScreen.h"
#include "Global.h"
using namespace std;
class clsMainScreen :protected clsScreen
{
public:
	static void ShowMainMenu()
	{
		system("cls");
		_DrawScreenHeader("Main Screen");
		
		clsUtility::PrintSpaces(37); cout << "==================================================================" << endl;
		clsUtility::PrintTaps(5); clsUtility::PrintSpaces(26); cout << "Main Screen" << endl;
		clsUtility::PrintSpaces(37); cout << "==================================================================" << endl;

		clsUtility::PrintTaps(5); cout << "[1] Show Client List." << endl;
		clsUtility::PrintTaps(5); cout << "[2] Add New Client." << endl;
		clsUtility::PrintTaps(5); cout << "[3] Delete Client." << endl;
		clsUtility::PrintTaps(5); cout << "[4] Update Client Info." << endl;
		clsUtility::PrintTaps(5); cout << "[5] Find Client." << endl;
		clsUtility::PrintTaps(5); cout << "[6] Transactions." << endl;
		clsUtility::PrintTaps(5); cout << "[7] Manege Users." << endl;
		clsUtility::PrintTaps(5); cout << "[8] Logout." << endl;
		clsUtility::PrintSpaces(37); cout << "==================================================================" << endl;
		_PerformMainMenuOption(enMainMenuOption (_ReadUserInput()));
	}
private:
	enum enMainMenuOption{eListClientsi=1,eAddNewClient=2,eDelteClient=3
		,eUpdateClient=4,eFindClient=5,eTransactions=6,eMangeUsers=7,eLogout=8};
	static short _ReadUserInput()
	{
		clsUtility::PrintTaps(5); cout << "Choose What do you want to do from [1] to [8]. ";
		return clsInputValidate::ReadIntNumberBetween(1, 8);
	}
	static void _GoBackToMainMenu()
	{
		cout << "Press any key to go back to the main menu screen..." << endl;
		system("pause>0");
		ShowMainMenu();
	}
	static void _ShowClientList()
	{
		system("cls");
		clsListClientScreen::ShowClientsList();
	}
	static void _AddNewClient()
	{
		system("cls");
		clsAddNewScreen::showAddNewClientScreen();
	}
	static void _DeleteClient()
	{
		system("cls");
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}
	static void _UpdateClientInfo()
	{
		system("cls");
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}
	static void _FindClient()
	{
		system("cls");
		clsFindClientScreen::ShowFindClientScreen();
	}
	static void _Transactions()
	{
		system("cls");
		clsTransactionsScreen::ShowTransactionMenue();
	}
	static void _ManegeUsers()
	{
		system("cls");
		clsManageUserScreen::ShowManageUserScreen();
	}


	static void _PerformMainMenuOption(enMainMenuOption option)
	{
		switch (option)
		{
		case clsMainScreen::eListClientsi:
			system("cls");
			_ShowClientList();
			_GoBackToMainMenu();
			break;
		case clsMainScreen::eAddNewClient:
			system("cls");
			_AddNewClient();
			_GoBackToMainMenu();
			break;
		case clsMainScreen::eDelteClient:
			system("cls");
			_DeleteClient();
			_GoBackToMainMenu();
			break;
		case clsMainScreen::eUpdateClient:
			system("cls");
			_UpdateClientInfo();
			_GoBackToMainMenu();
			break;
		case clsMainScreen::eFindClient:
			system("cls");
			_FindClient();
			_GoBackToMainMenu();
			break;
		case clsMainScreen::eTransactions:
			system("cls");
			_Transactions();
			_GoBackToMainMenu();
			break;
		case clsMainScreen::eMangeUsers:
			system("cls");
			_ManegeUsers();
			_GoBackToMainMenu();
			break;
		case clsMainScreen::eLogout:
			system("cls");
			CurrentUser = clsUser::Find("", "");
			cout << "thank you for using our bank,you have logout." << endl;
			break;
		default:
			break;
		}
		
	}
};

