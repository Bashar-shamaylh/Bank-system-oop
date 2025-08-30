#pragma once
#include "clsScreen.h"
#include <vector>
#include "clsUser.h"
#include <iomanip>
#include "clsInputValidate.h"
class clsLoginRegisterScreen :protected clsScreen
{
    static void PrintLogsRecord(clsUser::LoginInfo record)
    {
       
        cout << "| " << setw(15) << left <<record.date_time;
        cout << "| " << setw(20) << left << record.userName;
        cout << "| " << setw(12) << left <<record.password;
        cout << "| " << setw(12) << left << record.permission;

    }
public :
	static void ShowLoginRegisterScreen()
	{
        vector <clsUser::LoginInfo> Logs = clsUser::GetLogsVector();
		_DrawScreenHeader("Login Register",to_string(Logs.size()));
		
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "| " << left << setw(15) << "Register Time";
        cout << "| " << left << setw(20) << "User Name";
        cout << "| " << left << setw(12) << "Password";
        cout << "| " << left << setw(12) << "Permission";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (Logs.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsUser::LoginInfo Record: Logs)
            {

                PrintLogsRecord(Record);
                cout << endl;
            }

	}
};
