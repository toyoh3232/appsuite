#include <QNetworkDatagram>
#include <QDataStream>
#include "QDhcpServer.h"
#include "QDebug"

QDhcpServer::QDhcpServer(QObject *parent) :
    socket(new QUdpSocket(parent))
{
    connect(socket, &QUdpSocket::readyRead, this, [=]
            {
                if (socket->hasPendingDatagrams())
                {
                     auto data = socket->receiveDatagram().data();
                     QDataStream stream(&data, QIODevice::ReadOnly);
                     DhcpPacket p;
                     stream >> p.op >> p.htype >> p.hlen >> p.hops;
                     qDebug() << p.op << p.htype << p.hlen << p.hops;
                }
    });
}

QDhcpServer::~QDhcpServer()
{
    delete socket;
}

bool QDhcpServer::bind(const QHostAddress &address)
{
    return socket->bind(QHostAddress::Any, 67);
}

void QDhcpServer::listen()
{

}
