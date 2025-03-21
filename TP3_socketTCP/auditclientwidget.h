#ifndef AUDITCLIENTWIDGET_H
#define AUDITCLIENTWIDGET_H

#include <QWidget>
#include <QTcpSocket>


QT_BEGIN_NAMESPACE
namespace Ui {
class AuditClientWidget;
}
QT_END_NAMESPACE

class AuditClientWidget : public QWidget
{
    Q_OBJECT

public:
    AuditClientWidget(QWidget *parent = nullptr);
    ~AuditClientWidget();

private slots:
    void on_pushButtonConnexion_clicked();

    void on_pushButtonOrdinateur_clicked();

    void on_pushButtonUtilisateur_clicked();

    void on_pushButtonArchitecture_clicked();

    void on_pushButtonOS_clicked();
    void onQTcpSocket_Connected();
    void onQTcpSocket_Disconnected();
    void onQTcpSocket_ReadyRead();
    void onQTcpSocket_ErrorOccurred(QAbstractSocket::SocketError _socketError);
    void onQTcpSocket_HostFound();
    void onQTcpSocket_StateChanged(QAbstractSocket::SocketState _socketState);
    void onQTcpSocket_AboutToClose();
    void onQTcpSocket_BytesWritten(qint64 _bytes);
    void onQTcpSocket_ChannelBytesWritten(int _channel, qint64 _bytes);
    void onQTcpSocket_ChannelReadyRead(int _channel);
    void onQTcpSocket_ReadChannelFinished();
    void onQTcpSocket_Destroyed(QObject *_obj);


private:
    Ui::AuditClientWidget *ui;
    QTcpSocket *socketClient;
    char typeDeDemande;
};
#endif // AUDITCLIENTWIDGET_H
