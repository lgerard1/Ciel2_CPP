#include "compteclient.h"
#include "menu.h"


/**
 * @brief CompteClient::CompteClient
 * @param _nom
 * @param _numero
 * @details Constructeur de la classe CompteClient
 */
CompteClient::CompteClient(const string _nom, const int _numero):
    nom(_nom),
    numero(_numero)
{
    Epargne = nullptr;
    Bancaire = new CompteBancaire(0);
}
/**
 * @brief CompteClient::~CompteClient
 * @details Destructeur de la classe CompteClient
 */

CompteClient::~CompteClient()
{
    delete Bancaire;
    if (Epargne != nullptr) {
        delete Epargne;
    }
}

/**
 * @brief CompteClient::OuvrirCompteEpargne
 * @details Méthode permettant d'ouvrir un compte épargne
 */

void CompteClient::OuvrirCompteEpargne()
{
    float soldeDepart;
    float taux;
    if (Epargne != nullptr) {
        cout << "Vous avez déjà un compte épargne" << endl;
    }
    else{
        cout << "Quel est le montant que vous voulez mettre sur le compte ?" << endl;
        cin >> soldeDepart;
        cout << "Quel est le taux d'interêt ?" << endl;
        cin >> taux;
        Epargne = new CompteEpargne(taux, soldeDepart);
    }
}

/**
 * @brief CompteClient::GererCompteBancaire
 * @details Méthode permettant de gérer un compte bancaire déjà existant
 */

void CompteClient::GererCompteBancaire()
{
    Menu menuCB("../LaBanque/compteBancaire.txt");
    float solde;
    int choix;
    float depot;
    float retrait;
    bool possibilite;
    bool sortie = 0;
    while (sortie == 0) {
        choix = menuCB.Afficher();
        switch (choix) {
        case 1:
            solde = Bancaire->ConsulterSolde();
            cout << "Vous avez "<< solde<< "€ sur votre compte"<<endl;
            break;
        case 2:
            cout<< "Vous voulez déposez combien?" << endl;
            cin>> depot;
            Bancaire->Deposer(depot);
            cout << "Vous avez déposé " << depot<<"€"<<endl;
            break;
        case 3:
            cout<< "Vous voulez retirer combien?" << endl;
            cin>> retrait;
            possibilite = Bancaire->Retirer(retrait);
            if (possibilite == 1) {
                cout << "Vous avez retirer " << retrait<<"€"<<endl;
            }else{
                cout << "Vous n'avez pas pus retirer, solde insufisant " <<endl;
            }


            break;
        case 4:
            sortie = 1;
            break;
        }
        Menu::AttendreAppuiTouche();
    }
}

/**
 * @brief CompteClient::GererCompteEpargne
 * @details Méthode permettant de gérer le compte epargne déjà existant
 */

void CompteClient::GererCompteEpargne()
{
    int choix;
    float montant;
    float retrait;
    Menu menuCB("../LaBanque/compteEpargne.txt");
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

                epargne.ConsulterSolde();
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

}
