#ifndef DETECTEURTEMPORISE_H
#define DETECTEURTEMPORISE_H

#include "detecteur.h"

class DetecteurTemporise : public Detecteur
{
public:
    DetecteurTemporise();
    ~DetecteurTemporise();
    void onTimerDelay_timeout();
    void on_pushButtonIntrus_clicked();

private :
    QTimer timerDelay;
};

#endif // DETECTEURTEMPORISE_H
