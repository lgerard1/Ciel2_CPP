/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: LatitudeE6540
 *
 * Created on 10 février 2024, 13:42
 */
#include "menu.h"
#include "joueurs.h"
#include "gestionJoueurs.h"
#include <iostream>
#include <fstream>

int main() {
    Menu leMenu("menu.txt");
    int choix;
    const int NB_MAX_JOUEURS = 100;
    Joueur tabJoueurs[NB_MAX_JOUEURS];
    int nbJoueurs = 0;
    string pseudo;
    int score, duree;

    do {
        choix = leMenu.AfficherEtAttendreChoix();
        switch (choix) {
            case AJOUTER: {
                cout << "Pseudo score duree :";
                cin >> pseudo >> score >> duree;
                int index = RechercherJoueur(tabJoueurs, nbJoueurs, pseudo);
                if (index != -1) {
                    tabJoueurs[index].Actualiser(score, duree);
                } else {
                    tabJoueurs[nbJoueurs++] = Joueur(pseudo, score, duree);
                    if (nbJoueurs >= 2) {
                        TrierTableauJoueurs(tabJoueurs, nbJoueurs);
                    }
                }
                Menu::EffacerEcran();
                break;
            }
            case VISUALISER: {
                if (nbJoueurs == 0) {
                    cout << "Aucun joueur à afficher." << endl;
                } else {
                    // Afficher les joueurs
                    for (int i = 0; i < nbJoueurs; ++i) {
                        string pseudo;
                        int score, duree;
                        tabJoueurs[i].ObtenirInfo(pseudo, score, duree);
                        cout << pseudo << " - Score : " << score << " - Durée : " << duree << endl;
                    }
                }
                break;
            }
            case CHARGER: {
                // Charger les joueurs depuis le fichier
                ifstream fichier("joueurs.txt");
                if (fichier.is_open()) {
                    fichier >> nbJoueurs;
                    for (int i = 0; i < nbJoueurs; ++i) {
                        fichier >> tabJoueurs[i];
                    }
                    fichier.close();
                } else {
                    cerr << "Impossible d'ouvrir le fichier pour chargement." << endl;
                }
                break;
            }
            case SAUVEGARDER: {
                // Sauvegarder les joueurs dans le fichier
                ofstream fichier("joueurs.txt");
                if (fichier.is_open()) {
                    fichier << nbJoueurs << endl;
                    for (int i = 0; i < nbJoueurs; ++i) {
                        fichier << tabJoueurs[i];
                    }
                    fichier.close();
                } else {
                    cerr << "Impossible d'ouvrir le fichier pour sauvegarde." << endl;
                }
                break;
            }
            case QUITTER: {
                cout << "Programme terminé." << endl;
                break;
            }
            default: {
                cout << "Choix invalide. Veuillez entrer un nombre entre 1 et 5." << endl;
                break;
            }
        }
    } while (choix != QUITTER);

    return 0;
}
