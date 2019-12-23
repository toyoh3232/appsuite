#include <QCoreApplication>

#include "Settings.h"

QDataStream& operator<< (QDataStream& stream, RequestType type)
{
    return stream << static_cast<qint16>(type);
}

QDataStream& operator>> (QDataStream& stream, RequestType& type)
{
    qint16 v;
    stream >> v;
    type = static_cast<RequestType>(v);
    return stream;
}


Settings::Settings():
    _sets("Toshiba", QCoreApplication::applicationName())
{

}

Settings& Settings::instance()
{
    static Settings s;
    return s;
}

bool Settings::isNew()
{
    if (_sets.value("isNew",QVariant(false)).toBool() == false)
        return true;
    return false;
}
void Settings::save(SettingsEntity se)
{
    _sets.setValue("isNew", true);
    _sets.setValue("clientIP",se.ip);
    _sets.setValue("ClientPort", se.port);
    _sets.sync();
}
