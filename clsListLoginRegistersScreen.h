#pragma once
#include <iostream>
#include <iomanip>

#include "clsScreen.h"
#include "clsUser.h"

using namespace std;
class clsListLoginRegistersScreen:protected clsScreen
{
private:
	
    static void _printRegisterRecordLine(clsUser::stLoginRegistersRecord& reg)
    {

        cout << setw(8) << left << "" << "| " << setw(25) << left << reg.date;
        cout << "| " << setw(12) << left <<reg.username;
        cout << "| " << setw(12) << left << reg.password;
        cout << "| " << setw(12) << left <<reg.permissions;
        //cout << "| " << setw(10) << left << User.getPassword();
        //cout << "| " << setw(12) << left << User.getPermissions();

    }

public:
    static void showListUsersScreen() {

        if (!CheckAccessRights(clsUser::enUserPermissions::en_ListLoginRegistersPerm)) {
            return;
        }

        vector <clsUser::stLoginRegistersRecord> vRegisters = clsUser::getAllLoginRegisters();

        string Title = "\t  Login Registers List Screen";
        string SubTitle = "\t    (" + to_string(vRegisters.size()) + ") User(s).";

        _drawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(25) << "Date&Time";
        cout << "| " << left << setw(12) << "UserName";
        cout << "| " << left << setw(12) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
      /*  cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";*/
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vRegisters.size() == 0)
            cout << "\t\t\t\tNo Login Registers Available In the System!";
        else

            for (clsUser::stLoginRegistersRecord& reg : vRegisters )
            {

                _printRegisterRecordLine(reg);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }
};

