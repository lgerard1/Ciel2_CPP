#ifndef PAUSE_H
#define PAUSE_H

#include "element.h"

class Pause : public Element
{
public:
    Pause(const int _tempsAttente);
    void Afficher();
    double ObtenirLongueur();
    double ObtenirDuree();
    Vecteur ObtenirVecteurArrivee();

private :
    int tempsAttente;
};

#endif // PAUSE_H
