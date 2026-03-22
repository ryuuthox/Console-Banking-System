#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "clsUtil.h"
#include "clsString.h"
#include "clsPerson.h"


class clsUser:public clsPerson
{
public:
	struct stLoginRegistersRecord {
		string date;
		string username;
		string password;
		short permissions;
	};
private:
	enum enUserMode {
		en_EmptyMode = 1,
		en_UpdateMode = 2,
		en_AddNewMode = 3
	};
	string _userName;
	string _password;
	short _permissions;
	enUserMode _mode;

	bool _markedForDelete = false;

	 string _prepareRegisterRecord(string spt = "#||#") {
		
		return clsDate::getSystemDateTime() + spt + this->getUserName() + spt +clsUtil::encryptText( this->getPassword()) + spt + to_string(this->getPermissions());
	}

	static clsUser _getEmptyUser() {
		return clsUser("", "", "", "", "", "", 0, enUserMode::en_EmptyMode);
	}

	static clsUser _convertUserLineIntoObject(string line,string spt="#//#") {
		vector<string> vProperties = clsString::splitString(line, spt);
		return clsUser(vProperties[0], vProperties[1], vProperties[3], vProperties[2], vProperties[4],clsUtil::decryptText(vProperties[5]), stoi(vProperties[6]), enUserMode::en_UpdateMode);
	}

	static string _convertUserObjectIntoLine(clsUser& user,string spt="#//#") {
		string line = "";
		line += (user.getFirstName() + spt);
		line += (user.getLastName() + spt);
		line += (user.getEmail() + spt);
		line += (user.getPhoneNumber() + spt);
		line += (user.getUserName() + spt);
		line += (clsUtil::encryptText(user.getPassword())+ spt);
		line += to_string(user.getPermissions());
		return line;
	}

	static void _loadUsersFromVectorToFile(vector<clsUser>& vUsers) {
		fstream myFile;
		myFile.open("Users.txt", ios::out);
		if (myFile.is_open()) {
			for (clsUser& user : vUsers) {
				if (!user.isMarkedForDelete())
					myFile << _convertUserObjectIntoLine(user) << endl;
			}
		}
		myFile.close();
	}

	static vector<clsUser> _loadUsersFromFileToVector() {
		vector<clsUser> vUsers;
		fstream myFile;
		myFile.open("Users.txt", ios::in);
		if (myFile.is_open()) {
			string line;
			while (getline(myFile, line)) {
				vUsers.push_back(_convertUserLineIntoObject(line));
			}
		}
		myFile.close();
		return vUsers;
	}

	 void _update() {
		 vector<clsUser> vUsers = _loadUsersFromFileToVector();
		 for (clsUser& user : vUsers) {
			 if (user.getUserName() == _userName) {
				 user = *this;
			 }
		 }
		 _loadUsersFromVectorToFile(vUsers);
	}

	 void _add() {
		 fstream myFile;
		 myFile.open("Users.txt", ios::out | ios::app); 
		 if (myFile.is_open()) {
			 myFile << _convertUserObjectIntoLine(*this) << endl;
		}
		 myFile.close();
		 
	 }

	 static void _addLineToRegFile(string line) {
		 fstream myFile;
		 myFile.open("logs.txt", ios::out | ios::app);
		 if (myFile.is_open()) {
			 myFile << line << endl;
		 }
		 myFile.close();
	 }
	 static stLoginRegistersRecord _convertRegisterLineIntoRecord(string line,string spt="#||#") {
		 vector<string> vElements = clsString::splitString(line, spt);
		 return stLoginRegistersRecord{ vElements[0], vElements[1],clsUtil::decryptText(vElements[2]), short(stoi(vElements[3])) };
	 }

	 static vector<stLoginRegistersRecord> _loadLoginRegistersFileInVector() {
		 vector<stLoginRegistersRecord> vRegisters;
		 fstream myFile;
		 myFile.open("logs.txt", ios::in);
		 if (myFile.is_open()) {
			 string line;
			 while (getline(myFile, line)) {
				 vRegisters.push_back(_convertRegisterLineIntoRecord(line));
			 }
		 }
		 myFile.close();
		 return vRegisters;
	 }

public:
	clsUser(string firstName, string lastName, string phone, string email, string userName, string password, short permissions, enUserMode mode) :clsPerson(firstName, lastName, phone, email) {
		_userName = userName;
		_password = password;
		_permissions = permissions;
		_mode = mode;
	}

