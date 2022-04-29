#ifndef ZYCIE_H
#define ZYCIE_H
#include "Punkty.h"


class Zycie: public Punkty{
public:
    Zycie();
    virtual ~Zycie();
    Zycie ( const Zycie & ) = delete;
    void zmniejsz();
    int getZycie();
    void endmssg();
private:
    int zycie;
};

#endif // ZYCIE_H
