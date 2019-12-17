#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <QtNetwork/QTcpSocket>

#include "SettingsEntity.h"

class TcpSocket : private QTcpSocket
{
    Q_OBJECT

public:
    TcpSocket();
    void connectTo(SettingsEntity server);
    void request(RequestType type);

public:
    static TcpSocket* sendWOL(SettingsEntity target, int timeOut);
};

#endif/*TCPSOCKET_H*/
