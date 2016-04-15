#ifndef GUI_H
#define GUI_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Room.h"
#include "ftz.h"
#include "Aliens.h"
#include "Humans.h"
#include "health.h"
#include "package.h"


class Gui: public QGraphicsView{
public:
    void drawHuman(FTZ *ftz);
    void drawHealth(FTZ *ftz);
    void drawAlien(FTZ *ftz);
    void drawRoom(FTZ *ftz);
    void drawItem(FTZ *ftz);
    void refreshGui(FTZ *ftz);
    Gui(FTZ *ftz);
    QGraphicsScene * scene;
    Room * room;
    Aliens * aliens;
    Humans * humans;
    Health * health;
    Package * package;

};

#endif // GUI_H
