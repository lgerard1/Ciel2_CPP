#ifndef COMPTECLIENT_H
#define COMPTECLIENT_H
#include <string>
#include "comptebancaire.h"
#include "compteepargne.h"

class CompteClient
{
public:
    CompteClient(const string _nom, const int _numero);
    ~CompteClient();
    void OuvrirCompteEpargne();
    void GererCompteBancaire();
    void GererCompteEpargne();

private:
    string nom;
    int numero;
    bancaire *CompteBancaire;
    epargne *CompteEpargne;
};

#endif // COMPTECLIENT_H
