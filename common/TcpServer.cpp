#include <QtNetwork>
#include <QDataStream>
#include <QDebug>
#include <QByteArray>

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
    qDebug() << "iniial stream";
    connect(socket, &QTcpSocket::readyRead, this, [=]
    {
        QDataStream  in(socket);
        qDebug() << "readyRead";
        RequestType cmd;
        in.startTransaction();
        in >> cmd;
        if (!in.commitTransaction())
            return;
        QByteArray data;
        QDataStream out(&data, QIODevice::ReadWrite);
        switch (cmd)
        {
            case RequestType::ASK_INFOMATION:
                qDebug() << "readyWrite";
                in << QString("Window 7");
                break;
        }
        socket->write(data);
    });
}

