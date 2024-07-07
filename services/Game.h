#ifndef Game_H
#define Game_H
#include <iostream>
#include "../Entities/Dice.h"
#include "../Entities/Players.h"
#include "../Entities/Board.h"

class Game
{
private:
    Dice *dice;
    Players *players;
    Board *board;
    int noOfPlayers;

public:
    Game(Dice *dice, Players *players, Board *board, int noOfPlayers)
    {
        this->dice = dice;
        this->players = players;
        this->board = board;
        this->noOfPlayers = noOfPlayers;
    }

    int currentCell = 0;

    int playGame()
    {
        int currentPlayerPositionInCell = 0;
        while (currentPlayerPositionInCell < 100)
        {
            for (int i = 0; i < noOfPlayers; i++)
            {
                int currentPlayerNumbering = i;
                string currentPlayerName = players->getPlayerName(i);
                currentPlayerPositionInCell = players->getPlayerPositionInCell(currentPlayerName);
                if (currentPlayerPositionInCell < 100)
                {
                    int diceValue = dice->getDiceValue();

                    if (currentPlayerPositionInCell + diceValue < 100)
                    {
                        cout << currentPlayerName << " rolled a " << diceValue << " and moved from " << currentPlayerPositionInCell << " to ";
                        currentPlayerPositionInCell = currentPlayerPositionInCell + diceValue;
                        currentPlayerPositionInCell = board->isAtSnakeHead(currentPlayerPositionInCell);
                        currentPlayerPositionInCell = board->isAtLadderBottom(currentPlayerPositionInCell);
                        players->setPlayerPositionInCell(currentPlayerName, currentPlayerPositionInCell);
                        cout << currentPlayerPositionInCell << endl;
                    }
                    else if (currentPlayerPositionInCell + diceValue == 100)
                    {
                        return currentPlayerNumbering;
                    }
                }
            }
        }

        return 0;
    }
};
#endif