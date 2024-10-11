#ifndef CALCULATRICE_H
#define CALCULATRICE_H
#include <QPushButton>
#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <QJSEngine>
QT_BEGIN_NAMESPACE
namespace Ui {
class Calculatrice;
}
QT_END_NAMESPACE

class Calculatrice : public QWidget
{
    Q_OBJECT

public:
    Calculatrice(QWidget *parent = nullptr);
    ~Calculatrice();
private slots:
    void onQpushButtonClicked();
private:
    Ui::Calculatrice *ui;
    const int NB_TOUCHES;
    QGridLayout *grille;
    QLineEdit *afficheur;
    QPushButton **touches;

};
#endif // CALCULATRICE_H
