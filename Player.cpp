#include "Player.h"
#include <iostream>
Player::Player(char m) : marker(m) {}

Player::~Player() = default;

char Player::getMarker() const 
{ 
    return marker; 
}

HumanPlayer::HumanPlayer(char m) : Player(m) {}

int HumanPlayer::getMove() const 
{
    int move;
    std::cout << "Enter your move: ";
    std::cin >> move;
    return move;
}