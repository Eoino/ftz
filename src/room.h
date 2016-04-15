#ifndef ROOM_H
#define ROOM_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>

class Room:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Room(QGraphicsItem * parent=0);

public slots:
    void spawn();
private:

};

#endif // ROOM_H
