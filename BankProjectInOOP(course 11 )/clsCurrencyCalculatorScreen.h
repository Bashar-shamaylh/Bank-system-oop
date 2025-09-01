#pragma once
#include <iostream>
#include "clsUtility.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"
class clsCurrencyCalculatorScreen :protected clsScreen
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
	static clsCurrency ReadCurrencyCode(string message)
	{
		
			cout << message;
			string code = clsInputValidate::ReadString();
			clsCurrency currency= clsCurrency::FindByCode(code);

			while (currency.IsCurrencyEmpty())
			{
				cout << "Currency Code Was not Found ,Enter another one : ";
				string code = clsInputValidate::ReadString();
			    currency = clsCurrency::FindByCode(code);
			}
			return currency;
	}
	static clsCurrency::eCurrencyExchangeOperation DecideTheCurrencyOperation(clsCurrency currency1, clsCurrency currency2)
	{
		if (currency1.CureencyCode() == "USD")
			return clsCurrency::eCurrencyExchangeOperation::eFromUsdToCurrency;
		else if (currency2.CureencyCode() == "USD")
			return clsCurrency::eCurrencyExchangeOperation::eFromCurrencyToUsd;
		else
			return clsCurrency::eCurrencyExchangeOperation::eFromCurrencytoCurrency;
	}
	static float ExchangeCurrencyAmount(clsCurrency currency1, clsCurrency currency2, float amount)
	{
		clsCurrency UsdCurrency = clsCurrency::FindByCode("usd");
		clsCurrency::eCurrencyExchangeOperation operation = DecideTheCurrencyOperation(currency1, currency2);
		switch (operation)
		{
		case clsCurrency::eFromUsdToCurrency:
			PrintCarrrencyCard(currency2);
			return amount * currency2.CurrencyRate();
			break;
		case clsCurrency::eFromCurrencyToUsd:
			PrintCarrrencyCard(currency1);
			return amount / currency1.CurrencyRate();
			break;
		case clsCurrency::eFromCurrencytoCurrency:
			amount=ExchangeCurrencyAmount(currency1, UsdCurrency,amount);
			return ExchangeCurrencyAmount(UsdCurrency, currency2, amount);
			break;
		default:
			return 0;
			break;
		}
	}
public :
	static void ShowCalculatorScreen()
	{
		_DrawScreenHeader("Carrency Calculator");
		clsCurrency currency1 = ReadCurrencyCode("Plese enter currency1 code : ");
		clsCurrency currency2 = ReadCurrencyCode("Plese enter currency2 code : ");
		float amount,newAmount;
		cout << "Enter the amount : ";
		cin >> amount;
		newAmount = ExchangeCurrencyAmount(currency1, currency2, amount);
		cout << amount<<currency1.CureencyCode() <<" = "<< newAmount << currency2.CureencyCode()<<endl;
	}
};

//Read the first and second Carrency Code
//Decide the opration on to Trasfer the currencies
//perform the operation's and return the result
//print the result