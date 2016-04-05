#include <QApplication>

#include "ftz.h"
#include "gui/control.h"

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

    /* Create control class */
    Control ctr;

    /* Game Loop */
    bool alive = true;
    while(alive)
    {
        /* Proccess user input */
        ctr.handleInput(ftz);

        /* Update game state */
        alive = ftz->simTurn();

        // Update GUI
    }

    /* Cleanup */
    delete ftz;

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
