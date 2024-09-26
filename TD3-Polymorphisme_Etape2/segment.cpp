#include "segment.h"

Segment::Segment(const double _longueur, const double _angle, const int _vitesse):
    Element(_vitesse),
    longueur(_longueur),
    angle(_angle)

{

}

void Segment::Afficher()
{
    cout << "(" << numero << ") " << "SEGMENT L = ";
    cout << setw(6) << left <<  longueur << "A = " << angle;
    cout << right << setw(6) << "V = " << vitesse << endl;
}

double Segment::ObtenirLongueur()
{
    return longueur;
}

double Segment::ObtenirDuree()
{
    return longueur/vitesse;
}

Vecteur Segment::ObtenirVecteurArrivee()
{   
    return Vecteur(longueur * cos(angle), longueur * sin(angle));
}
