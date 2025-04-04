#include "widget.h"
#include "ui_widget.h"
#include <QJsonObject>
#include <QJsonDocument>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    ,ancienneCommande(nullptr)
    , socketEcouteServeur(new QTcpServer(this))
    , socketDialogueClient(nullptr)
{
    ui->setupUi(this);
    cpt=0;
    // Serveur HTTP
    serveurHttp.route("/", [this](const QHttpServerRequest &request) {
        return handleHttpRequest(request);
    });

    // Connexion du signal de nouvelle connexion pour le serveur TCP
    connect(socketEcouteServeur, &QTcpServer::newConnection, this, &Widget::onQTcpServer_NewConnection);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonLaunchWeb_clicked()
{
    // Lance le serveur HTTP
    if (serveurHttp.listen(QHostAddress::Any, ui->spinBoxPortHttp->value())) {
        qDebug() << "Lancement du serveur HTTP sur le port" << ui->spinBoxPortHttp->value();
    } else {
        qDebug() << "Problème de lancement du serveur HTTP sur le port" << ui->spinBoxPortHttp->value();
    }

    // Lance le serveur TCP
    if (socketEcouteServeur->listen(QHostAddress::Any, ui->spinBoxPortTCP->value())) {
        qDebug() << "Lancement du serveur TCP sur le port" << ui->spinBoxPortTCP->value();
    } else {
        qDebug() << "Problème de lancement du serveur TCP sur le port" << ui->spinBoxPortTCP->value();
    }
}

void Widget::onQTcpServer_NewConnection()
{
    // Récupère la nouvelle connexion TCP
    QTcpSocket *newClient = socketEcouteServeur->nextPendingConnection();
    if (newClient) {
        qDebug() << "Client TCP connecté : " << newClient->peerAddress().toString() << ":" << newClient->peerPort();
        socketDialogueClient = newClient;

        connect(newClient, &QTcpSocket::connected, this, &Widget::onQTcpSocket_Connected);
        connect(newClient, &QTcpSocket::disconnected, this, &Widget::onQTcpSocket_Disconnected);
        connect(newClient, &QTcpSocket::readyRead, this, &Widget::onQTcpSocket_ReadyRead);
        connect(newClient, &QTcpSocket::errorOccurred, this, &Widget::onQTcpSocket_ErrorOccurred);
    } else {
        qDebug() << "Aucun client TCP connecté.";
    }
}

void Widget::onQTcpSocket_Connected()
{
    qDebug() << "Connexion TCP établie.";
}

void Widget::onQTcpSocket_Disconnected()
{
    qDebug() << "Client TCP déconnecté.";
}

void Widget::onQTcpSocket_ReadyRead()
{
    // Lecture des données du client
    QByteArray data = socketDialogueClient->readAll();
    qDebug() << "Données reçues du client TCP : " << data;
}

void Widget::onQTcpSocket_ErrorOccurred(QAbstractSocket::SocketError socketError)
{
    qDebug() << "Erreur sur le socket TCP : " << socketError;
}
/*
QHttpServerResponse Widget::handleHttpRequest(const QHttpServerRequest &request)
{

    if (request.method() == QHttpServerRequest::Method::Get) {
        QUrlQuery query(request.url());
        QJsonObject json;

        // Construction de la réponse en JSON

        for (const auto &pair : query.queryItems()) {
            json.insert(pair.first, pair.second);
        }

        QJsonDocument jsonDoc(json);
        jsonData = jsonDoc.toJson(QJsonDocument::Compact);  // Commande reçue

        qDebug() << "Requête GET reçue : " << jsonData;

        // Si la commande reçue est différente de la dernière, on envoie les données
        if (jsonData != ancienneCommande) {
            cpt++;
            ui->textEditLog->append(QString::number(cpt));
            if (socketDialogueClient && socketDialogueClient->isOpen()) {
                socketDialogueClient->write(jsonData + "\n");
                socketDialogueClient->flush();  // Envoi des données au client TCP connecté
                qDebug() << "Données envoyées au client TCP.";
                ancienneCommande = jsonData;  // Mise à jour de la dernière commande envoyée
            } else {
                qDebug() << "Aucun client TCP connecté.";
            }
        } else {
            qDebug() << "Même commande que la précédente, rien à envoyer.";
        }

        return QHttpServerResponse(jsonData, "application/json");  // Réponse avec les données reçues
    } else {
        return QHttpServerResponse("Mauvaise requête envoyée", QHttpServerResponder::StatusCode::MethodNotAllowed);
    }

}
*/
bool jsonPresqueEgal(const QByteArray &a, const QByteArray &b, double delta)
{
    QJsonDocument docA = QJsonDocument::fromJson(a);
    QJsonDocument docB = QJsonDocument::fromJson(b);

    if (!docA.isObject() || !docB.isObject()) return false;

    QJsonObject objA = docA.object();
    QJsonObject objB = docB.object();

    if (objA.keys() != objB.keys()) return false;

    for (const QString &key : objA.keys()) {
        QJsonValue valA = objA.value(key);
        QJsonValue valB = objB.value(key);

        if (valA.isDouble() && valB.isDouble()) {
            if (qAbs(valA.toDouble() - valB.toDouble()) > delta) return false;
        } else {
            if (valA != valB) return false;
        }
    }
    return true;
}

QHttpServerResponse Widget::handleHttpRequest(const QHttpServerRequest &request)
{
    if (request.method() == QHttpServerRequest::Method::Get) {
        QUrlQuery query(request.url());
        QJsonObject json;

        for (const auto &pair : query.queryItems()) {
            json.insert(pair.first, pair.second);
        }

        QJsonDocument jsonDoc(json);
        jsonData = jsonDoc.toJson(QJsonDocument::Compact);

        qDebug() << "Requête GET reçue : " << jsonData;

        //⚠️ Comparaison avec tolérance delta = 4
        if (!jsonPresqueEgal(jsonData, ancienneCommande, 4.0)) {
            cpt++;
            ui->textEditLog->append(QString::number(cpt));
            if (socketDialogueClient && socketDialogueClient->isOpen()) {
                socketDialogueClient->write(jsonData + "\n");
                socketDialogueClient->flush();
                qDebug() << "Données envoyées au client TCP.";
                ancienneCommande = jsonData;
            } else {
                qDebug() << "Aucun client TCP connecté.";
            }
        } else {
           qDebug() << "Commande similaire (delta <= 4), rien à envoyer.";
        }

        return QHttpServerResponse(jsonData, "application/json");
    } else {
        return QHttpServerResponse("Mauvaise requête envoyée", QHttpServerResponder::StatusCode::MethodNotAllowed);
    }
}
