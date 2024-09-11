#ifndef TRAJECTOIRE_H
#define TRAJECTOIRE_H

#include "element.h"

class Trajectoire
{
public:
    Trajectoire(const int _nbEtapesMaxi);
    ~Trajectoire();
    bool Ajouter(Element *_pElement);
    void Afficher();

private :
    int nbEtapesMaxi;
    int prochaineEtape = 0;
    Element **parcours;
};

#endif // TRAJECTOIRE_H
