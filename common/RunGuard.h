#ifndef RUNNINGGUARD_H
#define RUNNINGGUARD_H

#include <QObject>
#include <QSharedMemory>

class RunGuard : public QObject
{
    Q_OBJECT
private:
    RunGuard(QString key);

public:
    static RunGuard* instance();
    void run();
    QString msg();

signals:
    void recreated(QString errMsg);

private:
    QSharedMemory _sharedMem;


};

#endif // RUNNINGGUARD_H
