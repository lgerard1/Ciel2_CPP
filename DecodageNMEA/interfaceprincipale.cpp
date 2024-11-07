#include "interfaceprincipale.h"
#include "ui_interfaceprincipale.h"

InterfacePrincipale::InterfacePrincipale(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::InterfacePrincipale),
    configGPS(lePort)
{
    ui->setupUi(this);
    labelEtatPort.setText("port fermé");
    ui->statusbar->addPermanentWidget(&labelEtatPort);
    ui->statusbar->show();
}

InterfacePrincipale::~InterfacePrincipale()
{
    delete ui;
}

void InterfacePrincipale::on_actionConfigurer_triggered()
{

    if (configGPS.exec() == QDialog::Accepted)
    {
        lePort.open(QIODevice::ReadOnly);
            qDebug() << lePort.portName() << lePort.baudRate() << lePort.dataBits();
            labelEtatPort.setText("port fermé");
            ui->statusbar->addPermanentWidget(&labelEtatPort);
            ui->statusbar->show();
            qDebug() << lePort.portName();
            QString message;
            QTextStream flux (&message);
            QString parite;
            switch (lePort.parity()) {
            case QSerialPort::NoParity:
                parite = "n";
                break;
            case QSerialPort::EvenParity:
                parite = "i";
                break;
            case QSerialPort::OddParity:
                parite = "p";
                break;
            default:
                break;
            }
            flux << "Port : " << lePort.portName() << "," << lePort.baudRate() << "," << lePort.dataBits() << "," << parite << "," << lePort.stopBits();
            labelEtatPort.setText(message);
            connect(&lePort, &QSerialPort::readyRead, this, &InterfacePrincipale::onQSerialPort_readyRead);    // ouverture du port et connexion du signal readyRead
            ui->statusbar->show();
        }
}
void InterfacePrincipale::onQSerialPort_readyRead()
{
    QByteArray data = lePort.readAll();
    ui->textEdit->append(data);
}

