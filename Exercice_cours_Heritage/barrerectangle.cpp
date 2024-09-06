#include "barrerectangle.h"


BarreRectangle::BarreRectangle(const string _reference, const int _longueur, const float _densite, const string _nomAlliage, const int _largeur):
    Barre(_reference, _longueur, _densite, _nomAlliage),
    largeur(_largeur)
{

}

void BarreRectangle::AfficherCaractéristiques()
{
        Barre::AfficherCaractéristiques();
        cout << "La largeur est de : " << largeur << endl;
        cout << "Poids de la Barre : " << CalculerMasse() / 10000.0 << " kg" << endl;
}

double BarreRectangle::CalculerSection()
{
    return longueur * largeur;
}

double BarreRectangle::CalculerMasse()
{
    return CalculerSection() * longueur * densite;
}
