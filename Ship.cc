#include <iostream>
#include "Ship.h"
using namespace std;

Ship::Ship(int size) : size(size), hitCount(0) {}


bool Ship::isSunk()
{
    return hitCount >= size; // zatopiony jesli liczba trafień >= rozmiar
}

void Ship::hit(int position)
{
    hitCount++;
}
