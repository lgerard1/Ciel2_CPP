/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Jeu2048.h
 * Author: LatitudeE6540
 *
 * Created on 3 février 2024, 13:24
 */

#ifndef JEU2048_H
#define JEU2048_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <math.h>
#include <time.h>
#define TAILLE 4


using namespace std;

class Jeu2048 {
public:
	enum ETATS_DU_JEU{
    	EN_COURS,
    	PERDU,
    	GAGNE
	};
    
	Jeu2048();
	void PlacerUneNouvelleTuile();
	bool Calculer(const char _direction);
	int CalculerScore();
        void Deplacer(char _direction); 
	void ObtenirGrille(int _grille[][TAILLE]);
	ETATS_DU_JEU RechercherFinDePartie();
   
private:
	int grille[TAILLE][TAILLE];
};


#endif /* JEU2048_H */

