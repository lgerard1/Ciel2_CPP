#ifndef ELEMENT_H
#define ELEMENT_H
#include <iostream>
#include <iomanip>
#include <string>

#include "vecteur.h"

using namespace std;

class Element
{
public:
    Element(const int _vitesse = 1);
    virtual ~Element();
    virtual void Afficher() = 0;
    virtual double ObtenirLongueur() = 0;
    virtual double ObtenirDuree() = 0;
    virtual Vecteur ObtenirVecteurArrivee() = 0;

    double getNumero() const;
    void setNumero(const double _numero);
protected:
    int numero;
    int vitesse;
};

#endif // ELEMENT_H
