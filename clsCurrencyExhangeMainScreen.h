#pragma once


#include <iostream>
#include <iomanip>
#include"clsInputValidate.h"

#include"clsScreen.h"


#include"clsCurrenciesListScreen.h"//1
#include"clsFindCurrency.h"//2
#include"clsUpdateCurrency.h"//3
#include "clsCurrencyCalculatorScrren.h"//4


using namespace std;


class clsCurrencyExhangeMainScreen : protected clsScreen
{
    enum  enMainMenueOptions
    {
		ListCurrencyRates = 1,
		FindCurrencyRate = 2,
        UpdateCurrencyRate = 3,
		CurrencyCalculator = 4,
		MainMenue = 5

    };

    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << " Choose what do you want to do  ? [ 1 to 5 ]  ?\n\t\t\t\t\t. ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, " Enter Number between 1 to 5 ?\n\t\t.");
        return Choice;
    }


    static void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n";
        cout << setw(37) << left << "" << "\n\t Press any key to go back to Main Menue...";
        system("pause>0");
        ShowCurrencyExchangeScreen();
	}




    static void _ShowListCurrencyRatesScreen()
    {

		clsCurrenciesListScreen::ShowCurrenciesListScreen();

    }
    static void _ShowFindCurrencyRateScreen()
    {
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}
    static void _ShowUpdateCurrencyRateScreen()
    {
        clsUpdateCurrenc::ShowUpdateCurrencyRateScreen();
    }

    static void _ShowCurrencyCalculatorScreen()
    {
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();    
	}





    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenueOptions::ListCurrencyRates:
            system("cls");

            _ShowListCurrencyRatesScreen();//1
            _GoBackToMainMenue();
            break;
        case enMainMenueOptions::FindCurrencyRate:
            system("cls");

            _ShowFindCurrencyRateScreen();//2
            _GoBackToMainMenue();               
            break;
        case enMainMenueOptions::UpdateCurrencyRate:
            system("cls");

            _ShowUpdateCurrencyRateScreen();//3
                _GoBackToMainMenue();

            break;
        case enMainMenueOptions::CurrencyCalculator:
            system("cls");

            _ShowCurrencyCalculatorScreen();//4
            _GoBackToMainMenue();

            break;
        case enMainMenueOptions::MainMenue:

            break;
        }
    }




    public:


    static void ShowCurrencyExchangeScreen()
    {
        system("cls");
        _DrawScreenHeader("\tCurrency Exchange Screen");
        cout << setw(37) << left << "" << "==============================================\n";
        cout << setw(37) << left << "" << "\t\t\tCurrency Exchange Menue\n";
        cout << setw(37) << left << "" << "==============================================\n";
        cout << setw(37) << left << "" << "\t  [1]  List Currency Rates         .\n";
        cout << setw(37) << left << "" << "\t  [2]  Find Currency Rate          .\n";
        cout << setw(37) << left << "" << "\t  [3]  Update Currency Rate        .\n";
        cout << setw(37) << left << "" << "\t  [4]  Currency Calculator         .\n";
        cout << setw(37) << left << "" << "\t  [5]  Main Menu                   .\n";
        cout << setw(37) << left << "" << "=============================================\n";
        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
    };
};

