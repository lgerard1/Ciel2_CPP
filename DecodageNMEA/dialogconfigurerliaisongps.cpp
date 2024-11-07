#include "dialogconfigurerliaisongps.h"
#include "ui_dialogconfigurerliaisongps.h"

DialogConfigurerLiaisonGPS::DialogConfigurerLiaisonGPS(QSerialPort &_lePort,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogConfigurerLiaisonGPS)
    ,lePort(_lePort)
{
    ui->setupUi(this);


    for(const auto &info : QSerialPortInfo::availablePorts() ) // foreach
    {
        qDebug() << info.portName();
        ui->comboBoxPort->addItem(info.portName());
    }
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    lePort.setBaudRate(QSerialPort::Baud9600);
    lePort.setDataBits(QSerialPort::Data8);
    lePort.setParity(QSerialPort::NoParity);
    lePort.setStopBits(QSerialPort::OneStop);
    lePort.setFlowControl(QSerialPort::NoFlowControl);
}

DialogConfigurerLiaisonGPS::~DialogConfigurerLiaisonGPS()
{
    delete ui;
}


void DialogConfigurerLiaisonGPS::on_checkBoxStop_toggled(bool checked)
{
    if (checked) {
        QSerialPort::TwoStop;
    }else {
        QSerialPort::OneStop;
    }
}


void DialogConfigurerLiaisonGPS::on_comboBoxVitesse_currentTextChanged(const QString &arg1)
{
    lePort.setBaudRate(arg1.toInt());
    qDebug() << "vitesse = " << arg1;
}



void DialogConfigurerLiaisonGPS::on_spinBoxBitData_valueChanged(int arg1)
{
    switch (arg1) {
    case 5:
        lePort.setDataBits(QSerialPort::Data5);
        break;
    case 6 :
        lePort.setDataBits(QSerialPort::Data6);
        break;
    case 7 :
        lePort.setDataBits(QSerialPort::Data7);
        break;
    case 8 :
        lePort.setDataBits(QSerialPort::Data8);
        break;
    default:
        break;
    }
}


void DialogConfigurerLiaisonGPS::on_radioButtonPaire_toggled(bool checked)
{
    lePort.setParity(QSerialPort::EvenParity);
}


void DialogConfigurerLiaisonGPS::on_radioButtonImpaire_toggled(bool checked)
{

    lePort.setParity(QSerialPort::OddParity);

}


void DialogConfigurerLiaisonGPS::on_radioButtonNone_toggled(bool checked)
{
    lePort.setParity(QSerialPort::NoParity);
}


void DialogConfigurerLiaisonGPS::on_comboBoxPort_currentIndexChanged(int index)
{

    if(ui->comboBoxPort->currentText() != "Choisissez un port"){
        for(const auto &info : QSerialPortInfo::availablePorts()) // foreach
        {
            if (info.portName() == ui->comboBoxPort->currentText()){
                qDebug() << "Changement du nom du port";

                lePort.setPortName(ui->comboBoxPort->currentText());
                qDebug() << lePort.portName();
                ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
            }
        }
    }

    else
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
}

