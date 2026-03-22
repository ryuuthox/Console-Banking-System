#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"

using namespace std;
class clsUpdateClientScreen:protected clsScreen
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

    static  void _readUpdatedInfos(clsBankClient& client) {
        cout << "Update client info... " << endl;
        cout << clsUtil::getRepeatedChar('-', 40) << endl;
        cout << "First name: ";
        client.setFirstName(clsInputOutput::readString("Invalid name! please try again... "));
        cout << "Last name: ";
        client.setLastName(clsInputOutput::readString("Invalid name! please try again... "));
        cout << "Phone number: ";
        client.setPhoneNumber(clsInputOutput::readString("Invalid phone number! please try again... "));
        cout << "Email: ";
        client.setEmail(clsInputOutput::readString("Invalid email! please try again... "));
        cout << "PinCode: ";
        client.setPinCode(clsInputOutput::readString("Invalid PinCode! please try again..."));
        cout << "Account ballance: ";
        client.setAccountBallance(clsInputOutput::readDblNumber("Invalid amount! please try again..."));
    }
public:
    static void showUpdateClientScreen() {
        if (!CheckAccessRights(clsUser::enUserPermissions::en_UpdateClientPerm)) {
            return;
        }
        _drawScreenHeader("Update Client Screen");
        cout << "Please enter the account number of the client u want to update... ";
        string accountNumber = clsInputOutput::readString("Invalid account number! please try again... ");
        while (!clsBankClient::isClientExist(accountNumber)) {
            cout << "This account number doesnt exist! try again...";
            accountNumber = clsInputOutput::readString("Invalid account number! please try again... ");
        }
        clsBankClient xClient = clsBankClient::findClient(accountNumber);


        _printClient(xClient);
        _readUpdatedInfos(xClient);
        switch (xClient.save())
        {
        case clsBankClient::enSave::saveFailed_Empty:
            cout << "Sorry! operation failed..." << endl;
            break;
        case  clsBankClient::enSave::saveSucceded:
            cout << "Client updated successfully :)" << endl;
            break;
        }
    }
};

