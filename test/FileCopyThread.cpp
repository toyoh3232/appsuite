#include <QDir>
#include "FileCopyThread.h"

void FileCopyThreadWorker::doWork(const QString& start, const QString& dest)
{
    QDir dir_o(start);
    QDir dir_n(dest);
    foreach(auto& file, dir_o.entryInfoList(QDir::Files))
    {
    emit resultReady(QString("copy %1 from %2 to %3").arg(file.fileName()).arg(start).arg(dest));
    QFile::copy(file.absoluteFilePath(),dir_n.absoluteFilePath(file.fileName()));
    QThread::sleep(1);

    }

}

FileCopyThreadController::FileCopyThreadController()
{
    FileCopyThreadWorker *worker = new FileCopyThreadWorker;
    worker->moveToThread(&_workerThread);
    connect(&_workerThread, &QThread::finished, worker, &QObject::deleteLater);
    connect(this, &FileCopyThreadController::operate, worker, &FileCopyThreadWorker::doWork);
    connect(worker, &FileCopyThreadWorker::resultReady, this, &FileCopyThreadController::copyStarted);
    _workerThread.start();
}

FileCopyThreadController::~FileCopyThreadController()
{
    _workerThread.quit();
    _workerThread.wait();
}
