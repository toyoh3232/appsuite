#ifndef QDHCPSERVER_H
#define QDHCPSERVER_H

#include <QtGlobal>
#include <QObject>
#include <QUdpSocket>
#include <QHostAddress>


class DhcpPacketEntity
{
    enum Opcode
    {
        BootRequest,
        BootReply
    };

    enum HardwareType
    {
        Ethernet,
        ExperimentalEthernet,
        AmateurRadioAX_25
        /*others*/
    };
    typedef struct tag_header
    {
        uchar op;
        uchar htype;
        uchar hlen;
        uchar hops;
    } Header;

public:
    DhcpPacketEntity(DhcpPacketEntity& old);
    DhcpPacketEntity& operator=(const DhcpPacketEntity& old) = delete;
private:
    DhcpPacketEntity();
public:
    void setYourAddres(const QHostAddress& address);
    void setServerAddr(const QHostAddress& address);
    QHostAddress clientAddr();
    QHostAddress yourAddr();
    QHostAddress serverAddr();
    QString clientHardwareAddr();
    uqint8 hardwareAddrLength();

private:
    QHostAddress m_clientaddr;
    QHostAddress m_youraddr;
    QHostAddress m_serveraddr;

};


struct DhcpPacket
{

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
