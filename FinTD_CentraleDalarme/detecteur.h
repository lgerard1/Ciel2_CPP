#ifndef DETECTEUR_H
#define DETECTEUR_H

#include <QDialog>

namespace Ui {
class Detecteur;
}

class Detecteur : public QDialog
{
    Q_OBJECT

public:
    explicit Detecteur(QWidget *parent = 0);
    ~Detecteur();

private slots:
    void on_pushButtonIntrus_clicked();

signals:
    void IntrusDetecte();

protected:
    Ui::Detecteur *ui;
};

#endif // DETECTEUR_H
