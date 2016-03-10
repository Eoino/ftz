#ifndef FTZ_H
#define FTZ_H

#include "character.h"
#include "ship.h"

class FTZ
{
private:
    Human *player;
    Ship *ship;
    void simTurn();
public:
    FTZ();
};

#endif // FTZ_H
