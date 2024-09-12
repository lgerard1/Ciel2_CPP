#include "trajectoire.h"

Trajectoire::Trajectoire(const int _nbEtapesMaxi, const Vecteur _depart) :
    nbEtapesMaxi(_nbEtapesMaxi),
    prochaineEtape(0),
    depart(_depart)
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
        parcours[prochaineEtape-1]->setNumero(prochaineEtape);
    }
    else
        retour = false;
    return retour;
}

void Trajectoire::Afficher()
{
    Vecteur vecteurTotal;

    double longueurTotal = 0.0;
    double dureeTotal = 0.0;

    cout << "Trajectoire : " << endl <<  endl;

    vecteurTotal = depart;

    for (int i = 0; i < nbEtapesMaxi; ++i) {
        parcours[i]->Afficher();
        vecteurTotal += parcours[i]->ObtenirVecteurArrivee();
        cout << "Vecteur en " << vecteurTotal << endl;

        longueurTotal += parcours[i]->ObtenirLongueur();
        dureeTotal += parcours[i]->ObtenirDuree();

    }
    cout << endl;

    cout << "Durée totale du parcours = " << dureeTotal << endl;
    cout << "Longueur totale du parcours = " << longueurTotal << endl << endl;

    cout << "Vecteur de départ = " << depart;
    cout << "Vecteur d'arrivée  = " << vecteurTotal << endl;

    cout << endl;

}
