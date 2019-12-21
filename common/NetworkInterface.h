#ifndef NETWORKINTERFACE_H
#define NETWORKINTERFACE_H

#include <QNetworkInterface>
#include <QString>

#include "ErrorHandler.h"

class NetworkInterface : public ErrorHandler
{
	
private:
	explicit NetworkInterface(QNetworkInterface& qinterface);
	
public:
	~NetworkInterface() override = default;

public:
	ErrorHandler* setIpv4Property(const QString ip, const QString netmask, const QString gateway="none");
	QString ipv4Addr() const;
	QString macAddr() const;
	QString netmask() const;
	QString name() const;
    QString deviceName() const;
	ErrorHandler* setWOLPowerReady();

public: 
	QString errorModuleName() override;

public:
	static QList<NetworkInterface> allActiveInterfaces();
    static void disableFirewall();

private:
	void reflesh();
    void setDeviceName();
	
private:
    QNetworkInterface _interface;
private:
    QString _deviceName;
};


#endif  /*NETWORKINTERFACE_H*/
