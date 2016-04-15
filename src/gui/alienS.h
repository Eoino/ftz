#ifndef ALIENS_H
#define ALIENS_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>

class Aliens:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Aliens(QGraphicsItem * parent=0);

public slots:
    void spawn();
private:

};

#endif // ALIENS_H
