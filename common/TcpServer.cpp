#include <QtNetwork>
#include <QDataStream>
#include <QDebug>

#include "TcpServer.h"

TcpServer::TcpServer() :
    QTcpServer(nullptr)
{
    connect(this, SIGNAL(newConnection()), this, SLOT(response()));
}


void TcpServer::listen(SettingsEntity local)
{
    QTcpServer::listen(QHostAddress(local.ip), local.port);
}

void TcpServer::response()
{
    qDebug() << "connected";
    auto socket = nextPendingConnection();
    connect(socket, &QTcpSocket::readyRead, this, [=]
                    {
                        qDebug() << "readyRead";
                    });
}

