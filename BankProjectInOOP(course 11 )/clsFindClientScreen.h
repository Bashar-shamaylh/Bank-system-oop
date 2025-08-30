#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"
#include "iomanip"
#include"InputEventFlags.h"
class clsFindClientScreen :protected clsScreen
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
	static void ShowFindClientScreen()
	{
        if (!CheckAccsessRights(clsUser::enPermissions::pFindClient))
        {
            return;
        }
        _DrawScreenHeader("Update Client Screen");
        string accountNum;
        cout << "plese enter client account number to look for : ";
        accountNum = clsInputValidate::ReadString();

        while (clsBankClient::IsClientExesit(accountNum))
        {
            cout << "there is no client Found,plese enter another account number : ";
            accountNum = clsInputValidate::ReadString();
        }
        clsBankClient client = clsBankClient::Find(accountNum);
        if (client.IsClientEmpty())
        {
            cout << "Client was not found" << endl;
        }
        else
            
        {
            cout << "Client was found." << endl;
            
        }
        _PrintClient(client);

	}
};

