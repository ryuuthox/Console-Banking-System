#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

#include "clsScreen.h"
#include "clsListCurrenciesScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsFindCurrency.h"
#include "clsCurrencyCalculatorScreen.h"
using namespace std;
class clsCurrencyMainMenu:protected clsScreen
{
private:
	static void _backCurrencyExchangeMenu() {
		cout << "Press any key to go back Currency Exchange Menu... ";
		system("pause>0");
		system("cls");
		showCurrencyExchangeScreen();
	}

	static void _showListCurrenciesScreen() {
		clsListCurrenciesScreen::showCurrenciesListScreen();
	}
	static void _showFindCurrencyScreen() {
		clsFindCurrency::showFindCurrencyScreen();
	}
	static void _showUpdateRateScreen() {
		clsUpdateCurrencyRateScreen::showUpdateRateScreen();
	}

	static void _showCurrencyCalculatorScreen() {
		clsCurrencyCalculatorScreen::showCurrencyExchangeScreen();
	}

	enum enOptions {
		en_listCurrencies = 1,
		en_findCurrency = 2,
		en_updateRate = 3,
		en_currencyCalculator = 4,
		en_backMainMenu = 5
	};

	static enOptions _readOptions() {
		cout << "Choose one option between [1] and [5]... ";
		short option = clsInputOutput::readShortNumberBetween(1, 5, "Invalid option, please try again...");
		return enOptions(option);
	}

	static void _performCurrencyExchangeMenu(enOptions option) {
		switch (option)
		{
		case clsCurrencyMainMenu::en_listCurrencies:
			system("cls");
			_showListCurrenciesScreen();
			_backCurrencyExchangeMenu();
			break;
		case clsCurrencyMainMenu::en_findCurrency:
			system("cls");
			_showFindCurrencyScreen();
			_backCurrencyExchangeMenu();
			break;
		case clsCurrencyMainMenu::en_updateRate:
			system("cls");
			_showUpdateRateScreen();
			_backCurrencyExchangeMenu();
			break;
		case clsCurrencyMainMenu::en_currencyCalculator:
			system("cls");
			_showCurrencyCalculatorScreen();
			_backCurrencyExchangeMenu();
			break;
		case clsCurrencyMainMenu::en_backMainMenu:
			system("cls");
			break;
		default:
			break;
		}
	}

	static void _body() {
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Currency Exhange Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";
	}
public:
	static void showCurrencyExchangeScreen() {
		_drawScreenHeader("Currency Exchange Main Screen");
		_body();
		_performCurrencyExchangeMenu(_readOptions());
	}
};

