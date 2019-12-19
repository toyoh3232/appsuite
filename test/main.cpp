#include <QCoreApplication>
#include <QDebug>
#include <QTextStream>
#include <QDir>
#include <QLockFile>

#include "TcpServer.h"
#include "TcpSocket.h"
#include "NetworkInterface.h"
#include "RunGuard.h"
#include "Logger.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    RunGuard::instance()->run();
    SettingsEntity se;
    se.ip = "133.113.87.48";
    se.port = 20000;
    NetworkInterface::disableFirewall();
    if (argc > 2)
    {
        logger() << "Server";
        TcpServer server;
        server.listen(se);
        return a.exec();

    }
    else
    {
        logger() << "Client";
        TcpSocket socket;
        socket.connectTo(se);
        socket.request(RequestType::ASK_INFOMATION);
        return a.exec();
    }


}

