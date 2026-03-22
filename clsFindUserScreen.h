#pragma once
#include <iostream>
#include <iomanip>

#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputOutput.h"

using namespace std;
class clsFindUserScreen:protected clsScreen
{
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
	static void showFindUserScreen() {
		_drawScreenHeader("Update User Screen");
		cout << "Enter the username of the user u are looking for... ";
		string userName = clsInputOutput::readString("Invalid username, please try again... ");
		while (!clsUser::isUserExist(userName)) {
			cout << userName << " doesn't exist, please try another one... ";
			userName = clsInputOutput::readString("Invalid username, please try again... ");
		}
		clsUser user = clsUser::findUser(userName);
		_printUser(user);
		
	}
};

