#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
class clsDeposite :protected clsScreen
{
	static void PrintClientCard(clsBankClient client)
	{
        cout << "______________________________________________________________" << endl;
        cout << "the account number is: "; cout << client.getAccountNumber() << endl;
        cout << "the first name is : "; cout << client.FirstName << endl;
        cout << "the last name is : "; cout << client.LastName << endl;
        cout << "the full name is :"; cout << client.getFullName() << endl;
        cout << "the phone is: "; cout << client.Phone << endl;
        cout << "the account balance is: "; cout << client.accountBalance << endl;
        cout << "the Pin Code is: "; cout << client.pinCode << endl;
        cout << "______________________________________________________________" << endl;
	}
    static string ReadAccountNumber()
    {
        string accountNumber;
        accountNumber = clsInputValidate::ReadString();
        return accountNumber;
    }
public:
    static void ShowDepositeScreen()
    {
        _DrawScreenHeader("Deposite screen");
        cout << "Enter an account Number : ";

        string accountNumber = ReadAccountNumber();
        while (!clsBankClient::IsClientExesit(accountNumber))
        {
            cout << "client with this account number does not exist try another one : ";
            accountNumber = ReadAccountNumber();
        }
        clsBankClient client = clsBankClient::Find(accountNumber);
        cout << "Client Card : " << endl;
        PrintClientCard(client);
        cout << "Enter a Number to Deposite : ";
        double amount=clsInputValidate::ReadDblNumber();

        
        cout << "are you sure you wanna deposite " << amount << " in this account?y,n ";
        char answer;
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            client.Deposite(amount);
            cout << "Transaction was made succsesfuly." << endl;
            cout << "New Balance is : " << client.accountBalance << endl;
        }
        else
        {
            cout << "transaction was faild." << endl;

        }
    }
};

