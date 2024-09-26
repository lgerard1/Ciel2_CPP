#include "detecteur.h"
#include "ui_detecteur.h"

Detecteur::Detecteur(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Detecteur)
{
    ui->setupUi(this);
    setWindowTitle("Detecteur");

}

Detecteur::~Detecteur()
{
    delete ui;

}

void Detecteur::on_pushButtonIntrus_clicked()
{
    QMessageBox messageChiffre;
    messageChiffre.setText("Intrus");
    messageChiffre.exec();
}

