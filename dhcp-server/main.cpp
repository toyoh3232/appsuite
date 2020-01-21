#include <QCoreApplication>
#include <QtDebug>
#include "QDhcpServer.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QDhcpServer server;
    qDebug() << server.bind(QHostAddress("127.0.0.1"));
    server.listen();
    return a.exec();
}
