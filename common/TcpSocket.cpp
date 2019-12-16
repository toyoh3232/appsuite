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

SettingsEntity TcpSocket::request(RequestType type)
{
    QByteArray array;
    QDataStream stream(this);
    SettingsEntity se;
    switch (type)
    {
    case  ASK_INFOMATION:
        stream << QString("Hello");
        waitForReadyRead(-1);
        break;
    }
    return se;
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
