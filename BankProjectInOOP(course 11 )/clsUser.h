#pragma once
#include<iostream>
#include<string>
#include <fstream>
#include"clsPerson.h"
#include"clsDate.h"
#include "clsString.h"
#include <vector>
#include <string>
class clsUser : public clsPerson
{
public:
	static struct LoginInfo {
		string date_time;
		string userName;
		string password;
		int permission;
	};
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddingMode = 2 };
	enMode _Mode;
	string _UserName;
	string _Password;
	int _Permissons;
	bool _MarkToDelete = false;
	static LoginInfo _ConverLoginInfoIntoLine(string line)
	{
		vector <string>tokens = clsString::split(line, "/##/");
		LoginInfo info;
		info.date_time = tokens.at(0);
		info.userName = tokens.at(1);
		info.password = tokens.at(2);
		info.permission =stoi( tokens.at(3));
		return info;
	}
	static vector<LoginInfo>_GetLogsRecords()
	{
		vector <LoginInfo>Logs;
		fstream myfile;
		myfile.open("Logs.txt", ios::in);
		if (myfile.is_open())
		{
			string line;
			while (getline(myfile, line))
			{
				
				Logs.push_back(_ConverLoginInfoIntoLine(line));

			}
			myfile.close();
		}
		return Logs;

	}
	 string _CreateLoginRecord(string seprator = "/##/")
	{
		string date = clsDate::fromDateToString(clsDate::GetCurrentDate());
		string time = clsUtility::CurrentTime();

		return date + "-" + time + seprator + _UserName + seprator + _Password + seprator + to_string(_Permissons);
	}
	static clsUser ConvertLineToUserRecord(string Line, string Seperator = "/##/")
	{
		vector <string>tokens = clsString::split(Line, Seperator);
		return clsUser(enMode::UpdateMode, tokens[0], tokens[1], tokens[2], tokens[3], tokens[4], tokens[5], stoi(tokens[6]));
	}
	string _ConvertUserRecordToLine(clsUser user, string Seprator = "/##/")
	{
		string text = user.FirstName;
		text += Seprator;
		text += user.LastName;
		text += Seprator;
		text += user.Email;
		text += Seprator;
		text += user.Phone;
		text += Seprator;
		text += user.UserName;
		text += Seprator;
		text += user.Password;
		text += Seprator;

		text += to_string(user.Permissions);
		return text;
	}
	static clsUser EmptyUser()
	{
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", -1);
	}
	static vector<clsUser> _LoadUsersFileIntoVector()
	{
		vector < clsUser> Users;
		fstream myfile;
		myfile.open("Users.txt", ios::in);
		if (myfile.is_open())
		{
			string line;
			while (getline(myfile, line))
			{
				clsUser client = ConvertLineToUserRecord(line);
				Users.push_back(client);

			}
			myfile.close();
		}
		return Users;
	}
	void _SaveUsersDataToFile(vector<clsUser>clients)
	{
		fstream myfile;
		myfile.open("Users.txt", ios::out);
		if (myfile.is_open())
		{
			for (clsUser user : clients)
			{
				if (user._MarkToDelete == false) {
					myfile << _ConvertUserRecordToLine(user);
					myfile << endl;
				}

			}
			myfile.close();
		}

	}
	void _Update()
	{
		vector < clsUser> clients = _LoadUsersFileIntoVector();
		for (clsUser& client : clients)
		{
			if (client.UserName == UserName)
			{
				client = *this;
				break;
			}
		}
		_SaveUsersDataToFile(clients);

	}
	void _AddNewUser()
	{
		string client = _ConvertUserRecordToLine(*this);
		fstream myfile;
		myfile.open("Users.txt", ios::in | ios::app);
		if (myfile.is_open())
		{

			myfile << client;
			myfile << endl;
			myfile.close();
		}
	}
