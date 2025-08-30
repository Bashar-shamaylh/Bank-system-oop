#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
class clsUpdateClientScreen :protected clsScreen
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
    static void _PrintClient(clsBankClient Client)
    {

        cout << "| " << setw(15) << left << Client.getAccountNumber();
        cout << "| " << setw(20) << left << Client.getFullName();
        cout << "| " << setw(12) << left << Client.Phone;
        cout << "| " << setw(20) << left << Client.Email;
        cout << "| " << setw(10) << left << Client.getPinCode();
        cout << "| " << setw(12) << left << Client.accountBalance;

    }
public :
  static  void ShowUpdateClientScreen()
    {
     /* if (!CheckAccsessRights(clsUser::enPermissions::pUpdateClients))
      {
          return;
      }*/
      _DrawScreenHeader("Update Client Screen");
        string accountNum;
        cout << "plese enter client account number : ";
        cin >> accountNum;
        clsBankClient client = clsBankClient::Find(accountNum);
        while (client.IsClientEmpty())
        {
            cout << "there is no client Found,plese enter another account number : ";
            cin >> accountNum;
            client = clsBankClient::Find(accountNum);
        }
        _PrintClient(client);
        _ReadClientInfo(client);
        clsBankClient::enSaveResults result = client.Save();
        switch (result)
        {
        case clsBankClient::SaveSucess:
            cout << "the update was made succsessfuly!" << endl;
            break;
        case clsBankClient::SaveFaild:
            cout << "the update was faild due to empty client." << endl;
            break;
        default:
            break;
        }

    }
};

