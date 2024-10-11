#ifndef LIASONSERIE_H
#define LIASONSERIE_H

#include <QWidget>
#include <QList>
#include <QSerialPortInfo>
#include <QDebug>
#include <QSerialPort>

QT_BEGIN_NAMESPACE
namespace Ui {
class LiasonSerie;
}
QT_END_NAMESPACE

class LiasonSerie : public QWidget
{
    Q_OBJECT

public:
    LiasonSerie(QWidget *parent = nullptr);
    ~LiasonSerie();

private slots:
    void on_comboBoxChoix_currentTextChanged(const QString &arg1);

private:
    Ui::LiasonSerie *ui;
    QSerialPort *portPtr;
};
#endif // LIASONSERIE_H
