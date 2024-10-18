#include "magasin.h"
#include "ui_magasin.h"

Magasin::Magasin(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Magasin)
{
    ui->setupUi(this);
}

void Magasin::AfficherStock()
{
    int diametre = ui->lineEditDiametre->text().toInt();
    QString reference = ui->lineEditReference->text();
    leStock.AjouterRouleau(Rouleau(reference,diametre));
    QStringList stock = leStock.ObtenirContenuDuStock();
    ui->listWidgetStock->clear();
    ui->listWidgetStock->addItems(stock);
}

void Magasin::AfficherRouleauEnceinte(const Rouleau _rouleau)
{
    if (ui->listWidgetStock->count() > 0) {
        nbRouleau = leStock.RechercherSerie(debut);
        auto memo = debut;

        ui->listWidgetEnceinte->clear();
        for (int i = 0; i < 6; ++i) {
            QString texte = QString("Référence : %1, Diamètre : %2 ").arg(memo.value().getReference()).arg(memo.value().getDiametre());
            ui->listWidgetEnceinte->addItem(texte);
            memo++;
        }
    }
}

Magasin::~Magasin()
{
    delete ui;
}

void Magasin::on_pushButtonNouveau_clicked()
{

}


void Magasin::on_pushButtonRetrait_clicked()
{

}

