#include <QCoreApplication>
#include <QDebug>
#include "TcpServer.h"
#include "TcpSocket.h"
#include "NetworkInterface.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    SettingsEntity se;
    se.ip = "133.113.87.48";
    se.port = 20000;
    NetworkInterface::disableFirewall();
    if (argc > 2)
    {
        qDebug() << "Server";
        TcpServer server;
        server.listen(se);
        return a.exec();

    }
    else
    {
        qDebug() << "Client";
        TcpSocket socket;
        socket.connectTo(se);
        socket.request(RequestType::ASK_INFOMATION);
        return a.exec();
    }


}
