#pragma once
#include <iostream>
#include <iomanip>

#include "clsScreen.h"
#include "clsCurrency.h"

using namespace std;
class clsCurrencyCalculatorScreen:protected clsScreen
{
private:
	static void _printCurrency(clsCurrency currency) {
		cout << "\n\n\t\t  Currency Infos: \n";
		cout << "\t======================================\n";
		cout << "\t Country: " << currency.getCountry() << endl;
		cout << "\t Currency Code: " << currency.getCurrencyCode() << endl;
		cout << "\t Currency Name: " << currency.getCurrencyName() << endl;
		cout << "\t Rate(/$): " << currency.getRate() << endl;
		cout << "\t======================================\n";
		cout << endl;
	}

	static string _readCurrencyCode() {
		string cCode = clsInputOutput::readString("Invalid Currency Code, please try again... ");
		while (!clsCurrency::isCurrencyExist(cCode)) {
			cout << cCode << " doesn't exist, try another one... ";
			cCode = clsInputOutput::readString("Invalid Currency Code, please try again... ");
		}

		return cCode;
	}

public:
	static void showCurrencyExchangeScreen() {
		char conf;
		do {
			CLEAR_SCREEN;
			_drawScreenHeader("Currency Calculator Screen");
			cout << "Exchange from: ";
			clsCurrency currencyFrom = clsCurrency::findCurrencyByCurrencyCode(_readCurrencyCode());
			cout << "To: ";
			clsCurrency currencyTo = clsCurrency::findCurrencyByCurrencyCode(_readCurrencyCode());
			cout << "How Much do u want to exchange? ";
			float amount = clsInputOutput::readFloatNumber("Invalid amount, please try again... ");
			float result = currencyFrom.convertToXcurr(amount, currencyTo);
			_printCurrency(currencyFrom);
			cout << "\n\t " << amount << " " + currencyFrom.getCurrencyCode() << " = " << result << " " + currencyTo.getCurrencyCode() << endl;

			cout << "\n Do u want to perform more [y/n] ?";
			 conf = clsInputOutput::readChar("Invalid char,try again... ");
		} while (conf == 'y' || conf == 'Y');


	}
};

