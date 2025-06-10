/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Joueurs.cpp
 * Author: LatitudeE6540
 * 
 * Created on 10 février 2024, 13:43
 */

#include "joueurs.h"

Joueur::Joueur() : pseudo(""), score(0), duree(0) {
}

Joueur::Joueur(const string& pseudo, int score, int duree)
: pseudo(pseudo), score(score), duree(duree) {
}

void Joueur::Actualiser(int newScore, int newDuree) {
    if (newScore > score)
        score = newScore;
    duree += newDuree;
}

void Joueur::ObtenirInfo(string& pseudo, int& score, int& duree) const {
    pseudo = this->pseudo;
    score = this->score;
    duree = this->duree;
}

bool Joueur::operator<(const Joueur& autre) const {
    return score < autre.score;
}

bool Joueur::operator!=(const string& autrePseudo) const {
    return pseudo != autrePseudo;
}

ostream& operator<<(ostream& os, const Joueur& joueur) {
    os << joueur.pseudo << " " << joueur.score << " " << joueur.duree << endl;
    return os;
}

istream& operator>>(istream& is, Joueur& joueur) {
    is >> joueur.pseudo >> joueur.score >> joueur.duree;
    return is;
}
