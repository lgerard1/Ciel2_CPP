#include <iostream>
#include <menu.h>
#include <comptebancaire.h>

using namespace std;

int main()
{
    int choix;
    float montant;
    float retrait;
    Menu menuCB("../LaBanque/compteBancaire.txt");
    CompteBancaire compte;

    do{
        choix = menuCB.Afficher();
        switch (choix)
        {
        case OPTION_1:
            cout << "Consulter le Solde" << endl;
            cout << compte.ConsulterSolde() << endl;
            Menu::AttendreAppuiTouche();
            break;
        case OPTION_2:
            cout << "Effectuer un dépot, quelle est le montant ?" << endl;
            cin >> montant;
            compte.Deposer(montant);
            Menu::AttendreAppuiTouche();
            break;
        case OPTION_3:
            cout << "Effectuer un retrait, quelle est le montant ?" << endl;
            cin >> retrait;
            if(compte.Retirer(retrait) == true){

                compte.Retirer(retrait);
            }
            else{
                cout << "Solde insuffisant" << endl;
            }
            Menu::AttendreAppuiTouche();
            break;
        default:
            cout << "Retour" << endl;
            Menu::AttendreAppuiTouche();
            break;
        }
    }
    while (choix != QUITTER);



    return 0;
}
