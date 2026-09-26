#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsUsers.h"
#include "clsInputValidate.h"

class clsDeleteUserScreen :protected clsScreen
{

private:
    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________\n";
		cout << "\n=============================================================";
        cout << "\nFirstName            :   " << User.FirstName;
        cout << "\nLastName             :   " << User.LastName;
        cout << "\nFull Name            :   " << User.FullName();
        cout << "\nEmail                :   " << User.Email;
        cout << "\nPhone                :   " << User.Phone;
        cout << "\nUser Name            :   " << User.UserName;
        cout << "\nPassword             :   " << User.Password;
        cout << "\nPermissions          :   " << User.Permissions;
		cout << "\n=============================================================";
    }

public:
    static void ShowDeleteUserScreen()
    {

        _DrawScreenHeader("\tDelete User Screen");

        string UserName = "";

        cout << "\n Please Enter UserName  : ";
        UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser is not found, choose another one  : ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User1 = clsUser::Find(UserName);
        _PrintUser(User1);

        cout << "\nAre you sure you want to delete this User  y and n ? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            if (User1.Delete())
            {
				system("cls");
                cout << "\nUser Deleted Successfully :-)\n";
                _PrintUser(User1);
            }
            else
            {
                cout << "\nError User Was not Deleted\n";
            }
        }
    }

};

