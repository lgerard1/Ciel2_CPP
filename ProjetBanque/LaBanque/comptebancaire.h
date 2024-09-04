#ifndef COMPTEBANCAIRE_H
#define COMPTEBANCAIRE_H
/**
 * @brief CompteBancaire::CompteBancaire
 * @abstract Classe pour gérer un compte bancaire
 * @param _solde
 * @version 1.1 (modification accès attribut)
 */
class CompteBancaire
{
public:
    CompteBancaire(const float _solde = 0);
    void Deposer(const float _montant);
    bool Retirer(const float _montant);
    float ConsulterSolde();

protected:
    float solde;
};

#endif // COMPTEBANCAIRE_H
