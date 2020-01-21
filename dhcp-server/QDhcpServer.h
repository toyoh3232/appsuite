#ifndef QDHCPSERVER_H
#define QDHCPSERVER_H

#include <QtGlobal>
#include <QObject>
#include <QUdpSocket>
#include <QHostAddress>

struct DhcpPacket
{
    uchar op;
    uchar htype;
    uchar hlen;
    uchar hops;
    uchar xid[4];
    uchar secs[2];
    uchar flags[2];
    uchar ciaddr[4];
    uchar yiaddr[4];
    uchar siaddr[4];
    uchar giaddr[4];
    uchar chaddr[16];
    uchar sname[64];
    uchar file[128];
    uchar options[312];
};

class QDhcpServer : public QObject
{
public:
    QDhcpServer(QObject* parent=nullptr);
    ~QDhcpServer();

public:
    bool bind(const QHostAddress& address);
    void listen();

private:
    QUdpSocket* socket;
};

#endif // QDHCPSERVER_H
