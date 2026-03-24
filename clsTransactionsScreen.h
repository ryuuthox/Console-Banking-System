#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUtil.h"
#include "clsDepositScreen.h"
#include "clsWithDrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransfersScreen.h"
#include "clsLogTransfersScreen.h"
using namespace std;
class clsTransactionsScreen:protected clsScreen
{
private:
	enum enTransactionsOptions {
		en_deposit = 1,
		en_withDraw = 2,
		en_totalBalances = 3,
		en_Transfers = 4,
		en_LogTransfers = 5,
		en_backMainMenu = 6
	};

	static enTransactionsOptions _readTransactionsOption() {
		cout << "Choose one option between [1] and [6]... ";
		short option = clsInputOutput::readShortNumberBetween(1, 6, "Invalid option, please try again...");
		return enTransactionsOptions(option);
	}

	static void _backToTransactionsMenu() {
		cout << "Press any key to go back transactions menu... ";
		system("pause>0");
		CLEAR_SCREEN;
		showTransactionsMenuScreen();
	}

	static void _showDepositScreen() {
		clsDepositScreen::showDepositScreen();
	}

	static void _showWithdrawScreen() {
		clsWithDrawScreen::showWithDrawScreen();
	}

	static void _showTotalBalancesScreen() {
		clsTotalBalancesScreen::showTotalBalancesScreen();
	}

	static void _showTransfersScreen() {
		clsTransfersScreen::showTransfersScreen();
	}

	static void _showLogTransfersScreen() {
		clsLogTansfersScreen::ShowTransferLogScreen();
	}

	static void _performTransactions(enTransactionsOptions option) {
		switch (option) {
		case enTransactionsOptions::en_deposit:
			CLEAR_SCREEN;
			_showDepositScreen();
			_backToTransactionsMenu();
			break;
		case enTransactionsOptions::en_withDraw:
			CLEAR_SCREEN;
			_showWithdrawScreen();
			_backToTransactionsMenu();
			break;
		case enTransactionsOptions::en_totalBalances:
			CLEAR_SCREEN;
			_showTotalBalancesScreen();
			_backToTransactionsMenu();
			break;
		case enTransactionsOptions::en_Transfers:
			CLEAR_SCREEN;
			_showTransfersScreen();
			_backToTransactionsMenu();
			break;
		case enTransactionsOptions::en_LogTransfers:
			CLEAR_SCREEN;
			_showLogTransfersScreen();
			_backToTransactionsMenu();
			break;
		case enTransactionsOptions::en_backMainMenu:
			break;
		}
	}

	static void _Body() {
		cout << "\n\t\t\t\t\t " <<clsUtil::getRepeatedChar('=',30) << endl;
		cout << clsUtil::getRepeatedChar(' ',43)<< "Transactions Menu";
		cout << "\n\t\t\t\t\t " << clsUtil::getRepeatedChar('=', 30) << endl;
		cout << "\t\t\t\t\t [1] Deposit \n";
		cout << "\t\t\t\t\t [2] Withdraw \n";
		cout << "\t\t\t\t\t [3] Total Ballances \n";
		cout << "\t\t\t\t\t [4] Transfers \n";
		cout << "\t\t\t\t\t [5] Log Transfer Registers \n";
		cout << "\t\t\t\t\t [6] Main Menu \n";
		cout << "\n\t\t\t\t\t " << clsUtil::getRepeatedChar('=', 30) << endl;
	}

public:
	static void showTransactionsMenuScreen() {
		if (!CheckAccessRights(clsUser::enUserPermissions::en_TransactionsPerm)) {
			return;
		}
		_drawScreenHeader("Transactions Screen");
		_Body();
		_performTransactions(_readTransactionsOption());
	}
};

