#pragma once
#include <iostream>
#include <iomanip>

#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputOutput.h"

using namespace std;
class clsAddNewUserScreen : protected clsScreen
{
private:
    static void _printUser(clsUser& User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.getFirstName();
        cout << "\nLastName    : " << User.getLastName();
        cout << "\nFull Name   : " << User.getFullName();
        cout << "\nEmail       : " << User.getEmail();
        cout << "\nPhone       : " << User.getPhoneNumber();
        cout << "\nUser Name   : " << User.getUserName();
        cout << "\nPassword    : " << User.getPassword();
        cout << "\nPermissions : " << User.getPermissions();
        cout << "\n___________________\n";

    }

    static short _readPermissions() {
        cout << "Do u want to give this user all permissions? [y/n] ";
        char confirm = clsInputOutput::readChar("Invalid character, try again... ");
        if (confirm == 'y' || confirm == 'Y') {
            return -1;
        }
        else {
            short perm = 0;
            cout << "List Clients permission [y/n] : ";
            confirm = clsInputOutput::readChar("Invalid character, try again... ");
            if (confirm == 'y' || confirm == 'Y') {
                perm += short(clsUser::enUserPermissions::en_ListClientsPerm);
            }
            cout << "Add New Client permission [y/n] : ";
            confirm = clsInputOutput::readChar("Invalid character, try again... ");
            if (confirm == 'y' || confirm == 'Y') {
                perm += short(clsUser::enUserPermissions::en_AddNewClientPerm);
            }
            cout << "Delete Client permission [y/n] : ";
            confirm = clsInputOutput::readChar("Invalid character, try again... ");
            if (confirm == 'y' || confirm == 'Y') {
                perm += short(clsUser::enUserPermissions::en_DeleteClientPerm);
            }
            cout << "Update Client permission [y/n] : ";
            confirm = clsInputOutput::readChar("Invalid character, try again... ");
            if (confirm == 'y' || confirm == 'Y') {
                perm += short(clsUser::enUserPermissions::en_UpdateClientPerm);
            }
            cout << "Find Client permission [y/n] : ";
            confirm = clsInputOutput::readChar("Invalid character, try again... ");
            if (confirm == 'y' || confirm == 'Y') {
                perm += short(clsUser::enUserPermissions::en_FindClientPerm);
            }
            cout << "Transactions permission [y/n] : ";
            confirm = clsInputOutput::readChar("Invalid character, try again... ");
            if (confirm == 'y' || confirm == 'Y') {
                perm += short(clsUser::enUserPermissions::en_TransactionsPerm);
            }
            cout << "Manage Users permission [y/n] : ";
            confirm = clsInputOutput::readChar("Invalid character, try again... ");
            if (confirm == 'y' || confirm == 'Y') {
                perm += short(clsUser::enUserPermissions::en_ManageUsersPerm);
            }
            cout << "List Login Registers permission [y/n] : ";
            confirm = clsInputOutput::readChar("Invalid character, try again... ");
            if (confirm == 'y' || confirm == 'Y') {
                perm += short(clsUser::enUserPermissions::en_ListLoginRegistersPerm);
            }
            return perm;
        }
    }

	static void _readNewUserInfo(clsUser& user) {
        cout << "First name: ";
        user.setFirstName(clsInputOutput::readString("Invalid name! please try again... "));
        cout << "Last name: ";
        user.setLastName(clsInputOutput::readString("Invalid name! please try again... "));
        cout << "Phone number: ";
        user.setPhoneNumber(clsInputOutput::readString("Invalid phone number! please try again... "));
        cout << "Email: ";
        user.setEmail(clsInputOutput::readString("Invalid email! please try again... "));
        cout << "Password: ";
        user.setPassword(clsInputOutput::readString("Invalid Password! please try again..."));
        user.setPermissions(_readPermissions());
	}

public:
	static void showAddNewUserScreen() {
        _drawScreenHeader("Add New User Screen");
        cout << "Username: ";
        string userName = clsInputOutput::readString("Invalid username, please try again... ");
        while (clsUser::isUserExist(userName)) {
            cout << userName << " already exist, try another one... ";
            userName = clsInputOutput::readString("Invalid username, please try again... ");
        }
        clsUser user = clsUser::getAddNewUserObject(userName);
        _readNewUserInfo(user);
        switch (user.save())
        {
        case clsUser::enSave::en_Failed_Empty:
            cout << "Sorry, this is empty user!" << endl;
            break;
        case clsUser::enSave::en_Failed_Exist:
            cout << "Sorry, this user is already exist!" << endl;
            break;
        case clsUser::enSave::en_Succeed:
            _printUser(user);
            cout << "User added successfully :)" << endl;
            break;
        default:
            break;
        }
	}
};
