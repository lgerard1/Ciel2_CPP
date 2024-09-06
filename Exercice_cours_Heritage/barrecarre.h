#ifndef BARRECARRE_H
#define BARRECARRE_H

#include "barre.h"

class BarreCarre : public Barre
{
public:
    BarreCarre(const string _reference, const int _longueur, const float _densite, const string _nomAlliage);
    void AfficherCaractéristiques();
    double CalculerSection();
    double CalculerMasse();
};

#endif // BARRECARRE_H
