#include <iostream>
#include "emballage.h"

using namespace std;

int main()
{
    Emballage *tab[5];

    string format;
    int largeur, longueur, hauteur, resistance;

    for (int i = 0; i < 2; i++){
        cout << "Format : "; getline(cin,format);
        cout << "Resistance : ";
        cin >> resistance;
        cout << "Longueur : ";
        cin >> longueur;
        cout << "Largeur : ";
        cin >> largeur;
        cout << "Hauteur : ";
        cin >> hauteur;
        cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
        tab[i] = new Emballage(format,resistance,largeur,longueur,hauteur);
    }
    /*
    Emballage colis1("XS",1,270,190);
    Emballage *pColis;
    pColis = new Emballage("XL",7,383,250,195);
    delete pColis;
    Emballage colis1("XS",1,270,190);
*/
    cout << "+" << setfill('-') << setw(18) << "+" << setw(13) << "+" << setw(17) << "+" << endl;
    cout << "|" << setfill(' ') << left << setw(17) << " Format" << "|" << setw(12) << " Resistance" << "|" << setw(16) << "Dimensions" << "|" << endl;
    cout << right << "+" << setfill('-') << setw(18) << "+" << setw(13) << "+" << setw(17) << "+" <<endl;
    for (int indice = 0; indice < 2; indice++){
        tab[indice]->Visualiser();
        delete tab[indice];
    }
    cout << "+" << setfill('-') << setw(18) << "+" << setw(13) << "+" << setw(17) << "+" << endl;

    if (*tab[0] == *tab[1]){
        cout << "tab[0] et tab[1] sont égaux" << endl;
        if (*tab[0] < *tab[1])
            cout << "tab[0] est plus petit que tab[1]" << endl;
        else
            cout << "tab[1] est plus petit que tab[0]" << endl;
    }
    float volume = *tab[0];
    cout << "Le volume est de " << volume << "Cm3" << endl;

    return 0;
}
