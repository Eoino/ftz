#ifndef FTZ_H
#define FTZ_H

#include <random>

#include "character.h"
#include "ship.h"

#define FTZ_DEBUG

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
    Human* getHuman();
    Ship* getShip();
};

template<typename TypeA, typename TypeB>
/* Print debug information to console */
void print(TypeA a, TypeB b)
{
    cout << a << b << endl;
}

#endif // FTZ_H
