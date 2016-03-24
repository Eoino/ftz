#include "ftz.h"

FTZ::FTZ()
{

}

FTZ::~FTZ()
{

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
            delete aliens[i]; // UNTESTED
        }
    }

    /* Set aliens to scout */
    for(int i = 0; i < aliens.size(); i++)
    {
        aliens[i]->scout(map, player); // UNTESTED
    }

    /* Check player health */
    if(player->getHealth() <= 0)
        alive = false;

    return alive;
}
