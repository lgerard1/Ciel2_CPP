/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Plateau.h
 * Author: lgerard
 *
 * Created on 13 février 2024, 15:57
 */

#ifndef PLATEAU_H
#define PLATEAU_H
#include "bateau.h"
#include "flotte.h"


class Plateau : public Flotte{
public:
    Plateau(const string _nomDuFichier);
    void AfficherGrille();
    void Tirer(const char _vertical, const int _horizontal, const bool _cible);
    void Jouer();
private:

    char grille[10][10];
};

#endif /* PLATEAU_H */

