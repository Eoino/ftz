#ifndef FTZ_H
#define FTZ_H

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
};

#endif // FTZ_H
