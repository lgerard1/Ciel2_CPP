#include "barre.h"


Barre::Barre(const string _reference, const int _longueur, const float _densite, const string _nomAlliage):
    reference(_reference),
    longueur(_longueur),
    densite(_densite),
    nomAlliage(_nomAlliage)

{

}

void Barre::AfficherCaractéristiques()
{
    cout << "Voici la réference : " << reference << endl;
    cout << "Voici la longueur : " << longueur << "cm" << endl;
    cout << "Voici la densité : " << densite << endl;
    cout << "Voici le nom de l'alliage : " << nomAlliage << endl;
}
