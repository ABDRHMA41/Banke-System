#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsDeleteClientScreen :protected clsScreen
{

private:
    static void _PrintClient(clsBankClient Client)
    {
   

        cout << "\nClient Card:";
        cout << "\n_______________\n";
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
    static void ShowDeleteClientScreen()
    {

        if (!CheckAccessRights(clsUser::enPermissions::pListClients))
        {
            return;// this will exit the function and it will not continue
        }


        _DrawScreenHeader("\tDelete Client Screen");

        string AccountNumber = "";

        cout << "\nPlease Enter Account Number : \n";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number is not Found, Choose Another one : ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        cout << "\nAre You Sure you Want To Delete This Client  Y and N ? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {


            if (Client1.Delete())
            {
				system("cls");
                cout << "\nClient Deleted Successfully :-)\n";
                _PrintClient(Client1);
            }
            else
            {
                cout << "\nError Client Was not Deleted\n";
            }
        }
    }

};

