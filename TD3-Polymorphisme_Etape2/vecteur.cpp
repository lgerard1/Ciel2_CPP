#include "vecteur.h"

Vecteur::Vecteur(const double _x, const double _y):
    x(_x),
    y(_y)
{}

Vecteur Vecteur::operator +(const Vecteur &_autre)
{
    return Vecteur(x +_autre.x, y + _autre.y);
}

Vecteur Vecteur::operator -(const Vecteur &_autre)
{
    return Vecteur(x -_autre.x, y - _autre.y);
}

Vecteur Vecteur::operator +=(const Vecteur &_autre){
    return Vecteur(x +=_autre.x, y += _autre.y);
}

Vecteur Vecteur::operator -=(const Vecteur &_autre){
    return Vecteur(x -=_autre.x, y -= _autre.y);
}

void Vecteur::Afficher()
{
    cout << "Vecteur en ( " << x << ", " << y << " )" << endl;
}

void Vecteur::setX(const double _x)
{
    x = _x;
}

void Vecteur::setY(const double _y)
{
    y = _y;
}

float Vecteur::getX()
{
    return x;
}

float Vecteur::getY()
{
    return y;
}

ostream& operator<<(ostream& out, const Vecteur &vecteur){
    out << "(" << vecteur.x << "," << vecteur.y << ")" << endl ;
}
