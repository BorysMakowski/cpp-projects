#include "Punkty.h"
#include <QFont>

Punkty::Punkty(): QGraphicsTextItem()
{
    punkty = 0;
    setPlainText(QString("Punkty: ") + QString::number(punkty));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",16));
}
Punkty::~Punkty()
{
}

void Punkty::zwieksz(){
    punkty++;
    setPlainText(QString("Punkty: ") + QString::number(punkty));
}

int Punkty::getPunkty(){
    return punkty;
}
