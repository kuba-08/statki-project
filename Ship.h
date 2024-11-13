#pragma once

using namespace std;
class Ship
{
private:
    int size; // rozmiary statków
    int hitCount; // przechowuje stan każdego pola 
public:
    Ship( int size);
    bool isSunk();
    void hit(int position);
    

};


