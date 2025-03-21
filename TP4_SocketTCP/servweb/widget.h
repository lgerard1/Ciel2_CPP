#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QHttpServer>
#include <QHttpServerResponder>
#include <QHttpServerRequest>
#include <QTcpServer>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButtonLaunchWeb_clicked();
    void onQTcpSocket_NewConnection();
    void onQTcpSocket_Connected();
    void onQTcpSocket_Disconnected();
    void onQTcpSocket_ReadyRead();
    void onQTcpSocket_ErrorOccurred(QAbstractSocket::SocketError _socketError);

private:
    Ui::Widget *ui;
    QNetworkAccessManager manager;
    QHttpServer serveurHttp;
    QHttpServerResponse handleHttpRequest(const QHttpServerRequest &request);
    QTcpServer *socketEcouteServeur;
    QTcpSocket *socketDialogueClient;
};
#endif // WIDGET_H
