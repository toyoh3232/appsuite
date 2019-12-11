#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QString>
#include <QTextStream>

#include "TcpSocket.h"
#include "SettingsEntity.h"

class TcpServer : private QTcpServer
{
public:
    TcpServer() = default;
public:
    void listen(SettingsEntity local);
    void response();
};

#endif  /*TCPSERVER_H*/
