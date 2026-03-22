#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUtil.h"
#include "clsDepositScreen.h"
#include "clsWithDrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsBankClient.h"

using namespace std;
class clsTransfersScreen:protected clsScreen
{
private:
	static void _printInfos(clsBankClient& user) {
		cout << "\n\t========================================= " << endl;
		cout << "\n\t| AccountNumber: " << user.getAccountNumber() << endl;
		cout << "\n\t| PinCode: " << user.getPinCode() << endl;
		cout << "\n\t| Ballance: " << user.getAccountBallance() << endl;
		cout << "\n\t========================================= " << endl;
	}
	static string _readAccountNumber() {
		string accountNumber = clsInputOutput::readString("Invalid account number, please try again... ");
		while (!clsBankClient::isClientExist(accountNumber)) {
			cout << accountNumber << " doesn't exist, try another one... ";
			accountNumber = clsInputOutput::readString("Invalid account number, please try again... ");
		}
		return accountNumber;
	}

public:
	static void showTransfersScreen() {
		_drawScreenHeader("Transfer Screen");

		cout << "Account Number of the Client to transfer from: ";
		clsBankClient srcCLient = clsBankClient::findClient(_readAccountNumber());
		_printInfos(srcCLient);

		cout << "Account Number of the Client to transfer to: ";
		clsBankClient destClient = clsBankClient::findClient(_readAccountNumber());
		while (srcCLient.getAccountNumber() == destClient.getAccountNumber()) {
			cout << "Sorry, u cant transfer to the same account... \n";
			cout << "ReEnter different account number to transfer: ";
		    destClient = clsBankClient::findClient(_readAccountNumber());
		}
		_printInfos(destClient);

		cout << "How much do u want to transfer? ";
		double amount = clsInputOutput::readDblNumber("Invalid amount, please try again... ");
		while (srcCLient.getAccountBallance() < amount) {
			cout << "Source client ballance can't support " << amount << ", please choose an amount < " << srcCLient.getAccountBallance() << "... ";
			amount = clsInputOutput::readDblNumber("Invalid amount, please try again... ");
		}

		cout << "are u sure u want to perform this transfer? [y/n] ";
		char conf = clsInputOutput::readChar("Invalid character, please try again... ");
		if (conf == 'y' || conf == 'Y') {
			if (srcCLient.transfer(amount, destClient)) {
				cout << "\n\tTransfer donne successfully :)" << endl;
			}
			else {
				cout << "\n\tTransfer failed" << endl;
			}
		}
		else {
			cout << "Operation stopped! " << endl;
		}

	}
};

