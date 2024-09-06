#include <iostream>
#include <menu.h>
#include <comptebancaire.h>
#include "compteepargne.h"
#include "compteclient.h"

using namespace std;

int main()
{
    int choix;
    Menu menuEpargne("../LaBanque/client.txt");
    CompteClient leCompte("ALbert", 1);
    do{
        choix = menuEpargne.Afficher();
        switch (choix)
        {
        case 1:
            leCompte.OuvrirCompteEpargne();
            break;

        case 2:
            leCompte.GererCompteBancaire();

            break;
        case 3:
            leCompte.GererCompteEpargne();
            break;
        }
    }while (choix != 4);

    return 0;
}
