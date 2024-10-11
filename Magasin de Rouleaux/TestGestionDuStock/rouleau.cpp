#include "rouleau.h"

Rouleau::Rouleau(const QString _reference, const int _diametre):
    reference(_reference),
    diametre(_diametre)
{}

Rouleau::Rouleau() {}

Rouleau::Rouleau(const Rouleau &_autre)
{
    diametre = _autre.diametre;
    reference = _autre.reference;
    rangee = _autre.rangee;
    colonne = _autre.colonne;
}

Rouleau &Rouleau::operator=(const Rouleau &_autre)
{
    if (this != &_autre) {
        diametre = _autre.diametre;
        reference = _autre.reference;
        rangee = _autre.rangee;
        colonne = _autre.colonne;
    }
}

void Rouleau::AffecterLocalisation(const int _rangee, const int _colonne)
{
    rangee = _rangee;
    colonne = _colonne;
}

void Rouleau::ObtenirLocalisation(int &_rangee, int &_colonne) const
{
    _rangee = rangee;
    _colonne = colonne;
}

int Rouleau::getDiametre() const
{
    return diametre;
}


QString Rouleau::getReference() const
{
    return reference;
}
