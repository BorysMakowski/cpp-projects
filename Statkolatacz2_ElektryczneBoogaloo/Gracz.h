#ifndef GRACZ_H
#define GRACZ_H
#include "Obiekt.h"

class Gracz:public Obiekt
{
    Q_OBJECT
public:
    Gracz();
    virtual ~Gracz();
    Gracz ( const Gracz & ) = delete;
    void keyPressEvent(QKeyEvent * event);//
public slots:
    void spawn();
    void move();
private:
int klawisz;
};

#endif // GRACZ_H
