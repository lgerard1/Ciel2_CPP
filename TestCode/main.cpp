#include <iostream>
#include <QtGlobal>
#include "code.h"

using namespace std;

#define TAILLE_CODE 4

int main(int argc, char *argv[])
{
    quint8 leCode[TAILLE_CODE];
    cout << "Saisissez Votre Code : " << endl;
    cin >> leCode[0] >> leCode[1] >> leCode[2] >> leCode[3];
    Code *unCode = new Code(TAILLE_CODE);
    for (int i = 0; i < TAILLE_CODE; ++i) {
        leCode[i] -= '0';
    }

    unCode->Memoriser(leCode);
    cout << "Saisissez Votre Code : " << endl;
    cin >> leCode[0] >> leCode[1] >> leCode[2] >> leCode[3];
    for (int i = 0; i < TAILLE_CODE; ++i) {
        leCode[i] -= '0';
    }
    unCode->VerifierCode(leCode);
    return 0;
}
