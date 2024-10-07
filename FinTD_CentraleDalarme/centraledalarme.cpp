#include <QDebug>

#include "centraledalarme.h"
#include "clavier.h"



CentraleDalarme::CentraleDalarme(const int _tailleCode, QObject *parent) :
    QObject(parent),
    tailleCode(_tailleCode),
    indiceCourant(0),
    mode(REPOS)
{
    combinaison = new quint8[tailleCode];
    for(int i = 0 ; i < tailleCode ; i++)
        combinaison[i]=0;

    leClavier = new Clavier(this);
    leClavier->show();

    connect(&timerDelai,&QTimer::timeout,this,&CentraleDalarme::onTimerDelai_timeout);

    emit EtatCentraleChange(mode);
}

CentraleDalarme::~CentraleDalarme()
{
    delete leClavier;
}

void CentraleDalarme::FabriquerCode(const quint8 _chiffre)
{
    if (indiceCourant < tailleCode)
        combinaison [indiceCourant++] = _chiffre;
    else
    {
        for (int i=0; i < tailleCode-1; i++)
            combinaison[i]=combinaison[i+1] ;
        combinaison[tailleCode - 1] = _chiffre ;
    }

    for(int i = 0 ; i < tailleCode; i++)
        qDebug() << combinaison[i];
    qDebug() << "-";
}

void CentraleDalarme::ModifierCode()
{
    if(indiceCourant == tailleCode)
    {
        mode = MODIFICATION_CODE;
        emit EtatCentraleChange(mode);
    }
}

void CentraleDalarme::TraiterBoutonMarche()
{
    switch(mode)
    {
    case REPOS:
        if(indiceCourant == tailleCode && leCode.VerifierCode(combinaison))
        {
            mode = ACTIVATION;
            timerDelai.start(5000);
        }
        break;
    case MODIFICATION_CODE:
        if(indiceCourant == tailleCode && leCode.VerifierCode(combinaison))
        {
            mode = SAISI_NOUVEAU;
        }
        else
        {
            mode = REPOS;
        }
        break;
    case SAISI_NOUVEAU:
        if(indiceCourant == tailleCode)
        {
            leCode.Memoriser(combinaison);
            mode = REPOS;
        }
        break;
    default:
        break;
    }
    emit EtatCentraleChange(mode);
    indiceCourant = 0;
}

void CentraleDalarme::TraiterBoutonArret()
{
    switch(mode)
    {
    case SURVEILLANCE:
        if(indiceCourant == tailleCode && leCode.VerifierCode(combinaison))
        {
            mode = REPOS;
            Desactiver();
        }
        break;
    case MODIFICATION_CODE:
    case SAISI_NOUVEAU:
        mode = REPOS;
        break;
    default:
        break;
    }
    emit EtatCentraleChange(mode);
}

void CentraleDalarme::Activer()
{
    leDetecteur = new Detecteur;
    leDetecteurTemporise = new DetecteurTemporise;
    connect(leDetecteur,&Detecteur::IntrusDetecte,this,&CentraleDalarme::onIntrusDetecte);
    connect(leDetecteurTemporise,&DetecteurTemporise::IntrusDetecte,this,&CentraleDalarme::onIntrusDetecte);
    laSirene = new Sirene;

    leDetecteur->show();
    leDetecteurTemporise->show();
}

void CentraleDalarme::Desactiver()
{
    laSirene->Arreter();
    disconnect(leDetecteur,&Detecteur::IntrusDetecte,this,&CentraleDalarme::onIntrusDetecte);
    disconnect(leDetecteurTemporise,&DetecteurTemporise::IntrusDetecte,this,&CentraleDalarme::onIntrusDetecte);
    delete leDetecteur;
    delete leDetecteurTemporise;
    delete laSirene;
}

void CentraleDalarme::onTimerDelai_timeout()
{
    mode = SURVEILLANCE;
    timerDelai.stop();
    emit EtatCentraleChange(mode);
    Activer();
}

void CentraleDalarme::onIntrusDetecte()
{
    laSirene->Enclencher();
}

