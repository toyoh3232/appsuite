#include <QDir>
#include "Controller.h"

void Worker::doWork(const QString& start, const QString& dest)
{
    QDir dir_o(start);
    QDir dir_n(dest);
    foreach(auto& file, dir_o.entryInfoList(QDir::Files))
    {
//      QFile::copy(file.absoluteFilePath(),dir_n.absoluteFilePath(file.fileName()));
        QThread::sleep(1);
        emit resultReady(QString("copy %1 from %2 to %3").arg(file.fileName()).arg(start).arg(dest));
    }

}

Controller::Controller()
{
    Worker *worker = new Worker;
    worker->moveToThread(&workerThread);
    connect(&workerThread, &QThread::finished, worker, &QObject::deleteLater);
    connect(this, &Controller::operate, worker, &Worker::doWork);
    connect(worker, &Worker::resultReady, this, &Controller::resultReady);
    workerThread.start();
}

Controller::~Controller()
{
    workerThread.quit();
    workerThread.wait();
}
