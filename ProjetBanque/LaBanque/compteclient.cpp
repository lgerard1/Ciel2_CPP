#include "compteclient.h"

CompteClient::CompteClient(const string _nom, const int _numero):
    nom(_nom),
    numero(_numero)
{
    CompteEpargne = nullptr;
    bancaire = new CompteBancaire(0);
}

CompteClient::~CompteClient()
{
    delete bancaire;
}
