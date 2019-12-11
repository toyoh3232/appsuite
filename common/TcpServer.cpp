#include <QtNetwork>
#include <QDataStream>

#include "TcpServer.h"

void TcpServer::listen(SettingsEntity local)
{
    QTcpServer::listen(QHostAddress(local.ip), local.port);
}

void TcpServer::response()
{
    if (hasPendingConnections())
    {
        auto socket = nextPendingConnection();
        QDataStream stream(socket);
        int c;
        stream >> c;
        switch(c)
        {
            case 1: stream << "Windows 7";
        }
    }
}
