#pragma once
#include <iostream>
#include <iomanip>

#include "clsScreen.h"
#include "clsCurrency.h"

using namespace std;
class clsListCurrenciesScreen:protected clsScreen
{
    static void _printCurrencyRecordLine(clsCurrency Currency)
    {

        cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.getCountry();
        cout << "| " << setw(8) << left << Currency.getCurrencyCode();
        cout << "| " << setw(45) << left << Currency.getCurrencyName();
        cout << "| " << setw(10) << left << Currency.getRate();

    }

public:

    static void showCurrenciesListScreen()
    {


        vector <clsCurrency> vCurrencys = clsCurrency::getAllCurrenciesDataInVector();
        string Title = "\t  Currencies List Screen";
        string SubTitle = "\t    (" + to_string(vCurrencys.size()) + ") Currency.";

        _drawScreenHeader(Title, SubTitle);
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(8) << "Code";
        cout << "| " << left << setw(45) << "Name";
        cout << "| " << left << setw(10) << "Rate/(1$)";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;

        if (vCurrencys.size() == 0)
            cout << "\t\t\t\tNo Currencies Available In the System!";
        else

            for (clsCurrency Currency : vCurrencys)
            {

                _printCurrencyRecordLine(Currency);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;

    }
};

