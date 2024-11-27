#include "auditserveurwidget.h"
#include "ui_auditserveurwidget.h"

AuditServeurWidget::AuditServeurWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AuditServeurWidget)
    ,socketEcouteServeur(new QTcpServer(this))
    ,socketDialogueClient(nullptr)
    ,process(new QProcess)

{
    ui->setupUi(this);
    connect(socketEcouteServeur,&QTcpServer::newConnection, this,&AuditServeurWidget::onQTcpSocket_NewConnection);
    connect(process, &QProcess::readyReadStandardOutput, this, &AuditServeurWidget::onQTcpSocket_ReadyReadStandardOutput);


}

AuditServeurWidget::~AuditServeurWidget()
{
    delete ui;
    delete process;
    socketDialogueClient->deleteLater();
    socketEcouteServeur->deleteLater();
}

void AuditServeurWidget::on_pushButtonLancement_clicked()
{
    if(!socketEcouteServeur->listen(QHostAddress::Any, ui->spinBoxPort->text().toInt()))
        qDebug() << "Echec au lancement du serveur : " << socketEcouteServeur->errorString();
    else
        qDebug() << "Serveur lancé sur le port : "<< QString::number(ui->spinBoxPort->text().toInt());
}

void AuditServeurWidget::onQTcpSocket_NewConnection()
{
    // QTcpSocket *newClient = socketEcouteServeur->nextPendingConnection();
    // if (socketDialogueClient) { // Si un client est déjà connecté, refuser la nouvelle connexion
    //     newClient->disconnectFromHost();

    //     if (newClient->state() != QAbstractSocket::UnconnectedState) {
    //         newClient->waitForDisconnected();
    //         qDebug() << "essai2";
    //     }
    //     newClient->deleteLater(); // Libérer les ressources
    // }
    // else {
    QTcpSocket *client;
    client = socketEcouteServeur->nextPendingConnection();

        qDebug() << "essai";
        socketDialogueClient = newClient;
        connect(client,&QTcpSocket::connected, this,&AuditServeurWidget::onQTcpSocket_Connected);
        connect(client,&QTcpSocket::disconnected, this,&AuditServeurWidget::onQTcpSocket_Disconnected);
        connect(client,&QTcpSocket::readyRead, this,&AuditServeurWidget::onQTcpSocket_ReadyRead);
        connect(client,&QTcpSocket::errorOccurred, this,&AuditServeurWidget::onQTcpSocket_ErrorOccurred);
        connect(client,&QTcpSocket::aboutToClose, this,&AuditServeurWidget::onQTcpSocket_AboutToClose);
        connect(client,&QTcpSocket::hostFound, this,&AuditServeurWidget::onQTcpSocket_HostFound);
        connect(client,&QTcpSocket::stateChanged, this,&AuditServeurWidget::onQTcpSocket_StateChanged);
        connect(client,&QTcpSocket::bytesWritten, this,&AuditServeurWidget::onQTcpSocket_BytesWritten);
        lesClients.append(client);
    //}

}

void AuditServeurWidget::onQTcpSocket_AcceptError()
{

}

void AuditServeurWidget::onQTcpSocket_Connected()
{

}

void AuditServeurWidget::onQTcpSocket_Disconnected()
{

}

void AuditServeurWidget::onQTcpSocket_ReadyRead()
{
    QByteArray data = socketDialogueClient->readAll();
    QString reponse;

    switch(data[0]) {
    case 'u': {
        reponse = getenv("USER");
        ui->textEditInformations->append("Username : " + reponse);
        break; }

    case 'c': {
        reponse = QHostInfo::localHostName();
        ui->textEditInformations->append("Computer : " + reponse);
        break; }

    case 'o':
        process->start("uname",QStringList("-p"));
        break;

    case 'a':
        process->start("uname");
        break;
    }
    socketDialogueClient->write(reponse.toLatin1());

}

void AuditServeurWidget::onQTcpSocket_ErrorOccurred(QAbstractSocket::SocketError _socketError)
{
    Q_UNUSED(_socketError); // le paramètre n'est pas utilisé dans cette méthode
    ui->textEditInformations->append(socketDialogueClient->errorString());
}

void AuditServeurWidget::onQTcpSocket_HostFound()
{

}

void AuditServeurWidget::onQTcpSocket_StateChanged(QAbstractSocket::SocketState _socketState)
{

}

void AuditServeurWidget::onQTcpSocket_AboutToClose()
{

}

void AuditServeurWidget::onQTcpSocket_BytesWritten(qint64 _bytes)
{

}

void AuditServeurWidget::onQTcpSocket_ReadyReadStandardOutput()
{
    QString reponse = process->readAllStandardOutput();
    if(!reponse.isEmpty())
        socketDialogueClient->write(reponse.toLatin1());
}

