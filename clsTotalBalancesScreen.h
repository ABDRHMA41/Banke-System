#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include "clsUtil.h"

class clsTotalBalancesScreen : protected clsScreen
{

private:

    static void PrintClientRecordBalanceLine(clsBankClient Client)
    {
        cout << setw(25) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
        cout << ". " << setw(35) << left << Client.FullName();
        cout << ". " << setw(12) << left << Client.AccountBalance <<setw(3)<<"|";
    }

public:

    static void ShowTotalBalances()
    {

        if (!CheckAccessRights(clsUser::enPermissions::pListClients))
        {
            return;// this will exit the function and it will not continue
        }



        vector <clsBankClient> vClients = clsBankClient::GetClientsList();

        string Title = "\t Balances List Screen\n";
        string SubTitle = " (" + to_string(vClients.size()) + ") Client(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(25) << left << "" << "\n\t\t\t_____________________________________________";
        cout << "__________________________\n" << endl;


        cout << setw(25) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(35) << "Client Name";
        cout << "| " << left << setw(12) << "Balance"<<setw(3)<<"|";
        cout << setw(25) << left << "" << "\n\t\t\t_____________________________________________";
        cout << "__________________________\n" << endl;


        double TotalBalances = clsBankClient::GetTotalBalances();

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient Client : vClients)
            {
                PrintClientRecordBalanceLine(Client);
                cout << endl;
            }

        cout << setw(25) << left << "" << "\n\t\t\t_____________________________________________";
        cout << "__________________________\n" << endl;

        cout << setw(8) << left << "" << "\t\t\t\t\tTotal Balances = " << TotalBalances <<" USD $" << endl;
        cout << setw(8) << left << "" << "\t\t\t\t [ " << clsUtil::NumberToText(TotalBalances) << " ]  US Dollar";
    }

};

