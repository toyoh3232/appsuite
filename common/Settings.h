#ifndef SETTINGS_H
#define SETTINGS_H

#include <QString>
#include <QDataStream>
#include <QSettings>

enum class RequestType : qint16
{
    ASK_INFOMATION
};

QDataStream& operator<< (QDataStream& stream, RequestType type);
QDataStream& operator>> (QDataStream& stream, RequestType& type);

enum class ExperimentType
{
    FULLY_EQUIPPED_RUNNING,
    ONOFF_LOOP_TEST
};

struct SettingsEntity
{
	
	ExperimentType _type;
	QString ip;
	QString mac;
	QString os;
    quint16     port;
	bool isWOLPowerOn;
};

class Settings
{

public:
    Settings();
public:
    static Settings& instance();
    bool isNew();
    void save(SettingsEntity se);

private:
    QSettings _sets;
};

#endif // SETTINGS_H
