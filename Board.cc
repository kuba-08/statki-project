#include "Board.h"
#include <iostream>
#include <cctype>
using namespace std;


Board::Board()
{
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            grid[i][j] = '-';  // Inicjalizacja planszy pustymi polami
        }
    }
}

void Board::printBoard(bool reveal) const {
    cout << "  0 1 2 3 4 5 6 7 8 9\n";
    for (int i = 0; i < 10; ++i) {
        cout << i << " ";
        for (int j = 0; j < 10; ++j) {
            if (grid[i][j] == 'S' && !reveal) {
                cout << "- ";  // Ukrycie statków, jeśli reveal == false
            } else {
                cout << grid[i][j] << " ";
            }
        }
        cout << endl;
    }
}

bool Board::placeShip(int x, int y, int size, bool horizontal) {
    if (!canPlaceShip(x, y, size, horizontal) || !isAreaClear(x, y, size, horizontal)) {
        return false;
    }

    if (horizontal) {
        for (int i = 0; i < size; ++i) {
            grid[x + i][y] = 'S';
        }
    } else {
        for (int i = 0; i < size; ++i) {
            grid[x][y + i] = 'S';
        }
    }

    return true;
}

bool Board::isAreaClear(int x, int y, int size, bool horizontal) const {
    int startX = max(0, x - 1);
    int endX = min(9, horizontal ? x + size : x + 1);
    int startY = max(0, y - 1);
    int endY = min(9, horizontal ? y + 1 : y + size);

    for (int i = startX; i <= endX; ++i) {
        for (int j = startY; j <= endY; ++j) {
            if (grid[i][j] == 'S') {
                return false;
            }
        }
    }
    return true;
}

bool Board::canPlaceShip(int x, int y, int size, bool horizontal) const {
    if (horizontal) {
        if (x + size > 10){
            cout << "Statek wychodzi poza planszę wysokosciowo" << endl;
        return false;
        }  
    }else {
        if (y + size > 10){
            cout << "Statek wychodzi poza plansze szerokosciowo" << endl;
            return false;
        }
    }

    if (horizontal) {
        for (int i = 0; i < size; ++i) {
            if (grid[x + i][y] != '-'){
                cout << "nie można umiescic statku - pole (" << x + i << ", " << y << ") jest zajete!" << endl;
                return false;
            }
        }
    } else {
        for (int i = 0; i < size; ++i) {
            if (grid[x][y + i] != '-'){
                return false;
            }
        }
    }
 for (int i = -1; i <= size; ++i) {
        for (int j = -1; j <= 1; ++j) {
            int checkX = horizontal ? x + i : x + j;
            int checkY = horizontal ? y + j : y + i;

            if (checkX >= 0 && checkX < 10 && checkY >= 0 && checkY < 10) { // Upewniamy się, że nie wychodzimy poza planszę
                if (i >= 0 && i < size && j == 0) continue; // Ignorujemy pole, gdzie statek rzeczywiście będzie
                if (grid[checkX][checkY] != '-') {
                    cout << "Nie mozna umiescic statku - pole styka się z innym statkiem" << endl;     
                    return false;
                }
            }
        }
    }
    return true;
}

bool Board::areAllShipsSunk() const {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (grid[i][j] == 'S') {
                return false;
            }
        }
    }
    return true;
}

bool Board::receiveAttack(int x, int y) {
    if (grid[x][y] == 'S') {
        grid[x][y] = 'X';  // Trafienie
        
        return true;
    } else if (grid[x][y] == '-') {
        grid[x][y] = 'O';  // Pudło
    }
    return false;
}

bool Board::hasbeenShotAt(int x, int y) const
{
    return grid[x][y] == 'X' || grid[x][y] == 'O';
}

