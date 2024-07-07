#ifndef Board_H
#define Board_H
#include <iostream>
#include <unordered_map>

class Board
{
private:
    unordered_map<int, int> snakes;
    unordered_map<int, int> ladder;

public:
    void storeSnakes(int head, int tail)
    {
        snakes[head] = tail;
    }

    void storeLadder(int bottom, int top)
    {
        ladder[bottom] = top;
    }
    int isAtSnakeHead(int cellPosition)
    {
        if (snakes.find(cellPosition) != snakes.end())
        {
            return snakes[cellPosition];
        }
        else
        {
            return cellPosition;
        }
    }
    int isAtLadderBottom(int cellPosition)
    {
        if (ladder.find(cellPosition) != ladder.end())
        {
            return ladder[cellPosition];
        }
        else
        {
            return cellPosition;
        }
    }
};
#endif