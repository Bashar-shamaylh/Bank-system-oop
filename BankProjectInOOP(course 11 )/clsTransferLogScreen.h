#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
class clsTransferLogScreen :protected clsScreen
{
    static void PrintLogsRecord(clsBankClient::TransferLog record)
    {

        cout << "| " << setw(15) << left << record.time;
        cout << "| " << setw(20) << left << record.amount;
        cout << "| " << setw(12) << left << record.sourceAccountNum;
        cout << "| " << setw(12) << left << record.destnationAccountNum;
        cout << "| " << setw(12) << left << record.sourceBalance;
        cout << "| " << setw(12) << left << record.destBalance;
        cout << "| " << setw(12) << left << record.User;

    }
public:
	static void _ShowTranserLogsScreen()
	{
        vector <clsBankClient::TransferLog> Logs = clsBankClient::GetLogsVector();
        _DrawScreenHeader("Transfer Register", to_string(Logs.size()));

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "| " << left << setw(15) << "Register Time";
        cout << "| " << left << setw(20) << "Amount";
        cout << "| " << left << setw(12) << "s.Account";
        cout << "| " << left << setw(12) << "d.Account";
        cout << "| " << left << setw(12) << "s.Balance";
        cout << "| " << left << setw(12) << "d.Balance";
        cout << "| " << left << setw(12) << "User";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (Logs.size() == 0)
            cout << "\t\t\t\tNo Transfer Available In the System!";
        else

            for (clsBankClient::TransferLog Record : Logs)
            {

                PrintLogsRecord(Record);
                cout << endl;
            }
	}
};

