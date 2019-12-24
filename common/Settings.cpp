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

QDataStream& operator<< (QDataStream& stream, SettingsEntity& se)
{
    return stream << se._maps;
}

QDataStream& operator>> (QDataStream& stream, SettingsEntity& se)
{
    return stream >> se._maps;
}

SettingsEntity::SettingsEntity()
{

}

Settings& Settings::instance()
{
    static Settings s;

    return s;
}

void Settings::save()
{
    QSettings set("Toshiba", QCoreApplication::applicationName());
    auto keys = _se._maps.keys();
    foreach(auto key, keys)
    {
        set.setValue(key, _se._maps[key]);
    }
}

void Settings::load()
{
    QSettings set("Toshiba", QCoreApplication::applicationName());
    foreach(auto key, set.allKeys())
    {
        _se._maps.insert(key, set.value(key, QVariant()));
    }
}

QStringList SettingsEntity::allKeys() const
{
    return _maps.keys();
}

void SettingsEntity::update(SettingsEntity& se)
{
    foreach(auto& key, se.allKeys())
    {
        _maps[key] = se[key];
    }
}

QVariant& SettingsEntity::operator[](const QString& key)
{
    return _maps[key];
}

const QVariant SettingsEntity::operator[](const QString& key) const
{
    return _maps[key];
}

SettingsEntity& Settings::entity()
{
    return  _se;
}
