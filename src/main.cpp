#include <QApplication>
#include <thread>
#include <windows.h>

#include "ftz.h"
#include "gui/control.h"
#include "gui/gui.h"

using std::thread;

#define FTZ_DEBUG

inline void createCharacter(FTZ*);
inline void selectShip(FTZ*);
void runFTZ(FTZ *ftz);
void guiFun(FTZ* ftz,QApplication a);

Gui * gui;
int cta = 10;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
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

    /* GUI */
	bool alive = true;
	gui = new Gui(ftz);
    gui->refreshGui(ftz);
    gui->show();
    a.processEvents();
	
	while(alive)
	{
		gui->refreshGui(ftz);
		a.processEvents();
	}

    game.join();

    /* Cleanup */
    delete ftz;

    int ctb = ::cta + 1;

    return 0;
}

/* Create character */
void createCharacter(FTZ *ftz)
{
    ftz->addPlayer("Ed");
}

/* Select ship */
void selectShip(FTZ *ftz)
{
    ftz->addShip("kestrel");
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

    cout << "GAME OVER" << endl;

}

void guiFun(FTZ* ftz,QApplication a)
{
    gui = new Gui(ftz);
    gui->show();
    a.exec();
}
