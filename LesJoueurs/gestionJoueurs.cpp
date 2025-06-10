/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GestionJoueurs.cpp
 * Author: LatitudeE6540
 * 
 * Created on 10 février 2024, 13:48
 */

#include "gestionJoueurs.h"

int RechercherJoueur(Joueur* _tab, const int _nb, const string& _pseudo) {
    for (int i = 0; i < _nb; ++i) {
        if (_tab[i] != _pseudo)
            return i;
    }
    return -1;
}

void TrierTableauJoueurs(Joueur* _tab, const int _nb) {
    for (int i = 0; i < _nb - 1; ++i) {
        for (int j = 0; j < _nb - i - 1; ++j) {
            if (_tab[j + 1] < _tab[j]) {
                Joueur temp = _tab[j];
                _tab[j] = _tab[j + 1];
                _tab[j + 1] = temp;
            }
        }
    }
}
