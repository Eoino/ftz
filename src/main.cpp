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

    thread game(runFTZ, ftz);

    // GUI

    game.join();

    /* Cleanup */
    delete ftz;

    return 0;
}

void createCharacter(FTZ *ftz)
{
    // TODO
    // Display UI and pass input details to
    // character creation method in ftz
    ftz->addPlayer("Eoin");
}

void selectShip(FTZ *ftz)
{
    // TODO
    // Display UI and pass selected
    // ship to import method in ftz
    ftz->addShip("vortex");
}

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
