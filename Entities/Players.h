#ifndef Players_H
#define Players_H
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Players
{
private:
    unordered_map<string, int> player;
    unordered_map<int, string> playerNumbering;

public:
    void setPlayerPositionInCell(string playerName, int position)
    {
        player[playerName] = position;
    }
    void setPlayerNumbering(int numbering, string playerName)
    {
        playerNumbering[numbering] = playerName;
    }
    string getPlayerName(int numbering)
    {
        return playerNumbering[numbering];
    }
    int getPlayerPositionInCell(string playerName)
    {
        return player[playerName];
    }
};
#endif