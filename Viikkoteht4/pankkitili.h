#ifndef PANKKITILI_H
#define PANKKITILI_H
#include <iostream>

using namespace std;

class Pankkitili
{

protected:
    string omistaja;
    double saldo;

public:
    Pankkitili();
    Pankkitili(string o);

    virtual bool withdraw(double);
    virtual bool deposit(double);
    double getBalance() const;
};

#endif // PANKKITILI_H
