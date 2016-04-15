#include "room.h"
#include "aliens.h"
#include "gui.h"
#include "Health.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QMediaPlayer>
#include <QBrush>
#include <QImage>
#include <QThread>


Gui::Gui(FTZ *ftz){
    // create the scene
    qreal xscreen = ftz->getShip()->getXlen()*100;
    qreal yscreen = ftz->getShip()->getYlen()*100;
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,yscreen,xscreen);
    setBackgroundBrush(QBrush(QImage(":/images/bg.PNG")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(yscreen,xscreen);

    int xpos=0;
    int ypos=0;

    char map [10][10] ;
    for( int x = 0; x < 10; x++ )
    {
        for( int a = 0; a < 10; a++)
        {
            if(ftz->getShip()->getMap()[x][a]->getType() == 'R')
                map[x][a] = 'R';

        else{
            map[x][a] = 'W';
            }
        }
    }
show();
}

void Gui::drawRoom(FTZ *ftz){
        for( int a = 0,ypos=0; a < ftz->getShip()->getYlen(); a++,ypos+=100)
        {
            for( int x = 0,xpos=0; x < ftz->getShip()->getXlen(); x++,xpos +=100 )
            {
                if(ftz->getShip()->getMap()[x][a]->getType() == 'R')
                {
                 room = new Room();
                 room->setPos(ypos,xpos);
                 // make the room focusable and set it to be the current focus
                 room->setFlag(QGraphicsItem::ItemIsFocusable);
                 room->setFocus();
                 // add the room to the scene
                 scene->addItem(room);

                }
            }

        }
}
void Gui::drawAlien(FTZ *ftz){
        for(int i = 0; i < ftz->getShip()->getAliens().size(); i++)
        {
            int* pos = ftz->getShip()->getAliens()[i]->getPos();
            int xpos = pos[0]*100;
            int ypos = pos[1]*100;
            aliens = new Aliens();
            aliens->setPos(ypos,xpos);
            // make the Alien focusable and set it to be the current focus
            aliens->setFlag(QGraphicsItem::ItemIsFocusable);
            aliens->setFocus();
            // add the Alien to the scene
            scene->addItem(aliens);

        }
}

void Gui::drawItem(FTZ *ftz){
        for(int i = 0; i < ftz->getShip()->getItems().size(); i++)
        {
            int* pos = ftz->getShip()->getItems()[i]->getPos();
            int xpos = pos[0]*100;
            int ypos = pos[1]*100;
            package = new Package();
            package->setPos(ypos,xpos);
            // make the Package focusable and set it to be the current focus
            package->setFlag(QGraphicsItem::ItemIsFocusable);
            package->setFocus();
            // add the Package to the scene
            scene->addItem(package);

        }
}

void Gui::drawHuman(FTZ *ftz){
        int* humanpos = ftz->getHuman()->getPos();
        int humanxpos = humanpos[0]*100;
        int humanypos = humanpos[1]*100;
        humans = new Humans();
        humans->setPos(humanypos,humanxpos);
        // make the Human focusable and set it to be the current focus
        humans->setFlag(QGraphicsItem::ItemIsFocusable);
        humans->setFocus();
        // add the Human to the scene
        scene->addItem(humans);
}
void Gui::drawHealth(FTZ *ftz){
        //delete health;
        health = new Health();
        health->setHealth(ftz);
        health->updateHealth(ftz);
        health->setPos(health->x(),health->y()+25);
        scene->addItem(health);

}


void Gui::refreshGui(FTZ *ftz){
    drawRoom(ftz);
    drawHealth(ftz);
    drawHuman(ftz);
    drawAlien(ftz);
    drawItem(ftz);
}


