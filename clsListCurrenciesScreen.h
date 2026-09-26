#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"
#include <iomanip>
class clsListCurrenciesScreen : protected clsScreen
{



private:

    static void PrintCurrencyLine(clsCurrency Currency)
    {

        cout<< setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
        cout << "| " << setw(15) << left << Currency.CurrencyCode();
        cout << "| " << setw(40) << left << Currency.CurrencyName();
		cout << "| " << setw(10) << left << Currency.Rate() << setw(2) <<"|";
    }

public:

    static void ShowCurrenciesList()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pListClients))
        {
            

            return;	


        }


        vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();

        
        string Title = "\tCurrencies List Screen\n";
        
        string SubTitle = " (" + to_string(vCurrencies.size()) +")Currency(s).";
        
        _DrawScreenHeader(Title, SubTitle);
        
        cout << setw(8) << left << "" << "\n\t_______________________________________________________________";
        cout << "_________________________________________\n" << endl;
        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(15) << " Currency Code";
        cout << "| " << left << setw(40) << " Currency Name";
        cout << "| " << left << setw(10) << " Rate" << setw(2) << "|";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________________";
        cout << "_________________________________________\n" << endl;
        if (vCurrencies.size() == 0)
            cout << "\t\t\t\tNo Currencies Available In the System!";
        else
            for (clsCurrency Currency : vCurrencies)
            {
                PrintCurrencyLine(Currency);
                cout << endl;
            }
        cout << setw(8) << left << "" << "\n\t_______________________________________________________________";
        cout << "_________________________________________\n" << endl;
	}



};

