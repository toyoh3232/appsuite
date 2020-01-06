#include <QDir>
#include <QCryptographicHash>
#include "FileCCDThread.h"

FileCCDThreadWorker::FileCCDThreadWorker(QObject *parent) :
    QObject(parent),
    _flag(false)
{

}

void FileCCDThreadWorker::doWork(const QString& src, const QString& dest)
{
    QDir dir1(src);
    QDir dir2(dest);
    foreach(QFileInfo file1Info, dir1.entryInfoList(QDir::Files))
    {
        if (QThread::currentThread()->isInterruptionRequested())
            return;
        QFileInfo file2Info(dir2.absoluteFilePath(file1Info.fileName()));

        emit started(file1Info.fileName());
        QThread::sleep(1);
        //start copying
        emit stateUpdated(FileCCDState::Copying);
        if (!QFile::copy(file1Info.absoluteFilePath(),file2Info.absoluteFilePath()))
        {
            emit errorCaused();
            if (_flag == true)
                break;
            else
                continue;
        }
        QThread::sleep(1);
        //start comparing
        emit stateUpdated(FileCCDState::Comparing);
        QFile file1(file1Info.absoluteFilePath());
        QFile file2(file2Info.absoluteFilePath());
        if (!file1.open(QIODevice::ReadOnly) || !file2.open(QIODevice::ReadOnly))
        {
            emit errorCaused();
            if (_flag == true)
                break;
            else
                continue;
        }
        auto hash1 = QString(QCryptographicHash::hash(file1.readAll(), QCryptographicHash::Md5).toHex());
        auto hash2 = QString(QCryptographicHash::hash(file2.readAll(), QCryptographicHash::Md5).toHex());
        file1.close();
        file2.close();
        if (hash1 != hash2)
        {
            emit errorCaused();
            if (_flag == true)
                break;
            else
                continue;
        }
        QThread::sleep(1);
        //start deleting
        emit stateUpdated(FileCCDState::Deleting);
        if (!QFile::remove(file2Info.absoluteFilePath()))
        {
            emit errorCaused();
            if (_flag == true)
                break;
            else
                continue;
        }
    }
}

FileCCDThreadController::FileCCDThreadController(ErrorHandlingPolicy policy)
{
    qRegisterMetaType<FileCCDState>("FileCCDState");
    FileCCDThreadWorker *worker = new FileCCDThreadWorker;
    if(policy == ErrorHandlingPolicy::TerminateInstantly)
        worker->_flag = true;
    worker->moveToThread(&_workerThread);
    connect(&_workerThread, &QThread::finished, worker, &QObject::deleteLater);
    connect(&_workerThread, &QThread::finished, this, &FileCCDThreadController::finished);
    connect(this, &FileCCDThreadController::operate, worker, &FileCCDThreadWorker::doWork);
    connect(worker, &FileCCDThreadWorker::stateUpdated, this, &FileCCDThreadController::stateUpdated);
    connect(worker, &FileCCDThreadWorker::errorCaused, this, &FileCCDThreadController::errorCatched);
    connect(worker, &FileCCDThreadWorker::started, this, &FileCCDThreadController::filePrepared);
    _workerThread.start();
}


FileCCDThreadController::~FileCCDThreadController()
{
    _workerThread.quit();
    _workerThread.wait();
}

void FileCCDThreadController::end()
{
    _workerThread.requestInterruption();
}
