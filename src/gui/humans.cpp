#include "tile.h"
#include "humans.h"
#include "control.h"
#include "ftz.h"
#include <QGraphicsScene>
#include <QKeyEvent>


Humans::Humans(QGraphicsItem *parent): QGraphicsPixmapItem(parent){

    // set Humans graphic
    setPixmap(QPixmap(":/images/human.png"));

}


void Humans::spawn(){

}
