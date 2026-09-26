#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUsers.h"
#include "clsInputValidate.h"
#include <iomanip>

class clsAddNewUserScreen : protected clsScreen
{
private:

    static void _ReadUserInfo(clsUser& User)
    {
        cout << "\n Pleas Enter FirstName: ";
        User.FirstName = clsInputValidate::ReadString();

        cout << "\n Pleas Enter LastName: ";
        User.LastName = clsInputValidate::ReadString();

        cout << "\n Pleas Enter Email: ";
        User.Email = clsInputValidate::ReadString();

        cout << "\n Pleas Enter Phone: ";
        User.Phone = clsInputValidate::ReadString();

        cout << "\n Pleas Enter Password: ";
        User.Password = clsInputValidate::ReadString();

        cout << "\n Pleas Enter Permission: ";
        User.Permissions = _ReadPermissionsToSet();
    }

    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n-----------------\n";
        cout << "=====================================================";
        cout << "\nFirstName          : " << User.FirstName;
        cout << "\nLastName           : " << User.LastName;
        cout << "\nFull Name          : " << User.FullName();
        cout << "\nEmail              : " << User.Email;
        cout << "\nPhone              : " << User.Phone;
        cout << "\nUser Name          : " << User.UserName;
        cout << "\nPassword           : " << User.Password;
        cout << "\nPermissions        : " << User.Permissions;
        cout << "\n===================================================\n";
    }

    static int _ReadPermissionsToSet()
    {

        int Permissions = 0;
        char Answer = 'n';


        cout << "\nDo you want to give full Access ? Y and N? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {


            Permissions += clsUser::enPermissions::pListClients;
        }

        cout << "\nAdd New Client ? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete Client ? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate Client ? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pUpdateClients;
        }

        cout << "\nFind Client ? y/n  ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions ? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pTranactions;
        }

        cout << "\nManage Users ? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pManageUsers;
        }

        return Permissions;

    }

public:

    static void ShowAddNewUserScreen()
    {

        _DrawScreenHeader("\tAdd New User Screen");

        string UserName = "";

        cout << "\nPlease Enter UserName  : ";
        UserName = clsInputValidate::ReadString();
        while (clsUser::IsUserExist(UserName))
        {
            cout << "\nUserName Is Already Used , Choose Another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser NewUser = clsUser::GetAddNewUserObject(UserName);

        _ReadUserInfo(NewUser);

        clsUser::enSaveResults SaveResult;

        SaveResult = NewUser.Save();

        switch (SaveResult)
        {
        case  clsUser::enSaveResults::svSucceeded:
        {
            cout << "\n User Addeded Successfully :-)\n";
            _PrintUser(NewUser);
            break;
        }
        case clsUser::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError User was not saved because it's Empty";
            break;

        }
        case clsUser::enSaveResults::svFaildUserExists:
        {
            cout << "\nError User was not saved because UserName is used!\n";
            break;

        }
        }
    }



};

