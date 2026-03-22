#pragma once
#include <iostream>
#include <iomanip>

#include "clsScreen.h"
#include "clsCurrency.h"

using namespace std;
class clsFindCurrency:protected clsScreen
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

	enum enOptions {
		en_byCode = 1,
		en_byCountry = 2
	};

	static enOptions _readOptions() {
		cout << "You want to search by Currency Code [1] or by Country Name [2] ? ";
		short option = clsInputOutput::readShortNumberBetween(1, 2, "Invalid option, please try again...");
		return enOptions(option);
	}

	static void _showFindByCode() {
		cout << "Please Enter Currency Code: ";
		string cCode = clsInputOutput::readString("Invalid Currency Code, please try again... ");
		cCode = clsString::upperString(cCode);
		while (!clsCurrency::isCurrencyExist(cCode)) {
			cout << cCode << " doesn't exist, try another one... ";
			cCode = clsInputOutput::readString("Invalid Currency Code, please try again... ");
			cCode = clsString::upperString(cCode);
		}

		clsCurrency currency = clsCurrency::findCurrencyByCurrencyCode(cCode);
		if (!currency.isEmpty()) {
			cout << "Currency found :)" << endl;
			_printCurrency(currency);
		}
		else {
			cout << "Sorry, we cant found it!" << endl;
		}
	}


	static void _showFindByCountry() {
		cout << "Please Enter Country Name: ";
		string cName = clsInputOutput::readString("Invalid Country name, please try again... ");
		while (!clsCurrency::isCurrencyExist(cName)) {
			cout << cName << " doesn't exist, try another one... ";
			cName = clsInputOutput::readString("Invalid Currency Code, please try again... ");
			
		}

		clsCurrency currency = clsCurrency::findCurrencyByCountryName(cName);
		if (!currency.isEmpty()) {
			cout << "Currency found :)" << endl;
			_printCurrency(currency);
		}
		else {
			cout << "Sorry, we cant found it!" << endl;
		}
	}

public:

	static void showFindCurrencyScreen() {
		_drawScreenHeader("Find Currency Screen");
		switch (_readOptions())
		{
		case enOptions::en_byCode:
			_showFindByCode();
			break;
		case enOptions::en_byCountry:
			_showFindByCountry();
			break;
		default:
			break;
		}
	}
};

