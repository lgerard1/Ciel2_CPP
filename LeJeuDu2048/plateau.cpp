/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Plateau.cpp
 * Author: LatitudeE6540
 * 
 * Created on 3 février 2024, 13:23
 */

#include "plateau.h"

Plateau::Plateau() : 
score(0),
nbCoups(0) {
}

void Plateau::Afficher() {
    int laGrille[TAILLE][TAILLE];
    leJeu2048.ObtenirGrille(laGrille);

    system("cls");

    cout << "| Score : " << score << " | Nombre de coups : " << nbCoups << " |" << endl;
    cout << endl;

    for (int ligne = 0; ligne < TAILLE; ligne++) {
        cout << " +";
        for (int indice = 0; indice < TAILLE; indice++)
            cout << setw(8) << setfill('-') << '+';
        cout << endl;
        cout << " ";
        for (int indice = 0; indice < TAILLE; indice++) {
            cout << "|";
            cout << setfill(' ') << setw(7);

            if (laGrille[ligne][indice] != 0)
                cout << laGrille[ligne][indice];
            else
                cout << " ";
        }
        cout << "|" << endl;
    }

    cout << " +";
    for (int indice = 0; indice < TAILLE; indice++)
        cout << setw(8) << setfill('-') << '+';
    cout << endl;

    cout << endl;
    cout << "F pour sortir du jeu" << endl;
    cout << "Votre deplacement : H (^), B (v), G (<-), D (->) : " << endl;
}


bool Plateau::JouerCoup() {
    bool retour = false;
    char touche;
    bool calculEffectue;
    cin >> touche;
    touche = toupper(touche);
    if (strchr("BHGD", touche) != nullptr) {
        nbCoups++;
        leJeu2048.Deplacer(touche);
        calculEffectue = leJeu2048.Calculer(touche);
        if (calculEffectue) {
            leJeu2048.Deplacer(touche);
        }
        leJeu2048.PlacerUneNouvelleTuile();
        Afficher();
        score += leJeu2048.CalculerScore();

        Jeu2048::ETATS_DU_JEU etatPartie = leJeu2048.RechercherFinDePartie();
        if (etatPartie == Jeu2048::GAGNE) {
            cout << "Félicitations ! Vous avez gagné !" << endl;
            retour = true; 
        } else if (etatPartie == Jeu2048::PERDU) {
            cout << "Désolé, vous avez perdu la partie. Réessayez !" << endl;
            retour = true; 
        }
    }
    if (touche == 'F')
        retour = true;

    return retour;
}

