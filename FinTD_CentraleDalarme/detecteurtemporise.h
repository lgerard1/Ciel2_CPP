#ifndef DETECTEURTEMPORISE_H
#define DETECTEURTEMPORISE_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class DetecteurTemporise;
}

class DetecteurTemporise : public QDialog
{
    Q_OBJECT

public:
    explicit DetecteurTemporise(QWidget *parent = 0);
    ~DetecteurTemporise();

private slots:
    void on_pushButtonIntrus_clicked();
    void onTimerIntrus_timeout();

signals:
    void IntrusDetecte();

private:
    Ui::DetecteurTemporise *ui;
    QTimer timerIntrus;
};

#endif // DETECTEURTEMPORISE_H
