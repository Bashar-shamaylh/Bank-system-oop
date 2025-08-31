#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"
class clsUpdateCarrencyRateScreen :protected clsScreen
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
	void UpdateRate()
	{
		float newRate;
		cout << "Enter new Rate : ";
		cin >> newRate;
	}
public:
	static void ShowUpdateCarrencyRateScreen()
	{
		_DrawScreenHeader("Update Carrency Rate Screen");
		cout << "Plese enter carrency code : ";
		string code;
		cin >> code;
		clsCurrency currency= clsCurrency::FindByCode(code);
		if (currency.IsCurrencyEmpty())
		{
			cout << "Carrency was Not Found!" << endl;
			
		}
		else
		{
			PrintCarrrencyCard(currency);
			cout << "Are you sure you want to update carrency rate?y,n";
			char answer;
			if (answer == 'y' || answer == 'Y')
			{
				float newRate;
				cout << "Enter new Rate : ";
				cin >> newRate;
				currency.UpdateRate(newRate);
				cout << "update was made succsessfully." << endl;
				cout << "new Card : ";
				PrintCarrrencyCard(currency);

			}
		}
	}
};

