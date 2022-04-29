#include "Gracz.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include "Laser.h"
#include "Wrog.h"

extern Silnik * silnik;

Gracz::Gracz(): Obiekt()
{
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}
Gracz::~Gracz()
{
}

void Gracz::keyPressEvent(QKeyEvent *event)
{
klawisz=event->key();
}

void Gracz::move()
{
    if (klawisz == Qt::Key_Left)
    {
        if (pos().x() > 0)
        setPos(x()-15,y());
        klawisz=0;
    }
    else if (klawisz == Qt::Key_Right)
    {
        if (pos().x() + silnik->getXg() < silnik->getX())
        setPos(x()+15,y());
        klawisz=0;
    }
    else if (klawisz == Qt::Key_Space)
    {
        Obiekt * laser = new Laser();
        laser->setPos((x()+(silnik->getXg()/2))-3,y()-30);
        scene()->addItem(laser);
        klawisz=0;
    }
}

void Gracz::spawn()
{
    Obiekt * wrog = new Wrog();
    scene()->addItem(wrog);
}

