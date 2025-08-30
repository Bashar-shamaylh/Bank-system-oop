#pragma once
#include "clsUser.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
class clsUpdateUserInfo :protected clsScreen
{
    static void _ReadClientInfo(clsUser& user)
    {
        cout << "plese enter the user First name : ";
        user.FirstName = (clsInputValidate::ReadString());
        cout << "plese enter the user Last name : ";
        user.LastName = (clsInputValidate::ReadString());

        cout << "plese enter the user Email  : ";
        user.Email = (clsInputValidate::ReadString());

        cout << "plese enter the user Phone number : ";
        user.Phone = (clsInputValidate::ReadString());

        cout << "plese enter the User password  : ";
        user.Password = (clsInputValidate::ReadString());

        cout << "plese enter the User Permissions  : ";
        user.Permissions = ReadPermissionsToSet();

    }
    static int ReadPermissionsToSet()
    {
        int permissions = 0;
       cout << "Do you want to give full access to the user?y,n :";
        char answer = 'n';
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
            return -1;
        cout << "Do you want to give Show Client List Permission?y,n : ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
            permissions += clsUser::enPermissions::pListClients;
        cout << "Do you want to give Add New Client Permission?y,n : ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
            permissions += clsUser::enPermissions::pAddNewClient;
        cout << "Do you want to give Delete Client Permission?y,n : ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
            permissions += clsUser::enPermissions::pDeleteClient;
        cout << "Do you want to give Update Client Info Permission?y,n : ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
            permissions += clsUser::enPermissions::pUpdateClients;
        cout << "Do you want to give Find Client Permission?y,n : ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
            permissions += clsUser::enPermissions::pFindClient;

        cout << "Do you want to give Transactions  Permission?y,n : ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
            permissions += clsUser::enPermissions::pTranactions;

        cout << "Do you want to give Manage Users Permission?y,n : ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
            permissions += clsUser::enPermissions::pManageUsers;
        cout << "Do you want to give Login Register  Permission?y,n : ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
            permissions += clsUser::enPermissions::pLoginRegister;


        return permissions;
    }
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
    static  void ShowUpdateUserScreen()
    {
        _DrawScreenHeader("Update User Screen");
        string accountNum;
        cout << "plese enter User Name : ";
        cin >> accountNum;
        clsUser user = clsUser::Find(accountNum);
        while (user.IsUserEmpty())
        {
            cout << "there is no user Found,plese enter another name  : ";
            cin >> accountNum;
            user = clsUser::Find(accountNum);
        }
        _PrintUser(user);
        _ReadClientInfo(user);
        clsUser::enSaveResults result = user.Save();
        switch (result)
        {
        case clsUser::SaveSucess:
            cout << "the update was made succsessfuly!" << endl;
            break;
        case clsUser::SaveFaild:
            cout << "the update was faild due to empty user." << endl;
            break;
        default:
            break;
        }

    }
};

