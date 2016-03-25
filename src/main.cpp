#include <QApplication>

#include "ftz.h"

void createCharacter(FTZ*);
void selectShip(FTZ*);

int main(int argc, char *argv[])
{
    /* Game Object */
    FTZ *ftz = new FTZ();

    /* Display character creation */
    createCharacter(ftz);

    /* Display ship selection */
    selectShip(ftz);

    /* Spawn player */
    ftz->spawnPlayer();

    /* Game Loop */
    bool alive = true;
    while(alive)
    {
        // TODO
        // Process user input

        /* Update game state */
        alive = ftz->simTurn();

        // Update GUI
    }

    return 0;
}

void createCharacter(FTZ *ftz)
{
    // TODO
    // Display UI and pass input details to
    // character creation method in ftz
    // ftz->addPlayer(name);
}

void selectShip(FTZ *ftz)
{
    // TODO
    // Display UI and pass selected
    // ship to import method in ftz
    // ftz->addShip(name);
}
