#include "sirene.h"
#include <QFileInfo>

Sirene::Sirene(QObject *parent) : QObject(parent)
{
    son.setSource(QUrl::fromLocalFile(QFileInfo("alarme.mp3").absoluteFilePath()));

}

void Sirene::Enclencher()
{
    son.play();
}

void Sirene::Arreter()
{
    son.stop();
}
