#include <iostream>

using namespace std;

int game(int maxnum);                                     //Funktion prototyyppi

int main()
{

    int arvaustenmaara = 0;
    int maxnum = 0;

    cout << "Anna maksiminumero" << endl;
    cin >> maxnum;

    arvaustenmaara = game(maxnum);
    cout << "Teit " << arvaustenmaara << " arvausta" << endl;




    return 0;
}


int game(int maxnum){

    int satunnaisluku = 0;                          //Alustetaan muuttuja satunnaisluku nollaksi
    int arvaus = 0;                                 //Alustetaan muuttuja arvaus nollaksi
    int arvaustenmaara = 0;                         //Alustetaan muuttuja arvaustenmaara nollaksi

    srand(time(NULL));
    satunnaisluku = rand() % maxnum;

    while (true){
        cout << "Syota luku" << endl;               //Pyydetään käyttäjää syöttämään arvaus

        cin >> arvaus;                              //Käyttäjän arvaus otetaan talteen
        arvaustenmaara++;                           //Arvausten lukumäärä kasvaa yhdellä aina kun tehdään uusi arvaus

        if (arvaus == satunnaisluku){               //Jos arvaus oikein, poistutaan while-loopista
            cout << "Oikein!" << endl;
            break;

        } else if (arvaus < satunnaisluku) {        //Jos arvaus liian pieni, tulostetaan näytölle "Luku on suurempi"
            cout << "Luku on suurempi" << endl;
        } else if (arvaus > satunnaisluku) {        //Jos arvaus liian suuri, tulostetaan näytölle "Luku on pienempi"
            cout << "Luku on pienempi" << endl;
        }
    }

    return arvaustenmaara;
}



