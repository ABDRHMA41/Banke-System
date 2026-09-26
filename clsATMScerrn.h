#pragma once

#include <iostream>
#include"clsScreen.h"
//#include"LibSystemATM.h"
class clsATMScerrn: protected clsScreen
{
	enum enMainMenueOptions 
    {

		eQuickWithdraw = 1, 

        eNormalWithdraw = 2, 

        eDeposit = 3,

		eCheckBalance = 4,

        eLogout = 5

	};

	static short ReadMainMenueOption()
	{
		cout << setw(37) << left << "" << " Choose what do you want to do  ? [ 1 to 5 ]  ?\n\t\t\t\t\t. ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, " Enter Number between 1 to 5 ?\n\t\t.");
		return Choice;
	}


	static void _GoBackToMainMenue()
	{
		cout << setw(37) << left << "" << "\n";
		cout << setw(37) << left << "" << "\n\t Press any key to go back to Main Menue...";
		cout << setw(37) << left << "" << "\n\t_________________________________________\n";
		system("pause>0");
		ShowMainMenue();
	}



	static void _ShowQuickWithdrawScreen()//1
	{
		//LibSystemATM::clsATM::ShowQuickWithdrawScreen();
		//cout << "\nQuick Withdraw Screen Will Be Here.\n";
	}


	static void _ShowNormalWithdrawScreen()//2
	{
		cout << "\nNormal Withdraw Screen Will Be Here.\n";
	}


	static void _ShowDepositScreen()//3
	{
		cout << "\nDeposit Screen Will Be Here.\n";
	}


	static void _ShowCheckBalanceScreen()//4
	{
		
		
		cout << "\nCheck Balance Screen Will Be Here.\n";

	}	

	static void _Logout()//5
	{
		CurrentUser = clsUser::Find("", "");

	}


    static  void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {
		switch (MainMenueOption)
		{
		case enMainMenueOptions::eQuickWithdraw://1
			_ShowNormalWithdrawScreen();
			_GoBackToMainMenue();
			break;

		case enMainMenueOptions::eNormalWithdraw://2
			_ShowNormalWithdrawScreen();
			_GoBackToMainMenue();
			break;

		case enMainMenueOptions::eDeposit://3
			_ShowDepositScreen();
			_GoBackToMainMenue();
			break;

		case enMainMenueOptions::eCheckBalance://4
			_ShowCheckBalanceScreen();
			_GoBackToMainMenue();
			break;

		case enMainMenueOptions::eLogout://5
			_Logout();
			break;

		}
    
    
    
    
    }






public:

              static  void ShowMainMenue()
                {
				clsScreen::_DrawScreenHeader("\tATM Screen");
                    system("cls");
					cout << "\n\n\n\n\n\n\n";
                    cout << setw(35) << left << "" << "===========================================\n";
                    cout << setw(35) << left << "" << "\t   ATM Main Menue Screen\n";
                    cout << setw(35) << left << "" << "===========================================\n";
                    cout << setw(35) << left << "" << "\t[1] Quick Withdraw.\n";
                    cout << setw(35) << left << "" << "\t[2] Normal Withdraw.\n";
                    cout << setw(35) << left << "" << "\t[3] Deposit\n";
                    cout << setw(35) << left << "" << "\t[4] Check Balance.\n";
                    cout << setw(35) << left << "" << "\t[5] Logout.\n";
                    cout << setw(35) << left << "" << "===========================================\n";
                    _PerfromMainMenueOption((enMainMenueOptions)ReadMainMenueOption());
                }

};

