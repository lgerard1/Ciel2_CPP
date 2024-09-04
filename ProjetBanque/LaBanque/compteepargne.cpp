#include "compteepargne.h"

CompteEpargne::CompteEpargne(const float _solde, const float _tauxInteret):
tauxInteret(_tauxInteret),
    CompteBancaire(_solde)
{

}

void CompteEpargne::CalculerTauxInteret()
{
    solde = solde + solde * tauxInteret / 100;
}

void CompteEpargne::ModifierTaux(const float _nouveauxTaux):

{

}
