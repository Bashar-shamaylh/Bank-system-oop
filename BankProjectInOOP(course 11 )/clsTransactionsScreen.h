#pragma once
#include <iostream>
#include "clsUtility.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDeposite.h"
#include "clsWithdraw.h"
#include"clsTotalBlanacesScreen.h"
#include "clsTransfer.h"
#include "clsTransferLogScreen.h"
using namespace std;

class clsTransactionsScreen :protected clsScreen
{
public:
	static void ShowTransactionMenue()
	{
		if (!CheckAccsessRights(clsUser::enPermissions::pTranactions))
		{
			return;
		};
		system("cls");
		_DrawScreenHeader("Transaction Screen");

		clsUtility::PrintSpaces(37); cout << "==================================================================" << endl;
		clsUtility::PrintTaps(5); clsUtility::PrintSpaces(26); cout << "Transaction Screen" << endl;
		clsUtility::PrintSpaces(37); cout << "==================================================================" << endl;

		clsUtility::PrintTaps(5); cout << "[1] Deposite." << endl;
		clsUtility::PrintTaps(5); cout << "[2] Withdraw." << endl;
		clsUtility::PrintTaps(5); cout << "[3] Total Balances." << endl;
		clsUtility::PrintTaps(5); cout << "[4] Transfer ." << endl;
		clsUtility::PrintTaps(5); cout << "[5] Transfer Logs ." << endl;

		clsUtility::PrintTaps(5); cout << "[5] Main Menu." << endl;
	
		clsUtility::PrintSpaces(37); cout << "==================================================================" << endl;
		_PerformTransactionMenuOption(enTransactionMenuOption(_ReadUserInput()));
	}
private:
	enum enTransactionMenuOption {
		eDeposite=1,eWithdraw=2,eShowTotalBalance=3,eTransfer=4,eTransferRegesters=5,eLogout=6
	};
	static short _ReadUserInput()
	{
		clsUtility::PrintTaps(5); cout << "Choose What do you want to do from [1] to [6]. ";
		return clsInputValidate::ReadIntNumberBetween(1, 5);
	}
	static void _GoBackToTransactionMenu()
	{
		cout << "Press any key to go back to the Transaction menu screen..." << endl;
		system("pause>0");
		ShowTransactionMenue();
	}
	static void _Deposite()
	{
		system("cls");
		clsDeposite::ShowDepositeScreen();
		_GoBackToTransactionMenu();
	}
	static void _Withdraw()
	{
		system("cls");
		//cout << "this is the withdraw screen" << endl;
		clsWithdraw::ShowWithDrawScreen();
		_GoBackToTransactionMenu();
	}
	static void _ShowTotalBalances()
	{
		system("cls");
		clsTotalBlanacesScreen::ShowTotalBalances();
		_GoBackToTransactionMenu();
	}
	static void _ShowTransfer()
	{
		system("cls");
		clsTransfer::ShowTransferScreen();
		_GoBackToTransactionMenu();
	}
	static void _ShowTransferRegisters()
	{
		system("cls");
		clsTransferLogScreen::_ShowTranserLogsScreen();
		_GoBackToTransactionMenu();
	}

	static void _PerformTransactionMenuOption(enTransactionMenuOption option)
	{
		switch (option)
		{
		case clsTransactionsScreen::eDeposite:
			system("cls");
			_Deposite();
			_GoBackToTransactionMenu();
			break;
		case clsTransactionsScreen::eWithdraw:
			system("cls");
			_Withdraw();
			_GoBackToTransactionMenu();
			break;
		case clsTransactionsScreen::eShowTotalBalance:
			system("cls");
			_ShowTotalBalances();
			_GoBackToTransactionMenu();
			break;
		case clsTransactionsScreen::eTransfer:
			system("cls");
			_ShowTransfer();
			_GoBackToTransactionMenu();
			break;
		case clsTransactionsScreen::eTransferRegesters:
			system("cls");
			_ShowTransferRegisters();
			_GoBackToTransactionMenu();
			break;
		case clsTransactionsScreen::eLogout:	
			break;
		default:
			system("cls");
			cout << "Plese Chose a valid option,from [1] to [6] . . .";
			_GoBackToTransactionMenu();
			break;
		}
	}
};

