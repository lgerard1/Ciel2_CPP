#include "serveur.h"
#include "ui_serveur.h"

Serveur::Serveur(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Serveur),
    indexMessage(0),
    alerte(false),
    alternanceAlerte(false),
    datagram(QByteArray(), QHostAddress::Broadcast, 45454)
{
    ui->setupUi(this);


}

void Serveur::EnvoyerDatagram(const QByteArray data)
{

    datagram.setData(data); // Configure les données à envoyer
    if (socketServeur.writeDatagram(datagram) == -1) {
        qDebug() << "Erreur lors de l'envoi du datagram :" << socketServeur.errorString();
    } else {
        qDebug() << "Datagram envoyé avec succès : " << data;
    }

}

Serveur::~Serveur()
{
    delete ui;
}

void Serveur::on_pushButtonDiffusion_clicked()
{
    // if (!timerInformation.isActive() && !timerHeure.isActive()) {
    //     connect(&timerInformation, &QTimer::timeout, this, &Serveur::onTimerInformation_timeout);
    //     connect(&timerHeure, &QTimer::timeout, this, &Serveur::onTimerHeure_timeout);
    //     timerInformation.start(10000);
    //     timerHeure.start(60000);
    //     ui->pushButtonDiffusion->setText("Arrêter la diffusion");
    //     qDebug() << "Diffusion démarrée : Timers activés.";
    // } else {
    //     timerInformation.stop();
    //     timerHeure.stop();
    //     disconnect(&timerInformation, &QTimer::timeout, this, &Serveur::onTimerInformation_timeout);
    //     disconnect(&timerHeure, &QTimer::timeout, this, &Serveur::onTimerHeure_timeout);
    //     ui->pushButtonDiffusion->setText("Lancer la diffusion");
    //     qDebug() << "Diffusion arrêtée : Timers désactivés.";
    // }
    QByteArray buffer;
    QDataStream out(&buffer, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_0);

    if (alerte && !ui->textEditAlerte->toPlainText().isEmpty()) {
        if (alternanceAlerte) {
            QString alerteMessage = ui->textEditAlerte->toPlainText();
            out << 'A' << alerteMessage;
            qDebug() << "Envoi du message d'alerte : " << alerteMessage;
        } else {
            if (ui->listWidgetMessage->count() > 0) {
                QString infoMessage = ui->listWidgetMessage->item(indexMessage)->text();
                out << 'I' << infoMessage;
                indexMessage = (indexMessage + 1) % ui->listWidgetMessage->count();
                qDebug() << "Envoi du message d'information : " << infoMessage;
            } else {
                qDebug() << "Aucun message d'information disponible à diffuser.";
                return;
            }
        }
        alternanceAlerte = !alternanceAlerte;
    } else {
        if (ui->listWidgetMessage->count() > 0) {
            QString infoMessage = ui->listWidgetMessage->item(indexMessage)->text();
            out << 'I' << infoMessage;
            indexMessage = (indexMessage + 1) % ui->listWidgetMessage->count();
            qDebug() << "Envoi du message d'information : " << infoMessage;
        } else {
            qDebug() << "Aucun message d'information disponible à diffuser.";
            return;
        }
    }

    EnvoyerDatagram(buffer);

}


void Serveur::on_pushButtonAjouter_clicked()
{
    QString message = ui->textEditInformation->toPlainText();

    if (!message.isEmpty()) {
        ui->listWidgetMessage->addItem(message);
        qDebug() << "Message ajouté : " << message;

        ui->textEditInformation->clear();
    } else {
        qDebug() << "Le champ de texte est vide, aucun message ajouté.";
    }
}


void Serveur::on_pushButtonAlerte_clicked()
{
    if (!alerte) {
        alerte = true;
        ui->pushButtonAlerte->setText("Supprimer l'alerte");
        qDebug() << "Alerte activée.";
    } else {
        alerte = false;
        ui->pushButtonAlerte->setText("Créer une alerte");
        qDebug() << "Alerte désactivée.";
    }
}


void Serveur::on_pushButtonSupprimer_clicked()
{
    QListWidgetItem *selectedItem = ui->listWidgetMessage->currentItem();

    if (selectedItem) {
        delete selectedItem;
        qDebug() << "Message supprimé.";
    } else {
        qDebug() << "Aucun message sélectionné ou liste vide.";
        QMessageBox::warning(this, "Attention", "Veuillez sélectionner un message à supprimer.");
    }
}


void Serveur::on_pushButtonMeteo_clicked()
{
    QByteArray buffer;
    QDataStream out(&buffer, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_0);
    out << 'M' << ui->lineEditMeteo->text();
    EnvoyerDatagram(buffer);

}

void Serveur::onTimerInformation_timeout()
{
    if (ui->listWidgetMessage->count() > 0) {
        QString message = ui->listWidgetMessage->item(indexMessage)->text();
        QByteArray buffer;
        QDataStream out(&buffer, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_6_0);
        out << 'I' << message;

        EnvoyerDatagram(buffer);

        indexMessage = (indexMessage + 1) % ui->listWidgetMessage->count();
    } else {
        qDebug() << "Aucun message d'information à diffuser.";
    }
}

void Serveur::onTimerHeure_timeout()
{
    QTime heure = QTime::currentTime();
    QString heureStr = heure.toString("HH:mm");

    QByteArray buffer;
    QDataStream out(&buffer, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_0);
    out << 'H' << heureStr;

    EnvoyerDatagram(buffer);
}

