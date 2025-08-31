
#pragma once
#include "clsUser.h"
#include "clsScreen.h"
#include "iomanip"
#include"clsInputValidate.h"
class clsFindUserScreen :protected clsScreen
{
    static void _PrintUser(clsUser user) {

        cout << "______________________________________________________________" << endl;
        cout << "the account number is: "; cout << user.UserName << endl;
        cout << "the first name is : "; cout << user.FirstName << endl;
        cout << "the last name is : "; cout << user.LastName << endl;
        cout << "the full name is :"; cout << user.getFullName() << endl;
        cout << "the phone is: "; cout << user.Phone << endl;
        cout << "the user Permissions is: "; cout << user.Permissions << endl;
        cout << "the  Password is: "; cout << user.Password << endl;
        cout << "______________________________________________________________" << endl;
    }
public:
    static void ShowFindClientScreen()
    {
        _DrawScreenHeader("Find User Screen");
        string accountNum;
        cout << "plese enter User Name to look for : ";
        accountNum = clsInputValidate::ReadString();

        while (!clsUser::IsUserExesit(accountNum))
        {
            cout << "there is no User Found,plese enter another Name  : ";
            accountNum = clsInputValidate::ReadString();
        }
        clsUser client = clsUser::Find(accountNum);
        if (client.IsUserEmpty())
        {
            cout << "Client was not found" << endl;
        }
        else

        {
            cout << "Client was found." << endl;

        }
        _PrintUser(client);

    }
};

