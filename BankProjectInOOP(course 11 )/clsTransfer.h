#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
class clsTransfer :protected clsScreen
{
    static void PrintClientCard(clsBankClient client)
    {
        cout << "______________________________________________________________" << endl;
        cout << "the account number is: "; cout << client.getAccountNumber() << endl;
        cout << "the full name is :"; cout << client.getFullName() << endl;
        cout << "the account balance is: "; cout << client.accountBalance << endl;
        cout << "______________________________________________________________" << endl;
    }
    static string ReadAccountNumber()
    {
        string accountNumber;
        accountNumber = clsInputValidate::ReadString();
        return accountNumber;
    }
public:
	static void ShowTransferScreen()
	{
		_DrawScreenHeader("Transfer Screen");

        cout << "Enter an account Number to Transfer From : ";
        string accountNumber = ReadAccountNumber();
        while (!clsBankClient::IsClientExesit(accountNumber))
        {
            cout << "client with this account number does not exist try another one : ";
            accountNumber = ReadAccountNumber();
        }
        clsBankClient client = clsBankClient::Find(accountNumber);
        cout << "Client Card : " << endl;
        PrintClientCard(client);

        cout << "Enter an account Number to Transfer To : ";
        string accountNumber1 = ReadAccountNumber();
        while (!clsBankClient::IsClientExesit(accountNumber1))
        {
            cout << "client with this account number does not exist try another one : ";
            accountNumber1 = ReadAccountNumber();
        }
        clsBankClient client1 = clsBankClient::Find(accountNumber1);
        cout << "Client Card : " << endl;
        PrintClientCard(client1);
        cout << "Enter a Transfer amount  : ";
        double amount = clsInputValidate::ReadDblNumber();
        cout << "are you sure you wanna Withdraw " << amount << " from this account?y,n ";
        char answer;
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            client.Transfer(amount, client1);
            PrintClientCard(client);
            PrintClientCard(client1);
           
        }
        else
        {
            cout << "transaction was canceld." << endl;

        }
	}
};

