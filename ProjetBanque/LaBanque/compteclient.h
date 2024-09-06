#ifndef COMPTECLIENT_H
#define COMPTECLIENT_H

#include <string>
#include "comptebancaire.h"
#include "compteepargne.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>

/**
 * @brief CompteEpargne::CompteEpargne
 * @abstract Classe pour gérer un compte epargne
 * @version 1.1 (modification accès attribut)
 */


using namespace std;

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
    CompteBancaire *Bancaire;
    CompteEpargne *Epargne;
};

#endif // COMPTECLIENT_H
