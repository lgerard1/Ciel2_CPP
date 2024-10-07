#include "clavier.h"
#include "ui_clavier.h"

#include "centraledalarme.h"


#include <QMessageBox>

Clavier::Clavier(CentraleDalarme *_centrale, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Clavier),
    centrale(_centrale),
    etatCentrale(CentraleDalarme::REPOS)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
    connect(ui->pushButton_1,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
    connect(ui->pushButton_2,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
    connect(ui->pushButton_3,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
    connect(ui->pushButton_4,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
    connect(ui->pushButton_5,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
    connect(ui->pushButton_6,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
    connect(ui->pushButton_7,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
    connect(ui->pushButton_8,&QPushButton::clicked,this,&Clavier::TraiterChiffre);
    connect(ui->pushButton_9,&QPushButton::clicked,this,&Clavier::TraiterChiffre);

    connect(&timerLed,&QTimer::timeout,this,&Clavier::onTimerLed_timeout);
    connect(&timerClavier,&QTimer::timeout,this,&Clavier::onTimerClavier_timeout);
    connect(centrale,&CentraleDalarme::EtatCentraleChange,this,&Clavier::onEtatCentraleChange);
}

Clavier::~Clavier()
{
    delete ui;
}


void Clavier::TraiterChiffre()
{
    QPushButton *pbouton = (QPushButton *)sender();
    QString texteBouton = pbouton->text();
    centrale->FabriquerCode(texteBouton.toInt());
}

void Clavier::on_pushButtonArret_clicked()
{
    centrale->TraiterBoutonArret();
}

void Clavier::onTimerLed_timeout()
{
    if(etatCentrale == CentraleDalarme::MODIFICATION_CODE)
    {

        if(ui->checkBoxLedRouge->checkState()== Qt::Checked)
            ui->checkBoxLedRouge->setCheckState(Qt::Unchecked);
        else
            ui->checkBoxLedRouge->setCheckState(Qt::Checked);
    }
    if(ui->checkBoxLedVerte->checkState()== Qt::Checked)
        ui->checkBoxLedVerte->setCheckState(Qt::Unchecked);
    else
        ui->checkBoxLedVerte->setCheckState(Qt::Checked);
}

void Clavier::onTimerClavier_timeout()
{
    timerClavier.stop();
    centrale->ModifierCode();
}

void Clavier::onEtatCentraleChange(CentraleDalarme::MODES_DE_MARCHE _mode)
{
    etatCentrale = _mode;
    switch(etatCentrale)
    {
    case CentraleDalarme::REPOS:
        ui->checkBoxLedRouge->setCheckState(Qt::Checked);
        ui->checkBoxLedVerte->setCheckState(Qt::Unchecked);
        break;
    case CentraleDalarme::MODIFICATION_CODE:
        ui->checkBoxLedRouge->setCheckState(Qt::Checked);
        ui->checkBoxLedVerte->setCheckState(Qt::Checked);
        timerLed.start(500);
        break;
    case CentraleDalarme::SAISI_NOUVEAU:
        ui->checkBoxLedRouge->setCheckState(Qt::Checked);
        ui->checkBoxLedVerte->setCheckState(Qt::Checked);
        timerLed.stop();
        break;
    case CentraleDalarme::SURVEILLANCE:
        timerLed.stop();
        ui->checkBoxLedRouge->setCheckState(Qt::Unchecked);
        ui->checkBoxLedVerte->setCheckState(Qt::Checked);
        break;
    case CentraleDalarme::ACTIVATION:
        ui->checkBoxLedRouge->setCheckState(Qt::Unchecked);
        ui->checkBoxLedVerte->setCheckState(Qt::Checked);
        timerLed.start(250);
        break;
    }
}



void Clavier::on_pushButtonMarche_pressed()
{
    timerClavier.start(5000);
}

void Clavier::on_pushButtonMarche_released()
{
    if(timerClavier.isActive())
    {
        timerClavier.stop();
        centrale->TraiterBoutonMarche();
    }
}
