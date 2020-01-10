#ifndef QDHCPSERVER_H
#define QDHCPSERVER_H

#include <QtGlobal>

struct DhcpPacket
{
    quint8 op;
    quint8 htype;
    quint8 hlen;
    quint8 hops;
    quint8 xid[4];
    quint8 secs[2];
    quint8 _unused1[2];
    quint8 ciaddr[4];
    quint8 yiaddr[4];
    quint8 siaddr[4];
    quint8 giaddr[4];
    quint8 chaddr[16];





};

class QDhcpServer
{
public:
    QDhcpServer();
};

#endif // QDHCPSERVER_H
