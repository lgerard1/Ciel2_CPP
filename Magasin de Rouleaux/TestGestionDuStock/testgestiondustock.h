#ifndef TESTGESTIONDUSTOCK_H
#define TESTGESTIONDUSTOCK_H

#include <QWidget>
#include "stock.h"
#include "rouleau.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class TestGestionDuStock;
}
QT_END_NAMESPACE

class TestGestionDuStock : public QWidget
{
    Q_OBJECT

public:
    TestGestionDuStock(QWidget *parent = nullptr);
    ~TestGestionDuStock();

private slots:
    void on_pushButtonNouveau_clicked();

    void on_pushButtonRetrait_clicked();

    void on_pushButtonSupprimer_clicked();

private:
    Ui::TestGestionDuStock *ui;
    int nbRouleau;
    QMultiMap<int,Rouleau>::iterator debut;
    Stock leStock;
};
#endif // TESTGESTIONDUSTOCK_H
