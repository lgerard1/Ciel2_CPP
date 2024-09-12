#include "arc.h"

Arc::Arc(const double _rayon, const double _angleDebut, const double _angleFin, const int _vitesse):
    Element(_vitesse),
    rayon(_rayon),
    angleDebut(_angleDebut),
    angleFin(_angleFin)

{}

void Arc::Afficher()
{
    cout << left << "(" << numero << ") " << "ARC R = " << setw(6) << rayon << "Angle début = " << setw(10) << angleDebut << "Angle fin = " << setw(6) << angleFin << "V = " << setw(6) << vitesse << endl;
}

double Arc::ObtenirLongueur()
{
    return fabs(angleDebut - angleFin) * rayon;
}

double Arc::ObtenirDuree()
{
    return (ObtenirLongueur() / vitesse);
}

Vecteur Arc::ObtenirVecteurArrivee()
{
    Vecteur ptCentre(rayon * cos(angleDebut),rayon * sin(angleDebut));
    Vecteur ptArrivee(rayon * cos(angleFin),rayon * sin(angleFin));
    return (ptArrivee - ptCentre) ;
}
