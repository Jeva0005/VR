#include "pankkitili.h"

Pankkitili::Pankkitili() {}

Pankkitili::Pankkitili(string o) : omistaja(o), saldo(0)
{
    cout << "Pankkitili luotu " << omistaja << ":lle" << endl;

}

bool Pankkitili::withdraw(double summa)
{
    if(summa < 0){
        cout << "nosto ei onnistu, summa negatiivinen" << endl;
        return false;
    } else if (summa > saldo){
            cout << "nosto ei onnistu, summa liian iso" << endl;
            return false;
        } else {
            saldo -= summa;
            cout << "Nostettu: " << summa << ", uusi saldo:" << saldo << endl;
            return true;
        }
}

bool Pankkitili::deposit(double summa)
{
    if (summa < 0){
        cout << "talletus ei onnistu, summa negatiivinen" <<endl;
        return false;
    }
    saldo+= summa;
    cout << "talletettu: " << summa << ", uusi saldo: " << saldo << endl;
    return true;
}

double Pankkitili::getBalance() const
{
    return saldo;
}