public:
	
	enum enPermissions {
		eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
		pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64, pLoginRegister = 128
	};
	void SetUserName(string UserName)
	{
		_UserName = UserName;
	}
	void SetPassword(string Password)
	{
		_Password = Password;
	}
	void SetPermissions(int Permission)
	{
		_Permissons = Permission;
	}
	string GetUserName()
	{
		return _UserName;
	}
	string GetPassword()
	{
		return _Password;
	}
	int GetPermission()
	{
		return _Permissons;
	}
	_declspec(property(get = GetUserName, put = SetUserName)) string UserName;
	_declspec(property(get = GetPassword, put = SetPassword)) string Password;
	_declspec(property(get = GetPermission, put = SetPermissions)) int Permissions;
	clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone, string UserName, string Password, int Permission) :
		clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissons = Permission;
	}
	bool IsUserEmpty()
	{
		return _Mode == enMode::EmptyMode;
	}
	static vector<clsUser> GetUsersList()
	{
		return _LoadUsersFileIntoVector();
	}
	static clsUser Find(string UserName)
	{
		fstream myfile;
		myfile.open("Users.txt", ios::in );
		if (myfile.is_open())
		{
			string line;
			while (getline(myfile, line))
			{
				clsUser user = ConvertLineToUserRecord(line);
				if (user.UserName == UserName)
				{
					myfile.close();
					return user;
				}

			}
			myfile.close();
		}
		return EmptyUser();
	}
	static clsUser Find(string UserName, string Password)
	{
		fstream myfile;
		myfile.open("Users.txt", ios::in );

		if (myfile.is_open())
		{
			string line;
			while (getline(myfile, line))
			{
				clsUser user = ConvertLineToUserRecord(line);
				if (user.UserName == UserName && user.Password == Password)
				{
					myfile.close();
					return user;
				}
			}
			myfile.close();
		}
		return EmptyUser();
	}
	static bool IsUserExesit(string UserName)
	{
		clsUser user = clsUser::Find(UserName);
		return(!user.IsUserEmpty());
	}
	static enum enSaveResults { SaveSucess = 0, SaveFaild = 1, SaveFaildDueToExistUserName = 2 };
	enSaveResults Save()
	{
		if (_Mode == enMode::EmptyMode)
			return enSaveResults::SaveFaild;
		else if (_Mode == enMode::UpdateMode)
		{
			_Update();
			return enSaveResults::SaveSucess;
		}
		else if (_Mode == enMode::AddingMode && IsUserExesit(_UserName))
		{
			return enSaveResults::SaveFaildDueToExistUserName;
		}
		else if (_Mode == enMode::AddingMode)
		{
			_AddNewUser();
			_Mode = enMode::UpdateMode;
			return enSaveResults::SaveSucess;
		}
		return enSaveResults::SaveFaild;

	}
	static clsUser GetUserToAdd(string UserName)
	{

		return clsUser(enMode::AddingMode, "", "", "", "", UserName, "", -1);
	}
	bool Delete()
	{
		vector<clsUser> vUsers = _LoadUsersFileIntoVector();
		for (clsUser& user : vUsers)
		{
			if (user.UserName == UserName)
				user._MarkToDelete = true;
		}
		_SaveUsersDataToFile(vUsers);
		*this = EmptyUser();
		return true;
	}
	 bool CheckAccsessPermission(enPermissions permission)
	{
		if (this->Permissions == enPermissions::eAll)
			return true;
		else if ((permission & this->Permissions) == permission)
			return true;
		else
			return false;
	}
	  void SaveLoginData()
	 {
		 
		 string LoginRecord = _CreateLoginRecord();
		 fstream myfile;
		 myfile.open("Logs.txt", ios::out | ios::app);
		 if (myfile.is_open())
		 {
			 myfile << LoginRecord;
			 myfile << endl;
			 myfile.close();
		 }
	 }
	 
	  static vector<LoginInfo>GetLogsVector()
	  {
		  return _GetLogsRecords();
		}
	
};

