#ifndef LASER_H
#define LASER_H
#include "Silnik.h"


class Laser:public Obiekt
{
    Q_OBJECT
public:
    Laser();
    virtual ~Laser();
    Laser ( const Laser & ) = delete;
public slots:
    void move();
};

#endif // LASER_H
