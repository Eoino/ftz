#ifndef HEALTH
#define HEALTH

#include <QGraphicsTextItem>
#include "character.h"
#include "ftz.h"

class Health: public QGraphicsTextItem{
public:
    Health(QGraphicsItem * parent=0);
    void setHealth(FTZ* ftz);
    void clearHealth(FTZ* ftz);
    void updateHealth(FTZ* ftz);
    virtual ~Health();
private:

    int health;
};

#endif // HEALTH

