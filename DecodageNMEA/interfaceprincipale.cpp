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

    QSettings settings("SettingsInterfacePrincipale","Paramètres");
    settings.beginGroup("Liaison_serie");
    if (settings.contains("Port")) {
        lePort.setPortName(settings.value("Port").toString());
        lePort.setBaudRate(settings.value("Vitesse").toInt());
        QSerialPort::DataBits nbBits = static_cast<QSerialPort::DataBits>(settings.value("Bits").toInt());
        lePort.setDataBits(nbBits);
        QSerialPort::Parity parite = static_cast<QSerialPort::Parity>(settings.value("Parite").toInt());
        lePort.setParity(parite);
        QSerialPort::StopBits stop = static_cast<QSerialPort::StopBits>(settings.value("BitDeStop").toInt());
        lePort.setStopBits(stop);
        settings.endGroup();

        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    }
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
        QSettings settings("SettingsInterfacePrincipale","Paramètres");
        settings.beginGroup("Liaison_serie");
        settings.setValue("Port", lePort.portName());
        settings.setValue("Vitesse", lePort.baudRate());
        settings.setValue("Bits", lePort.dataBits());
        settings.setValue("Parite", lePort.parity());
        settings.setValue("BitDeStop", lePort.stopBits());
        settings.endGroup();
    }
}
void InterfacePrincipale::onQSerialPort_readyRead()
{
    QByteArray data = lePort.readAll();
    ui->textEdit->append(data);
}

