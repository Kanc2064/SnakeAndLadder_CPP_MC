
#ifndef Dice_H
#define Dice_H
#include <iostream>
#include <cstdlib>

using namespace std;

class Dice
{
public:
    int getDiceValue()
    {
        return rand() % 6 + 1;
    }
};
#endif