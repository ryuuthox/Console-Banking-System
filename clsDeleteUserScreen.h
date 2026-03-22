#pragma once
#include <iostream>
#include <iomanip>

#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputOutput.h"

using namespace std;
class clsDeleteUserScreen:protected clsScreen
{
private:
	static void _printUser(clsUser& User)
	{
		cout << "\nUser Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << User.getFirstName();
		cout << "\nLastName    : " << User.getLastName();
		cout << "\nFull Name   : " << User.getFullName();
		cout << "\nEmail       : " << User.getEmail();
		cout << "\nPhone       : " << User.getPhoneNumber();
		cout << "\nUser Name   : " << User.getUserName();
		cout << "\nPassword    : " << User.getPassword();
		cout << "\nPermissions : " << User.getPermissions();
		cout << "\n___________________\n";

	}

public:
	static void showDeleteUserScreen() {
		_drawScreenHeader("Delete User Screen");
		cout << "Enter the Username of the user u want to delete: ";
		string userName = clsInputOutput::readString("Invalid username, please try again... ");
		while (!clsUser::isUserExist(userName)) {
			cout << userName << " doesn't exist, please try another one... ";
			userName = clsInputOutput::readString("Invalid username, please try again... ");
		}
		clsUser user = clsUser::findUser(userName);
		_printUser(user);
		cout << "Are u sure u want to delete this user? [y/n] ";
		char confirm = clsInputOutput::readChar("Invalid charactere, please try again... ");
		if (confirm == 'y' || confirm == 'Y') {
			if (!user.isEmpty()) {
				user.Delete();
				_printUser(user);
				cout << "User deleted successfully :)" << endl;
			}
			else {
				cout << "Sorry, this is empty user! " << endl;
			}
		}
		else {
			cout << "Operation stopped! " << endl;
		}
	}
};

