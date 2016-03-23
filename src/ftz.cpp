#include "ftz.h"

FTZ::FTZ()
{

}

/* Executed after player turn */
void FTZ::simTurn()
{
    vector<Alien*> aliens = ship->getAliens();
    Tile ***map = ship->getMap();

    /* Check victory conditions */

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
    // Check health and end game
    // if zero or less
}
