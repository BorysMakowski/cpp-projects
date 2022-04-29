#include <QApplication>
#include "Silnik.h"

Silnik * silnik;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    silnik = new Silnik(600,800,75,75);
    silnik->show();

    return a.exec();
}
