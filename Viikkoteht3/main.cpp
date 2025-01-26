#include <iostream>
#include "chef.h"
#include "italianchef.h"
using namespace std;

int main()
{
    Chef c_olio("Gordon");

    int salaattiannoksia = c_olio.makeSalad(10);
    cout << "Salaattiannoksia valmistettiin " << salaattiannoksia << endl;

    int keittoannoksia = c_olio.makeSoup(9);
    cout << "Keittoannoksia valmistettiin " << keittoannoksia << endl;


    ItalianChef i_olio("Mario");

    string salasana;
    int jauho = 0, vesi = 0;

    cout << "Anna salasana pizzan valmistukseen" << endl;
    cin >> salasana;

    if (salasana != "pizza")
    {
        cout << "Salasana vaarin, ohjelma lopetetaan" << endl;
        return 0;
    }

    cout << "Salasana oikein!" << endl;
    cout << "Anna jauhojen maara: ";
    cin >> jauho;

    cout << "Anna veden maara: ";
    cin >> vesi;

    i_olio.askSecret(salasana, jauho, vesi);

    return 0;
}
