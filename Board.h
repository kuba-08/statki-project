#pragma once
 
class Board {
private:

    char grid[10][10];  // Plansza gry
    int rows, cols;
    
public:
    Board(int rows = 10, int cols = 10);
    void placeShip(int row, int col, int size, bool horizontal);
    bool receiveShot(int row, int col);
    bool areAllShipsSunk() const;
    void markSurroundingArea(int row, int col, int size, bool horizontal); 
    void printBoard(bool revealShips) const;
    bool canPlaceShip(int x, int y, int size, bool horizontal) const;
    bool hasbeenShotAt(int row, int col) const; // metoda sprawdzająca czy dane pole było już trafione
    // void markAreaArrounShip(int x, int y, int size, bool horizontal); // funcja do umieszczania pudła wokó zatopionego statku
    bool isAreaClear(int x, int y, int size , bool horizontal) const;
    


};
