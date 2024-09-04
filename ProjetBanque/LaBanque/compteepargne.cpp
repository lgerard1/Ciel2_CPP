#include "compteepargne.h"

CompteEpargne::CompteEpargne(const float _tauxInteret, const float _solde):
    CompteBancaire(_solde),
    tauxInteret(_tauxInteret)
{

}

void CompteEpargne::CalculerTauxInteret()
{
    solde = solde + solde * tauxInteret / 100;

}

