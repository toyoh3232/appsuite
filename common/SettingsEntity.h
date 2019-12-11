#ifndef SETTINGSENTITY_H
#define SETTINGSENTITY_H
#include <QString>

enum class ExperimentType {FULLY_EQUIPPED_RUNNING, ONOFF_LOOP_TEST};

struct SettingsEntity
{
	
	ExperimentType _type;
	QString ip;
	QString mac;
	QString os;
    quint16     port;
	bool isWOLPowerOn;
};

#endif // SETTINGSENTITY_H
