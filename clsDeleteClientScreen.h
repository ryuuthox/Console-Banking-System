#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
using namespace std;
class clsDeleteClientScreen:protected clsScreen
{
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
	static  void showDeleteClientScreen() {
        if (!CheckAccessRights(clsUser::enUserPermissions::en_DeleteClientPerm)) {
            return;
        }
        _drawScreenHeader("\tDelete Client Screen");
        cout << "Enter the account number of the client u want to delete... ";
        string accountNumber = clsInputOutput::readString("Invalid acount number, please try again!");
        while (!clsBankClient::isClientExist(accountNumber)) {
            cout << accountNumber << " doesn't exist, please try another one... ";
            accountNumber = clsInputOutput::readString("Invalid acount number, please try again!");
        }
        clsBankClient dClient = clsBankClient::findClient(accountNumber);
        _printClient(dClient);
        cout << "Are u sure u want to delete this client? [y/n] ";
        char confirm = clsInputOutput::readChar("Invalid character, please try again... ");
        if (confirm == 'y' || confirm == 'Y') {
            dClient.Delete();
            _printClient(dClient);
            cout << "Client deleted successfully :)" << endl;
        }
        else {
            cout << "Operation stopped!" << endl;
        }

    }
};

