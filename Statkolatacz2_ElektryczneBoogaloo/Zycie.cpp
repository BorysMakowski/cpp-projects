#include "Zycie.h"
#include "Silnik.h"
#include <QFont>

extern Silnik * silnik;

Zycie::Zycie(): Punkty()
{
    zycie = 5;
    setPlainText(QString("Życia: ") + QString::number(zycie));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",16));
}
Zycie::~Zycie()
{
}

void Zycie::zmniejsz()
{
    zycie--;
    setPlainText(QString("Życia: ") + QString::number(zycie));
    if (zycie==0)
    {
        silnik->endgame();
    }
}

void Zycie::endmssg()
{
    setPlainText(QString("Umarłeś i nie żyjesz"));
}

int Zycie::getZycie()
{
    return zycie;
}
