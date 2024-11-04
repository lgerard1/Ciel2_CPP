#include "chariot.h"

Chariot::Chariot(QObject *parent)
    : QObject{parent}
{}

void Chariot::DeplacerChariot(const int _rangee, const int _colonne, const bool _sens)
{
    if(_sens){
        QMessageBox::information(nullptr, "Rouleau déposé", QString("Le rouleau a été déposé dans l'alvéole [%1, %2]").arg(_rangee).arg(_colonne));
    }
    else {
        QMessageBox::information(nullptr, "Rouleau retiré", QString("Le rouleau a été retiré de l'alvéole [%1, %2]").arg(_rangee).arg(_colonne));
    }
}
