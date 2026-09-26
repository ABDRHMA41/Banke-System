#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUsers.h"
#include "clsMainScreen.h"
#include "Golobal.h"

class clsLoginScreen :protected clsScreen
{

private:

    static  bool _Login()
    {
        bool LoginFaild = false;
		short FalidLoginCount = 0;
        string
         Username,
         Password;
        int count = 3;



            do
            {

                if (LoginFaild)
                {
                    FalidLoginCount++;

                    cout << "\nInvlaid Username/Password!\n";
                    cout << "You have " << (3 - FalidLoginCount) << " attempt(s) left before the program exits. \n";
                    cout << "Trails To Login \n";

                }
                if (FalidLoginCount == 3)
                {
                    cout << "You Are Locked  After 3 Faild Trails \n\n ";
                    return false;
                }
                cout << "\n";
                cout << "\t\tPleas Enter Username  ? \n";
                cout << "\t\t"; cin >> Username;
                cout << "\t\t Pleas Enter Password  ? \n";
                cout << "\t\t"; cin >> Password;

                CurrentUser = clsUser::Find(Username, Password);

                LoginFaild = CurrentUser.IsEmpty();

            } while (LoginFaild);
            CurrentUser.RegisterLogIn();
            clsMainScreen::ShowMainMenue();
        

    }

public:




    

    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\tLogin Screen");

      return   _Login();
    }

};

    