#pragma once
#include "Board.h"
#include <string>
using namespace std;
class Player {
protected:
    string name;
    Board board;

public:
    Player(const string& name);
    virtual void placeShips();  // Metoda wirtualna do umieszczania statków
    virtual bool takeTurn(Player& opponent);  // Wirtualna metoda do ruchu
    Board& getBoard();
    string getName() const;
};

 /*class HumanPlayer : public Player {
public:
    HumanPlayer(const string& name);
    void placeShips() override;
    bool takeTurn(Player& opponent) override;
};

class AIPlayer : public Player {
public:
    AIPlayer();
    void placeShips() override;
    bool takeTurn(Player& opponent) override;
}; /*
