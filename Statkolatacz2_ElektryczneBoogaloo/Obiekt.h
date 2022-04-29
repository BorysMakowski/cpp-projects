#ifndef OBIEKT_H
#define OBIEKT_H
#include <QGraphicsRectItem>
#include <QObject>

 class Obiekt: public QObject, public QGraphicsRectItem
{
public:
    Obiekt();
    virtual ~Obiekt();
    Obiekt ( const Obiekt & ) = delete;
    virtual void move();
};

#endif // OBIEKT_H
