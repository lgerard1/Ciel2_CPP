#include "testgestiondustock.h"
#include "ui_testgestiondustock.h"

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

