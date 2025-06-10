/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: LatitudeE6540
 *
 * Created on 3 février 2024, 13:23
 */

#include <cstdlib>

#include "plateau.h"
#include "jeu2048.h"

using namespace std;

Plateau lePlateau;

/*
 * 
 */
int main(int argc, char** argv) {
    lePlateau.Afficher();
    while (!lePlateau.JouerCoup()) {
       
    }
    return 0;
}
