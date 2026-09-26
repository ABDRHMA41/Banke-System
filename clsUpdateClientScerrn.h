#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsUpdateClientScreen :protected clsScreen

{
private:

    static void _PrintClient(clsBankClient Client)
    {

        cout << "\nClient Card:";
        cout << " \n---------------\n";
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

    static void ReadClientInfo(clsBankClient& Client)
    {
        cout << "\n Pleas Enter New FirstName: ";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\n Pleas Enter New LastName: ";
        Client.LastName = clsInputValidate::ReadString();

        cout << "\n Pleas Enter New  Email: ";
        Client.Email = clsInputValidate::ReadString();

        cout << "\n Pleas Enter New  Phone: ";
        Client.Phone = clsInputValidate::ReadString();

        cout << "\n Pleas Enter New PinCode: ";
        Client.PinCode = clsInputValidate::ReadString();

        cout << "\n Pleas Enter New  Account Balance: ";
        Client.AccountBalance = clsInputValidate::ReadFloatNumber();
    }

public:

    static void ShowUpdateClientScreen()
    {


        if (!CheckAccessRights(clsUser::enPermissions::pListClients))
        {
            return;// this will exit the function and it will not continue
        }



        _DrawScreenHeader("\tUpdate Client Screen");

        string AccountNumber = "";

        cout << "\n Please Enter client Account Number  : ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one : ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);

        _PrintClient(Client1);

        cout << "\n Are you sure you want to update this client  Y And N ? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

			system("cls");
            cout << "\n\nUpdate Client Info:";
            cout << "\n______________________\n";


            ReadClientInfo(Client1);

            clsBankClient::enSaveResults SaveResult;

            SaveResult = Client1.Save();

            switch (SaveResult)
            {
            case  clsBankClient::enSaveResults::svSucceeded:
            {
                cout << "\n Account Updated Successfully :- )\n";

                _PrintClient(Client1);
                break;
            }
            case clsBankClient::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError account was not saved because it's Empty";
                break;

            }

            }

        }

    }
};

