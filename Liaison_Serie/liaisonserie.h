#ifndef LIAISONSERIE_H
#define LIAISONSERIE_H

#include <QWidget>
#include <QList>
//#include <QSerialPortInfo>
#include <QDebug>
#include <QSerialPort>

QT_BEGIN_NAMESPACE
namespace Ui {
class LiaisonSerie;
}
QT_END_NAMESPACE

class LiaisonSerie : public QWidget
{
    Q_OBJECT

public:
    LiaisonSerie(QWidget *parent = nullptr);
    ~LiaisonSerie();

private slots :
    void on_comboBoxChoix_currentTextChanged(const QString &arg1);

private:
    Ui::LiaisonSerie *ui;
};
#endif // LIAISONSERIE_H
