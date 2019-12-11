#include <QtNetwork>
#include <QList>

#include "NetworkInterface.h"
#include "Utility.h"
#include "Logger.h"

NetworkInterface::NetworkInterface(QNetworkInterface& qinterface) : 
	ErrorHandler(),
	_interface(qinterface)
{
	/*no need to implement*/
}


QString NetworkInterface::errorModuleName()
{
	return "NetworkInterface";
}

QList<NetworkInterface> NetworkInterface::allActiveInterfaces()
{
	Logger::add("start getting nic info...\n");
	QList<NetworkInterface> qlist;
	int n = 0;
	foreach(QNetworkInterface netInterface, QNetworkInterface::allInterfaces())
	{
		Logger::add(QString("scanning number %1 nic...").arg(n));
		if (!(netInterface.flags() & QNetworkInterface::IsLoopBack) && netInterface.flags() & QNetworkInterface::IsUp)
		{
			
			qlist.append(NetworkInterface(netInterface));
			Logger::add("active");
		}
		Logger::add("\n");
		n++;
	}
	return qlist;
}

ErrorHandler* NetworkInterface::setIpv4Property(const QString ip, const QString netmask, const QString gateway)
{
	QString cmd_ip = QString("netsh interface ip set address \"%1\" static %2 %3 %4")
	                        .arg(_interface.humanReadableName(), ip, netmask, gateway);
	QString cmd_dl ="netsh interface ip delete address \"%1\" addr=%2";
	// if multiple nics, delete others' ip settings that already has the same ip 
	foreach(QNetworkInterface netInterface, QNetworkInterface::allInterfaces())
	{     
		if (_interface.humanReadableName() != netInterface.humanReadableName())
		{
			foreach(QNetworkAddressEntry addressEntry, netInterface.addressEntries())
			{
				if (addressEntry.ip().toString() == ip)
				{
					if (Utility::execCommand(cmd_dl.arg(netInterface.humanReadableName(), ip)))
					{
						setErrorMessage("remote process calling failed", cmd_dl.arg(netInterface.humanReadableName(), ip));
						return this;
					}
				}
			}
		}
	}
	if (Utility::execCommand(cmd_ip))
	{
		setErrorMessage("remote process calling failed", cmd_ip);
		return this;
	}
	reflesh();
	return nullptr;
}

QString NetworkInterface::ipv4Addr() const 
{
	QString ip;
	foreach(QNetworkAddressEntry addressEntry, _interface.addressEntries())
	{
		if (addressEntry.ip().protocol() == QAbstractSocket::IPv4Protocol)
			ip = addressEntry.ip().toString();
	}
	return ip;
	
}
	
QString NetworkInterface::macAddr() const
{
	return _interface.hardwareAddress();
}

QString NetworkInterface::name() const
{
	return _interface.humanReadableName();
}

QString NetworkInterface::netmask() const
{
	QString mask;
	foreach(QNetworkAddressEntry addressEntry, _interface.addressEntries())
	{
		if (addressEntry.ip().protocol() == QAbstractSocket::IPv4Protocol)
			mask = addressEntry.netmask().toString();
	}
	return mask;
}

ErrorHandler* NetworkInterface::setWOLPowerReady()
{
	QString ps_power = QString("Set-NetAdapterPowerManagement -Name \"%1\" -WakeOnPattern Enabled").arg(_interface.humanReadableName());
	QString ps_magic = QString("Set-NetAdapterPowerManagement -Name \"%1\" -WakeOnMagicPacket Enabled").arg(_interface.humanReadableName());
	QString cmd_ps1 = QString("PowerShell.exe -Command {%1}").arg(ps_power);
	QString cmd_ps2 = QString("PowerShell.exe -Command {%1}").arg(ps_magic);
	if (Utility::execCommand(cmd_ps1))
	{
		setErrorMessage("remote process calling failed",ps_power);
		return this;
	}
	if (Utility::execCommand(cmd_ps2))
	{
		setErrorMessage("remote process calling failed",ps_magic);
		return this;
	}
	reflesh();
	return nullptr;
}

void NetworkInterface::reflesh()
{
	foreach(auto netInterface, QNetworkInterface::allInterfaces())
	{
		if (netInterface.humanReadableName() == _interface.humanReadableName())
			_interface = netInterface;
	}
}



