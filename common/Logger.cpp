#include <QtGlobal>
#include <QDateTime>
#include <QDebug>

#include "Logger.h"

Logger& Logger::instance()
{
	static Logger logger;
    return logger;
}

void Logger::setDevice(QIODevice* device)
{
    instance()._device = device;
}

void Logger::add(const QString& msg)
{
    auto dt = QDateTime::currentDateTime();
    QString nmsg = QString("%1: %2").arg(dt.toString(Qt::SystemLocaleDate)).arg(msg);
    if (instance()._device != nullptr)
        instance()._device->write(qUtf8Printable(nmsg));
    else
        qDebug() << qUtf8Printable(nmsg);
}

Logger& Logger::operator<<(QString msg)
{
    add(msg);
    return *this;
}

Logger& Logger::operator<<(const char* c)
{
    (*this) << QString(c);
    return *this;
}


Logger& Logger::operator<<(bool b)
{
    if(b)
        (*this) << QString("true");
    else
        (*this) << QString("false");
    return *this;
}

Logger &Logger::operator<<(int i)
{
    (*this) << QString("%1").arg(i);
    return *this;
}

Logger& logger()
{
    return Logger::instance();
}
