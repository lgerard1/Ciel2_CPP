#include "widget.h"
#include "ui_widget.h"
#include <QJsonObject>
#include <QJsonDocument>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    ,socketEcouteServeur(new QTcpServer(this))
    ,socketDialogueClient(nullptr)
{
    ui->setupUi(this);
    serveurHttp.route("/", [this](const QHttpServerRequest &request) {
        return handleHttpRequest(request);
    });
    connect(socketEcouteServeur,&QTcpServer::newConnection, this,&Widget::onQTcpSocket_NewConnection);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonLaunchWeb_clicked()
{
    if (   serveurHttp.listen(QHostAddress::Any,ui->spinBoxPortHttp->value()))
    {
        qDebug()<<"lancement du serveur http sur le port "<<ui->spinBoxPortHttp->value();
    }
    else
    {
        qDebug()<<"probleme de lancement du serveur http sur le port "<<ui->spinBoxPortHttp->value();
    }
}

void Widget::onQTcpSocket_NewConnection()
{
    QTcpSocket *newClient = socketEcouteServeur->nextPendingConnection();
    QTcpSocket *client;
    client = socketEcouteServeur->nextPendingConnection();

    qDebug() << "essai";
    socketDialogueClient = newClient;
    connect(client,&QTcpSocket::connected, this,&Widget::onQTcpSocket_Connected);
    connect(client,&QTcpSocket::disconnected, this,&Widget::onQTcpSocket_Disconnected);
    connect(client,&QTcpSocket::readyRead, this,&Widget::onQTcpSocket_ReadyRead);
    connect(client,&QTcpSocket::errorOccurred, this,&Widget::onQTcpSocket_ErrorOccurred);
}

void Widget::onQTcpSocket_Connected()
{

}

void Widget::onQTcpSocket_Disconnected()
{

}

void Widget::onQTcpSocket_ReadyRead()
{

}

void Widget::onQTcpSocket_ErrorOccurred(QAbstractSocket::SocketError _socketError)
{

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
        QByteArray jsonData = jsonDoc.toJson(QJsonDocument::Compact);

        qDebug() << "Received GET request:" << jsonData;

        // Envoi aux clients WebSocket
      //  broadcastToWebSocketClients(jsonData);

        return QHttpServerResponse(jsonData, "application/json");
    } else {
        return QHttpServerResponse("Only GET requests are supported", QHttpServerResponder::StatusCode::MethodNotAllowed);
    }

}



