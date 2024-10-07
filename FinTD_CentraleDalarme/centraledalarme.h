#ifndef CENTRALEDALARME_H
#define CENTRALEDALARME_H

#include <QObject>
#include <QTimer>

#include "Code.h"
#include "detecteur.h"
#include "detecteurtemporise.h"
#include "sirene.h"

class Clavier;

#define TAILLE_CODE 4

class CentraleDalarme : public QObject
{
    Q_OBJECT
public:
    enum MODES_DE_MARCHE
    {
        REPOS,
        MODIFICATION_CODE,
        SAISI_NOUVEAU,
        SURVEILLANCE,
        ACTIVATION,
        ALARME
    };

    explicit CentraleDalarme(const int _tailleCode = 4, QObject *parent = nullptr);
    ~CentraleDalarme();
    void FabriquerCode(const quint8 _chiffre);
    void ModifierCode();
    void TraiterBoutonMarche();
    void TraiterBoutonArret();
    void Activer();
    void Desactiver();

signals:
    void EtatCentraleChange(MODES_DE_MARCHE _nouvelmode);
private slots:
    void onTimerDelai_timeout();

public slots:
    void onIntrusDetecte();

private:
    const int tailleCode;
    quint8 *combinaison;
    int indiceCourant;
    MODES_DE_MARCHE mode;
    Code    leCode;
    QTimer timerDelai;
    Clavier *leClavier;
    Detecteur *leDetecteur;
    DetecteurTemporise *leDetecteurTemporise;
    Sirene *laSirene;




};

#endif // CENTRALEDALARME_H
