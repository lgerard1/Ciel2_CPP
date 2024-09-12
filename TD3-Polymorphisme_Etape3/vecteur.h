#ifndef VECTEUR_H
#define VECTEUR_H

#include <iostream>
#include <string>

using namespace std;

class Vecteur
{
public:
    Vecteur(const double _x = 0, const double _y = 0);
    Vecteur operator +(const Vecteur &_autre);
    Vecteur operator -(const Vecteur &_autre);
    Vecteur operator +=(const Vecteur &_autre);
    Vecteur operator -=(const Vecteur &_autre);
    void Afficher();

    void setX(const double _x);
    void setY(const double _y);
    float getX();
    float getY();

private:
    double x;
    double y;
    friend ostream& operator<<(ostream& out, const Vecteur &vecteur);
};

#endif // VECTEUR_H
