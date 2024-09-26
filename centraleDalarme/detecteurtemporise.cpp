#include "detecteurtemporise.h"

DetecteurTemporise::DetecteurTemporise() {
    setWindowTitle("Détecteur Temporisé");
    connect(&timerDelay,&QTimer::timeout,this,&DetecteurTemporise::onTimerDelay_timeout);
}

DetecteurTemporise::~DetecteurTemporise()
{
    timerDelay.stop();
}

void DetecteurTemporise::onTimerDelay_timeout()
{

    QMessageBox messageChiffre;
    messageChiffre.setText("Il y a un Intrus");
    messageChiffre.exec();
    timerDelay.stop();

}

void DetecteurTemporise::on_pushButtonIntrus_clicked()
{
    timerDelay.start(3000);

}
