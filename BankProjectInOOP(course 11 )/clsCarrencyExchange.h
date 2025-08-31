#pragma once
#include <iostream>
#include "clsUtility.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "Global.h"
#include "clsListCarrenciesScreen.h"
#include "clsFindCarrency.h"
#include "clsUpdateCarrencyRateScreen.h"
class clsCarrencyExchange :protected clsScreen
{
public:
	static void ShowCarrencyExchangeScreen()
	{
		system("cls");
		_DrawScreenHeader("Carrency Echange Main Screen");

		clsUtility::PrintSpaces(37); cout << "==================================================================" << endl;
		clsUtility::PrintTaps(5); clsUtility::PrintSpaces(26); cout << "Carrency Exchange Menu" << endl;
		clsUtility::PrintSpaces(37); cout << "==================================================================" << endl;

		clsUtility::PrintTaps(5); cout << "[1] List Carrencies." << endl;
		clsUtility::PrintTaps(5); cout << "[2] Find Carrency." << endl;
		clsUtility::PrintTaps(5); cout << "[3] Update Carrency Rate." << endl;
		clsUtility::PrintTaps(5); cout << "[4] Carrency Calculator." << endl;
		clsUtility::PrintTaps(5); cout << "[5] Main Menu." << endl;
		clsUtility::PrintSpaces(37); cout << "==================================================================" << endl;
		_PerformCarrencyExchangeOption(enCarrencyOption(_ReadUserInput()));
	}
private:
	static short _ReadUserInput()
	{
		clsUtility::PrintTaps(5); cout << "Choose What do you want to do from [1] to [5]. ";
		return clsInputValidate::ReadIntNumberBetween(1, 9);
	}
	static void _GoBackToCarrencyScreen()
	{
		cout << "Press any key to go back to the Carrency menu screen..." << endl;
		system("pause>0");
		ShowCarrencyExchangeScreen();
	}
	static void _ListCarrencies()
	{
		//nothing here yet
		//cout << "comgin soon !" << endl;
		clsListCarrenciesScreen::ShowCarrencyList();
	}
	static void _FindCarrency()
	{
		//nothing here yet
		//cout << "comgin soon !" << endl;
		clsFindCarrency::ShowFindClientScreen();
	}
	static void _UpdateCarrency()
	{
		//nothing here yet
		//cout << "comgin soon !" << endl;
		//clsUpdateCarrencyRateScreen::ShowUpdateCarrencyRateScreen();
	}
	static void _CarrencyCalculator()
	{
		//nothing here yet
		cout << "comgin soon !" << endl;
	}

	enum enCarrencyOption {
		eListCarrencies=1,eFindCarrency=2,eUpdateCarrency=3,eCarrencyCalculator=4,eMainMenu=5
	};
	static void _PerformCarrencyExchangeOption(enCarrencyOption option)
	{
		switch(option) 
		{
		case enCarrencyOption::eListCarrencies:
			system("cls");
			_ListCarrencies();
			_GoBackToCarrencyScreen();
			break;
		case enCarrencyOption::eFindCarrency:
			system("cls");
			_FindCarrency();
			_GoBackToCarrencyScreen();
			break;
		case enCarrencyOption::eUpdateCarrency:
			system("cls");
			_UpdateCarrency();
			_GoBackToCarrencyScreen();
			break;
		case enCarrencyOption::eCarrencyCalculator:
			system("cls");
			_CarrencyCalculator();
			_GoBackToCarrencyScreen();
			break;
		case enCarrencyOption::eMainMenu:
			break;
		default :
			cout << "Plese enter Number between 1 to 5" << endl;
		}

		
	}
};

