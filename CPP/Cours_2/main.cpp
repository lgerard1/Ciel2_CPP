/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: lgerard
 *
 * Created on 30 janvier 2024, 09:00
 */

#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    string motCle;
    
    int valeur;
    ifstream fichier("config.txt");
    if (!fichier.is_open())
        cerr << "Erreur lors de l'ouverture du fichier" << endl;
    else {
        do {
            
            fichier >> motCle >> valeur;
            if (fichier.good())
            {
                cout << motCle << " " << valeur << endl;
            }
        } while (!fichier.eof());
    }
    return 0;
}



