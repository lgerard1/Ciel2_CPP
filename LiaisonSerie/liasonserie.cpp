#include "liasonserie.h"
#include "ui_liasonserie.h"


LiasonSerie::LiasonSerie(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LiasonSerie)
{
    ui->setupUi(this);
    for(const auto &info : QSerialPortInfo::availablePorts() ) // foreach
    {
        qDebug() << info.portName();
        ui->comboBoxChoix->addItem(info.portName());
    }
    portPtr = new QSerialPort;

}

LiasonSerie::~LiasonSerie()
{
    delete ui;
}

void LiasonSerie::on_comboBoxChoix_currentTextChanged(const QString &arg1)
{
    if (arg1 != "Choisissez un port Série") {
        portPtr->close();
        portPtr->setPortName(arg1);
    }
}

