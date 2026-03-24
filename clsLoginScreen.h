#pragma once
#include <iostream>
#include <iomanip>

#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputOutput.h"
#include "Global.h"
#include "clsMainMenuScreen.h"


using namespace std;
class clsLoginScreen:protected clsScreen
{
private:
	static bool _login() {
		bool loginFailed = false;
		short countlogs = 0;
		do {
			if (loginFailed) {
				cout << "Invalid Username or Password, please try again... " << endl;
				cout << "U still have " << 3 - countlogs << " trails! \n";
			}
			cout << "Username: ";
			string userName = clsInputOutput::readString("Invalid userName, try again... ");
			cout << "Password: ";
			string password = clsInputOutput::readString("Invalid password, try again... ");
			currentUser = clsUser::findUser(userName, password);
			loginFailed = currentUser.isEmpty();
			countlogs++;
			if (countlogs == 3) {
				cout << "You are locked, u get 3 falls!" << endl;
				return 0;
			}

		} while (loginFailed);
		CLEAR_SCREEN;
		currentUser.saveLogin();
			clsMainMenuScreen::showMainMenuScreen();
			return 1;
	}

public:
	static bool showLoginScreen() {
		_drawScreenHeader("Login Screen");
		return _login();
	}
};

