#include <QtNetwork>
#include <QDataStream>

#include "TcpServer.h"

TcpServer::TcpServer() :
    QTcpServer(nullptr)
{
    connect(this, &QTcpServer::newConnection, this, &TcpServer::response);
}


void TcpServer::listen(SettingsEntity local)
{
    QTcpServer::listen(QHostAddress(local.ip), local.port);
}

void TcpServer::response()
{
    auto socket = nextPendingConnection();
    QDataStream stream(socket);
    stream.startTransaction();
    if (!stream.commitTransaction())
        return;
    quint16 command;
    stream >> command;
    switch(command)
    {
    case 1:
        stream << "Windows 7";
    }
}
