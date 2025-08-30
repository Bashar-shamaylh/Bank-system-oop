#pragma once
#include"clsScreen.h"
#include "clsUser.h"
#include <iomanip>

class clsShowUsersListScreen :protected clsScreen
{
    static void PrintUserRecordLine(clsUser User)
    {

        cout << "| " << setw(15) << left << User.UserName;
        cout << "| " << setw(20) << left << User.getFullName();
        cout << "| " << setw(12) << left << User.Phone;
        cout << "| " << setw(20) << left << User.Email;
        cout << "| " << setw(10) << left << User.Password;
        cout << "| " << setw(12) << left << User.Permissions;

    }
public:
    static void ShowUsersList()
    {

        vector <clsUser> vUsers = clsUser::GetUsersList();
        string title = "Users List Screen";
        string subtitle = "( " + to_string(vUsers.size()) + (" ) Users.");
        clsScreen::_DrawScreenHeader(title, subtitle);
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "| " << left << setw(15) << "User Name";
        cout << "| " << left << setw(20) << "Full Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vUsers.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else

            for (clsUser User : vUsers)
            {

                PrintUserRecordLine(User);
                cout << endl;
            }

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
};

