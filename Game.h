#pragma once
#include "Player.h"
#include <memory>
using namespace std;
class Game {
private:
  unique_ptr<Player> player1;
    unique_ptr<Player> player2;
    int player1Wins = 0;
    int player2Wins = 0;

public:
Game();
    void setupPlayers(bool aiMode);
    void play();
    void showResults() const;
    bool askPlayerAgain();

};
