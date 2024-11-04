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
    lesAlveoles.Reserver(rangee, colonne);
    leChariot.DeplacerChariot(rangee, colonne, true);

}

void Magasin::AfficherRouleauEnceinte(const Rouleau _rouleau)
{
    if (ui->listWidgetStock->count() > 0) {
        nbRouleau = leStock.RechercherSerie(debut);
        auto memo = debut;
        ui->listWidgetEnceinte->clear();
        for (int i = 0; i < nbRouleau && memo != leStock.lesRouleaux.end(); ++i) {
            QString texte = QString("Référence : %1, Diamètre : %2").arg(memo.value().getReference()).arg(memo.value().getDiametre());
            ui->listWidgetEnceinte->addItem(texte);
            int rangee = 0, colonne = 0;
            memo.value().ObtenirLocalisation(rangee, colonne);
        lesAlveoles.Liberer(rangee, colonne);
        leChariot.DeplacerChariot(rangee, colonne, false);

        }
        ++memo;
    }
}




Magasin::~Magasin()
{
    delete ui;
}

void Magasin::on_pushButtonNouveau_clicked()
{
    AfficherStock();
}


void Magasin::on_pushButtonRetrait_clicked()
{
    QListWidgetItem *selectedItem = ui->listWidgetStock->currentItem();
    QString reference = selectedItem->text();
    int diametre = lesRouleaux.getDiametre();
    Rouleau rouleauFiltre(reference, diametre);
    AfficherRouleauEnceinte(rouleauFiltre);
}

