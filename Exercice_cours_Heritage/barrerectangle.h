#ifndef BARRERECTANGLE_H
#define BARRERECTANGLE_H

#include "barre.h"

class BarreRectangle : public Barre
{
public:
    BarreRectangle(const string _reference, const int _longueur, const float _densite, const string _nomAlliage, const int _largeur);
    void AfficherCaractéristiques();
    double CalculerSection();
    double CalculerMasse();
private :
    int largeur;
};

#endif // BARRERECTANGLE_H
