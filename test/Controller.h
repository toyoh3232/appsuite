#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QObject>
#include <QThread>


class Worker : public QObject
{
    Q_OBJECT

public slots:
    void doWork(const QString& start, const QString& dest);

signals:
    void resultReady(const QString &result);
};

class Controller : public QObject
{
    Q_OBJECT
    QThread workerThread;
public:
    Controller();
    ~Controller();
signals:
    void resultReady(const QString &result);
    void operate(const QString&, const QString&);
};

#endif // CONTROLLER_H
