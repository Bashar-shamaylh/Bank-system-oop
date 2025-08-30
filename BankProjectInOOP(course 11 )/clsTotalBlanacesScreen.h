#pragma once
#include"clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
class clsTotalBlanacesScreen :protected clsScreen
{
    static void PrintClientBalanceRecord(clsBankClient Client)
    {

        cout << "| " << setw(15) << left << Client.getAccountNumber();
        cout << "| " << setw(20) << left << Client.getFullName();
        cout << "| " << setw(12) << left << Client.accountBalance;

    }
public:
    static void ShowTotalBalances()
    {

        vector <clsBankClient> vClients = clsBankClient::GetClientsList();
        string title = "Total Balances Screen";
        string subtitle = "( " + to_string(vClients.size()) + (" ) Clients.");
        clsScreen::_DrawScreenHeader(title, subtitle);
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient Client : vClients)
            {

                PrintClientBalanceRecord(Client);
                cout << endl;
            }

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        cout << "\t\t\The total Balance is : " << clsBankClient::TotalBalance() << endl;
    }
};

