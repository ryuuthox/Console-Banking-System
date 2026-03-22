#pragma once
#include <iostream>
#include "clsInputOutput.h"
#include "clsUtil.h"
#include "Global.h"
#include "clsDate.h"

using namespace std;

class clsScreen
{
protected:
    static bool CheckAccessRights(clsUser::enUserPermissions Permission)
    {

        if (!currentUser.checkAccesPermissions(Permission))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        }

    }

    static void _drawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        cout << "\n\t\t\t\t\t UserName: " << currentUser.getUserName() << "\n";
        cout << "\n\t\t\t\t\t Date: "; clsDate::print(clsDate()); cout << "\n";
    }


};

