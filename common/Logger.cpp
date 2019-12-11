#include <QtConcurrentRun>
#include <QtGlobal>
#include "Logger.h"

static void write(QIODevice* device, const QString msg)
{
	device->write(qUtf8Printable(msg));
}

Logger* Logger::instance()
{
	static Logger logger;
	return &logger;
}

void Logger::setDevice(QIODevice& device)
{
	instance()->_device = &device;
}

void Logger::add(const QString& msg)
{
	if (instance()->_device != nullptr)
		QFuture<void> future = QtConcurrent::run(write, instance()->_device, msg);
}
