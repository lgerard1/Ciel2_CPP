#include <iostream>
#include <menu.h>
#include <comptebancaire.h>
#include "compteepargne.h"

using namespace std;

int main()
{
    int choix;
    float montant;
    float retrait;
    Menu menuCB("../LaBanque/compteBancaire.txt");
    CompteBancaire compte;
    CompteEpargne epargne;

    do{
        choix = menuCB.Afficher();
        switch (choix)
        {
        case 1:
            cout << "Votre solde est de : " << endl;
            cout << epargne.ConsulterSolde() << endl;

            break;
        case 2:
            cout << "Effectuer un dépot, quelle est le montant ?" << endl;
            cin >> montant;
            epargne.Deposer(montant);

            break;
        case 3:
            cout << "Effectuer un retrait, quelle est le montant ?" << endl;
            cin >> retrait;
            if(epargne.Retirer(retrait) == true){

                epargne.Retirer(retrait);
            }
            else{
                cout << "Solde insuffisant" << endl;
            }

            break;
        case 4:
            epargne.CalculerTauxInteret();
        }
    }
    while (choix != 5);




    return 0;
}
