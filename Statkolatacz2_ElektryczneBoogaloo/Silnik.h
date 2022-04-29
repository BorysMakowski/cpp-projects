#ifndef SILNIK_H
#define SILNIK_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Gracz.h"
#include "Punkty.h"
#include "Zycie.h"
#include "Obiekt.h"

class Silnik: public QGraphicsView
{
public:
    Silnik(int X,int Y, int Xg, int Yg);
    virtual ~Silnik();
    Silnik ( const Silnik & ) = delete;
    int getX();
    int getY();
    int getXg();
    int getYg();
    Punkty * getPunkty();
    Zycie * getZycie();
    void endgame();
    bool gameended;
private:
    QGraphicsScene * scene;
    Obiekt * gracz;
    Punkty * punkty;
    Zycie * zycie;
    int X, Y, Xg, Yg;
//friend class Wrog;


};

#endif // SILNIK_H
