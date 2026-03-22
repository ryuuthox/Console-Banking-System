#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"


using namespace std;
class clsAddNewClientScreen:protected clsScreen
{
private:
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
	static  void showAddNewClientScreen() {
        if (!CheckAccessRights(clsUser::enUserPermissions::en_AddNewClientPerm)) {
            return;
        }
        _drawScreenHeader("Add New Client Screen");
        string accountNumber = "";
        cout << "Pleas enter the account number... ";
        accountNumber = clsInputOutput::readString("Invalid account number, try again! ");
        while (clsBankClient::isClientExist(accountNumber)) {
            cout << "This account number is already exist! try another one... ";
            accountNumber = clsInputOutput::readString("Invalid account number, try again! ");
        }
        clsBankClient newClient = clsBankClient::getAddNewClientObject(accountNumber);
        _readUpdatedInfos(newClient);
        switch (newClient.save())
        {
        case clsBankClient::enSave::saveFailed_Empty:
            cout << "Sorry its empty client!\n";
            break;
        case clsBankClient::enSave::saveFailed_Exist:
            cout << "Sorry this client is already exist!\n";
            break;
        case clsBankClient::enSave::saveSucceded:
            cout << "Client added successfully :)" << endl;
            _printClient(newClient);
            break;
        }
    }
};