	void setUserName(string userName) {
		_userName = userName;
	}
	string getUserName() {
		return _userName;
	}

	void setPassword(string password) {
		_password = password;
	}

	string getPassword() {
		return _password;	
	}

	void setPermissions(short permissions) {
		_permissions = permissions;
	}

	short getPermissions() {
		return _permissions;
	}

	enUserMode getMode() {
		return _mode;
	}

	bool isMarkedForDelete() {
		return _markedForDelete;
	}

	bool isEmpty() {
		return _mode == enUserMode::en_EmptyMode;
	}

	static clsUser findUser(string userName) {
		fstream myFile;
		myFile.open("Users.txt", ios::in);
		if (myFile.is_open()) {
			string line;
			while (getline(myFile, line)) {
				clsUser tempUser = _convertUserLineIntoObject(line);
				if (tempUser.getUserName() == userName) {
					myFile.close();
					return tempUser;
				}
			}
		}
		myFile.close();
		return _getEmptyUser();
	}

	static clsUser findUser(string userName,string password) {
		fstream myFile;
		myFile.open("Users.txt", ios::in);
		if (myFile.is_open()) {
			string line;
			while (getline(myFile, line)) {
				clsUser tempUser = _convertUserLineIntoObject(line);
				if (tempUser.getUserName() == userName&& tempUser.getPassword()==password) {
					myFile.close();
					return tempUser;
				}
			}
		}
		myFile.close();
		return _getEmptyUser();
	}

	static bool isUserExist(string userName) {
		vector<clsUser> vUsers = _loadUsersFromFileToVector();
		for (clsUser& user : vUsers) {
			if (user.getUserName() == userName) {
				return 1;
			}
		}
		return 0;
	}

	bool isUserExist() {
		return isUserExist(this->getUserName());
	}

	enum enSave {
		en_Failed_Empty = 1,
		en_Succeed = 2,
		en_Failed_Exist = 3
	};

	enSave save() {
		switch (_mode) {
		case enUserMode::en_EmptyMode:
			return enSave::en_Failed_Empty;
		case enUserMode::en_UpdateMode:
			_update();
			return enSave::en_Succeed;
		case enUserMode::en_AddNewMode:
			if (isUserExist()) {
				return enSave::en_Failed_Exist;
			}
			else {
				_add();
				_mode = enUserMode::en_UpdateMode;
				return enSave::en_Succeed;
			}
		}
	}

	void Delete() {
		vector<clsUser> vUsers = _loadUsersFromFileToVector();
		for (clsUser& user : vUsers) {
			if (user.getUserName() == _userName) {
				user._markedForDelete = true;
			}
		}
		_loadUsersFromVectorToFile(vUsers);
		*this = _getEmptyUser();
	}

	static clsUser getAddNewUserObject(string userName) {
		return clsUser("", "", "", "", userName, "", 0, enUserMode::en_AddNewMode);
	}

	static vector<clsUser> getAllUsers() {
		return _loadUsersFromFileToVector();
	}

	enum enUserPermissions {
		en_AllPerms = -1,
		en_ListClientsPerm = 1,
		en_AddNewClientPerm = 2,
		en_DeleteClientPerm = 4,
		en_UpdateClientPerm = 8,
		en_FindClientPerm = 16,
		en_TransactionsPerm = 32,
		en_ManageUsersPerm = 64,
		en_ListLoginRegistersPerm = 128
	};

	bool checkAccesPermissions(enUserPermissions permission) {
		if (_permissions == -1) {
			return 1;
		}
		if ((_permissions & permission) == permission) {
			return 1;
		}
		else {
			return 0;
		}
	}


	void saveLogin() {
		string record = _prepareRegisterRecord();
		_addLineToRegFile(record);
	}

	static vector<stLoginRegistersRecord> getAllLoginRegisters() {
		return _loadLoginRegistersFileInVector();
	}

	static void test() {
		vector<clsUser> vUsers = _loadUsersFromFileToVector();
		_loadUsersFromVectorToFile(vUsers);
	}
	
};

