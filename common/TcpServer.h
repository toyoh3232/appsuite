#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QString>
#include <QTextStream>

#include "TcpSocket.h"
#include "Settings.h"

class TcpServer : public QObject
{
    Q_OBJECT
public:
    TcpServer(QObject* parent=nullptr);
public:
    void listen(QString ip, quint16 port);

public slots:
    void response();

private:
    QTcpServer* _s;
};

#endif  /*TCPSERVER_H*/
