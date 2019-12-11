#ifndef LOGGER_H
#define LOGGER_H

#include <QIODevice>
#include <QString>

class Logger
{

public:
	Logger(const Logger&) = delete;
    const Logger& operator=(const Logger&) = delete;

private:
	Logger() = default;

public:
	static void setDevice(QIODevice&);
	static void add(const QString& msg);
	
private:
	static Logger* instance();
	
private:
	QIODevice* _device;
};

#endif // LOGGER_H
