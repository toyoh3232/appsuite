#include <QByteArray>
#include <QUdpSocket>
#include <QDataStream>
#include "Logger.h"

#include "TcpSocket.h"

TcpSocket::TcpSocket() :
   _s(new QTcpSocket)
{
    connect(_s, &QTcpSocket::connected, this,[]{logger() << "server connected";} );
    connect(this,&TcpSocket::arrived,this, [](QString s){logger() << "data arrived" << s;});
}

void TcpSocket::connectTo(SettingsEntity server)
{
    _s->connectToHost(QHostAddress(server.ip), server.port);
}

void TcpSocket::request(RequestType type)
{
    QByteArray data;
    QDataStream out(&data, QIODevice::ReadWrite);
    out << type;
    _s->write(data);
    connect(_s, &QIODevice::readyRead,[=]
    {
        QDataStream in(_s);
        SettingsEntity e;
        in.startTransaction();
        in >> e.os;
        if (!in.commitTransaction())
            return;
        qDebug() << e.os;
        emit arrived(e.os);
    });
}

void TcpSocket::sendWOL(SettingsEntity target, int timeOut)
{
	// build magic packet
	QByteArray magic;
    for (int i=0;i<6;i++)
    {
        magic.append(static_cast<char>(0xFF));
	}
	for (int i=0;i<16;i++)
	{
		foreach(QString hex, target.mac.split('-'))
        {
            magic.append(static_cast<char>(hex.toInt(nullptr, 16)));
		}
	}
	// use udpSocket to broadcast magic packet
	QUdpSocket udpSocket;
    udpSocket.writeDatagram(magic, QHostAddress::Broadcast, 45454);
    udpSocket.close();
}
