#include <QCoreApplication>
#include <QSettings>
#include <QDebug>
#include <QDataStream>
#include <QFile>

#include "TcpServer.h"
#include "TcpSocket.h"
#include "Settings.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    if (argc > 2)
    {
        TcpServer s;
        s.listen("127.0.0.1", 20000);
        return app.exec();
    }
}

