#include "testalveoleslibres.h"
#include "ui_testalveoleslibres.h"

TestAlveolesLibres::TestAlveolesLibres(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TestGestionStock)
    ,lesAlveoles(2,3)
{
    ui->setupUi(this);

}

TestAlveolesLibres::~TestAlveolesLibres()
{
    delete ui;
}

void TestAlveolesLibres::on_pushButtonReserver_clicked()
{
    int rangee, colonne;
    if(lesAlveoles.Reserver(rangee, colonne)){
        QString texte = "Alvéole occupée en : ";
        texte += QString::number(rangee) + "," + QString::number(colonne);
        ui->listWidgetAlveolesLibres->addItem(texte);
        ui->lineEditLiberer->clear();
    }
    else {
        QMessageBox msgAlveolesPleine;
        msgAlveolesPleine.setText("Il n'y a plus de place");
        msgAlveolesPleine.exec();
    }
}


void TestAlveolesLibres::on_pushButtonLiberer_clicked()
{
    if (ui->listWidgetAlveolesLibres->currentItem()) {
        QString alveolesChoisi = ui->listWidgetAlveolesLibres->currentItem()->text();
        QStringList coordonnee = alveolesChoisi.split(": ");
        QString coor = coordonnee[1];
        QStringList pdf = coor.split(",");
        QString pdf2 = pdf[0];
        QString pdf3 = pdf[1];
        int rangee = pdf2.toInt();
        int colonne = pdf3.toInt();
        ui->lineEditLiberer->setText(coordonnee[1]);
        lesAlveoles.Liberer(rangee, colonne);
        delete ui->listWidgetAlveolesLibres->currentItem();

    }
}

