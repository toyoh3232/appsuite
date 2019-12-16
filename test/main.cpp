#include <QCoreApplication>
#include <QDebug>
#include "TcpServer.h"
#include "TcpSocket.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    SettingsEntity se;
    se.ip = "127.0.0.1";
    se.port = 20000;
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
        se = socket.request(RequestType::ASK_INFOMATION);
        qDebug() << se.os;
        return 0;
    }


}
