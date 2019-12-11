#ifndef WOLWOLUtility_H
#define WOLWOLUtility_H

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

#endif //WOLWOLUtility_H