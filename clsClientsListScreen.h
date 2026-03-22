#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "clsBankClient.h"
#include "clsScreen.h"
using namespace std;


class clsClientsListScreen:protected clsScreen
{
private:
    static void printClientRecordLine(clsBankClient& Client)
    {

        cout << "| " << setw(15) << left << Client.getAccountNumber();
        cout << "| " << setw(20) << left << Client.getFullName();
        cout << "| " << setw(12) << left << Client.getPhoneNumber();
        cout << "| " << setw(20) << left << Client.getEmail();
        cout << "| " << setw(10) << left << Client.getPinCode();
        cout << "| " << setw(12) << left << Client.getAccountBallance();

    }

public:
	static  void showClientsListScreen() {
        if (!CheckAccessRights(clsUser::enUserPermissions::en_ListClientsPerm)) {
            return;
        }
        vector<clsBankClient> vClients = clsBankClient::getAllClientsInVector();
        string subTitle = "Client List (" + to_string(vClients.size()) + ") Client(s).";
        _drawScreenHeader("Client List Screen",subTitle);
      
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient& Client : vClients)
            {

                printClientRecordLine(Client);
                cout << endl;
            }

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
};

