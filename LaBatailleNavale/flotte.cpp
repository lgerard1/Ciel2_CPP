/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Flotte.cpp
 * Author: lgerard
 * 
 * Created on 13 février 2024, 15:32
 */

#include "flotte.h"

Flotte::Flotte(const string _nomDuFichier) :
nbBateaux(0) {
    ifstream fichier(_nomDuFichier);
    int indice = 0;
    if (!fichier.is_open()) {
        cout << "Erreur lors de l'ouverture du fichier " << endl;
    } else {
        string nom;
        string position;
        int taille;
        char sens;
        char lettre;
        int chiffre;
        do {
            fichier >> nom >> position >> taille >> sens;
            if (fichier.good() && indice < NB_BATEAUX_MAX) {
                lettre = position.front();
                stringstream ss(position.substr(1));
                ss >> chiffre;
                lesBateaux[indice++] = new Bateau(nom, lettre, chiffre, taille, sens);
            }
        } while (!fichier.eof() && indice < NB_BATEAUX_MAX);
        nbBateaux = indice;
    }
    while (indice < NB_BATEAUX_MAX) {
        lesBateaux[indice++] = nullptr;
    }
}



Flotte::~Flotte() {
    int indice;
    if (lesBateaux[indice++] != nullptr){
         delete lesBateaux[indice++];
    }
       
}

Bateau::ETATS_BATEAU TirerSurLaFlotte(const char _vertical, const int _horizontal){
    
}

Bateau::ETATS_BATEAU VerifierEtatDeLaFlotte()
{
    int i;
    int indice;
    for(i = 0; i < 10; i++){
        for(indice = 0; indice < 10; indice++){
            if(){
                Bateau::TOUCHE;
            }
            if(){
                Bateau::MANQUE;
            }
            else{
                Bateau::COULE;
            }
        }
    }
}