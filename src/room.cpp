#include "tile.h"
#include "room.h"
#include <QGraphicsScene>
#include <QKeyEvent>


Room::Room(QGraphicsItem *parent): QGraphicsPixmapItem(parent){

    // set room graphic
    setPixmap(QPixmap(":/images/room.png"));
}

void Room::spawn(){

}
