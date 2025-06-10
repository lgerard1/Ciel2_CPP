/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Plateau.cpp
 * Author: lgerard
 * 
 * Created on 13 février 2024, 15:57
 */

#include "plateau.h"
#include <iostream>
#include <iomanip>

Plateau::Plateau(const string _nomDuFichier) :
Flotte(_nomDuFichier) {
    int i;
    int indice;
    for (i = 0; i <= 10; i++) {
        for (indice = 0; indice <= 10; indice++) {
            grille[10][10] = 0;
        }
    }

}

void Plateau::AfficherGrille() {
    int i;
    for (i = 0; i <= 10; i++) {
        cout << setw(3) << i;
    }
    cout << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << endl;
    cout << "A" << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << endl;
    cout << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << endl;
    cout << "B" << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << endl;
    cout << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << endl;
    cout << "C" << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << endl;
    cout << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << endl;
    cout << "D" << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << endl;
    cout << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << endl;
    cout << "E" << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << endl;
    cout << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << endl;
    cout << "F" << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << endl;
    cout << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << endl;
    cout << "G" << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << endl;
    cout << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << endl;
    cout << "H" << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << endl;
    cout << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << endl;
    cout << "I" << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << endl;
    cout << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << endl;
    cout << "J" << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << setfill(' ') << setw(3) << "|" << endl;
    cout << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << setfill('-') << setw(3) << "+" << endl;

}

void Plateau::Tirer(const char _vertical, const int _horizontal, const bool _cible)
{
    _cible = false;
    if(_vertical = true && _horizontal = true){
        cout << 'X';
        _cible = true;
        
    }
    else
        cout << 'O';
    Plateau.AfficherGrille();
}

void Plateau::Jouer() {

    void Plateau::Jouer() {
        Bateau::ETATS_BATEAU Torpiller;
        bool sortie = false;
        char vertical;
        int horizontal;
        if (laFlotte.ObtenirNbBateaux() != 0) {
            cout << "Entrer les coordonnées de la torpille : ";
            do {
                cin >> vertical >> horizontal;
                Torpiller = laFlotte.TirerSurLaFlotte(vertical, horizontal);
                switch (Torpiller) {
                    case Bateau::TOUCHE:
                        Tirer(vertical, horizontal, true);
                        cout << "Rejouer : ";
                        break;
                    case Bateau::COULE:
                        Tirer(vertical, horizontal, true);
                        cout << "Bateau coulé... ";
                        if (laFlotte.VerifierEtatDeLaFlotte() != Bateau::COULE)
                            cout << "rejouer : ";
                        else
                            sortie = true;
                        break;
                    case Bateau::MANQUE:
                        Tirer(vertical, horizontal, false);
                        cout << "Rejouer : ";
                        break;
                }
            } while (sortie == false);
        }
        cout << "fin de la partie !" << endl;
    }
}