#include "compteclient.h"

CompteClient::CompteClient(const string _nom, const int _numero):
    nom(_nom),
    numero(_numero)
{
    bancaire = 0;
}
