#pragma once
#include <iostream>
#include <iomanip>

#include "clsScreen.h"
#include "clsInputOutput.h"
#include "clsClientsListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "clsListLoginRegistersScreen.h"
#include "clsCurrencyMainMenu.h"
#include "Global.h"

using namespace std;


class clsMainMenuScreen:protected clsScreen
{
private:
	enum enMainMenuOptions {
		en_ShowClientsList = 1,
		en_AddNewClient = 2,
		en_DeleteClient = 3,
		en_UpdateClient = 4,
		en_FindClient = 5,
		en_Transactions = 6,
		en_ManageUsers = 7,
		en_LoginRegisterList = 8,
		en_CurrencyExchange = 9,
		en_LogOut = 10
	};

	static void _backToMainMenu() {
		cout << "press any key to go back to main menu ";
		system("pause>0");
		system("cls");
		showMainMenuScreen();
	}

	static void _showClientsList() {
		clsClientsListScreen::showClientsListScreen();
	}

	static void _addNewClient() {
		clsAddNewClientScreen::showAddNewClientScreen();
	}

	static void _deleteClient() {
		clsDeleteClientScreen::showDeleteClientScreen();
	}

	static void _updateClientInfo() {
		clsUpdateClientScreen::showUpdateClientScreen();
	}

	static void _findClient() {
		clsFindClientScreen::showFindClientScreen();
	}

	static void _Transactions() {
		clsTransactionsScreen::showTransactionsMenuScreen();
	}

	static void _manageUsers() {
		clsManageUsersScreen::showManageUsersScreen();
	}

	static void _LoginRegistersScreen() {
		clsListLoginRegistersScreen::showListUsersScreen();
	}

	static void _showCurrencyExchangScreen() {
		clsCurrencyMainMenu::showCurrencyExchangeScreen();
	}

	static void _logout() {
		currentUser = clsUser::findUser("");
	}

	static enMainMenuOptions _readMainMenuOptions() {
		cout << "Choose one option between [1] and [10]... ";
		short op = clsInputOutput::readShortNumberBetween(1, 10, "Invalid option, please try again... ");
		return enMainMenuOptions(op);
	}

	static void _performMainMenu(enMainMenuOptions option) {
		switch (option)
		{
		case clsMainMenuScreen::en_ShowClientsList:
			system("cls");
			_showClientsList();
			_backToMainMenu();
			break;
		case clsMainMenuScreen::en_AddNewClient:
			system("cls");
			_addNewClient();
			_backToMainMenu();
			break;
		case clsMainMenuScreen::en_DeleteClient:
			system("cls");
			_deleteClient();
			_backToMainMenu();
			break;
		case clsMainMenuScreen::en_UpdateClient:
			system("cls");
			_updateClientInfo();
			_backToMainMenu();
			break;
		case clsMainMenuScreen::en_FindClient:
			system("cls");
			_findClient();
			_backToMainMenu();
			break;
		case clsMainMenuScreen::en_Transactions:
			system("cls");
			_Transactions();
			_backToMainMenu();
			break;
		case clsMainMenuScreen::en_ManageUsers:
			system("cls");
			_manageUsers();
			_backToMainMenu();
			break;
		case clsMainMenuScreen::en_LoginRegisterList:
			system("cls");
			_LoginRegistersScreen();
			_backToMainMenu();
			break;
		case clsMainMenuScreen::en_CurrencyExchange:
			system("cls");
			_showCurrencyExchangScreen();
			_backToMainMenu();
			break;
		case clsMainMenuScreen::en_LogOut:
			system("cls");
			_logout();
			break;
		default:
			break;
		}
	}

	static void _Body() {
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t[6] Transactions.\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t[8] Show Login Registers List.\n";
		cout << setw(37) << left << "" << "\t[9] Currency Exchang Menu.\n";
		cout << setw(37) << left << "" << "\t[10] Logout.\n";
		cout << setw(37) << left << "" << "===========================================\n";
	}

	public:

		static void showMainMenuScreen() {
			_drawScreenHeader("Main Menu Screen");
			_Body();
			_performMainMenu(_readMainMenuOptions());
		}
};

