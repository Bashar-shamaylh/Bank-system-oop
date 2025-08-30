#pragma once
#include"clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsInputValidate.h"
class clsAddNewUser :protected clsScreen
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
        user.Permissions =ReadPermissionsToSet();

    }
    static int ReadPermissionsToSet()
    {
        int permissions = 0;
        
        cout << "Do you want to give full access to the user?y,n :";
        char answer = 'n';
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
            return -1;
        cout << "Do you want to give Show Users List Permission?y,n : ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
            permissions += clsUser::enPermissions::pListClients;
        cout << "Do you want to give Add New User Permission?y,n : ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
            permissions += clsUser::enPermissions::pAddNewClient;
        cout << "Do you want to give Delte Users Permission?y,n : ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
            permissions += clsUser::enPermissions::pDeleteClient;
        cout << "Do you want to give Update Users Info Permission?y,n : ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
            permissions += clsUser::enPermissions::pUpdateClients;
        cout << "Do you want to give Find Users Permission?y,n : ";
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
        cout << "Do you want to give Login Register Permission?y,n : ";
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
    static void showAddNewUserScreen()
    {
        _DrawScreenHeader("Add New User Page");
        string UserName = "";
        cout << "plese enter an User Name : ";
        UserName = clsInputValidate::ReadString();
        while (clsUser::IsUserExesit(UserName))
        {
            cout << "User Name is already in use,try another one :";
            UserName = clsInputValidate::ReadString("");
        }
        clsUser UserToAdd = clsUser::GetUserToAdd(UserName);
        _ReadClientInfo(UserToAdd);
        clsUser::enSaveResults Save = UserToAdd.Save();
        switch (Save)
        {
        case clsUser::SaveSucess:
            cout << "User was Add succsesfuly. :-)\n";
            break;
        case clsUser::SaveFaild:
            cout << "Save faild because the User is empty." << endl;
            break;
        case clsUser::SaveFaildDueToExistUserName:
            cout << "Save was faild due to exsting User Name \n";
            break;
        default:
            cout << "Adding process was faild due to anKnown error in Add New User" << endl;
            break;
        }
        _PrintUser(UserToAdd);
    }

};

