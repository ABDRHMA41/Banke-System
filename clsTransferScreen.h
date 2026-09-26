#pragma once
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
class clsTransferScreen  :private clsScreen
{
private:

    static void _PrintClient(clsBankClient Client)
    {

        cout << "\nClient Card:";
        cout << "\n_______________\n";
        cout << "\----------------------------------------------------";
        cout << "\nFull Name     :    " << Client.FullName();
        cout << "\nAcc. Number   :    " << Client.AccountNumber();
        cout << "\nBalance       :    " << Client.AccountBalance;
        cout << "\n----------------------------------------------------\n";
    }

    static string _ReadAccountNumber()
    {
        string AccountNumber = "";
        cin >> AccountNumber;
        return AccountNumber;
    }


public:


	static void ShowTresfort()
	{
		clsScreen::_DrawScreenHeader("\tTresfer Screen");
        cout << "\nPlease enter AccountNumber ? \n";
        string AccountNumber = _ReadAccountNumber();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
            AccountNumber = _ReadAccountNumber();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);

        _PrintClient(Client1);

        //=============================


        string AccountNumber2 = _ReadAccountNumber();

		cout << "\nPlease enter Amount to transfer? ";

        while (!clsBankClient::IsClientExist(AccountNumber2))
        {
            cout << "\nClient with [" << AccountNumber2 << "] does not exist.\n";
            AccountNumber2 = _ReadAccountNumber();
        }
		clsBankClient Client2 = clsBankClient::Find(AccountNumber2);
		_PrintClient(Client2);
		cout << "\nPlease enter Amount to transfer? ";
		double Amount = clsInputValidate::ReadDblNumber();
        while (Amount > Client1.AccountBalance)
        {
            cout << "\nAmount Exceeds the available balance (" << Client1.AccountBalance << "), Enter again? ";
            Amount = clsInputValidate::ReadDblNumber();
		}
		Client1.AccountBalance -= Amount;
		Client2.AccountBalance += Amount;
		Client1.Save();
		Client2.Save();
		cout << "\nTransfer done successfully.\n";

	
	}
};

