#pragma once
#include "Board.h"
#include "Player.h"

class Game 
{
private:
    Board board;
    std::vector<std::unique_ptr<Player>> players;
    int currentPlayerIndex;
    void switchTurn();

public:
    Game(int n, int m);
    void play();
};

