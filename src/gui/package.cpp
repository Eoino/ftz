#include "tile.h"
#include "package.h"
#include <QGraphicsScene>
#include <QKeyEvent>


Package::Package(QGraphicsItem *parent): QGraphicsPixmapItem(parent){

    // set Package graphic
    setPixmap(QPixmap(":/images/package.png"));
}

void Package::spawn(){

}
