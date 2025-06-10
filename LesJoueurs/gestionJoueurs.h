/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GestionJoueurs.h
 * Author: LatitudeE6540
 *
 * Created on 10 février 2024, 13:48
 */
#ifndef GESTION_JOUEURS_H
#define GESTION_JOUEURS_H

#include "joueurs.h"
#include <string>

int RechercherJoueur(Joueur* _tab, const int _nb, const string& _pseudo);
void TrierTableauJoueurs(Joueur* _tab, const int _nb);

#endif // GESTION_JOUEURS_H
