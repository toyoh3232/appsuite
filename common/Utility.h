#ifndef Utility_H
#define Utility_H

#include <QString>
#include <QTextStream>

class Utility
{
public:
	static int execCommand(const QString cmd);
	static QString execCommandWithOutput(const QString cmd);
	static bool isReachable(QString ip);
	static QString searchArp(QString ip);

public:
	Utility() = delete;
};

#endif //Utility_H
