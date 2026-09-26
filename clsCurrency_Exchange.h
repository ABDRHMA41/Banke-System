#pragma once
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsMainScreen.h"
#include"clsUsers.h"
#include <iomanip>
#include"clsCurrency_Exchange.h"
#include"clsListCurrenciesScreen.h"
#include"clsFindCurrenciesScreen.h"
#include"Update Currency Rate Screen.h"
using namespace std;
class clsCurrency_Exchange : private  clsScreen

{

   private:
    enum enCurrency_ExchangeMenueOptions
    {
        eListCurrency = 1,
        eFindCurrncy = 2,
        eUpdateRate = 3,
        eCurrn_Calc = 4,
        eShowMainMenue = 5
    };
    


    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do  ? [ 1 to 5 ]  ?\n\t\t\t\t\t. ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 10, " Enter Number between 1 to 5 ?\n\t\t.");
        return Choice;
    }




    static  void _ShowListCurrencyScreen()//1
    {
		//cout << "List Currency Screen will be here.\n";
		clsListCurrenciesScreen::ShowCurrenciesList();

    }


	static void _ShowFindCurrencyScreen()//2
    {

		//cout << "Find Currency Screen will be here.\n";
        clsFindCurrenciesScreen::ShowFindCurrencyScreen();
        
    }

    static void _ShowUpdateCurrencyRateScreen()//3
    {

	//	cout << " Update Currency Rate Screen will be here.\n";
        clsUpdateCurrrenciesScreen::ShowUpdateCurrencyRateScreen();
    
    }

    static void _ShowCurrencyCalculatorScreen()//4
    {

   
		cout << "Currency Calculator Screen will be here.\n";

    }
	


    static void _GoBackToCurrency_ExchangeMenue()
    {

        
        cout << setw(37) << left << "" << "\n";
        cout << setw(37) << left << "" << "\n\t Press any key to go back to Main Menue........";
        cout << setw(37) << left << "" << "\n\t_________________________________________\n";
        system("pause>0");
        ShowCurrency_ExchangeScreen();


    }















    static void _Perform_Currency_Exchange_MenueOption(enCurrency_ExchangeMenueOptions Currency_ExchangeMenueOptions)
    {

        switch ( Currency_ExchangeMenueOptions)
       
        {
              case enCurrency_ExchangeMenueOptions::eListCurrency://1
              {
                  system("cls");
				  _ShowListCurrencyScreen();
				  _GoBackToCurrency_ExchangeMenue();
                  break;
             
              }
              case enCurrency_ExchangeMenueOptions::eFindCurrncy://2
              {
                  system("cls");
				  _ShowFindCurrencyScreen();
				  _GoBackToCurrency_ExchangeMenue();
              break;
              }
             
              case enCurrency_ExchangeMenueOptions::eUpdateRate://3
              {
                  system("cls");
				  _ShowUpdateCurrencyRateScreen();
				  _GoBackToCurrency_ExchangeMenue();
                  break;
              }
              case enCurrency_ExchangeMenueOptions::eCurrn_Calc://4
              {
                  system("cls");
				  _ShowCurrencyCalculatorScreen();
				  _GoBackToCurrency_ExchangeMenue();
                  break;
              }
             
              case enCurrency_ExchangeMenueOptions::eShowMainMenue://5
              {


              }
             
        }
    }
   

 

public:

    static void ShowCurrency_ExchangeScreen()
    {

            if (!CheckAccessRights(clsUser::enPermissions::pListClients))
            {
                return;// this will exit the function and it will not continue
            }
			system("cls");
        _DrawScreenHeader("\tCurrency Exchange Main Screen");

        cout << setw(37) << left << "" << "==============================================\n";
        cout << setw(37) << left << "" << "\t\tCurrency Exchange  Menue\n";
        cout << setw(37) << left << "" << "==============================================\n";
        cout << setw(37) << left << "" << "\t  [ 1]  List Currencies          .\n";
        cout << setw(37) << left << "" << "\t  [ 2]  Find Currency            .\n";
        cout << setw(37) << left << "" << "\t  [ 3]  Update  Rate             .\n";
        cout << setw(37) << left << "" << "\t  [ 4]  Currency Calculator      .\n";
        cout << setw(37) << left << "" << "\t  [ 5]  Main Menue               .\n";
        cout << setw(37) << left << "" << "=============================================\n";
        _Perform_Currency_Exchange_MenueOption((enCurrency_ExchangeMenueOptions)_ReadMainMenueOption());
    }
    
};


