#ifndef SEGMENT_H
#define SEGMENT_H
#include <math.h>

#include "element.h"

class Segment : public Element
{
public:
    Segment(const double  _longueur, const double _angle, const int _vitesse);
    void Afficher();
    double ObtenirLongueur();
    double ObtenirDuree();
    Vecteur ObtenirVecteurArrivee();

private:
    double longueur;
    double angle;
};

#endif // SEGMENT_H
