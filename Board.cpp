#include "Board.h"

Board::Board(int n, int m) : size(n), winCondition(m), grid(n, std::vector<char>(n)) 
{
    int cellNumber = 1;
    for (int i = 0; i < size; ++i) 
    {
        for (int j = 0; j < size; ++j) 
        {
            grid[i][j] = '0' + cellNumber;
            ++cellNumber;
        }
    }
}

void Board::printBoard() const 
{
    for (const auto& row : grid) 
    {
        for (const auto& cell : row) 
        {
            std::cout << cell << " ";
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}

bool Board::markCell(int cell, char marker) 
{
    int row = (cell - 1) / size;
    int col = (cell - 1) % size;

    if (row < 0 || row >= size || col < 0 || col >= size || 
        grid[row][col] == 'X' || grid[row][col] == 'O') 
    {
        return false; // Invalid move
    }

    grid[row][col] = marker;
    return true;
}


bool Board::checkWin(int lastRow, int lastCol, char marker) const 
{
    static const std::vector<std::pair<int, int>> directions = 
    {
        {0, 1}, {1, 0}, {1, 1}, {1, -1}
    };

    for (const auto& [dx, dy] : directions) 
    {
        int count = 1;

        for (int dir = -1; dir <= 1; dir += 2) 
        {
            for (int step = 1; step < winCondition; ++step) 
            {
                int nx = lastRow + dir * step * dx;
                int ny = lastCol + dir * step * dy;

                if (nx < 0 || nx >= size || ny < 0 ||
                    ny >= size || grid[nx][ny] != marker) 
                {
                    break;
                }

                ++count;
                if (count >= winCondition) 
                {
                    return true;
                }
            }
        }
    }

    return false;
}
