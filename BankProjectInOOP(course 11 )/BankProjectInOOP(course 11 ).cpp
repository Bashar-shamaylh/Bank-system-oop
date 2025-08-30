
#include <iostream>
using namespace std;

#include "clsMainScreen.h"


#include "clsLoginScreen.h"
int main()
{
    //clsMainScreen::ShowMainMenu();
    while (true)
    {
        if(!clsLoginScreen::ShowLoginScreen())
            break;

    }
   
}

