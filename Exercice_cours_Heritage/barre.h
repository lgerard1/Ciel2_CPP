#ifndef BARRE_H
#define BARRE_H

#include <string>
#include <iostream>

using namespace std;

class Barre
{
public:
    Barre(const string _reference, const int _longueur, const float _densite, const string _nomAlliage);
    void AfficherCaractéristiques();

protected :
    string reference;
    int longueur;
    float densite;
    string nomAlliage;
};

#endif // BARRE_H
