/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Bateau.h
 * Author: lgerard
 *
 * Created on 13 février 2024, 15:04
 */

#ifndef BATEAU_H
#define BATEAU_H
#include <string>

using namespace std;

class Bateau {
public:
    enum ETATS_BATEAU{
        MANQUE,
        TOUCHE,
        COULE
    };
    
    Bateau(const string _nom, const char _vertical = 'V', const int _horizontal = 'H', const int _taille, const char _sens = 'H');
    ETATS_BATEAU Torpiller(const char _vertical, const int _horizontal);
    ETATS_BATEAU ObtenirEtatBateau();
    string ObtenirNom();
    ~Bateau();
private:
    string nom;
    char vertical;
    int horizontal;
    int taille;
    char sens;
    int *coque;
};

#endif /* BATEAU_H */

