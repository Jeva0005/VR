#ifndef NOTIFIKAATTORI_H
#define NOTIFIKAATTORI_H
#include "seuraaja.h"


class Notifikaattori
{
public:
    Notifikaattori();
    void lisaa(Seuraaja *seur);
    void poista(Seuraaja *poistseur);
    void tulosta();
    void postita(string viesti);

private:
    Seuraaja *seuraajat = nullptr;
};

#endif // NOTIFIKAATTORI_H
