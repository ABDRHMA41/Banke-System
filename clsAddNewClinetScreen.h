#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>

class clsAddNewClientScreen : protected clsScreen
{
private:
    static void _ReadClientInfo(clsBankClient& Client)
    {
        cout << "\n Pleas  Enter FirstName  : \n";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\n Pleas Enter LastName  :\n ";
        Client.LastName = clsInputValidate::ReadString();
        
       // cout << "\n Pleas Enter Age  :\n ";
        //Client.Age = clsInputValidate::ReadString();    

        cout << "\n Pleas Enter Email  :\n ";
        Client.Email = clsInputValidate::ReadString();

        cout << "\n Pleas Enter Phone :\n ";
        Client.Phone = clsInputValidate::ReadString();

        cout << "\n Pleas Enter PinCode  : \n";
        Client.PinCode = clsInputValidate::ReadString();

        cout << "\n Pleas  Enter Account Balance :\n";

        Client.AccountBalance = clsInputValidate::ReadFloatNumber();
    }

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << " ---------------\n";
        cout << "\n=====================================================";
        cout << "\nFirstName     :    " << Client.FirstName;
        cout << "\nLastName      :    " << Client.LastName;
        cout << "\nFull Name     :    " << Client.FullName();
        cout << "\nEmail         :    " << Client.Email;
        cout << "\nPhone         :    " << Client.Phone;
        cout << "\nAcc. Number   :    " << Client.AccountNumber();
        cout << "\nPin Cod       :    " << Client.PinCode;
        cout << "\nBalance       :    " << Client.AccountBalance;
        cout << "\n=====================================================";

    }

public:

    static void ShowAddNewClientScreen()
    {


        if (!CheckAccessRights(clsUser::enPermissions::pListClients))
        {
            return;// this will exit the function and it will not continue
        }


        _DrawScreenHeader("\tAdd New Client Screen");

        string AccountNumber = "";

        cout << "\n  Please Enter Account Number :\n ";
        AccountNumber = clsInputValidate::ReadString();
        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number Is Already Used , Choose Another One : ";
            AccountNumber = clsInputValidate::ReadString();
        }


        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);


        _ReadClientInfo(NewClient);

        clsBankClient::enSaveResults SaveResult;

        SaveResult = NewClient.Save();

        switch (SaveResult)
        {
        case  clsBankClient::enSaveResults::svSucceeded:
        {
            cout << "\nAccount Addeded Successfully :-)\n";
            _PrintClient(NewClient);
            break;
        }
        case clsBankClient::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError account was not saved because it's Empty";
            break;

        }
        case clsBankClient::enSaveResults::svFaildAccountNumberExists:
        {
            cout << "\nError account was not saved because account number is used!\n";
            break;

        }
        }
    }



};

