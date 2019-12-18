#include <QtNetwork>
#include <QDataStream>
#include <QDebug>
#include <QByteArray>
#include "Logger.h"

#include "TcpServer.h"

TcpServer::TcpServer(QObject* parent) :
    _s(new QTcpServer(parent))
{
    connect(_s, &QTcpServer::newConnection, this, &TcpServer::response);
}


void TcpServer::listen(SettingsEntity local)
{
    _s->listen(QHostAddress(local.ip), local.port);
    logger() << "listening";
}

void TcpServer::response()
{
    logger() << "connected";
    auto socket = _s->nextPendingConnection();
    logger() << "iniial stream";
    connect(socket, &QTcpSocket::readyRead, this, [=]
    {
        QDataStream  in(socket);
        logger() << "readyRead";
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

