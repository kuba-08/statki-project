#include "Board.h"
#include <iostream>
#include <cctype>
using namespace std;

Board::Board(int rows, int cols) : rows(rows), cols(cols) {
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            grid[i][j] = '~';  // Puste pole
}

void Board::placeShip(int row, int col, int size, bool horizontal) {
    for (int i = 0; i < size; ++i) {
        if (horizontal) {
            grid[row][col + i] = 'S';  // 'S' oznacza statek
        } else {
            grid[row + i][col] = 'S';
        }
    }
}

bool Board::receiveShot(int row, int col) {
    if (grid[row][col] == 'S') {
        grid[row][col] = 'X';  // Trafiony statek
        return true;
    } else if (grid[row][col] == '~') {
        grid[row][col] = 'O';  // Pudło
    }
    return false;
}

bool Board::areAllShipsSunk() const {
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            if (grid[i][j] == 'S')  // Jeśli pozostał jakiś statek
                return false;
    return true;
}

void Board::markSurroundingArea(int row, int col, int size, bool horizontal) {
    int startRow = row - 1;
    int startCol = col - 1;
    int endRow = row + (horizontal ? 0 : size - 1) + 1;
    int endCol = col + (horizontal ? size - 1 : 0) + 1;

    // Przechodzimy po wszystkich polach wokół statku
    for (int i = startRow; i <= endRow; ++i) {
        for (int j = startCol; j <= endCol; ++j) {
            // Sprawdzamy, czy indeksy są w zakresie tablicy i czy pole jest puste
            if (i >= 0 && i < rows && j >= 0 && j < cols && grid[i][j] == '~') {
                grid[i][j] = 'O';  // Zaznaczenie pola jako otoczenia statku
            }
        }
    }
}

void Board::printBoard(bool revealShips) const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 'S' && !revealShips)
                std::cout << '~' << ' ';  // Ukrywamy statki
            else
                std::cout << grid[i][j] << ' ';
        }
        std::cout << '\n';
    }
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
        if (x + size > 10) return false;
    } else {
        if (y + size > 10) return false;
    }

    if (horizontal) {
        for (int i = 0; i < size; ++i) {
            if (grid[x + i][y] != '-') return false;
        }
    } else {
        for (int i = 0; i < size; ++i) {
            if (grid[x][y + i] != '-') return false;
        }
    }

    return true;
}
bool Board::hasbeenShotAt(int row, int col) const
{
    return grid[row][col] == 'X' || grid[row][col] == 'O';
}
