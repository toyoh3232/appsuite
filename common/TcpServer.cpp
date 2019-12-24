#include <QtNetwork>
#include <QDataStream>
#include <QDebug>
#include <QByteArray>
#include <QSysInfo>
#include "Logger.h"

#include "TcpServer.h"

TcpServer::TcpServer(QObject* parent) :
    _s(new QTcpServer(parent))
{
    connect(_s, &QTcpServer::newConnection, this, &TcpServer::response);
}


void TcpServer::listen(QString ip, quint16 port)
{
    _s->listen(QHostAddress(ip), port);
    logger() << QString("starting server on %1:%2").arg(ip).arg(port);
}

void TcpServer::response()
{
    auto socket = _s->nextPendingConnection();
    logger() << QString("client %1 connected").arg(socket->peerAddress().toString());
    connect(socket, &QTcpSocket::readyRead, this, [=]
    {
        QDataStream  in(socket);
        RequestType cmd;
        in.startTransaction();
        in >> cmd;
        if (!in.commitTransaction())
            return;
        logger() << "remote command received";
        QByteArray data;
        QDataStream out(&data, QIODevice::ReadWrite);
        switch (cmd)
        {
            case RequestType::ASK_INFOMATION:
                logger() << "sending OS info";
                SettingsEntity se;
                se["targetOS"] = QSysInfo::prettyProductName();
                out << se;
                break;
        }
        socket->write(data);
    });
}

