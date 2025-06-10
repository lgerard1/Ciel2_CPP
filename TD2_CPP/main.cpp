/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: lgerard
 *
 * Created on 30 janvier 2024, 15:33
 */


#include "menu.h"
#include <iostream>
#include <cstdlib>


        using namespace std;

/*
 * 
 */
int main()
{
    int choix;
    Menu leMenu("menu.txt");

    do
    {
        choix = leMenu.Afficher();
        switch (choix)
        {
        case OPTION_1:
            cout << "Vous avez choisi l'option n°1" << endl;
            Menu::AttendreAppuiTouche();
            break;
        case OPTION_2:
            cout << "Vous avez choisi l'option n°2" << endl;
            Menu::AttendreAppuiTouche();
            break;
        case OPTION_3:
            cout << "Vous avez choisi l'option n°3" << endl;
            Menu::AttendreAppuiTouche();
            break;
        case OPTION_4:
            cout << "Vous avez choisi l'option n°4" << endl;
            Menu::AttendreAppuiTouche();
            break;
        default:
            cout << "Le choix n'est pas valide" << endl;
            Menu::AttendreAppuiTouche();
            break;
        }
    }
    while (choix != QUITTER);
    return 0;
}
