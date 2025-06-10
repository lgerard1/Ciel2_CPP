/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: lgerard
 *
 * Created on 30 janvier 2024, 09:13
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    string nomDuFichier;
    cout << "Entrer le nom du fichier à lire : ";
    cin >> nomDuFichier;
    
    ifstream leFichier(nomDuFichier.c_str()); // c_str() transforme string en char*
    ofstream monFichier("fichier.txt");
    if (!leFichier.is_open())
        cerr << "Erreur lors de l'ouverture du fichier" << endl;
    if (!monFichier.is_open())
        cerr << "Erreur lors de l'ouverture du fichier" << endl;
    else {
        string pays;
        int nbOr;
        int nbArgent;
        int nbBronze;
        monFichier << "+" << setfill('-') << setw(17) << "+" << setfill('-') << setw(8) << "+" << setfill('-') << setw(8) << "+" << setfill('-') << setw(8) << "+" << endl;// A compléter, affichage de la première ligne du tableau
        do {
            //récupération des valeurs
            leFichier >> pays >> nbOr >> nbArgent >> nbBronze;
            if (leFichier.good())//Si les valeurs ont bien été lues
            {
                monFichier << "|" << setfill(' ') << setw(16) << left << pays << "|" << setfill(' ') << setw(7) << right << nbOr << "|" << setfill(' ') << setw(6) << nbArgent << " " << "|" << setfill(' ') << setw(6) << nbBronze << " " << "|" << endl;// A compléter, affichage de chaque ligne du tableau
            }
        } while (!leFichier.eof());
        monFichier << "+" << setfill('-') << setw(17) << "+" << setfill('-') << setw(8) << "+" << setfill('-') << setw(8) << "+" << setfill('-') << setw(8) << "+" << endl; // A compléter, affichage de la dernière ligne du tableau.
        monFichier.close();
    }
    return 0;
}

