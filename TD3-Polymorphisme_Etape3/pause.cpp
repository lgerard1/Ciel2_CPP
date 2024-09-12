#include "pause.h"

Pause::Pause(const int _tempsAttente):
    tempsAttente(_tempsAttente)
{}

void Pause::Afficher()
{
    cout << "(" << numero << ") " << "Pause D = " << tempsAttente << endl;
}

double Pause::ObtenirLongueur()
{
    return 0;
}

double Pause::ObtenirDuree()
{
    return tempsAttente;
}

Vecteur Pause::ObtenirVecteurArrivee()
{
    return Vecteur(0,0);
}
