#include "Player.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
using namespace std;


Player::Player(const std::string& name) : name(name), board(Board(10, 10)) {}

void Player::placeShips() {
    // Implementacja rozmieszczania statków przez gracza
}

bool Player::takeTurn(Player& opponent) {
    int row, col;
    bool validShot = false;

    while (!validShot) {
        std::cout << name << ", wybierz współrzędne do strzału (wiersz i kolumna): ";
        std::cin >> row >> col;

        if (opponent.getBoard().hasBeenShotAt(row, col)) {
            std::cout << "Już strzelałeś w to miejsce. Wybierz inne współrzędne.\n";
        } else {
            validShot = true;
        }
    }

    // Wykonanie strzału
    bool hit = opponent.getBoard().receiveShot(row, col);

    if (hit) {
        std::cout << name << " trafia!\n";
        // Sprawdź, czy statek jest zatopiony i zaznacz otaczające pola
        // Załóżmy, że implementacja receiveShot wykrywa zatopiony statek
        int shipSize = 1;  // Wielkość zatopionego statku, zależnie od implementacji
        bool horizontal = true;  // Ustawienie statku, zależnie od implementacji
        opponent.getBoard().markSurroundingArea(row, col, shipSize, horizontal);
    } else {
        std::cout << name << " pudłuje.\n";
    }

    return hit;
}

Board& Player::getBoard() {
    return board;
}

std::string Player::getName() const {
    return name;
}