#pragma once
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsCurrency.h"
class clsFindCurrenciesScreen : protected clsScreen
{

	private:
	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\n\tCurrency Card:";
		cout << "\n\t________________\n";
		cout << "\n\t=====================================================";
		cout << "\n\tCountry          :    " << Currency.Country();
		cout << "\n\tCurrency Code    :    " << Currency.CurrencyCode();
		cout << "\n\tCurrency Name    :    " << Currency.CurrencyName();
		cout << "\n\tRate             :    " << Currency.Rate();
		cout << "\n\t=====================================================";
	}


	static string _ReadCurrencyCode()
	{
		string CurrencyCode;
		cout << "\nPlease Enter Currency Code: ";
		CurrencyCode = clsInputValidate::ReadString();
		return CurrencyCode;
	}
public:

	static void ShowFindCurrencyScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pListClients))
		{
			return;// this will exit the function and it will not continue
		}

		_DrawScreenHeader("\tFind Currency Screen");
		string CurrencyCode;
		CurrencyCode = _ReadCurrencyCode();

		clsCurrency Currency1 = clsCurrency::FindByCode(CurrencyCode);
		if (!Currency1.IsEmpty())
		{
			_DrawScreenHeader("\tFind Currency Screen");
			system("cls");
			cout << "\nCurrency Found :-)\n";
			_PrintCurrency(Currency1);
		}
		else
		{
			cout << "\nCurrency Was not Found :-(\n";
		}
	}

};

