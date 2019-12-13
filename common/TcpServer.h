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
    Q_OBJECT
public:
    TcpServer();
public:
    void listen(SettingsEntity local);

public slots:
    void response();
};

#endif  /*TCPSERVER_H*/
