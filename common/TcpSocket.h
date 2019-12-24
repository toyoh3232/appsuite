#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <QtNetwork/QTcpSocket>

#include "Settings.h"

class TcpSocket : public QObject
{
    Q_OBJECT

public:
    explicit TcpSocket();
    void connectTo(QString ip, quint16 port);
    void request(RequestType type);

signals:
    void arrived();

public:
    static void sendWOL(QString mac, int timeOut);

private:
    QTcpSocket* _s;
};

#endif/*TCPSOCKET_H*/
