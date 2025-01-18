#include <iostream>
#include "game.h"


using namespace std;

int main()
{
    int maxNumber;
    cout << "Anna suurin mahdollinen arvottava luku" << endl;
    cin >> maxNumber;

    Game peliolio(maxNumber);
    peliolio.play();

    return 0;
}
