#include "testgestiondustock.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestGestionDuStock w;
    w.show();
    return a.exec();
}
