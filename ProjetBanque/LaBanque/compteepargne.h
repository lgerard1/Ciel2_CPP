#ifndef COMPTEEPARGNE_H
#define COMPTEEPARGNE_H
#include "comptebancaire.h"
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
/**
 * @brief The CompteEpargne class
 */

using namespace std;

class CompteEpargne : public CompteBancaire
{
public:
    CompteEpargne(const float _tauxInteret = 3, const float _solde = 0);
    void CalculerTauxInteret();
    void ModifierTaux(const float _nouveauxTaux);
private :

    float tauxInteret;
};

#endif // COMPTEEPARGNE_H
