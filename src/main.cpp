#include <QApplication>
#include <thread>

#include "ftz.h"
#include "gui/control.h"

using std::thread;

inline void createCharacter(FTZ*);
inline void selectShip(FTZ*);
void runFTZ(FTZ *ftz);

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

    /* Simulate game on seperate thread */
    thread game(runFTZ, ftz);

    // GUI

    game.join();

    /* Cleanup */
    delete ftz;

    return 0;
}

/* Create character */
void createCharacter(FTZ *ftz)
{
    ftz->addPlayer("Eoin");
}

/* Select ship */
void selectShip(FTZ *ftz)
{
    ftz->addShip("vortex");
}

/* Game thread */
void runFTZ(FTZ *ftz)
{
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
    }
}
