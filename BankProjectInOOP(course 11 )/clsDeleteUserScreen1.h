#pragma once
#include"clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsInputValidate.h"

class clsDeleteUserScreen1 :protected clsScreen
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
    static void ShowDeleteUserScreen()
    {
        _DrawScreenHeader("Delte User Page");
        string UserName = "";
        cout << "plese enter a User Name : ";
        UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExesit(UserName))
        {
            cout << "User Name was not found ,try again  :";
            UserName = clsInputValidate::ReadString("");
        }
        clsUser user = clsUser::Find(UserName);
        cout << "User Card : " << endl;
        _PrintUser(user);
        cout << "Are you sure you wanna delete this user?(y,n).";
        char choice;
        cin >> choice;
        if (choice == 'y' || choice == 'Y')
        {
            if (user.Delete())
            {
                cout << "client was deleted succsefly." << endl;
                cout << "Client Card After delteing : " << endl;
                _PrintUser(user);
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

