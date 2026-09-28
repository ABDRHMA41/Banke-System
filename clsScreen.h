#pragma once
#include <iostream>
#include "clsUsers.h"
#include "Golobal.h"
#include"clsDate.h"
using namespace std;

class clsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle ="")
    {

        cout << "\n\n\n\n\n\n";
        cout << "\033[0m\n";

        cout << "\t\t\t\t\t__________________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t__________________________________________\n\n";

        clsDate Date;
        cout << "\t\t\t\t\tDate : " << Date.DateToString() << "\n";

	   cout << "\t\t\t\t\tUser  : " << CurrentUser.FullName() << "\n";
    }





    static bool CheckAccessRights(clsUser::enPermissions Permission)
    {

        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            cout << "\n\n\t\t\t\t\t  Sorry Not  Parmations  Access System .";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin .";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        }

    }

};

