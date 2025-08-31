#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"
class clsFindCarrency :protected clsScreen
{
	static void PrintCarrrencyCard(clsCurrency carrency)
	{
		cout << "-------------------------" << endl;
		cout << "Country :" << carrency.CountryName() << endl;
		cout << "Code :" << carrency.CureencyCode() << endl;
		cout << "Name :" << carrency.CurrencyName() << endl;
		cout << "Rate :" << carrency.CurrencyRate() << endl;
		cout << "-------------------------" << endl;
	}
public :
	static void ShowFindClientScreen()
	{
		_DrawScreenHeader("Find Client Screen");
		cout << "Find by : [1] Country Name or ,[2] Carrency Code : ";
		short answer = 1;
		answer = clsInputValidate::ReadIntNumberBetween(1, 2);
		if (answer == 1)
		{
			cout << "enter a country name";
			string countryName;
			cin >> countryName;
			clsCurrency currency = clsCurrency::FindByCountryName(countryName);
			if (currency.IsCurrencyEmpty())
			{
				cout << "Currency was not found !" << endl;
			}
			else
				PrintCarrrencyCard(currency);
		}
		else
		{
			cout << "Enter a Carrensy code ";
			string countryName;
			cin >> countryName;
			clsCurrency currency = clsCurrency::FindByCode(countryName);
			if (currency.IsCurrencyEmpty())
			{
				cout << "Currency was not found !" << endl;
			}
			else
				PrintCarrrencyCard(currency);
		}
	}
};

