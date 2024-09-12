#ifndef TRAJECTOIRE_H
#define TRAJECTOIRE_H

#include "element.h"
#include "vecteur.h"
#include "pause.h"

class Trajectoire
{
public:
    Trajectoire(const int _nbEtapesMaxi, const Vecteur _depart);
    ~Trajectoire();
    bool Ajouter(Element *_pElement);
    void Afficher();

private :
    int nbEtapesMaxi;
    int prochaineEtape = 0;
    Element **parcours;
    Vecteur depart;
};

#endif // TRAJECTOIRE_H
