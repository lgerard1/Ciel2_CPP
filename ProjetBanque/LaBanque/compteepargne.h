#ifndef COMPTEEPARGNE_H
#define COMPTEEPARGNE_H
#include "comptebancaire.h"
/**
 * @brief The CompteEpargne class
 */
class CompteEpargne : public CompteBancaire
{
public:
    CompteEpargne(const float _solde = 0, const float _tauxInteret);
    void CalculerTauxInteret();
    void ModifierTaux(const float _nouveauxTaux);
private :

    float tauxInteret;
};

#endif // COMPTEEPARGNE_H
