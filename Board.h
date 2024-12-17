#pragma once
#include <vector>
#include <iostream>
class Board
{

private:
    int size;
    int winCondition;
    std::vector<std::vector<char>> grid;

public:
    Board(int n, int m);
    void printBoard() const;
    bool markCell(int cell, char marker);
    bool checkWin(int lastRow, int lastCol, char marker) const;
    int getSize() const { return size; }
    
};

