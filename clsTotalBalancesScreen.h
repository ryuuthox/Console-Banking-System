#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "clsScreen.h"
#include "clsBankClient.h"

using namespace std;
class clsTotalBalancesScreen:protected clsScreen
{
private:
	static void _printClientRecordBalanceLine(clsBankClient& Client)
    {

        cout << "| " << setw(15) << left << Client.getAccountNumber();
        cout << "| " << setw(40) << left << Client.getFullName();
        cout << "| " << setw(12) << left << Client.getAccountBallance();

    }

public:
    static void showTotalBalancesScreen()
    {
      

        vector <clsBankClient> vClients = clsBankClient::getAllClientsInVector();
        string subtitle = "\n\t\t\t\t\tBalances List (" + to_string(vClients.size()) + ") Client(s).";
        _drawScreenHeader("Total Balances Screen", subtitle);
        
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(40) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        double TotalBalances = clsBankClient::getTotalBallances();

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient Client : vClients)
            {
                _printClientRecordBalanceLine(Client);
                cout << endl;
            }

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        cout << "\t\t\t\t\t   Total Balances = " << TotalBalances << endl;
        cout << "\t\t\t\t\t   ( " << clsUtil::NumberToText(TotalBalances) << ")";
        cout << endl;
    }
};

