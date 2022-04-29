#include "Wrog.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>

extern Silnik * silnik;

Wrog::Wrog(): Obiekt()
{
    int pozycja = rand() % (silnik->getX()-silnik->getXg());
    setPos(pozycja,0);
    setRect(0,0,100,100);
    setBrush(Qt::black);

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}
Wrog::~Wrog()
{
}

void Wrog::move()
{
QList<QGraphicsItem *> colliding_items = collidingItems();

for (int i = 0, n = colliding_items.size(); i < n; ++i){
    if (typeid(*(colliding_items[i])) == typeid(Gracz))
    {
        silnik->getZycie()->zmniejsz();
        scene()->removeItem(this);
        delete this;
        return;
    }
}

setPos(x(),y()+10);

if (silnik->gameended==false)
{
    if (pos().y() > silnik->getY())
    {
        silnik->getZycie()->zmniejsz();
        scene()->removeItem(this);
        delete this;
    }
}
}
