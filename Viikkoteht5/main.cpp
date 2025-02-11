#include <iostream>
#include "seuraaja.h"
#include "notifikaattori.h"

using namespace std;

int main()
{

    Seuraaja *A = new Seuraaja("Jope");
    Seuraaja *B = new Seuraaja("Simo");
    Seuraaja *C = new Seuraaja("Aimo");


    Notifikaattori *N = new Notifikaattori();
    cout << endl;


    N->lisaa(A);
    N->lisaa(B);
    N->lisaa(C);
    cout << endl;


    N->tulosta();
    cout << endl;


    N->postita("Hei kaikille!");
    cout << endl;

    N->poista(B);
    cout << endl;

    N->postita("Hei kaikille keta on jaljella");
    cout << endl;

    delete A;
    delete B;
    delete C;
    delete N;

    return 0;
}
