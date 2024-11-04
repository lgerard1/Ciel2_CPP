#ifndef STOCK_H
#define STOCK_H

#include "rouleau.h"
#include <QMultiMap>
#include <QDebug>
#include <QObject>

class Stock : public QObject
{
public:
    Stock();
    void AjouterRouleau(const Rouleau _nouveau);
    int RechercherSerie(QMultiMap<int,Rouleau>::iterator &_positionDebut);
    bool RetirerRouleauDuStock(const QMultiMap<int,Rouleau>::iterator &_positionRouleau);
    QStringList ObtenirContenuDuStock() const;

public :
    QMultiMap<int,Rouleau> lesRouleaux;

};

#endif // STOCK_H
