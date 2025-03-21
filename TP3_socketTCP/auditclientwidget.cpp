#include "auditclientwidget.h"
#include "ui_auditclientwidget.h"

AuditClientWidget::AuditClientWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AuditClientWidget)
    ,socketClient(new QTcpSocket)
{
    ui->setupUi(this);


    connect(socketClient,&QTcpSocket::connected, this,&AuditClientWidget::onQTcpSocket_Connected);
    connect(socketClient,&QTcpSocket::disconnected, this,&AuditClientWidget::onQTcpSocket_Disconnected);
    connect(socketClient,&QTcpSocket::readyRead, this,&AuditClientWidget::onQTcpSocket_ReadyRead);
    connect(socketClient,&QTcpSocket::errorOccurred, this,&AuditClientWidget::onQTcpSocket_ErrorOccurred);
    connect(socketClient,&QTcpSocket::aboutToClose, this,&AuditClientWidget::onQTcpSocket_AboutToClose);
    connect(socketClient,&QTcpSocket::hostFound, this,&AuditClientWidget::onQTcpSocket_HostFound);
    connect(socketClient,&QTcpSocket::stateChanged, this,&AuditClientWidget::onQTcpSocket_StateChanged);
    connect(socketClient,&QTcpSocket::bytesWritten, this,&AuditClientWidget::onQTcpSocket_BytesWritten);
    connect(socketClient,&QTcpSocket::channelBytesWritten, this,&AuditClientWidget::onQTcpSocket_ChannelBytesWritten);
    connect(socketClient,&QTcpSocket::channelReadyRead, this,&AuditClientWidget::onQTcpSocket_ChannelReadyRead);
    connect(socketClient,&QTcpSocket::readChannelFinished, this,&AuditClientWidget::onQTcpSocket_ReadChannelFinished);
    connect(socketClient,&QTcpSocket::destroyed, this,&AuditClientWidget::onQTcpSocket_Destroyed);
}

AuditClientWidget::~AuditClientWidget()
{
    delete ui;
}

void AuditClientWidget::on_pushButtonConnexion_clicked()
{
    if (ui->pushButtonConnexion->text() == "Connexion") {
        socketClient->connectToHost(ui->lineEditAdresseIP->text(), ui->lineEditPort->text().toInt());
        ui->groupBoxInformationClient->setEnabled(true);
        ui->lineEditAdresseIP->setEnabled(false);
        ui->lineEditPort->setEnabled(false);
        ui->pushButtonConnexion->setText("Déconnexion");
    }

    else {
       ui->groupBoxInformationClient->setEnabled(false);

       ui->pushButtonConnexion->setText("Connexion");
       socketClient->disconnectFromHost();
       ui->lineEditAdresseIP->setEnabled(true);
       ui->lineEditPort->setEnabled(true);
       ui->textEditEtat->clear();
    }


}


void AuditClientWidget::on_pushButtonOrdinateur_clicked()
{
    typeDeDemande='c';
    socketClient->write(&typeDeDemande,1);
}


void AuditClientWidget::on_pushButtonUtilisateur_clicked()
{
    typeDeDemande='u';
    socketClient->write(&typeDeDemande,1);
}


void AuditClientWidget::on_pushButtonArchitecture_clicked()
{
    typeDeDemande='a';
    socketClient->write(&typeDeDemande,1);
}


void AuditClientWidget::on_pushButtonOS_clicked()
{
    typeDeDemande='o';
    socketClient->write(&typeDeDemande,1);
}

void AuditClientWidget::onQTcpSocket_Connected()
{

}

void AuditClientWidget::onQTcpSocket_Disconnected()
{

}

void AuditClientWidget::onQTcpSocket_ReadyRead()
{
    ui->textEditEtat->append("Prêt à lire");
    switch (typeDeDemande) {
    case 'a':
        ui->lineEditArchitecture->setText(socketClient->readAll());
        break;
    case 'o':
        ui->lineEditOS->setText(socketClient->readAll());
        break;
    case 'u':
        ui->lineEditUtilisateur->setText(socketClient->readAll());
        break;
    case 'c':
        ui->lineEditOrdinateur->setText(socketClient->readAll());
        break;
    default:
        break;
    }
}

void AuditClientWidget::onQTcpSocket_ErrorOccurred(QAbstractSocket::SocketError _socketError)
{
    Q_UNUSED(_socketError); // le paramètre n'est pas utilisé dans cette méthode
    ui->textEditEtat->append(socketClient->errorString());
}

void AuditClientWidget::onQTcpSocket_HostFound()
{
    ui->textEditEtat->append("un hôte à été trouvé");
}

void AuditClientWidget::onQTcpSocket_StateChanged(QAbstractSocket::SocketState _socketState)
{
    switch (_socketState) {
    case QAbstractSocket::UnconnectedState:
        ui->textEditEtat->append("pas connecté");
        break;
    case QAbstractSocket::HostLookupState:
        ui->textEditEtat->append("État de recherche de l'hôte");
        break;
    case QAbstractSocket::ConnectingState:
        ui->textEditEtat->append("État de connexion");
        break;
    case QAbstractSocket::ConnectedState:
        ui->textEditEtat->append("Connecté");
        break;
    case QAbstractSocket::BoundState:
        ui->textEditEtat->append("État lié");
        break;
    case QAbstractSocket::ClosingState:
        ui->textEditEtat->append("État de fermeture");
        break;
    case QAbstractSocket::ListeningState:
        ui->textEditEtat->append("État d'écoute");
    default:
        break;
    }

}

void AuditClientWidget::onQTcpSocket_AboutToClose()
{
    ui->textEditEtat->append("about to close");
}

void AuditClientWidget::onQTcpSocket_BytesWritten(qint64 _bytes)
{
    ui->textEditEtat->append("Bytes Written");
}

void AuditClientWidget::onQTcpSocket_ChannelBytesWritten(int _channel, qint64 _bytes)
{
    ui->textEditEtat->append("Channel bytes written");
}

void AuditClientWidget::onQTcpSocket_ChannelReadyRead(int _channel)
{
    ui->textEditEtat->append("prêt à lire");
}

void AuditClientWidget::onQTcpSocket_ReadChannelFinished()
{
    ui->textEditEtat->append("fin de lecture");
}

void AuditClientWidget::onQTcpSocket_Destroyed(QObject *_obj)
{
    ui->textEditEtat->append("Destruction");
}

