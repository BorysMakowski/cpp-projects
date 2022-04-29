#include "Laser.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Wrog.h"

extern Silnik * silnik;

Laser::Laser(): Obiekt()
{
    setRect(0,0,6,30);
    setBrush(Qt::red);

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}
Laser::~Laser()
{
}

void Laser::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(Wrog))
        {
            silnik->getPunkty()->zwieksz();

            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            delete colliding_items[i];
            delete this;
            return;
        }
    }
    setPos(x(),y()-10);
    if (pos().y() + rect().height() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}
