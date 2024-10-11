#include "stock.h"

Stock::Stock() {}

void Stock::AjouterRouleau(const Rouleau _nouveau)
{
    lesRouleaux.insert(_nouveau.getDiametre(), _nouveau);
}

int Stock::RechercherSerie(QMultiMap<int,Rouleau>::iterator &_positionDebut)
{

}

bool Stock::RetirerRouleauDuStock(const QMultiMap<int,Rouleau>::iterator &_positionRouleau)
{
    bool retour = false;
    if (_positionRouleau != lesRouleaux.end()) {
        lesRouleaux.erase(_positionRouleau);
        retour = true;
    }
    return retour;
}

QStringList Stock::ObtenirContenuDuStock() const
{
    QStringList descriptionStock;
    for (auto it = lesRouleaux.begin(); it != lesRouleaux.end(); it++) {
        // QString reference = it.value().getReference();
        // QString diametre = it.value().getDiametre();
        // QString descriptionRouleau = QString("Référence : " + reference);


        QString descriptionRouleau = QString("Référence : %1, Diamètre : %2").arg(it.value().getReference()).arg(it.value().getDiametre());
        descriptionStock.append(descriptionRouleau);
    }
    return descriptionStock;
}
