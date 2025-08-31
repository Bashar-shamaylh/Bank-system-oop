#pragma once
#include <iomanip>
#include "clsCurrency.h"
#include "clsScreen.h"
class clsListCarrenciesScreen:protected clsScreen
{
    static void PrintCarrencyRecordLine(clsCurrency carrency)
    {

        cout << "| " << setw(30) << left << carrency.CountryName();
        cout << "| " << setw(30) << left << carrency.CurrencyName();
        cout << "| " << setw(20) << left << carrency.CureencyCode();
        cout << "| " << setw(12) << left << carrency.CurrencyRate();
    }
public:
    static void ShowCarrencyList()
    {
      
        vector <clsCurrency> vCarrencies = clsCurrency::GetCurrenciesList();
        string title = "Carrencies List Screen";
        string subtitle = "( " + to_string(vCarrencies.size()) + (" ) Carrency.");
        clsScreen::_DrawScreenHeader(title, subtitle);
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "| " << left << setw(15) << "Country";
        cout << "| " << left << setw(20) << "Carrency Name";
        cout << "| " << left << setw(12) << "Carrency Code";
        cout << "| " << left << setw(20) << "Carrency Rate";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vCarrencies.size() == 0)
            cout << "\t\t\t\tNo Carrencies Available In the System!";
        else

            for (clsCurrency carrency : vCarrencies)
            {

                PrintCarrencyRecordLine(carrency);
                cout << endl;
            }

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
};

