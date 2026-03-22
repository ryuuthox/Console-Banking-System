#pragma once
#include <iostream>
#include <iomanip>

#include "clsScreen.h"
#include "clsCurrency.h"

using namespace std;
class clsUpdateCurrencyRateScreen:protected clsScreen
{
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

public:
	
	static void showUpdateRateScreen() {
		_drawScreenHeader("Update Rate Screen");
		cout << "Please Enter Currency Code u want to update its rate: ";
		string cCode = clsInputOutput::readString("Invalid Currency Code, please try again... ");
		while (!clsCurrency::isCurrencyExist(cCode)) {
			cout << cCode << " doesn't exist, try another one... ";
			cCode = clsInputOutput::readString("Invalid Currency Code, please try again... ");
		}

		clsCurrency currency = clsCurrency::findCurrencyByCurrencyCode(cCode);
		if (!currency.isEmpty()) {
			_printCurrency(currency);
			cout << "Are u sure u want to update its rate [y/n] ? ";
			char conf = clsInputOutput::readChar("Invalid character, please try again... ");
			if (conf == 'y' || conf == 'Y') {
				cout << "Enter the new rate: ";
				float nRate = clsInputOutput::readFloatNumber("Invalid rate, please try again... ");
				currency.updateRate(nRate);
				_printCurrency(currency);
				cout << "Currency rate updated successfully :)" << endl;
			}
			else {
				cout << "Operation stoped!" << endl;
			}
		}
		else {
			cout << "Sorry, we cant found it!" << endl;
		}
	}
};

