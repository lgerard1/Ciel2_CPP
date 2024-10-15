#ifndef MAGASIN_H
#define MAGASIN_H

#include <QWidget>
#include "rouleau.h"
#include "alveoleslibres.h"
#include "chariot.h"
#include "stock.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Magasin;
}
QT_END_NAMESPACE

class Magasin : public QWidget
{
    Q_OBJECT

public:
    Magasin(QWidget *parent = nullptr);
    void AfficherStock();
    void AfficherRouleauEnceinte(const Rouleau _rouleau);
    ~Magasin();

private:
    Ui::Magasin *ui;
    AlveolesLibres lesAlveoles;
    Chariot leChariot;
    Stock leStock;
    int nbRouleau;
    QMultiMap<int,Rouleau>::iterator debut;
};
#endif // MAGASIN_H
