#ifndef BARRERONDE_H
#define BARRERONDE_H

#include "barre.h"

class BarreRonde : public Barre
{
public:
    BarreRonde(const string _reference, const int _longueur, const float _densite, const string _nomAlliage, const int _diametre);
    void AfficherCaractéristiques();
    double CalulerSection();
    double CalculerMasse();
private:
    int diametre;
};

#endif // BARRERONDE_H
