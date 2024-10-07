#include "detecteurtemporise.h"
#include "ui_detecteurtemporise.h"

#include <QMessageBox>

DetecteurTemporise::DetecteurTemporise(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DetecteurTemporise)
{
    ui->setupUi(this);
    setWindowTitle("Détecteur temporisé");
    connect(&timerIntrus,&QTimer::timeout,this,&DetecteurTemporise::onTimerIntrus_timeout);
}

DetecteurTemporise::~DetecteurTemporise()
{
    delete ui;
}

void DetecteurTemporise::on_pushButtonIntrus_clicked()
{
    timerIntrus.start(3000);
}

void DetecteurTemporise::onTimerIntrus_timeout()
{
    timerIntrus.stop();
    emit IntrusDetecte();
}
