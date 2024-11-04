#include "alveoleslibres.h"

AlveolesLibres::AlveolesLibres(const int _nbRangees, const int _nbColonnes):
    nbRangees(_nbRangees),
    nbColonnes(_nbColonnes)

{
    reserve(nbColonnes*nbRangees);
    for (int i = 0; i <= nbColonnes*nbRangees ; ++i) {
       push(i + 1);
    }
    qDebug() << "Dans le constructeur : "<< *this;
}

bool AlveolesLibres::Reserver(int &_rangee, int &_colonne)
{
    bool retour = false;
    int numAlveole;
    numAlveole = pop();
    if (!isEmpty()) {
        _rangee = ((numAlveole - 1) / nbColonnes) + 1;
        _colonne =  ((numAlveole - 1) % nbColonnes) + 1;

        retour = true;
    }
    qDebug() << "Dans la méthode Réserver : "<< *this;
    return retour;
}

void AlveolesLibres::Liberer(const int _rangee, const int _colonne)
{
    int numAlveole = (_rangee - 1) * nbColonnes + _colonne;
    if (!contains(numAlveole)) {
        push(numAlveole);
    }

    qDebug() << "Alvéole libérée : Rangée =" << _rangee << ", Colonne =" << _colonne;
}

