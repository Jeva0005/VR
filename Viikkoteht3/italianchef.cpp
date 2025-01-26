#include "italianchef.h"

ItalianChef::ItalianChef() : jauho (0), vesi (0) {

    cout << "ItalianChef default konstruktori" << endl;
}

ItalianChef::ItalianChef(string name)
    : Chef(name), jauho (0), vesi (0)
{


    cout << "ItalianChef konstruktori" << ", kokin nimi " << name << endl;


}

ItalianChef::~ItalianChef()
{
    cout << "ItalianChef destruktori" << endl;
}

bool ItalianChef::askSecret(string pass, int jauholisatty, int vesilisatty)
{
    if (pass == password)
    {
        jauho += jauholisatty;
        vesi += vesilisatty;
        cout << "Salasana oikein" << endl;
        makePizza();
        return true;
    }
    else
    {
        return false;
    }
}

int ItalianChef::makePizza()
{
    int pizzas = min(jauho / 5, vesi / 5);
    cout << "Kokki " << chefName << " jolla on " << jauho << " jauhoa ja " << vesi << " vetta, voi valmistaa " << pizzas << " pizzaa" << endl;
    jauho -= pizzas * 5;
    vesi -= pizzas * 5;
    return pizzas;
}
