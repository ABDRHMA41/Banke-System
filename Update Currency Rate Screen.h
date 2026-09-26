#pragma once
#include"clsScreen.h"
class clsUpdateCurrrenciesScreen : protected clsScreen

{
private:
	static void _PrintCurrencyRateUpdateMessage()
	{
		cout << "\n\n\t\t\t\t\tCurrency Rate Updated Successfully :-)\n";
	}
public:
	static void ShowUpdateCurrencyRateScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pListClients))
		{
			return;// this will exit the function and it will not continue
		}

		_DrawScreenHeader("\tUpdate Currency Rate Screen");
		_PrintCurrencyRateUpdateMessage();

	}

};

