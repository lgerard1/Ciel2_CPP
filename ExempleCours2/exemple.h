#ifndef EXEMPLE_H
#define EXEMPLE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Exemple;
}
QT_END_NAMESPACE

class Exemple : public QMainWindow
{
    Q_OBJECT

public:
    Exemple(QWidget *parent = nullptr);
    ~Exemple();

private:
    Ui::Exemple *ui;
};
#endif // EXEMPLE_H
