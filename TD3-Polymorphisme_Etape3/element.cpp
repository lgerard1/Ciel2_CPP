#include "element.h"

Element::Element(const int _vitesse) :
    numero(0),
    vitesse(_vitesse)
{}

Element::~Element()
{

}

double Element::getNumero() const
{
    return numero;
}

void Element::setNumero(const double _numero)
{
    numero = _numero;
}

