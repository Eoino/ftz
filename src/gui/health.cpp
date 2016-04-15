#include "Health.h"
#include "ftz.h"
#include <QFont>

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){

}
void Health::setHealth(FTZ* ftz){
    health = ftz->getHuman()->getHealth();
}

Health::~Health()
{

}
void Health::updateHealth(FTZ* ftz){
    setPlainText(QString("Health: ") + QString::number(health)); // Health: current Health
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

//}
