#include "Game.h"
#include <iostream>
using namespace std;
Game::Game() : player1Wins(0), player2Wins(0)
{
    make_unique<Player>("Gracz 1");
    make_unique<Player>("Gracz 2");
}
void Game::setupPlayers(bool aiMode)
{
    if (aiMode) {
        player1 = make_unique<HumanPlayer>(" Gracz 1");
        player2 = make_unique<AIPlayer>();
    } else {
        player1 = make_unique<HumanPlayer>("Gracz 1");
        player2 = make_unique<HumanPlayer>("Gracz 2");
    }
}

void Game::play() {
    bool gameOver = false;
    Player* currentPlayer = player1.get();
    Player* opponent = player2.get();

    cout << "Rozpocznijmy nową grę!\n";

    player1->placeShips();
    player2->placeShips();

    while (!gameOver) {
        bool playerTurn = true; // Zmeinna sprawdzająca czy gracz może wykonać kolejny ruch
       cout << "\nTura: " << currentPlayer->getName() << "\n";
        opponent->getBoard().printBoard(false); // wyswietlenie ukrytej planszy przeciwnika
        while (playerTurn)
        {
       playerTurn = currentPlayer->takeTurn(*opponent); // wykonanie przez gracza ruchu
       if (playerTurn)
       {
        cout << currentPlayer->getName() << " trafia! strzel ponownie, \n";
       }else{
        cout << currentPlayer->getName() << " pudłuje. \n";
       }
        // sprawdzanie czy wszystkie statki przeciwnka są zatopione
        if (opponent->getBoard().areAllShipsSunk())
        {
            cout << currentPlayer->getName() << " wygrał!! \n";
            gameOver = true;
            //aktualizacja wyników
            if (currentPlayer == player1.get())
            {
                player1Wins++;
            }else{
                player2Wins++;
            }
            break;
            
        }
        
        
           
        }
        if (!gameOver)
        {
            swap(currentPlayer, opponent);
        }

        
    }
}

void Game::showResults() const
{
   cout << "Wyniki po wszystkich grach: " << endl;
cout << "Gracz 1: " << player1->getName() << " wygrane: " << player1Wins << endl;
cout << "Gracz 2: " << player1->getName() << " wygrane: " << player2Wins << endl;
}

bool Game::askPlayerAgain()
{
    
    char choice;
    cout << "Czy chcecsz zagrać jeszcze raz? (t/n): ";
    cin >> choice;
    return (choice == 't' || choice == 'T');
}
