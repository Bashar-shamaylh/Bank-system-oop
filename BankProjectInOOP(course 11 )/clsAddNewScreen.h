#pragma once
#include"clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include "clsInputValidate.h"

class clsAddNewScreen : protected clsScreen
{
   static void _ReadClientInfo(clsBankClient& client)
    {
        cout << "plese enter the Account First name : ";
        client.FirstName = (clsInputValidate::ReadString());
        cout << "plese enter the Account Last name : ";
        client.LastName = (clsInputValidate::ReadString());

        cout << "plese enter the Account Email  : ";
        client.Email = (clsInputValidate::ReadString());

        cout << "plese enter the Account Phone number : ";
        client.Phone = (clsInputValidate::ReadString());

        cout << "plese enter the Account Pin code : ";
        client.pinCode = (clsInputValidate::ReadString());

        cout << "plese enter the Account Balance : ";
        client.accountBalance = (clsInputValidate::ReadDblNumber());

    }
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
	static void showAddNewClientScreen()
	{
        if (!CheckAccsessRights(clsUser::enPermissions::pAddNewClient))
        {
            return;
        }
		_DrawScreenHeader("Add New Client Page");
        string AccountNumber = "";
        cout << "plese enter an account Number : ";
        AccountNumber = clsInputValidate::ReadString();
        while (clsBankClient::IsClientExesit(AccountNumber))
        {
            cout << "client Number is already in use,try another one :";
            AccountNumber = clsInputValidate::ReadString("");
        }
        clsBankClient clientToAdd = clsBankClient::GetClientToAdd(AccountNumber);
        _ReadClientInfo(clientToAdd);
        clsBankClient::enSaveResults Save = clientToAdd.Save();
        switch (Save)
        {
        case clsBankClient::SaveSucess:
            cout << "Client was Add succsesfuly. :-)\n";
            break;
        case clsBankClient::SaveFaild:
            cout << "Save faild because the client is empty." << endl;
            break;
        case clsBankClient::SaveFaildDueToExistAccountNumber:
            cout << "Save was faild due to exsting Account Number\n";
            break;
        default:
            cout << "Adding process was faild due to anKnown error in AddNewClient" << endl;
            break;
        }
        _PrintClient(clientToAdd);
    }

	
};

