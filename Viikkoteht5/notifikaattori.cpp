#include "notifikaattori.h"


Notifikaattori::Notifikaattori() {
    cout << "Luodaan notifikaattori" << endl;
}

void Notifikaattori::lisaa(Seuraaja *uusiSeur)
{
    cout << "Notifikaattori lisaa seuraajan " << uusiSeur->getNimi() << endl;
    uusiSeur->next = seuraajat;
    seuraajat = uusiSeur;
}

void Notifikaattori::poista(Seuraaja *poistSeur)
{

    cout << "Notifikaattori poistaa seuraajan " << poistSeur->getNimi() << endl;
    if (seuraajat == nullptr) {
        return;
    }

    if (seuraajat == poistSeur) {
        seuraajat = seuraajat->next;
        return;
    }

    Seuraaja *ptr = seuraajat;
    while (ptr->next != nullptr && ptr->next != poistSeur) {
        ptr = ptr->next;
    }

    if (ptr->next == poistSeur) {
        ptr->next = poistSeur->next;
    }

}

void Notifikaattori::tulosta()
{
    cout << "Notifikaattorin seuraajat: " << endl;
    Seuraaja *alku = seuraajat;
    while (alku != nullptr) {
        cout << "Seuraaja " << alku->getNimi() << endl;
        alku = alku->next;
    }
}

void Notifikaattori::postita(string viesti)
{
    cout << "Notifikaattori postaa viestin " << viesti << endl;

    Seuraaja *ptr = seuraajat;
    while (ptr != nullptr) {
        ptr->paivitys(viesti);
        ptr = ptr->next;
    }
}
