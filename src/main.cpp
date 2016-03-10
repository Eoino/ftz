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

    /* Game Loop */
    bool stay = true;
    while(stay)
    {
        // TODO
        // Process user input
        // Update game state / ftz.simTurn();
        // Update GUI
        break;
    }

    return 0;
}

void createCharacter(FTZ *ftz)
{
    // TODO
    // Display UI and pass input details to
    // character creation method in ftz
}

void selectShip(FTZ *ftz)
{
    // TODO
    // Display UI and pass selected
    // ship to import method in ftz
}
