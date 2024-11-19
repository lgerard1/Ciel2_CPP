#ifndef SERVEUR_H
#define SERVEUR_H

#include <QWidget>
#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QTimer>
#include <QTime>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class Serveur;
}
QT_END_NAMESPACE

class Serveur : public QWidget
{
    Q_OBJECT

public:
    Serveur(QWidget *parent = nullptr);
    void LancerTimerHeure();
    void EnvoyerDatagram(const QByteArray data);
    ~Serveur();

private slots:
    void on_pushButtonDiffusion_clicked();

    void on_pushButtonAjouter_clicked();

    void on_pushButtonAlerte_clicked();

    void on_pushButtonSupprimer_clicked();

    void on_pushButtonMeteo_clicked();
    void onTimerInformation_timeout();
    void onTimerHeure_timeout();

private:
    Ui::Serveur *ui;
    int indexMessage;
    bool alerte;
    bool alternanceAlerte;
    QUdpSocket socketServeur;
    QNetworkDatagram datagram;
    QTimer timerInformation;
    QTimer timerHeure;
};
#endif // SERVEUR_H
