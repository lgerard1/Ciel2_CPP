/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Joueurs.h
 * Author: LatitudeE6540
 *
 * Created on 10 février 2024, 13:43
 */

#ifndef JOUEURS_H
#define JOUEURS_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <math.h>
#include <time.h>
using namespace std;


class Joueur {


public:
    // Constructeurs
    Joueur();
    Joueur(const string& pseudo, int score = 0, int duree = 0);

    // Méthodes
    void Actualiser(int newScore, int newDuree);
    void ObtenirInfo(string& pseudo, int& score, int& duree) const;

    // Surcharge d'opérateurs
    bool operator<(const Joueur& autre) const;
    bool operator!=(const string& autrePseudo) const;
    friend ostream& operator<<(ostream& os, const Joueur& joueur);
    friend istream& operator>>(istream& is, Joueur& joueur);

private:
    string pseudo;
    int score;
    int duree;
};

#endif // JOUEUR_H


