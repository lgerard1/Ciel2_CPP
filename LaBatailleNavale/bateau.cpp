/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Bateau.cpp
 * Author: lgerard
 * 
 * Created on 13 février 2024, 15:04
 */

#include "bateau.h"

Bateau::Bateau(const string _nom, const char _vertical, const int _horizontal, const int _taille, const char _sens):
taille(_taille),
vertical(_vertical),
sens(_sens),
horizontal(_horizontal)        
{
    int i;
    int indice;
    int etatBateau = MANQUE;
    coque[taille];
    for(i = 0; i < taille; i++){
        for(indice = 0; indice < taille; indice++){
            coque[taille] = 0;
        }
    }
    
    
    
}
Bateau::ETATS_BATEAU Torpiller(const char _vertical, const int _horizontal){
    if(sens = 'H'){
        
    }
}

Bateau::~Bateau() {
  delete [] coque; //le destructeur nous permet d'effacer le tableau
}

