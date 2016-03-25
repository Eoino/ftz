#ifndef FTZ_H
#define FTZ_H

#include <random>

#include "character.h"
#include "ship.h"

class FTZ
{
private:
    Human *player;
    Ship *ship;
public:
    FTZ();
    ~FTZ();
    bool simTurn();
    void addPlayer(string name);
    void addShip(string name);
    void spawnPlayer();
};

#endif // FTZ_H
