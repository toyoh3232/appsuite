#include <QByteArray>
#include <QUdpSocket>
#include <QDataStream>
#include "Logger.h"
#include "Settings.h"

#include "TcpSocket.h"

TcpSocket::TcpSocket() :
   _s(new QTcpSocket)
{
    connect(_s, &QTcpSocket::connected, this,[]{logger() << "server connected";} );
    connect(this,&TcpSocket::arrived,this, []{logger() << "data arrived";});
}

void TcpSocket::connectTo(QString ip, quint16 port)
{
    logger() << "connect to";
    _s->connectToHost(QHostAddress(ip), port);
}

void TcpSocket::request(RequestType type)
{
    QByteArray data;
    QDataStream out(&data, QIODevice::ReadWrite);
    out << type;
    _s->write(data);
    connect(_s, &QIODevice::readyRead,[=]
    {
                logger() << "readyRead";
        QDataStream in(_s);
        SettingsEntity se;
        in.startTransaction();
        in >> se;
        if (!in.commitTransaction())
            return;
        logger() << se["hostOS"].toString();
        Settings::instance().entity().update(se);
        emit arrived();
    });
}

void TcpSocket::sendWOL(QString mac, int timeOut)
{
	// build magic packet
	QByteArray magic;
    for (int i=0;i<6;i++)
    {
        magic.append(static_cast<char>(0xFF));
	}
	for (int i=0;i<16;i++)
	{
        foreach(QString hex, mac.split('-'))
        {
            magic.append(static_cast<char>(hex.toInt(nullptr, 16)));
		}
	}
	// use udpSocket to broadcast magic packet
	QUdpSocket udpSocket;
    udpSocket.writeDatagram(magic, QHostAddress::Broadcast, 45454);
    udpSocket.close();
}
