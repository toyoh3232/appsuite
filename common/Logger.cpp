#include <QtGlobal>
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
}

Logger& Logger::operator<<(QString msg)
{
    add(msg);
    return *this;
}

Logger& logger()
{
    return Logger::instance();
}
