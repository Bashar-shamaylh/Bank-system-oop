#pragma once
#include<iostream>
#include<string>
#include <fstream>
#include"clsPerson.h"
#include"clsDate.h"
#include "clsString.h"
#include <vector>
#include <string>
class clsBankClient:public clsPerson
{public:
	struct TransferLog {
		string time;
		string sourceAccountNum;
		string destnationAccountNum;
		double amount;
		double sourceBalance;
		double destBalance;
		string User;
	};

private:
	enum enMode{EmptyMode=0,UpdateMode=1,AddingMode=2};
	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkToDelete = false;
	static TransferLog _ConverLoginInfoIntoLine(string line)
	{
		vector <string>tokens = clsString::split(line, "/##/");
		TransferLog info;
		info.time = tokens.at(0);
		info.amount = stod(tokens.at(1));
		info.sourceAccountNum = tokens.at(2);
		info.destnationAccountNum = tokens.at(3);
		
		info.sourceBalance = stod(tokens.at(4));
		info.destBalance = stod(tokens.at(5));
		info.User = tokens.at(6);
		return info;
	}
	static vector<TransferLog>_GetLogsRecords()
	{
		vector <TransferLog>Logs;
		fstream myfile;
		myfile.open("TransferLogs.txt", ios::in);
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
	string _CreateTransferRecord(int amount,clsBankClient DestentationClient, string seprator = "/##/")
	{
		string date = clsDate::fromDateToString(clsDate::GetCurrentDate());
		string time = clsUtility::CurrentTime();

		return date + "-" + time + seprator + to_string(amount)+seprator+_AccountNumber+ seprator +DestentationClient.getAccountNumber()+seprator+ to_string(_AccountBalance) + seprator +to_string(DestentationClient.accountBalance )+seprator+CurrentUser.UserName;
	}
	static clsBankClient ConvertLineToClientRecord(string Line, string Seperator="/##/")
	{
		vector <string>tokens = clsString::split(Line,Seperator);
		return clsBankClient(enMode::UpdateMode, tokens[0], tokens[1], stof(tokens[6]), tokens[2], tokens[3], tokens[4], tokens[5]);
	}
	string _ConvertClientRecordToLine(clsBankClient client,string Seprator ="/##/")
	{
		string text =client.getAccountNumber();
		text += Seprator;
		text +=client.pinCode;
		text += Seprator;
		text +=client.FirstName;
		text += Seprator;
		text += client.LastName;
		text += Seprator;
		text += client.Email;
		text += Seprator;
		text += client.Phone;
		text += Seprator;
		
		text += to_string(client.accountBalance);
		return text;
	}
	static clsBankClient EmptyClient()
	{
		return clsBankClient(enMode::EmptyMode, "", "", 0, "", "", "", "");
	}
	static vector<clsBankClient> _LoadClientFileIntoVector()
	{
		vector < clsBankClient> clients;
		fstream myfile;
		myfile.open("Myfile.txt", ios::in);
		if (myfile.is_open())
		{
			string line;
			while (getline(myfile, line))
			{
				clsBankClient client = ConvertLineToClientRecord(line);
				clients.push_back(client);

			}
			myfile.close();
		}
		return clients;
	}
	void _SaveClientsDataToFile(vector<clsBankClient>clients)
	{
		fstream myfile;
		myfile.open("Myfile.txt", ios::out);
		if (myfile.is_open())
		{
			for (clsBankClient client : clients)
			{
				if (client._MarkToDelete == false) {
					myfile << _ConvertClientRecordToLine(client);
					myfile << endl;
				}
				
			}
			myfile.close();
		}

	}
	void _Update()
	{
		vector < clsBankClient> clients = _LoadClientFileIntoVector();
		for (clsBankClient& client : clients)
		{
			if (client.getAccountNumber() == _AccountNumber)
			{
				client = *this;
				break;
			}
		}
		_SaveClientsDataToFile(clients);

	}
	void _AddNewClient()
	{
		string client = _ConvertClientRecordToLine(*this);
		fstream myfile;
		myfile.open("Myfile.txt", ios::in | ios::app);
		if (myfile.is_open())
		{
			
			myfile <<client;
			myfile << endl;
			myfile.close();
		}
	}

public:
	clsBankClient(enMode mode, string accountNumber, string pinCode, float accountBalance, string firstName, string lastName, string email, string phone) :
		clsPerson(firstName, lastName, email, phone)
	{
		_Mode = mode;
		_AccountNumber = accountNumber;
		_PinCode = pinCode;
		_AccountBalance = accountBalance;
	}
	bool IsClientEmpty()
	{
		return _Mode == enMode::EmptyMode;
	}
	string getAccountNumber()
	{
		return _AccountNumber;
	}
	void setPinCode(string pinCode)
	{
		_PinCode = pinCode;
	}
	string getPinCode()
	{
		return _PinCode;
	}
	void setAccountBalance(float accountBalance)
	{
		_AccountBalance = accountBalance;
	}
	float getAccountBalance()
	{
		return _AccountBalance;
	}
	_declspec(property(get = getAccountBalance, put = setAccountBalance)) float accountBalance;
	_declspec(property(get = getPinCode, put = setPinCode)) string pinCode;
	void Print()
	{
		cout << "______________________________________________________________" << endl;
		cout << "the account number is: "; cout << _AccountNumber << endl;
		cout << "the first name is : "; cout << FirstName << endl;
		cout << "the last name is : "; cout << LastName << endl;
		cout << "the full name is :"; cout << getFullName()<< endl;
		cout << "the phone is: "; cout << Phone << endl;
		cout << "the account balance is: "; cout << _AccountBalance << endl;
		cout << "the Pin Code is: "; cout << _PinCode << endl;
		cout << "______________________________________________________________" << endl;
	}
	
	static clsBankClient Find(string AccountNum)
	{
		fstream myfile;
		myfile.open("Myfile.txt", ios::in | ios::app);
		if (myfile.is_open())
		{
			string line;
			while (getline(myfile, line))
			{
				clsBankClient client=ConvertLineToClientRecord(line);
				if (client.getAccountNumber() == AccountNum)
				{
					myfile.close();
					return client;
				}
					
			}
			myfile.close();
		}
		return EmptyClient();
	}
	static clsBankClient Find(string AccountNum, string PinCode)
	{
		fstream myfile;
		myfile.open("Myfile.txt", ios::in | ios::app);
		
		if (myfile.is_open())
		{
			string line;
			while (getline(myfile, line))
			{
				clsBankClient client = ConvertLineToClientRecord(line);
				if (client.getAccountNumber() == AccountNum && client.pinCode == PinCode)
				{
					myfile.close();
					return client;
				}
			}
			myfile.close();
		}
		return EmptyClient();
	}
	static bool IsClientExesit(string AccountNum)
	{
		clsBankClient client = clsBankClient::Find(AccountNum);
		return(!client.IsClientEmpty());
	}
	static enum enSaveResults {SaveSucess=0,SaveFaild=1, SaveFaildDueToExistAccountNumber=2};
	enSaveResults Save()
	{
		if (_Mode == enMode::EmptyMode)
			return enSaveResults::SaveFaild;
		else if(_Mode==enMode::UpdateMode)
		{
			_Update();
			return enSaveResults::SaveSucess;
		}
		else if (_Mode == enMode::AddingMode && IsClientExesit(_AccountNumber))
		{
			return enSaveResults::SaveFaildDueToExistAccountNumber;
		}
		else if (_Mode == enMode::AddingMode)
		{
			_AddNewClient();
			_Mode = enMode::UpdateMode;
			return enSaveResults::SaveSucess;
		}
	}
	static clsBankClient GetClientToAdd(string AccountNum)
	{
		return clsBankClient(enMode::AddingMode,AccountNum, "", 0, "", "", "", "");
	}
	static clsBankClient GetEmptyClient()
	{
		 return clsBankClient(enMode::EmptyMode, "", "", 0, "", "", "", "");
	}
	 bool Delete()
	{
		vector<clsBankClient> Clients =_LoadClientFileIntoVector();
		for (clsBankClient client : Clients)
		{
			if (client._AccountNumber == _AccountNumber)
				client._MarkToDelete = true;
		}
		_SaveClientsDataToFile(Clients);
		*this = GetEmptyClient();
		return true;
	}
	 static vector<clsBankClient> GetClientsList()
	 {
		 return _LoadClientFileIntoVector();
	 }
	static  double TotalBalance()
	 {
		 double totalBalance = 0;
		 vector<clsBankClient>VClients = _LoadClientFileIntoVector();
		 for (clsBankClient& client : VClients)
		 {
			 totalBalance += client.accountBalance;
		 }
		 return totalBalance;
	 }
	 void Deposite(double DepositeAmount)
	{
		_AccountBalance += DepositeAmount;
		Save();
	}
	 bool Withdraw(double WithDrawAmount)
	 {
		 if (_AccountBalance < WithDrawAmount)
			 return false;

		 _AccountBalance -= WithDrawAmount;
		 Save();
		 return true;
	 }
	 bool Transfer(double Amount, clsBankClient& DestenationAccount)
	 {
		 if (Withdraw(Amount))
		 {
			 DestenationAccount.Deposite(Amount);
			 SaveTransferData(Amount, DestenationAccount);
			 return true;
		 }

		 return false;
	 }
	 void SaveTransferData(int amount,clsBankClient client)
	 {

		 string LoginRecord = _CreateTransferRecord(amount,client);
		 fstream myfile;
		 myfile.open("TransferLogs.txt", ios::out | ios::app);
		 if (myfile.is_open())
		 {
			 myfile << LoginRecord;
			 myfile << endl;
			 myfile.close();
		 }
	 }
	
	 static vector<TransferLog>GetLogsVector()
	 {
		 return _GetLogsRecords();
	 }
};

