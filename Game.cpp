#include "Game.h"


Game::Game(int n, int m) : board(n, m), currentPlayerIndex(0)
{
    players.emplace_back(std::make_unique<HumanPlayer>('X'));
    players.emplace_back(std::make_unique<HumanPlayer>('O'));
}

void Game::switchTurn() 
{
    currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
}

void Game::play() 
{
    int turnCount = 0;
    int maxTurns = board.getSize() * board.getSize();

    board.printBoard();
    while (turnCount < maxTurns) 
    {
        Player& currentPlayer = *players[currentPlayerIndex];

        std::cout << "Player " << currentPlayer.getMarker() << "'s turn\n";
        int move = currentPlayer.getMove();

        if (!board.markCell(move, currentPlayer.getMarker())) 
        {
            std::cout << "Invalid move. Try again.\n";
            continue;
        }

        board.printBoard();

        int row = (move - 1) / board.getSize();
        int col = (move - 1) % board.getSize();
        if (board.checkWin(row, col, currentPlayer.getMarker())) 
        {
            std::cout << "Player " << currentPlayer.getMarker() << " wins!\n";
            return;
        }

        switchTurn();
        ++turnCount;
    }

    std::cout << "It's a draw!\n";
}