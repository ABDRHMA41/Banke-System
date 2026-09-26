#pragma once
#include <iostream> 
#include <iomanip>

//=======================================
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include"clsAddNewClinetScreen.h"
#include"clsDlateScreen.h"
#include"clsUpdateClientScerrn.h"   
#include"clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include"clsManageUsersScreen.h"
#include"Golobal.h"
#include"clsLoginRegister.h"
#include"clsListUsersScreen.h"
#include"clsCurrencyExhangeMainScreen.h"
#include"clsATMScerrn.h"
//========================================
using namespace std;

class clsMainScreen :protected clsScreen
{


private:
    enum enMainMenueOptions 
    {
        eListClients = 1,
        eAddNewClient = 2,
        eDeleteClient = 3,
        eUpdateClient = 4, 
        eFindClient = 5, 
        eShowTransactionsMenue = 6,
        eManageUsers = 7,
		enLoginRegister = 8,
		enCurrencyExchange = 9,
		enATMScreen = 10,
        eExit = 11
    };

    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << " Choose what do you want to do  ? [ 1 to 11 ]  ?\n\t\t\t\t\t. ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 11," Enter Number between 1 to 11 ?\n\t\t.");
        return Choice;
    }

    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n";
        cout << setw(37) << left << "" << "\n\t Press any key to go back to Main Menue...";
        cout << setw(37) << left << "" << "\n\t_________________________________________\n";
        system("pause>0");
        ShowMainMenue();
    }
    //-------------------------------------------------------------



    static void _Logout()
    {
        CurrentUser = clsUser::Find("", "");

    }



    static void _ShowAllClientsScreen()//1
    {
        clsClientListScreen::ShowClientsList();
    }
    
    

    static void _ShowAddNewClientsScreen()//2
    {
        clsAddNewClientScreen::ShowAddNewClientScreen();
    }
    


    static void _ShowDeleteClientScreen()//3
    {
		clsDeleteClientScreen::ShowDeleteClientScreen();
    }



	static void _ShowUpdateClientScreen()//4
    {
		clsUpdateClientScreen::ShowUpdateClientScreen();
    }



	static void _ShowFindClientScreen()//5
    {
        clsFindClientScreen::ShowFindClientScreen();
    }



	static void _ShowTransactionsMenue()//6
    {
		clsTransactionsScreen::ShowTransactionsMenue();
    }



	static void _ShowManageUsersMenue()//7
    {
       clsManageUsersScreen::ShowManageUsersMenue();
    }



    static void _ShowCurrencyExchangeScreen()//8
    {
       clsCurrencyExhangeMainScreen::ShowCurrencyExchangeScreen();
    }



    static void _ShowLoginRegisterScreen()//9
    {
		clsLoginRegisterScreen::ShowLoginRegisterScreen();
    }



	static void _ShowATMScreen()//10
	{
		clsATMScerrn::ShowMainMenue();
    }



	static void _ShowEndScreen()//11
    {
        system(" ");
        _Logout();

    }




    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
		case enMainMenueOptions::eListClients://1
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        }





		case enMainMenueOptions::eAddNewClient://2
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;





		case enMainMenueOptions::eDeleteClient://3
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;




		case enMainMenueOptions::eUpdateClient:// 4
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;




		case enMainMenueOptions::eFindClient://5
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;



		case enMainMenueOptions::eShowTransactionsMenue://6
            system("cls");
            _ShowTransactionsMenue();
            _GoBackToMainMenue();

            break;



		case enMainMenueOptions::eManageUsers://7
            system("cls");
            _ShowManageUsersMenue();
			_GoBackToMainMenue();
            break;



		case enMainMenueOptions::enLoginRegister://8
            system("cls");
            _ShowLoginRegisterScreen();
			_GoBackToMainMenue();
			break;



            case enMainMenueOptions::enCurrencyExchange://9
            system("cls");
			_ShowCurrencyExchangeScreen();
            _GoBackToMainMenue();

            break;



		case enMainMenueOptions::enATMScreen://10
			system("cls");
               _ShowATMScreen();           
               _GoBackToMainMenue();
			   break;

               

		case enMainMenueOptions::eExit://11
            system("cls");
            _ShowEndScreen();
        }

    }




public:



    static void ShowMainMenue()
    {
        system("cls");
        _DrawScreenHeader("\t\tMain Screen");
		cout << "\n\n";
        cout << setw(37) << left << "" << "===============================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===============================================\n";
        cout << setw(35) << left << "" << "\t[ 1]    Show Client List             .\n";
        cout << setw(35) << left << "" << "\t[ 2]    Add New Client               .\n";
        cout << setw(35) << left << "" << "\t[ 3]    Delete Client                .\n";
        cout << setw(35) << left << "" << "\t[ 4]    Update Client Info           .\n";
        cout << setw(35) << left << "" << "\t[ 5]    Find Client                  .\n";
        cout << setw(35) << left << "" << "\t[ 6]    Transactions                 .\n";
        cout << setw(35) << left << "" << "\t[ 7]    Manage Users                 .\n";
        cout << setw(35) << left << "" << "\t[ 8]    Login Register               .\n";
        cout << setw(35) << left << "" << "\t[ 9]    Currency Exchange            .\n";
        cout << setw(35) << left << "" << "\t[10]    ATM Screen                     .\n";
        cout << setw(35) << left << "" << "\t[11]    Logout                       .\n";
        cout << setw(37) << left << "" << "==============================================\n";

        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption() );
    }

};

