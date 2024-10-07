#ifndef CLAVIER_H
#define CLAVIER_H

#include <QWidget>
#include <QTimer>

#include "centraledalarme.h"


namespace Ui {
class Clavier;
}

class Clavier : public QWidget
{
    Q_OBJECT

public:
    explicit Clavier(CentraleDalarme *_centrale, QWidget *parent = 0);
    ~Clavier();


private slots:

    void TraiterChiffre();
    void on_pushButtonArret_clicked();
    void onTimerLed_timeout();
    void onTimerClavier_timeout();
    void on_pushButtonMarche_pressed();
    void on_pushButtonMarche_released();

public slots:
    void onEtatCentraleChange(CentraleDalarme::MODES_DE_MARCHE _etat);


private:
    Ui::Clavier *ui;
    CentraleDalarme *centrale;
    CentraleDalarme::MODES_DE_MARCHE etatCentrale;
    QTimer timerLed;
    QTimer timerClavier;

};

#endif // CLAVIER_H
