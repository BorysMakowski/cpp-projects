#ifndef PUNKTY_H
#define PUNKTY_H

#include <QGraphicsTextItem>

class Punkty: public QGraphicsTextItem{
public:
    Punkty();
    virtual ~Punkty();
    Punkty ( const Punkty & ) = delete;
    void zwieksz();
    int getPunkty();
private:
    int punkty;
};

#endif // PUNKTY_H
