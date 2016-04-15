#include "ftz.h"

FTZ::FTZ()
{

}

FTZ::~FTZ()
{
    delete player;
    delete ship;
}

/* Executed after player turn */
bool FTZ::simTurn()
{
    bool alive = true;
    vector<Alien*> aliens = ship->getAliens();
    Tile ***map = ship->getMap();

    /* Check victory conditions */
    if(aliens.size() == 0)
        alive = false;

    /* Check alien health */
    for(int i = 0; i < aliens.size(); i++)
    {
        if(aliens[i]->getHealth() <= 0)
        {
            ship->deleteAlien(i);
#ifdef FTZ_DEBUG
            print("Deleting alien..\nRemaining: ", aliens.size() - 1);
#endif
        }
    }

    /* Set aliens to scout */
    for(int i = 0; i < aliens.size(); i++)
    {
        aliens[i]->scout(map, player);
    }

    /* Check player health */
    if(player->getHealth() <= 0)
        alive = false;

#ifdef FTZ_DEBUG
    print("Health: ", player->getHealth());
#endif

    return alive;
}

void FTZ::addPlayer(string name)
{
   Human *player = new Human(name, 100, 10, 0, 0);
   this->player = player;
}

void FTZ::addShip(string name)
{
    Ship *ship = new Ship(name);
    this->ship = ship;
}

/* Spawn player at random location */
void FTZ::spawnPlayer()
{
    random_device rd;
    mt19937 mersenne(rd());

    Tile ***map = ship->getMap();

    /* Get map length and height */
    int *size = ship->getSize();
    int xlen = size[0];
    int ylen = size[1];

    /* Cleanup */
    delete [] size;

    bool spawned = false;
    while(!spawned)
    {
        int xpos = (mersenne() % xlen);
        int ypos = (mersenne() % ylen);
        if(map[xpos][ypos]->isEnterable())
        {
            player->setPos(xpos, ypos);
            spawned = true;
        }
    }
}

Human* FTZ::getHuman()
{
    return player;
}

Ship* FTZ::getShip()
{
    return ship;
}
