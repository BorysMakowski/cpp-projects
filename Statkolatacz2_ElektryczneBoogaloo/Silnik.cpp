
#include "Silnik.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Wrog.h"

Silnik::Silnik(int _X,int _Y,int _Xg,int _Yg)
{
    gameended = false;
    X=_X;
    Y=_Y;
    Xg=_Xg;
    Yg=_Yg;

    scene = new QGraphicsScene();
    scene->setBackgroundBrush(Qt::Dense1Pattern);
    scene->setSceneRect(0,0,X,Y);

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(X,Y);

    gracz = new Gracz();
    gracz->setRect(0,0,Xg,Yg);
    gracz->setBrush(Qt::white);
    gracz->setPos((X/2)-(Xg/2),Y-Yg);
    gracz->setFlag(QGraphicsItem::ItemIsFocusable);
    gracz->setFocus();
    scene->addItem(gracz);

    punkty = new Punkty();
    scene->addItem(punkty);
    zycie = new Zycie();
    zycie->setPos(zycie->x(),zycie->y()+25);
    scene->addItem(zycie);

    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),gracz,SLOT(spawn()));
    timer->start(2000);

    show();
}
Silnik::~Silnik()
{
    delete scene;
    delete gracz;
    delete punkty;
    delete zycie;
}
void Silnik::endgame()
{
    scene->removeItem(gracz);
    delete gracz;
    scene->removeItem(punkty);
    delete punkty;
    zycie->setPos(X/2,Y/2);
    zycie->endmssg();
    gameended=true;
}
int Silnik::getX()
{
    return X;
}
int Silnik::getXg()
{
    return Xg;
}
int Silnik::getY()
{
    return Y;
}
int Silnik::getYg()
{
    return Yg;
}
Punkty * Silnik::getPunkty()
{
    return punkty;
}
Zycie * Silnik::getZycie()
{
    return zycie;
}

