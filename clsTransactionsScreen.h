#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include"clsDepositScreen.h"
#include"clsWithdraoScreen.h"
#include"clsTotalBalancesScreen.h"
#include"clsMainScreen.h"
#include"clsTransferLogScreen.h"
#include"clsTransferScreen.h"
using namespace std;

class clsTransactionsScreen :protected clsScreen
{


private:
    enum enTransactionsMenueOptions 
     {
        eDeposit = 1,
        eWithdraw = 2,
		eTransfer = 3,
        eShowTotalBalance = 4,
        eShowTransferLog = 5,
        eShowMainMenue = 6
    };

    static short ReadTransactionsMenueOption()
    {
        cout << setw(37) << left << "" << ". Choose what do you want to do ? [ 1 to 6 ] ? \n";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, " Enter Number between 1 to 6  User1  ? \n");
        return Choice;
    }


    static void _ShowDepositScreen()//1
    {
       // cout << "\n Deposit Screen will be here.\n";
		clsDepositScreen::ShowDepositScreen();
    }

    static void _ShowWithdrawScreen()//2
    {
		clsWithdrawScreen::ShowWithdrawScreen();
        //cout << "\n Withdraw Screen will be here.\n";
    }

    static void _ShowTotalBalancesScreen()//3
    {
        //cout << "\n Balances Screen will be here.\n";
		clsTotalBalancesScreen::ShowTotalBalances();
    }


   static  void _ShowTransferScreen()//4
    {
          clsTransferLogScreen::ShowTransferLogScreen();

	}


    static void _ShoweTransfer()//5
    {
		        //cout << "\n Transfer Screen will be here.\n";
                clsTransferScreen::ShowTresfort();


    }




    static void _GoBackToTransactionsMenue()
    {
        cout << "\n\nPress any key to go back to Transactions Menue...........";
        system("pause>0");
        ShowTransactionsMenue();

    }

    static void _PerformTransactionsMenueOption(enTransactionsMenueOptions TransactionsMenueOption)
    {
        switch (TransactionsMenueOption)
        {
        case enTransactionsMenueOptions::eDeposit://1
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eWithdraw://2
        {
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenue();
            break;
        }
		case enTransactionsMenueOptions::eTransfer://3
        
        {
            system("cls");
			_ShoweTransfer();
            _GoBackToTransactionsMenue();
			break;
        }


        case enTransactionsMenueOptions::eShowTotalBalance://4
        {
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eShowTransferLog://5
        {
            system("cls");
            _ShowTransferScreen();
            _GoBackToTransactionsMenue();


        }

        case enTransactionsMenueOptions::eShowMainMenue://6
        {

            //do nothing here the main screen will handle it :-) ;
        }
        }


    }



public:


    static void ShowTransactionsMenue()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pListClients))
        {
            return;// this will exit the function and it will not continue
        }

        system("cls");
        _DrawScreenHeader("\tTransactions Screen");

      

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t Transactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t   [1]   Deposit                .   \n";
        cout << setw(37) << left << "" << "\t   [2]   Withdraw               .   \n";
		cout << setw(37) << left << "" << "\t   [3]   Transfer               .   \n";
        cout << setw(37) << left << "" << "\t   [4]   Total Balances         .   \n";
        cout << setw(37) << left << "" << "\t   [5]   Show Transfer Log      .   \n";
        cout << setw(37) << left << "" << "\t   [6]   Main Menue             .   \n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransactionsMenueOption((enTransactionsMenueOptions)ReadTransactionsMenueOption());
    }

};

