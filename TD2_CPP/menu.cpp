/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Menu.cpp
 * Author: lgerard
 * 
 * Created on 30 janvier 2024, 15:36
 */

#include "menu.h"


Menu::Menu(const string &_nom) : nom(_nom), longueurMax(0)
{
    string option;
    string nomDuFichier;
    cout << "Entrer le nom du fichier à lire : ";
    cin >> nomDuFichier;
    ifstream leFichier(nomDuFichier.c_str());
    if (!leFichier.is_open())
    {
        cerr << "Erreur lors de l'ouverture du fichier" << endl;
        nbOptions = 0;
    }
    else
    {
        int nbLignes;
        nbLignes = static_cast<int> (count(istreambuf_iterator<char>(leFichier), istreambuf_iterator<char>(), '\n'));
        leFichier.seekg(0, ios::beg);
        nbOptions = nbLignes;
        options = new string[nbLignes];
        int i;
        for (i = 0; i < nbLignes; i++)
        {
            getline(leFichier,option);
            if (leFichier.good())
            {
                options[i] = option;
                if (option.length() > longueurMax)
                {
                    longueurMax = option.length();
                }
            }
        }
    }
}

int Menu::Afficher()
{
    int i;
    int choix;
    cout << "+" << setfill('-') << setw(6) << "+" << setfill('-') << setw(11) << "+" << endl;
    for (i = 0; i < nbOptions; i++)
    {
        int num = i + 1;

        cout << "|" << setfill(' ') << setw(5) << num << "|" << setw(10) <<  options[i] << setfill(' ') << "|" << endl;
    }
    cout << "+" << setfill('-') << setw(6) << "+" << setfill('-') << setw(11) << "+" << endl;
    cout << endl << endl;
    cout << "Entrez un nombre entre 1 et 5 : " << endl;

    if (!(cin >> choix))
    {
        cin.clear();
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        choix = -1;
    }
    return choix;
}

void Menu::AttendreAppuiTouche()
{
    string uneChaine;

    cout << endl << "appuyer sur la touche Entrée pour continuer...";
    getline(cin, uneChaine);
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    system("clear");
}

Menu::~Menu()
{
    delete [] options;
}

