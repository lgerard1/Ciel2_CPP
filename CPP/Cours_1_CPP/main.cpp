/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: lgerard
 *
 * Created on 30 janvier 2024, 08:35
 */

#include <iostream>
#include <iomanip>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    int val = 192;
    float val2 = 3.141592654;
    bool sortie = true;
    
    cout <<"Affichage par défaut : " << val << endl;
    cout <<"Affichage en Héxadécimal : " << hex << val << endl;
    cout <<"Affichage en décimal :" << dec << val << endl;
    cout << hex << val << " " << uppercase << " " << val << " ";
    cout << showbase << val << nouppercase << " " << val << endl;
    cout << endl;
    
    cout << "+" << setfill('-') << setw(21) << "+" << setfill(' ') << endl;
    cout << "|" << setw(20) << left << "abc" << "|" << endl;
    cout << "|" << setw(20) << right << "abc" << "|" << endl;
    cout << "+" << setfill('-') << setw(21) << "+" << setfill(' ') << endl;
    cout << endl;
    
    cout << dec << sortie << " " << boolalpha << sortie << endl;
    cout << val2 << " " << fixed << val2 << " " << scientific << val2 << " ";
    cout <<  fixed << setprecision(2) << val2 << endl ;
    cout << "Entrez un nombre en octal : ";
    cin >> oct >> val;
    cout << "vous avez saisie " << dec << val << " en décimal" << endl;
    
    return 0;
}

