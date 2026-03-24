#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "clsString.h"
#include "clsUtil.h"

using namespace std;

class clsCurrency
{
private:

	enum enMode {
		en_emptyMode = 1,
		en_updateMode = 2
	};

	string _country;
	string _currencyCode;
	string _currencyName;
	float _rate;

	enMode _mode;

	static clsCurrency _convertLineIntoCurrencyObject(string line, string spt="#//#") {
		vector<string> vItems = clsString::splitString(line, spt);
		return clsCurrency(vItems[0], vItems[1], vItems[2], stof(vItems[3]), enMode::en_updateMode);
	}

	static string _convertCurrencyObjectIntoLine(clsCurrency currency, string spt = "#//#") {
		string line = "";
		line += (currency.getCountry() + spt);
		line += (currency.getCurrencyCode() + spt);
		line += (currency.getCurrencyName() + spt);
		line += to_string(currency.getRate());
		return line;
	}

	static vector<clsCurrency> _loadCurrenciesFileInVector() {
		fstream myFile;
		vector<clsCurrency> vCurrencies;
		myFile.open("Currencies.txt", ios::in);
		if (myFile.is_open()) {
			string line;
			while (getline(myFile, line)) {
				vCurrencies.push_back(_convertLineIntoCurrencyObject(line));
			}
		}
		myFile.close();
		return vCurrencies;
	}

	static void _loadCurrenciesVectorInFile(vector<clsCurrency>& vCurrencies) {
		fstream myFile;
		myFile.open("Currencies.txt", ios::out);
		if (myFile.is_open()) {
			for (clsCurrency& currency : vCurrencies) {
				myFile << _convertCurrencyObjectIntoLine(currency) << endl;
			}
		}
		myFile.close();
	}

	void _update() {
		vector<clsCurrency> vCurrencies = _loadCurrenciesFileInVector();
		for (clsCurrency& currency : vCurrencies) {
			if (_currencyCode == currency.getCurrencyCode()) {
				currency = *this;
				break;
			}
		}
		_loadCurrenciesVectorInFile(vCurrencies);
	}

	static clsCurrency _getEmptyObject() {
		return clsCurrency("", "", "", 0, enMode::en_emptyMode);
	}

public:

	clsCurrency(string country, string currencyCode, string currencyName, float rate, enMode mode) {
		_country = country;
		_currencyCode = currencyCode;
		_currencyName = currencyName;
		_rate = rate;
		_mode = mode;
	}

	string getCountry() {
		return _country;
	}

	string getCurrencyCode() {
		return _currencyCode;
	}

	string getCurrencyName() {
		return _currencyName;
	}

	void updateRate(float newRate) {
		_rate = newRate;
		_update();
	}

	float getRate() {
		return _rate;
	}

	bool isEmpty() {
		return _mode == enMode::en_emptyMode;
	}

	static bool isCurrencyExist(string currencyCode) {
		clsCurrency currency = findCurrencyByCurrencyCode(currencyCode);
		return (!currency.isEmpty());
	}

	static clsCurrency findCurrencyByCountryName(string country) {
		fstream myFile;
		myFile.open("Currencies.txt", ios::in);
		if (myFile.is_open()) {
			string line;
			while (getline(myFile, line)) {
				clsCurrency tempCurr = _convertLineIntoCurrencyObject(line);
				if (tempCurr.getCountry() == country) {
					myFile.close();
					return tempCurr;
				}
			}
		}
		myFile.close();
		return _getEmptyObject();
	}

	static clsCurrency findCurrencyByCurrencyCode(string currencyCode) {
		currencyCode = clsString::upperString(currencyCode);
		fstream myFile;
		myFile.open("Currencies.txt", ios::in);
		if (myFile.is_open()) {
			string line;
			while (getline(myFile, line)) {
				clsCurrency tempCurr = _convertLineIntoCurrencyObject(line);
				if (tempCurr.getCurrencyCode() == currencyCode) {
					myFile.close();
					return tempCurr;
				}
			}
		}
		myFile.close();
		return _getEmptyObject();
	}

	static vector<clsCurrency> getAllCurrenciesDataInVector() {
		return _loadCurrenciesFileInVector();
	}

	float convertToUSD(float amount) {
		return float(amount / _rate);
	}

	float convertToXcurr(float amount, clsCurrency X) {
		float myCurrencyInUSD = convertToUSD(amount);

		if (X.getCurrencyCode() == "USD") {
			return myCurrencyInUSD;
		}

		return float(myCurrencyInUSD * X.getRate());
	}

};

