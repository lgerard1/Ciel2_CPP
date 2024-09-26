#include "clavier.h"
#include "ui_clavier.h"

Clavier::Clavier(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Clavier)
{
    ui->setupUi(this);
    connect(ui->pushButton0, &QPushButton::clicked,this,&Clavier::TraiterChiffre);
    connect(ui->pushButton1, &QPushButton::clicked,this,&Clavier::TraiterChiffre);
    // connect(ui->pushButton2, &QPushButton::clicked,this,&Clavier::TraiterChiffre);
    // connect(ui->pushButton3, &QPushButton::clicked,this,&Clavier::TraiterChiffre);
    // connect(ui->pushButton4, &QPushButton::clicked,this,&Clavier::TraiterChiffre);
    // connect(ui->pushButton5, &QPushButton::clicked,this,&Clavier::TraiterChiffre);
    connect(ui->pushButton6, &QPushButton::clicked,this,&Clavier::TraiterChiffre);
    connect(ui->pushButton7, &QPushButton::clicked,this,&Clavier::TraiterChiffre);
    connect(ui->pushButton8, &QPushButton::clicked,this,&Clavier::TraiterChiffre);
    connect(ui->pushButton9, &QPushButton::clicked,this,&Clavier::TraiterChiffre);
    connect(&timerLed,&QTimer::timeout,this,&Clavier::onTimerLed_timeout);
    leDetecteur = nullptr;
    leDetecteurTempo = nullptr;
}

Clavier::~Clavier()
{
    delete ui;
}

void Clavier::on_pushButtonMarche_clicked()
{
    // QMessageBox messageMarche;
    // messageMarche.setText("j'ai appuyé sur Marche");
    // messageMarche.exec();
    ui->checkBoxLedRouge->setCheckState(Qt::Checked);
    timerLed.start(500);
}

void Clavier::TraiterChiffre()
{
    QPushButton *pbouton = static_cast<QPushButton *>(sender());
    QString texteBouton = pbouton->text();
    QMessageBox messageChiffre;
    messageChiffre.setText("j'ai appuyé sur la touche " + texteBouton);
    messageChiffre.exec();
}

void Clavier::onTimerLed_timeout()
{
    if(ui->checkBoxLedRouge->checkState() == Qt::Checked)
        ui->checkBoxLedRouge->setCheckState(Qt::Unchecked);
    else
        ui->checkBoxLedRouge->setCheckState(Qt::Checked);
}





void Clavier::on_pushButtonArret_clicked()
{
    ui->checkBoxLedRouge->setCheckState(Qt::Unchecked);
    timerLed.stop();
}


void Clavier::on_pushButton2_clicked()
{
    leDetecteur = new Detecteur;
    leDetecteur->show();
}


void Clavier::on_pushButton3_clicked()
{
    if (leDetecteur != nullptr) {
        leDetecteur->hide();
        delete leDetecteur;
        leDetecteur = nullptr;
    }

}


void Clavier::on_pushButton4_clicked()
{
    leDetecteurTempo = new DetecteurTemporise;
    leDetecteurTempo->show();

}


void Clavier::on_pushButton5_clicked()
{

    if (leDetecteurTempo != nullptr) {
        leDetecteurTempo->hide();
        delete leDetecteurTempo;
        leDetecteurTempo = nullptr;
    }
}

