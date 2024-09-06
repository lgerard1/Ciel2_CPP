#include "barrecarre.h"


BarreCarre::BarreCarre(const string _reference, const int _longueur, const float _densite, const string _nomAlliage):
    Barre(_reference, _longueur, _densite, _nomAlliage)
{
}

void BarreCarre::AfficherCaractéristiques()
{
    Barre::AfficherCaractéristiques();
    cout << "Poids de la Barre : " << CalculerMasse() / 10000.0 << " kg" << endl;
}

double BarreCarre::CalculerSection()
{
    return longueur * longueur;
}

double BarreCarre::CalculerMasse()
{
    return CalculerSection() * longueur * densite;
}
