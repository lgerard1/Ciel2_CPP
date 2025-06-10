/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   batailleNavale.cpp
 * Author: lgerard
 *
 * Created on 13 février 2024, 16:26
 */

#include <cstdlib>
#include "plateau.h"


using namespace std;

/*
 * 
 */

int main() {
    Plateau lePlateau("LaFlotte2.txt");
    lePlateau.AfficherGrille();
    return 0;
}

