/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Flotte.h
 * Author: lgerard
 *
 * Created on 13 février 2024, 15:32
 */

#ifndef FLOTTE_H
#define FLOTTE_H

#include "bateau.h"
#include <fstream>
#include <sstream>
#include <iostream>

//la relation entre la classe flotte et la classe bateau se nomme la relation de composition, 
//et le 5 à l'extrémité de la fleche définis le nombre d'instances liées entre ses 2 classes

using namespace std;

class Flotte {
public:
    Flotte(const string _nomDuFichier);
    ~Flotte();
    Bateau::ETATS_BATEAU TirerSurLaFlotte(const char _vertical, const int _horizontal);
    Bateau::ETATS_BATEAU VerifierEtatDeLaFlotte();
    int ObtenirNbBateaux() const;
private:
    static const int NB_BATEAUX_MAX = 5;
    int nbBateaux;
    Bateau *lesBateaux[NB_BATEAUX_MAX];
};

#endif /* FLOTTE_H */

