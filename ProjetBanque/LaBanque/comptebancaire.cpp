#include "comptebancaire.h"

CompteBancaire::CompteBancaire(const float _solde):
    solde(_solde)
{

}
/**
 * @brief CompteBancaire::Deposer
 * @details dépose le montant passé en paramètre sur le compte
 * @param _montant
 */
void CompteBancaire::Deposer(const float _montant)
{
    solde += _montant;
}
/**
 * @brief CompteBancaire::Retirer
 * @param _montant
 * @details Retire le montant passé en paramètre sur le compte
 */
bool CompteBancaire::Retirer(const float _montant)
{
    bool retour = false;
    if (solde >= _montant){
        solde -= _montant;
        return true;
    }
    return retour;

}
/**
 * @brief CompteBancaire::ConsulterSolde
 * @details Consulte le solde su compte bancaire
 * @return
 */

float CompteBancaire::ConsulterSolde()
{
    return solde;
}
