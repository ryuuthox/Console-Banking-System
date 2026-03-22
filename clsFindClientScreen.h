#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsUtil.h"

using namespace std;
class clsFindClientScreen:protected clsScreen
{
private:
    static void _printClient(clsBankClient& client) {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << client.getFirstName();
        cout << "\nLastName    : " << client.getLastName();
        cout << "\nFull Name   : " << client.getFullName();
        cout << "\nEmail       : " << client.getEmail();
        cout << "\nPhone       : " << client.getPhoneNumber();
        cout << "\nAcc. Number : " << client.getAccountNumber();
        cout << "\nPassword    : " << client.getPinCode();
        cout << "\nBalance     : " << client.getAccountBallance();
        cout << "\n___________________\n";
    }

public:
	static void showFindClientScreen() {
        if (!CheckAccessRights(clsUser::enUserPermissions::en_FindClientPerm)) {
            return;
        }
		_drawScreenHeader("Find Client Screen");
		cout << "Please enter the account number of the client u are looking for... ";
		string accountNumber = clsInputOutput::readString("Invalid account Number pls try again! ");
		while (!clsBankClient::isClientExist(accountNumber)) {
			cout << accountNumber << " doesn't exist, pls try another one... ";
			accountNumber= clsInputOutput::readString("Invalid account Number pls try again! ");
		}
		clsBankClient client = clsBankClient::findClient(accountNumber);
        if (!client.isEmpty()) {
            cout << "Client found :)" << endl;
        }
        else {
            cout << "Client not found :(" << endl;
        }
        _printClient(client);

	}
};

