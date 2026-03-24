#pragma once
#include <iostream>
#include <iomanip>

#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

using namespace std;
class clsManageUsersScreen:protected clsScreen
{
private:

    enum enManageUsersOptions {
        en_ListUsers = 1,
        en_AddNewUser = 2,
        en_DeleteUser = 3,
        en_UpdateUser = 4,
        en_FindUser = 5,
        en_BackMainMenu = 6
    };

    static enManageUsersOptions _readManageUsersOptions() {
        cout << "Choose one option between [1] and [6]... ";
        short option = clsInputOutput::readShortNumberBetween(1, 6, "Invalid option, please try again... ");
        return enManageUsersOptions(option);
    }

    static void backToManageUsersMenu() {
        cout << "Press any key to go back manage users screen... ";
        system("pause>0");
        CLEAR_SCREEN;
        showManageUsersScreen();

    }

	static void _body() {
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Manage Users Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";
	}

    static void _showListUsersScreen() {
        clsListUsersScreen::showListUsersScreen();
    }

    static void _showAddNewUserScreen() {
        clsAddNewUserScreen::showAddNewUserScreen();
    }

    static void _showDeleteUserScreen() {
        clsDeleteUserScreen::showDeleteUserScreen();
    }

    static void _showUpdateUserScreen() {
        clsUpdateUserScreen::showUpdateUserScreen();
    }

    static void _showFindUserScreen() {
        clsFindUserScreen::showFindUserScreen();
    }

    

    static void _performManageUsersScreen(enManageUsersOptions option) {
        switch (option)
        {
        case clsManageUsersScreen::en_ListUsers:
            CLEAR_SCREEN;
            _showListUsersScreen();
            backToManageUsersMenu();
            break;
        case clsManageUsersScreen::en_AddNewUser:
            CLEAR_SCREEN;
            _showAddNewUserScreen();
            backToManageUsersMenu();
            break;
        case clsManageUsersScreen::en_DeleteUser:
            CLEAR_SCREEN;
            _showDeleteUserScreen();
            backToManageUsersMenu();
            break;
        case clsManageUsersScreen::en_UpdateUser:
            CLEAR_SCREEN;
            _showUpdateUserScreen();
            backToManageUsersMenu();
            break;
        case clsManageUsersScreen::en_FindUser:
            CLEAR_SCREEN;
            _showFindUserScreen();
            backToManageUsersMenu();
            break;
        case clsManageUsersScreen::en_BackMainMenu:
            break;
        default:
            break;
        }
    }

public:
    static void showManageUsersScreen() {
        if (!CheckAccessRights(clsUser::enUserPermissions::en_ManageUsersPerm)) {
            return;
        }
        _drawScreenHeader("Manage Users Screen");
        _body();
        _performManageUsersScreen(_readManageUsersOptions());
    }
};

