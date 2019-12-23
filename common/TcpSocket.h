#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <QtNetwork/QTcpSocket>

#include "Settings.h"

class TcpSocket : public QObject
{
    Q_OBJECT

public:
    explicit TcpSocket();
    void connectTo(SettingsEntity server);
    void request(RequestType type);

signals:
    void arrived(QString e);

public:
    static void sendWOL(SettingsEntity target, int timeOut);

private:
    QTcpSocket* _s;
};

#endif/*TCPSOCKET_H*/
