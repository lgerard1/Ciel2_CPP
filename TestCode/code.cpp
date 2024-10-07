#include "code.h"

Code::Code(const int _tailleCode):
    tailleCode(_tailleCode)
{

    codeUsine= new quint8[tailleCode];
    codeUtilisateur = new quint8[tailleCode];

    for (int i = 0; i < tailleCode; ++i) {
        codeUsine[i] = i + 1;
        codeUtilisateur[i] = 0;
    }
}

Code::~Code()
{
    delete codeUsine;
    delete codeUtilisateur;
}

bool Code::VerifierCode(quint8 *unCode)
{
    int cpt1 = 0;
    int cpt2 = 0;
    for (int i = 0; i < tailleCode; ++i) {
        if (unCode[i] == codeUsine[i]) {
            cpt1++;
        }
        if (unCode[i] == codeUtilisateur[i]) {
            cpt2++;
        }

    }
    if (cpt1 == tailleCode || cpt2 == tailleCode) {
        cout << "Le code est bon" << endl;
        return true;

    }
    else {
        cout << "Le code est faux" << endl;
        return false;

    }


}

void Code::Memoriser(const quint8 *unCode)
{
    for (int i = 0; i < tailleCode; ++i) {
        codeUtilisateur[i] = unCode[i];
    }
}


