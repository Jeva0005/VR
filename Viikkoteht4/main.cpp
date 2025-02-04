#include <iostream>
#include "asiakas.h"

using namespace std;

int main()
{
    Asiakas asiakas1("Mario", 1000.0);
    Asiakas asiakas2("Gordon", 1000.0);

    asiakas1.talletus(250);
    asiakas1.luotonNosto(150);
    asiakas1.showSaldo();

    asiakas2.showSaldo();

    asiakas1.tiliSiirto(50, asiakas2);

    asiakas1.showSaldo();
    asiakas2.showSaldo();

    return 0;
}
