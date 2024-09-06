#include "barreronde.h"

BarreRonde::BarreRonde(const string _reference, const int _longueur, const float _densite, const string _nomAlliage, const int _diametre):
    Barre(_reference, _longueur, _densite, _nomAlliage),
    diametre(_diametre)
{

}

void BarreRonde::AfficherCaractéristiques()
{
    Barre::AfficherCaractéristiques();
    cout << "Le Diamètre est de : " << diametre << endl;
    cout << "Poids de la Barre : " << CalculerMasse() / 10000.0 << " kg" << endl;
}

double BarreRonde::CalulerSection()
{
    return (3.14 * (diametre * diametre) / 4);
}

double BarreRonde::CalculerMasse()
{
    return CalulerSection() * longueur * densite;
}
