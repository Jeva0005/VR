#include "game.h"
#include <cstdlib>
#include <ctime>


Game::Game(int mn)
{
    maxNumber = mn;

    cout << "GAME CONSTRUCTOR: Object initialized with " << maxNumber << " as a maximum value" <<endl;
    srand(time(NULL));
}

Game::~Game()
{
    cout << "GAME DESTRUCTOR: object cleared from stack memory" <<endl;
}

void Game::play()
{
    cout << "Game started" <<endl;

    numOfGuesses = 0;                         //Alustetaan muuttuja numOfGuesses nollaksi


    randomNumber = rand() % maxNumber + 1;

    while (true){
        cout << "Syota luku" << endl;               //Pyydetään käyttäjää syöttämään arvaus

        cin >> playerGuess;                              //Käyttäjän arvaus otetaan talteen
        numOfGuesses++;                           //Arvausten lukumäärä kasvaa yhdellä aina kun tehdään uusi arvaus

        if (playerGuess == randomNumber){               //Jos arvaus oikein, poistutaan while-loopista
            cout << "Oikein!" << endl;
            break;

        } else if (playerGuess < randomNumber) {        //Jos arvaus liian pieni, tulostetaan näytölle "Luku on suurempi"
            cout << "Luku on suurempi" << endl;
        } else if (playerGuess > randomNumber) {        //Jos arvaus liian suuri, tulostetaan näytölle "Luku on pienempi"
            cout << "Luku on pienempi" << endl;
        }
    }

    printGameResult();
}

void Game::printGameResult()
{
    cout << "Teit " << numOfGuesses << " arvausta" << endl;
}
