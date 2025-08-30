#pragma once
#include <iostream>
#include "clsUtility.h"
#include "clsUser.h"
#include "Global.h"
#include "clsDate.h"
using namespace std;
class clsScreen
{
protected:
	static void _DrawScreenHeader(string Title,string subTitle="")
	{
		clsUtility::PrintTaps(5); cout << "------------------------------------------------------------" << endl;
		clsUtility::PrintTaps(5); clsUtility::PrintSpaces(26); cout << Title << endl;
		clsUtility::PrintTaps(5); clsUtility::PrintSpaces(26); cout << subTitle << endl;
		clsUtility::PrintTaps(5); cout << "------------------------------------------------------------" << endl;
		clsUtility::PrintTaps(5); cout << "User : " << CurrentUser.UserName << endl;
		

		clsUtility::PrintTaps(5); cout << "Date : "; 
		clsDate::Print(clsDate::GetCurrentDate());
		cout << endl;
	}
	static bool CheckAccsessRights(clsUser::enPermissions Permission)
	{
		if (!CurrentUser.CheckAccsessPermission(Permission))
		{
			clsUtility::PrintTaps(5); cout << "----------------------------------------------------------------------" << endl;
			clsUtility::PrintTaps(5); clsUtility::PrintSpaces(26); cout << "Accsess denied ,Contact your Admin!" << endl;
			clsUtility::PrintTaps(5); cout << "----------------------------------------------------------------------" << endl;
			return false;
		}
		else
			return true;
	}
};

