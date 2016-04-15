#include "tile.h"
#include "aliens.h"
#include <QGraphicsScene>
#include <QKeyEvent>


Aliens::Aliens(QGraphicsItem *parent): QGraphicsPixmapItem(parent){

    // set Aliens graphic
    setPixmap(QPixmap(":/images/alien.png"));
}

void Aliens::spawn(){

}
