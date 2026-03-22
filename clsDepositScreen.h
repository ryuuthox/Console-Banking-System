#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"

using namespace std;
class clsDepositScreen:protected clsScreen
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
	static void showDepositScreen() {
		char confirm = 'y';
		cout << "Enter the account number to deposit... ";
		string accountNumber = clsInputOutput::readString("Invalid account number, please try again... ");

		while (!clsBankClient::isClientExist(accountNumber)) {
			cout << accountNumber << " doesn't exist, please try another one... ";
            accountNumber = clsInputOutput::readString("Invalid account number, please try again... ");
		}
		clsBankClient client = clsBankClient::findClient(accountNumber);
		_printClient(client);
		cout << "Are u sure u want to continue operation? ";
		char conf = clsInputOutput::readChar("Invalid charactere, please try again");
		if (conf == 'y' || conf == 'Y') {
			if (!client.isEmpty()) {
				cout << "How much u want to deposit? ";
				double amount = clsInputOutput::readDblNumber("Invalid number, please try again... ");
				client.deposit(amount);
				cout << "Deposit donne successfully :)" << endl;
				_printClient(client);
			}
			else {
				cout << "this is fake client!" << endl;
			}
		}
		else {
			cout << "Operation stopped! " << endl;
		}
	}
};

