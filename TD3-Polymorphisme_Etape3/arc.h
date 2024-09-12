#ifndef ARC_H
#define ARC_H

#include "element.h"
#include "segment.h"

class Arc : public Element
{
public:
    Arc(const double _rayon, const double _angleDebut, const double _angleFin, const int _vitesse);
    void Afficher();
    double ObtenirLongueur();
    double ObtenirDuree();
    Vecteur ObtenirVecteurArrivee();
private:
    double rayon;
    double angleDebut;
    double angleFin;
    int vitesse;

};

#endif // ARC_H
