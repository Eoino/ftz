#ifndef PACKAGE
#define PACKAGE

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>

class Package:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Package(QGraphicsItem * parent=0);

public slots:
    void spawn();
private:

};

#endif // PACKAGE

