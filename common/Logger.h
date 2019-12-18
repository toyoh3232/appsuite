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
    static void setDevice(QIODevice*);
	static void add(const QString& msg);

public:
    Logger& operator<< (QString msg);
	
private:
    static Logger& instance();
    friend Logger& logger();
private:
	QIODevice* _device;
};

Logger& logger();

#endif // LOGGER_H
