#ifndef SETTINGS_H
#define SETTINGS_H

#include <QString>
#include <QDataStream>
#include <QSettings>
#include <QVariant>
#include <QStringList>

enum class RequestType : qint16
{
    ASK_INFOMATION
};

QDataStream& operator<< (QDataStream& stream, RequestType type);
QDataStream& operator>> (QDataStream& stream, RequestType& type);


class SettingsEntity
{
public:
    SettingsEntity();
private:
    QVariantMap _maps;

public:
    QStringList allKeys() const;
    void update(SettingsEntity& se);
    // setter
    QVariant& operator[](const QString& key);
    // getter
    const QVariant operator[](const QString& key) const;
    friend class Settings;
    friend QDataStream& operator<< (QDataStream& stream, SettingsEntity& se);
    friend QDataStream& operator>> (QDataStream& stream, SettingsEntity& se);

};

QDataStream& operator<< (QDataStream& stream, SettingsEntity& se);
QDataStream& operator>> (QDataStream& stream, SettingsEntity& se);

class Settings
{

private:
    Settings() = default;
    Settings(Settings&) = delete;
    Settings& operator=(Settings&) = delete;

public:
    static Settings& instance();
    SettingsEntity& entity();
    void save();
    void load();

private:
    SettingsEntity _se;
};

#endif // SETTINGS_H
