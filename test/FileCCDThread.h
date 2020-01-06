#ifndef FILECCDTHREAD_H
#define FILECCDTHREAD_H
#include <QObject>
#include <QThread>
#include <QFileInfo>


enum class FileCCDState {Copying, Comparing, Deleting};
enum class ErrorHandlingPolicy {TerminateInstantly,ContinueAnyway};

class FileCCDThreadWorker : public QObject
{
    Q_OBJECT

public:
    FileCCDThreadWorker(QObject* parent=nullptr);

public slots:
    void doWork(const QString& src, const QString& dest);

signals:
    void errorCaused();
    void started(QString fileName);
    void stateUpdated(FileCCDState state);
public:
    friend class FileCCDThreadController;
private:
    bool _flag;
};

class FileCCDThreadController : public QObject
{
    Q_OBJECT
public:
    FileCCDThreadController(ErrorHandlingPolicy policy);
    ~FileCCDThreadController();
signals:
    void filePrepared(QString fileName);
    void stateUpdated(FileCCDState state);
    void errorCatched();
    void finished();
signals:
    void operate(const QString& src, const QString& dest);

public slots:
    void end();
private:
    QThread _workerThread;
};

Q_DECLARE_METATYPE(FileCCDState)

#endif // FILECCDTHREAD_H
