#include "testgestiondustock.h"
#include "ui_testgestiondustock.h"
#include <QFile>
#include <QFileDialog>

TestGestionDuStock::TestGestionDuStock(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TestGestionDuStock)
{
    ui->setupUi(this);
}

TestGestionDuStock::~TestGestionDuStock()
{
    delete ui;
}

void TestGestionDuStock::on_pushButtonNouveau_clicked()
{
    int diametre = ui->lineEditDiametre->text().toInt();
    QString reference = ui->lineEditReference->text();
    leStock.AjouterRouleau(Rouleau(reference,diametre));
    QStringList stock = leStock.ObtenirContenuDuStock();
    ui->listWidgetStock->clear();
    ui->listWidgetStock->addItems(stock);
}


void TestGestionDuStock::on_pushButtonRetrait_clicked()
{
    if (ui->listWidgetStock->count() > 0) {
        nbRouleau = leStock.RechercherSerie(debut);
        auto memo = debut;

        ui->listWidgetRouleauxRetenus->clear();
        for (int i = 0; i < 6; ++i) {
            QString texte = QString("Référence : %1, Diamètre : %2 ").arg(memo.value().getReference()).arg(memo.value().getDiametre());
            ui->listWidgetRouleauxRetenus->addItem(texte);
            memo++;
        }
    }
}


void TestGestionDuStock::on_pushButtonSupprimer_clicked()
{
    ui->listWidgetRouleauxRetenus->clear();
    for (int i = 0; i < nbRouleau; ++i) {
        auto memo = debut;
        memo++;
        leStock.RetirerRouleauDuStock(debut);
        debut = memo;
    }
    QStringList stock = leStock.ObtenirContenuDuStock();

    ui->listWidgetStock->clear();
    ui->listWidgetStock->addItems(stock);

}


void TestGestionDuStock::on_pushButtonEnregistrer_clicked()
{
    QString enregistrement = QFileDialog::getSaveFileName(this,
                                                    tr("Enregistrer un fichier"),
                                                    "/Users/lenny/Documents/GitHub/Ciel2_CPP/EnregistrementDuStock.txt",
                                                    tr("Fichiers texte (*.txt);;Tous les fichiers (*)"));
    if (!enregistrement.isEmpty()) {
        QFile file(enregistrement);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QDataStream out(&file);
            out << leStock.ObtenirContenuDuStock();
        }
    }
}


void TestGestionDuStock::on_pushButtonRecuperer_clicked()
{
    QString recuperer = QFileDialog::getOpenFileName(this,
                                                    tr("Ouvrir un fichier"),
                                                    "/Users/lenny/Documents/GitHub/Ciel2_CPP/",
                                                    tr("Fichiers texte (*.txt);;Tous les fichiers (*)"));
    if (!recuperer.isEmpty()) {
        QFile file(recuperer);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QDataStream in(&file);
            QStringList stock;
            in >> stock;  // Lire directement le QStringList depuis le fichier
            ui->listWidgetStock->clear();  // Vider la liste
            ui->listWidgetStock->addItems(stock);  // Ajouter les éléments récupérés
        }
    }
}

