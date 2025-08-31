#pragma once
#include <iostream>
#include <string>
#include <clsUtility.h>
#include <vector>
#include <fstream>
using namespace std;
class clsCurrency
{
	enum enMode {
		eEmptyMode=1,eUpdateMode=2
	};
	enMode _Mode;
	string _CountryName;
	string _CurrencyName;
	string _CurrencyCode;
	float _CurrencyRate;
	static clsCurrency _ConvertLineToCurrencyObject(string line,string Seperator="#//#")
	{
		vector <string>tokens = clsString::split(line, Seperator);
		return clsCurrency(enMode::eUpdateMode, tokens[0], tokens[2],tokens[1] ,stof(tokens[3]));
}
	static vector<clsCurrency> _LoadCurrencyFileIntoVector()
	{
		vector < clsCurrency> vCurrencies;
		fstream myfile;
		myfile.open("Currencies.txt", ios::in);
		if (myfile.is_open())
		{
			string line;
			while (getline(myfile, line))
			{
				clsCurrency currency = _ConvertLineToCurrencyObject(line);
				vCurrencies.push_back(currency);

			}
			myfile.close();
		}
		return vCurrencies;
	}
	string _ConvertCurrencyRecordToLine(clsCurrency currency, string Seprator = "#//#")
	{
		
		string text = currency.CountryName();
		text += Seprator;
		text += currency.CurrencyName();
		text += Seprator;
		text += currency.CureencyCode();
		text += Seprator;
		text += currency.CurrencyRate();

		return text;
	}
	void _SaveCurrenciesDataToFile(vector<clsCurrency>Currencies)
	{
		fstream myfile;
		myfile.open("Currencies.txt", ios::out);
		if (myfile.is_open())
		{
			for (clsCurrency currency : Currencies)
			{
				
					myfile << _ConvertCurrencyRecordToLine(currency);
					myfile << endl;
				

			}
			myfile.close();
		}

	}
	void _Update()
	{
		vector < clsCurrency> currencies = _LoadCurrencyFileIntoVector();
		for (clsCurrency& currency : currencies)
		{
			if (currency.CureencyCode() == CureencyCode())
			{
				currency = *this;
				break;
			}
		}
		_SaveCurrenciesDataToFile(currencies);

	}
public:
	clsCurrency(enMode mode,string CountryName, string CurrencyName, string CurrencyCode, float Rate)
	{
		_Mode = mode;
		_CountryName=CountryName;
		 _CurrencyName=CurrencyName;
		 _CurrencyCode=CurrencyCode;
		_CurrencyRate=Rate;
	}
	string CountryName()
	{
		return _CountryName;
	}
	string CurrencyName()
	{
		return _CurrencyName;
	}
	string CureencyCode()
	{
		return _CurrencyCode;
	}
	float CurrencyRate()
	{
		return _CurrencyRate;
	}
	void UpdateRate(float newRate)
	{
		_CurrencyRate = newRate;
		_Update();
	}
	static clsCurrency FindByCode(string CurrencyCode)
	{
		fstream myfile;
		myfile.open("Currencies.txt", ios::in | ios::app);
		if (myfile.is_open())
		{
			string line;
			while (getline(myfile, line))
			{
				clsCurrency currency = _ConvertLineToCurrencyObject(line);
				if (clsString::upperAllString(currency.CureencyCode()) == (clsString::upperAllString(CurrencyCode)))
				{
					myfile.close();
					return currency;
				}

			}
			myfile.close();
		}
		return EmptyCurrency();
		//later on
	}
	static clsCurrency EmptyCurrency()
	{
		return clsCurrency(enMode::eEmptyMode, "", "", "", 0);
	}
	static clsCurrency FindByCountryName(string CountryName)
	{
		fstream myfile;
		myfile.open("Currencies.txt", ios::in | ios::app);
		if (myfile.is_open())
		{
			string line;
			while (getline(myfile, line))
			{
				clsCurrency currency = _ConvertLineToCurrencyObject(line);
				if (clsString::upperAllString(currency.CountryName()) == (clsString::upperAllString(CountryName)))
				{
					myfile.close();
					return currency;
				}

			}
			myfile.close();
		}
		return EmptyCurrency();
		//later on
	}
	bool IsCurrencyEmpty() {
		return _Mode == enMode::eEmptyMode;
	}
		
	static bool IsCurrencyExist(clsCurrency currency)
	{
		clsCurrency c1 = clsCurrency::FindByCode(currency.CureencyCode());
		return (!c1.IsCurrencyEmpty());
	}
	static vector<clsCurrency>GetCurrenciesList()
	{
		return _LoadCurrencyFileIntoVector();
	}

};

