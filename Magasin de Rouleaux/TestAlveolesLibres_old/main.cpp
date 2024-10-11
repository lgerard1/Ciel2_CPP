#include "testalveoleslibres.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AlveolesLibres w;
    w.show();
    return a.exec();
}
