#include <QtGlobal>
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
    if (instance()._device != nullptr)
        instance()._device->write(qUtf8Printable(msg));
    else
        qDebug() << qUtf8Printable(msg);
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

Logger& logger()
{
    return Logger::instance();
}
