#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "clsString.h"
#include "clsDate.h"
#include "clsUser.h"

using namespace std;
class clsLogsRegister
{
private:
	string _date;
	string _userName;
	string _password;
	short _permissions;

	static string _convertObjectRegisterIntoLine(clsLogsRegister& reg, string spt = "#||#") {
		string line = "";
		line += (reg.getDate() + spt);
		line += (reg.getUsername() + spt);
		line += (reg.getPassword() + spt);
		line += to_string(reg.getPermissions());
		return line;
	}

	static void _addLineToRegFile(string line) {
		fstream myFile;
		myFile.open("logs.txt", ios::out | ios::app);
		if (myFile.is_open()) {
			myFile << line << endl;
		}
		myFile.close();
	}

public:
	clsLogsRegister(string date, string userName, string password, short permissions) {
		_date = date;
		_userName = userName;
		_password = password;
		_permissions = permissions;
	}

	string getDate() {
		return _date;
	}

	void setUsername(string userName) {
		_userName = userName;
	}

	string getUsername() {
		return _userName;
	}

	void setPassword(string password) {
		_password = password;
	}

	string getPassword() {
		return _password;
	}

	void setPermissions(short perm) {
		_permissions = perm;
	}
	short getPermissions() {
		return _permissions;
	}

	static void saveLogRegister(clsUser& user) {
		clsLogsRegister logReg(clsDate::getSystemDateTime(), user.getUserName(), user.getPassword(), user.getPermissions());
		_addLineToRegFile(_convertObjectRegisterIntoLine(logReg));
	}
};

