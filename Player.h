#pragma once
class Player
{
protected:
    char marker;

public:
    explicit Player(char m);
    virtual ~Player();
    virtual int getMove() const = 0;
    char getMarker() const;
};

class HumanPlayer : public Player 
{
public:
    explicit HumanPlayer(char m);
    int getMove() const override;
};

