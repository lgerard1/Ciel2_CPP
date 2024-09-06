#include <iostream>
#include "barre.h"
#include "barreronde.h"
#include "barrerectangle.h"
#include "barrecarre.h"

using namespace std;

int main()
{
    Barre laBarre("B154", 200, 8.73, "Laiton");
    BarreRonde uneBarre("B154", 320, 8.73, "Laiton", 15);
    BarreRectangle barreRectangle("B154", 320, 8.73, "Laiton", 30);
    BarreCarre barreCarre("B154", 200, 8.73, "Laiton");
    laBarre.AfficherCaractéristiques();
    uneBarre.AfficherCaractéristiques();
    barreRectangle.AfficherCaractéristiques();
    barreCarre.AfficherCaractéristiques();

    return 0;
}
