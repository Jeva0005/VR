#include "chef.h"

Chef::Chef() {

    cout << "Chef default konstruktori, ei nimea" << endl;
}

Chef::Chef(string name)
{
    chefName = name;
    cout << "Chef konstruktori, kokin nimi " << chefName <<endl;
}

Chef::~Chef()
{
    cout << "Chef destruktori" <<endl;
}

string Chef::getChefName() const
{
    return chefName;
}

int Chef::makeSalad(int aines)
{
    int annoksia = aines / 5;
    cout << "Kokki " << chefName << " jolla on " << aines << " ainesta, voi tehda " << annoksia << " annosta salaattia" << endl;
    return annoksia;
}

int Chef::makeSoup(int aines)
{
    int annoksia = aines / 3;
    cout << "Kokki " << chefName << " jolla on " << aines << " ainesta, voi tehda " << annoksia << " annosta keittoa" << endl;
    return annoksia;
}
