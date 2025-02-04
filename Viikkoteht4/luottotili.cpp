#include "luottotili.h"

Luottotili::Luottotili() {


}

Luottotili::Luottotili(string o, double lr)
: Pankkitili(o)
{
    luottoRaja = lr;
    saldo = luottoRaja;
    cout << "luottotili luotu " << omistaja << ":lle, luottoraja " << luottoRaja << endl;
}

bool Luottotili::withdraw(double summa)
{
    if (summa < 0){
        cout << "luottotililta nosto ei onnistu, summa negatiivinen" << endl;
        return false;
    } else if (saldo - summa < -luottoRaja){
        cout << "luottotililta nosto ei onnistu, luottoraja ylitetty" << endl;
        return false;
    } else {
        saldo -= summa;
        cout << "luottotililta nostettu: " << summa << ", uusi saldo: " << saldo << endl;
        return true;
    }
}

bool Luottotili::deposit(double summa)
{
    if (summa < 0){
        cout << "luottotililta talletus ei onnistu, summa negatiivinen" << endl;
        return false;
    } else if (saldo + summa > luottoRaja){
        cout << "luottotililta talletus ei onnistu, luottoraja ylitetty" << endl;
        return false;
    } else {
        saldo += summa;
        cout << "luottotilin velkaa maksettu: " << summa << ", uusi velka: " << saldo << endl;
        return true;
    }
}
