#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <QtNetwork/QTcpSocket>

#include "SettingsEntity.h"

enum RequestType {ASK_INFOMATION = 1};

class TcpSocket : private QTcpSocket
{
public:
    TcpSocket() = default;
    void connect(SettingsEntity server);
    SettingsEntity request(RequestType type);

public:
    static TcpSocket* sendWOL(SettingsEntity target, int timeOut);
};

#endif/*TCPSOCKET_H*/
