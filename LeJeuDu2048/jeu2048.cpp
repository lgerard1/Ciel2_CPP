/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Jeu2048.cpp
 * Author: LatitudeE6540
 * 
 * Created on 3 février 2024, 13:24
 */

#include "jeu2048.h"

Jeu2048::Jeu2048() {

    int i;
    int indice;
    for (i = 0; i < TAILLE; i++) {
        for (indice = 0; indice < TAILLE; indice++) {
            grille[i][indice] = 0;
        }
    }
    PlacerUneNouvelleTuile();
}

void Jeu2048::ObtenirGrille(int _grille[][TAILLE]) {
    int i;
    int indice;
    for (i = 0; i < TAILLE; i++) {
        for (indice = 0; indice < TAILLE; indice++) {
            _grille[i][indice] = grille[i][indice];
        }
    }
}

void Jeu2048::PlacerUneNouvelleTuile() {
    srand(time(nullptr));
    int ligne, colonne;
    do {
        ligne = rand() % TAILLE;
        colonne = rand() % TAILLE;
    } while (grille[ligne][colonne] != 0);

    grille[ligne][colonne] = (rand() % 2 == 0) ? 2 : 4;
}
void Jeu2048::Deplacer(char _direction) {
    int ligne;
    int colonne;
    for (int indice = 0; indice < 4; indice++) {
        switch (_direction) {
            case 'G': 
                for (ligne = 0; ligne < TAILLE; ligne++) {
                    for (colonne = 0; colonne < TAILLE - 1; colonne++) {
                        if (grille[ligne][colonne] == 0) {
                            grille[ligne][colonne] = grille[ligne][colonne + 1];
                            grille[ligne][colonne + 1] = 0;
                        }
                    }
                }
                break;
            case 'D': 
                for (ligne = 0; ligne < TAILLE; ligne++) {
                    for (colonne = TAILLE - 1; colonne > 0; colonne--) {
                        if (grille[ligne][colonne] == 0) {
                            grille[ligne][colonne] = grille[ligne][colonne - 1];
                            grille[ligne][colonne - 1] = 0;
                        }
                    }
                }
                break;
            case 'B':
                for (colonne = 0; colonne < TAILLE; colonne++) {
                    for (ligne = TAILLE - 1; ligne > 0; ligne--) {
                        if (grille[ligne][colonne] == 0) {
                            grille[ligne][colonne] = grille[ligne - 1][colonne];
                            grille[ligne - 1][colonne] = 0;
                        }
                    }
                }
                break;
            case 'H': 
                for (colonne = 0; colonne < TAILLE; colonne++) {
                    for (ligne = 0; ligne < TAILLE - 1; ligne++) {
                        if (grille[ligne][colonne] == 0) {
                            grille[ligne][colonne] = grille[ligne + 1][colonne];
                            grille[ligne + 1][colonne] = 0;
                        }
                    }
                }
                break;
        }
    }
}

bool Jeu2048::Calculer(const char _direction) {
    bool calculEffectue = false;
    int ligne, colonne;

    switch (_direction) {
        case 'G': // Gauche
            for (ligne = 0; ligne < 4; ligne++) {
                for (colonne = 0; colonne < 3; colonne++) {
                    if (grille[ligne][colonne] == grille[ligne][colonne + 1] && grille[ligne][colonne] != 0) {
                        grille[ligne][colonne] += grille[ligne][colonne + 1];
                        grille[ligne][colonne + 1] = 0;
                        calculEffectue = true;
                    }
                }
            }
            break;
        case 'D': // Droite
            for (ligne = 0; ligne < 4; ligne++) {
                for (colonne = 3; colonne > 0; colonne--) {
                    if (grille[ligne][colonne] == grille[ligne][colonne - 1] && grille[ligne][colonne] != 0) {
                        grille[ligne][colonne] += grille[ligne][colonne - 1];
                        grille[ligne][colonne - 1] = 0;
                        calculEffectue = true;
                    }
                }
            }
            break;
        case 'B': // Bas
            for (colonne = 0; colonne < 4; colonne++) {
                for (ligne = 3; ligne > 0; ligne--) {
                    if (grille[ligne][colonne] == grille[ligne - 1][colonne] && grille[ligne][colonne] != 0) {
                        grille[ligne][colonne] += grille[ligne - 1][colonne];
                        grille[ligne - 1][colonne] = 0;
                        calculEffectue = true;
                    }
                }
            }
            break;
        case 'H': // Haut
            for (colonne = 0; colonne < 4; colonne++) {
                for (ligne = 0; ligne < 3; ligne++) {
                    if (grille[ligne][colonne] == grille[ligne + 1][colonne] && grille[ligne][colonne] != 0) {
                        grille[ligne][colonne] += grille[ligne + 1][colonne];
                        grille[ligne + 1][colonne] = 0;
                        calculEffectue = true;
                    }
                }
            }
            break;
    }

    return calculEffectue;
}
int Jeu2048::CalculerScore() {
    int score = 0;
    for (int ligne = 0; ligne < 4; ligne++) {
        for (int colonne = 0; colonne < 4; colonne++) {
            score += grille[ligne][colonne];
        }
    }
    return score;
}
#include "Jeu2048.h"

Jeu2048::ETATS_DU_JEU Jeu2048::RechercherFinDePartie() {
    for (int ligne = 0; ligne < TAILLE; ligne++) {
        for (int colonne = 0; colonne < TAILLE; colonne++) {
            if (grille[ligne][colonne] == 2048) {
                return GAGNE;
            }
        }
    }
    
    for (int ligne = 0; ligne < TAILLE; ligne++) {
        for (int colonne = 0; colonne < TAILLE; colonne++) {
            if (grille[ligne][colonne] == 0) {
                return EN_COURS; 
            }
            
            if ((ligne < TAILLE - 1 && grille[ligne][colonne] == grille[ligne + 1][colonne]) ||
                (colonne < TAILLE - 1 && grille[ligne][colonne] == grille[ligne][colonne + 1])) {
                return EN_COURS; 
            }
        }
    }

    
    return PERDU;
}
