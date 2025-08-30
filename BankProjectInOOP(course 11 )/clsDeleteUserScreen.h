#pragma once
#include"clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include "clsInputValidate.h"

class clsDeleteUserScreen :protected clsScreen
{
    static void _PrintClient(clsBankClient client) {

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
public:
	static void ShowDeleteUserScreen()
	{
        if (!CheckAccsessRights(clsUser::enPermissions::pDeleteClient))
        {
            return;
        }
		_DrawScreenHeader("Delete User Screen");
        string AccountNumber;
        cout << "Plese enter an Account Number to Delete : ";
        AccountNumber = clsInputValidate::ReadString("plese enter  string value ");
        while (!clsBankClient::IsClientExesit(AccountNumber))
        {
            cout << "Account Number dose not exsit try another one : ";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient client = clsBankClient::Find(AccountNumber);
        cout << "Client Card : " << endl;
       _PrintClient(client);
        cout << "Are you sure you wanna delete this client?(y,n).";
        char choice;
        cin >> choice;
        if (choice == 'y' || choice == 'Y')
        {
            if (client.Delete())
            {
                cout << "client was deleted succsefly." << endl;
                cout << "Client Card After delteing : " << endl;
                client.Print();
                return;
            }
            else
            {
                cout << "client was not deleted due to unknown error!" << endl;
                return;
            }
        }
	}
};

