#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputOutput.h"

using namespace std;
class clsWithDrawScreen:protected clsScreen
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
	static void showWithDrawScreen() {
		_drawScreenHeader("Withdraw Screen");
		cout << "Enter account number u want to withdraw in ";
		string accountNumber = clsInputOutput::readString("Invalid account Number, please try again... ");
		while (!clsBankClient::isClientExist(accountNumber)) {
			cout << accountNumber << " doesn't exist, please try another one... ";
			accountNumber = clsInputOutput::readString("Invalid account Number, please try again... ");
		}
		clsBankClient client = clsBankClient::findClient(accountNumber);
		if (!client.isEmpty()) {
			_printClient(client);
			cout << "Are u sure u want to perform this operation? [y/n] ";
			char conf = clsInputOutput::readChar("Invalid charactere, please try again... ");
			if (conf == 'y' || conf == 'Y') {
				cout << "How much u want to draw? ";
				double amount = clsInputOutput::readDblNumber("Invalid number, please try again... ");
				while (amount > client.getAccountBallance()) {
					cout << "U cant draw that much of money, because ur account balance cant support\n please reenter a valid amount... ";
					amount = clsInputOutput::readDblNumber("Invalid number, please try again... ");
				}
				client.withDraw(amount);
				_printClient(client);
				cout << "Withdraw donne successfully :)" << endl;
			}
			else {
				cout << "This operation stopped!" << endl;
			}
		}
		else {
			cout << "Sorry, this is fake client!" << endl;
		}
	}
};

