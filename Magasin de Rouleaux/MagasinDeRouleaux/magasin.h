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
    void extracted(int &rangee, int &colonne);
    void AfficherRouleauEnceinte(const Rouleau _rouleau);
    ~Magasin();

private slots:
    void on_pushButtonNouveau_clicked();

    void on_pushButtonRetrait_clicked();

private:
    Ui::Magasin *ui;
    AlveolesLibres lesAlveoles;
    Chariot leChariot;
    Stock leStock;
    int nbRouleau;
    Rouleau lesRouleaux;
    QMultiMap<int,Rouleau>::iterator debut;
    int rangee;
    int colonne;
};
#endif // MAGASIN_H
