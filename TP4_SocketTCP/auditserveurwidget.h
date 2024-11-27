#ifndef AUDITSERVEURWIDGET_H
#define AUDITSERVEURWIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostInfo>
#include <QProcess>
#include <QDebug>
#include <QList>

QT_BEGIN_NAMESPACE
namespace Ui {
class AuditServeurWidget;
}
QT_END_NAMESPACE

class AuditServeurWidget : public QWidget
{
    Q_OBJECT

public:
    AuditServeurWidget(QWidget *parent = nullptr);
    ~AuditServeurWidget();

    QList<QTcpSocket> lesClients;
private slots:
    void on_pushButtonLancement_clicked();

    void onQTcpSocket_NewConnection();
    void onQTcpSocket_AcceptError();
    void onQTcpSocket_Connected();
    void onQTcpSocket_Disconnected();
    void onQTcpSocket_ReadyRead();
    void onQTcpSocket_ErrorOccurred(QAbstractSocket::SocketError _socketError);
    void onQTcpSocket_HostFound();
    void onQTcpSocket_StateChanged(QAbstractSocket::SocketState _socketState);
    void onQTcpSocket_AboutToClose();
    void onQTcpSocket_BytesWritten(qint64 _bytes);
    void onQTcpSocket_ReadyReadStandardOutput();

private:
    Ui::AuditServeurWidget *ui;
    QTcpServer *socketEcouteServeur;
    QProcess *process;
    QTcpSocket *socketDialogueClient;
    QList<QProcess> lesProcess;
};
#endif // AUDITSERVEURWIDGET_H
