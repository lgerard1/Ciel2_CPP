#include "trajectoire.h"

Trajectoire::Trajectoire(const int _nbEtapesMaxi) :
    nbEtapesMaxi(_nbEtapesMaxi),
    prochaineEtape(0)
{
    parcours = new Element *[nbEtapesMaxi];
}

Trajectoire::~Trajectoire()
{
    for (int indice = 0; indice < prochaineEtape; ++indice) {
        delete parcours[indice];
    }
    delete[] parcours;
}

bool Trajectoire::Ajouter(Element *_pElement)
{
    bool retour = true;
    if (prochaineEtape < nbEtapesMaxi) {
        parcours[prochaineEtape++] = _pElement;
    }
    else
        retour = false;
    return retour;
}

void Trajectoire::Afficher()
{
    cout << "Trajectoire : " << endl <<  endl;

    for (int i = 0; i < nbEtapesMaxi; ++i) {
        parcours[i]->Afficher();
    }
    cout << endl;
}
