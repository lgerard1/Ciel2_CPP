#include <iostream>
#include "element.h"
#include "trajectoire.h"
#include "segment.h"
#include "arc.h"

using namespace std;

int main()
{
    Vecteur positionInitial(5, 10);
    Trajectoire laTrajectoire(5, positionInitial);
    laTrajectoire.Ajouter(new Segment(9,0,3));
    laTrajectoire.Ajouter(new Segment(5,0.927, 1));
    laTrajectoire.Ajouter(new Segment(6,1.5708, 2));
    laTrajectoire.Ajouter(new Pause(4));
    laTrajectoire.Ajouter(new Arc(5, 3.14159, 0, 6));

    laTrajectoire.Afficher();

    return 0;
}
