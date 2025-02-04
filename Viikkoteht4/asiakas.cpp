#include "asiakas.h"

Asiakas::Asiakas(string n, double luottoRaja)
    : nimi(n), kayttotili(n), luottotili(n, luottoRaja) {
    cout << "asiakkuus luotu: " << nimi << endl;
    showSaldo();
}

void Asiakas::showSaldo()
{
    cout << "\n" << nimi << endl;
    cout << "kayttotilin saldo: " << kayttotili.getBalance() << endl;
    cout << "luottotilin saldo: " << luottotili.getBalance() << endl;
}

bool Asiakas::talletus(double summa)
{
    return kayttotili.deposit(summa);
}

bool Asiakas::nosto(double summa)
{
    return kayttotili.withdraw(summa);
}

bool Asiakas::luotonMaksu(double summa)
{
    return luottotili.deposit(summa);
}

bool Asiakas::luotonNosto(double summa)
{
    return luottotili.withdraw(summa);
}

bool Asiakas::tiliSiirto(double summa, Asiakas &vastaanottaja)
{
    if (summa <= 0) {
        cout << "ei onnistu, summa nolla tai negatiivinen" << endl;
        return false;
    }
    cout << "pankkitili: " << nimi << " siirtaa " << summa << " " << vastaanottaja.nimi << ":lle" << endl;

    if (kayttotili.withdraw(summa)) {
        cout << "pankkitili: " << nimi << " nosto " << summa << " tehty " << endl;
    }

    else if (luottotili.withdraw(summa)) {
        cout << "luottotili: " << nimi << " nosto " << summa << " tehty, luottoa jaljella " << luottotili.getBalance() << endl;
    }

    else {
        cout << "siirto ei onnistu, ei tarpeeksi rahaa" << endl;
        return false;
    }

    if (vastaanottaja.talletus(summa)) {
        cout << vastaanottaja.nimi << " pankkitili: talletus " << summa << " tehty" << endl;
    }
    return true;
}
