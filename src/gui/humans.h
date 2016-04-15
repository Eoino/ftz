#ifndef HUMANS_H
#define HUMANS_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>
#include "control.h"

class Humans:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Humans(QGraphicsItem * parent=0);


public slots:
    void spawn();
private:
};

#endif // HUMANS_H
