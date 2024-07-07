#include <iostream>
#include <string>
#include "../Entities/Players.h"
#include "../Entities/Board.h"
#include "../Entities/Dice.h"
#include "../services/Game.h"

int main()
{
    Dice *dice = new Dice();
    Board *board = new Board();
    Players *players = new Players();

    int noOfSnakes;
    cin >> noOfSnakes;
    for (int i = 0; i < noOfSnakes; i++)
    {
        int head, tail;
        cin >> head >> tail;
        board->storeSnakes(head, tail);
    }

    int noOfLadders;
    cin >> noOfLadders;
    for (int i = 0; i < noOfLadders; i++)
    {
        int bottom, top;
        cin >> bottom >> top;
        board->storeLadder(bottom, top);
    }

    int noOfPlayers;
    cin >> noOfPlayers;
    for (int i = 0; i < noOfPlayers; i++)
    {
        string playerName;
        cin >> playerName;
        players->setPlayerPositionInCell(playerName, 0);
        players->setPlayerNumbering(i, playerName);
    }

    Game *game = new Game(dice, players, board, noOfPlayers);
    int winner = game->playGame();
    string winnerName = players->getPlayerName(winner);
    cout << winnerName << " is Winner";

    return 0;
}