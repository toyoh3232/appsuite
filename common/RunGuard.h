#ifndef RUNNINGGUARD_H
#define RUNNINGGUARD_H

#include <QSharedMemory>
#include <QMessageBox>
#include <QCoreApplication>

class RunGuard
{

private:
    RunGuard(QString key);

public:
    static RunGuard& instance();
    bool isNewRun();

private:
    QSharedMemory _sharedMem;

};

#endif // RUNNINGGUARD_H
