#ifndef WROG_H
#define WROG_H
#include "Silnik.h"

class Wrog: public Obiekt
{
    Q_OBJECT
public:
    Wrog();
    virtual ~Wrog();
    Wrog ( const Wrog & ) = delete;
public slots:
    void move();
};

#endif // WROG_H
