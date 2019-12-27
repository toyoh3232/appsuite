#ifndef FILECOPYTHREAD_H
#define FILECOPYTHREAD_H
#include <QObject>
#include <QThread>


class FileCopyThreadWorker : public QObject
{
    Q_OBJECT

public slots:
    void doWork(const QString& src, const QString& dest);

signals:
    void startt(const QString &result);
};

class FileCopyThreadController : public QObject
{
    Q_OBJECT
public:
    FileCopyThreadController();
    ~FileCopyThreadController();
signals:
    void started(const QString &result);
    void operate(const QString& src, const QString& dest);
private:
    QThread _workerThread;
};

#endif // FILECOPYTHREAD_H
