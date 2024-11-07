#ifndef INTERFACEPRINCIPALE_H
#define INTERFACEPRINCIPALE_H

#include <QMainWindow>
#include "dialogconfigurerliaisongps.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui {
class InterfacePrincipale;
}
QT_END_NAMESPACE

class InterfacePrincipale : public QMainWindow
{
    Q_OBJECT

public:
    InterfacePrincipale(QWidget *parent = nullptr);
    ~InterfacePrincipale();

private slots:
    void on_actionConfigurer_triggered();

    void onQSerialPort_readyRead();

private:
    Ui::InterfacePrincipale *ui;
    QSerialPort lePort;
    DialogConfigurerLiaisonGPS configGPS;
    QLabel labelEtatPort;
    QByteArray trameCourant;
};
#endif // INTERFACEPRINCIPALE_H
