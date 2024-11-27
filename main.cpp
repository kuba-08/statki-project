#include "Game.cc"
#include "Player.cc"
#include "Ship.cc"
#include "Board.cc"
#include <iostream>
using namespace std;
int main() {
    Game game;
    char choice;
    cout << "---------------------------------------------------------" << endl;
cout << "                       Gra w Statki!                        " << endl;
    cout << "---------------------------------------------------------" << endl;
do
{
do
{
    cout << "Wybierz tryb gry: (1) Gracz vs Gracz, (2) Gracz vs AI: ";
   cin >> choice;
    if (choice == '1') {
        game.setupPlayers(false);  // Gra dla dwóch graczy
        break;
    } else if (choice == '2') {
        game.setupPlayers(true);   // Gra z AI
        break;
    } else {
        cout << "Nieprawidłowy wybór, Spróbuj ponownie.\n";
        
    }
} while (choice != '2' || choice != '1');

    

    game.play();  // Rozpocznij grę
    game.showResults();
} while (game.askPlayerAgain());

    cout << "Dziekuję za grę.\n"; 

    return 0;
}
