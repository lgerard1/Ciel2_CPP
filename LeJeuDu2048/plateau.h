/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Plateau.h
 * Author: LatitudeE6540
 *
 * Created on 3 février 2024, 13:23
 */

#ifndef PLATEAU_H
#define PLATEAU_H
#include "jeu2048.h"

using namespace std;



class Plateau{
public:
	Plateau();
	void Afficher();
	bool JouerCoup();
    
private:
	int nbCoups;
	int score;
        Jeu2048 leJeu2048;
};


#endif /* PLATEAU_H */

