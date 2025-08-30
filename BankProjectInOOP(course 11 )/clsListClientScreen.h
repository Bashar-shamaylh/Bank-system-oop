#pragma once
#include"clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>

class clsListClientScreen:protected clsScreen
{
    static void PrintClientRecordLine(clsBankClient Client)
    {

        cout << "| " << setw(15) << left << Client.getAccountNumber();
        cout << "| " << setw(20) << left << Client.getFullName();
        cout << "| " << setw(12) << left << Client.Phone;
        cout << "| " << setw(20) << left << Client.Email;
        cout << "| " << setw(10) << left << Client.getPinCode();
        cout << "| " << setw(12) << left << Client.accountBalance;

    }
public:
	static void ShowClientsList()
	{
        /*if (!CheckAccsessRights(clsUser::enPermissions::pListClients))
        {
            return;
        }*/
        vector <clsBankClient> vClients = clsBankClient::GetClientsList();
        string title = "Client List Screen";
        string subtitle = "( " + to_string(vClients.size()) + (" ) Clients.");
        clsScreen::_DrawScreenHeader(title, subtitle);
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient Client : vClients)
            {

                PrintClientRecordLine(Client);
                cout << endl;
            }

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

	}
};

