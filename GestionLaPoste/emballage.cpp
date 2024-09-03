#include "emballage.h"

Emballage::Emballage(const string _format, const int _resistance, const int _largeur,const int _longueur, const int _hauteur):
    format(_format),
    resistance(_resistance),
    largeur(_largeur),
    longueur(_longueur),
    hauteur(_hauteur),
    stock(0)
{
    //cout << "Constructeur: Emballage /" << format << endl;
}

Emballage::~Emballage() {
    //cout << "Destructeur: Emballage /" << format << endl;
}

void Emballage::Visualiser()
{
    cout << left << "| " << setfill(' ') << setw(16) << format << "| " << setw(2) << resistance  << setw(9) << " kg" << "|"  << setw(3) << longueur << " X "  << setw(3) << largeur;
    if (hauteur > 0 )
        cout << " X " << setw(3) << hauteur << " |" << endl;
    else
        cout << right << setw(8) << " |" << endl;
}

bool Emballage::operator <(Emballage &autre)
{
    return CalculerVolume() < autre.CalculerVolume();
}

double Emballage::CalculerVolume()
{
    int volume = largeur * longueur;
    if (hauteur > 0)
        volume *= hauteur;


    double volumeCm3 = volume / 1000.0;
    return volumeCm3;
}

bool Emballage::operator ==(Emballage &autre)
{
    return (longueur == autre.longueur && largeur == autre.largeur && hauteur == autre.hauteur && resistance == autre.resistance);
}

Emballage::operator float()
{
    return CalculerVolume();
}
