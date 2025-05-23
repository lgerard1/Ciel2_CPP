#ifndef DIALOGCONFIGURERLIAISONGPS_H
#define DIALOGCONFIGURERLIAISONGPS_H

#include <QDialog>
#include <QSerialPort>
#include <QtSerialPort>
#include <QList>
#include <QSerialPortInfo>
#include <QPushButton>
#include <QDebug>
#include <QSettings>
#include <QDir>
#include <QSize>
#include <QPoint>

namespace Ui {
class DialogConfigurerLiaisonGPS;
}

class DialogConfigurerLiaisonGPS : public QDialog
{
    Q_OBJECT

public:
    explicit DialogConfigurerLiaisonGPS(QSerialPort &_lePort, QWidget *parent = nullptr);
    ~DialogConfigurerLiaisonGPS();

private slots:
    void on_checkBoxStop_toggled(bool checked);

    void on_comboBoxVitesse_currentTextChanged(const QString &arg1);

    void on_spinBoxBitData_valueChanged(int arg1);

    void on_radioButtonPaire_toggled(bool checked);

    void on_radioButtonImpaire_toggled(bool checked);

    void on_radioButtonNone_toggled(bool checked);

    void on_comboBoxPort_currentIndexChanged(int index);

private:
    Ui::DialogConfigurerLiaisonGPS *ui;
    QSerialPort &lePort;
};

#endif // DIALOGCONFIGURERLIAISONGPS_H
