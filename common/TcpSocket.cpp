#include <QByteArray>
#include <QUdpSocket>
#include <QDataStream>

#include "TcpSocket.h"

TcpSocket::TcpSocket() :
    QTcpSocket()
{

}

void TcpSocket::connectTo(SettingsEntity server)
{
    connectToHost(QHostAddress(server.ip), server.port);

}

void TcpSocket::request(RequestType type)
{
    QByteArray data;
    QDataStream out(&data, QIODevice::ReadWrite);
    out << type;
    this->write(data);
    connect(this, &QIODevice::readyRead,[&]
    {
        QDataStream in(this);
        QString os;
        in.startTransaction();
        in >> os;
        if (!in.commitTransaction())
            return;
        qDebug() << os;
    });
}

TcpSocket* TcpSocket::sendWOL(SettingsEntity target, int timeOut)
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
    auto socket = new TcpSocket;
    socket->connectTo(target);
    socket->waitForConnected(timeOut*1000);
    return socket;
}
