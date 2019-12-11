#include <QProcess>
#include <QRegularExpression> 

#include "Utility.h"

int Utility::execCommand(const QString cmd)
{
	QProcess* process = new QProcess();
	process->start(cmd);
	process->waitForFinished();
	return process->exitCode();
}

QString Utility::execCommandWithOutput(const QString cmd)
{
	QProcess* process = new QProcess();
	process->start(cmd);
	process->waitForFinished();
	if (process->exitCode() > 0)
		return QString();
	return QString(process->readAllStandardOutput());
	
}

bool Utility::isReachable(QString ip)
{
	auto output = Utility::execCommandWithOutput(QString("ping -n 1 -w 1000 %1").arg(ip));
	if (output.contains("TTL="))
		return true;
	else 
		return 0;
}

QString Utility::searchArp(QString ip)
{
	QString mac;
	if (isReachable(ip))
	{
		auto result = Utility::execCommandWithOutput(QString("arp -a %1").arg(ip));
		QRegularExpression rx("([0-9a-fA-F][0-9a-fA-F]-){5}([0-9a-fA-F][0-9a-fA-F])");
		QRegularExpressionMatchIterator rxIterator = rx.globalMatch(result);
		if (rxIterator.hasNext())
		{
			QRegularExpressionMatch match = rxIterator.next();
			if (match.hasMatch())
			{
			 mac = match.captured(0);
			}
		}
	}
	return mac;
}


