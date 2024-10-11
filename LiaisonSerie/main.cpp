#include "liasonserie.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LiasonSerie w;
    w.show();
    return a.exec();
}
