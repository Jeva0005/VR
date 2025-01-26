#ifndef ITALIANCHEF_H
#define ITALIANCHEF_H

#include "chef.h"

class ItalianChef : public Chef
{
public:
    ItalianChef();
    ItalianChef(string name);
    ~ItalianChef();

    bool askSecret(string pass, int jauholisatty, int vesilisatty);

private:
    const string password = "pizza";
    int jauho;
    int vesi;

    int makePizza();
};

#endif // ITALIANCHEF_H
