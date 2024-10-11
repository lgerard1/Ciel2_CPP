#ifndef ROULEAU_H
#define ROULEAU_H

#include <QString>
#include <string>

using namespace std;

class Rouleau
{
public:
    Rouleau(const QString _reference, const int _diametre);
    Rouleau();
    Rouleau(const Rouleau& _autre);
    Rouleau &operator=(const Rouleau& _autre);
    ~Rouleau();
    void AffecterLocalisation(const int _rangee, const int _colonne);
    void ObtenirLocalisation(int &_rangee, int &_colonne) const;

    int getDiametre() const;

    QString getReference() const;

private :
    QString reference;
    int diametre;
    int rangee;
    int colonne;


};

#endif // ROULEAU_H
