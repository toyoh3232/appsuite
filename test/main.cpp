#include <QCoreApplication>
#include <QSettings>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QSettings settings("HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Class\\{4d36e972-e325-11ce-bfc1-08002be10318}", QSettings::NativeFormat);
    foreach(auto key , settings.childGroups() )
    {
        qDebug() << key;
        qDebug() << settings.value(key+"/DriverDesc", QSettings::NativeFormat).toString();
        qDebug() << settings.value(key+"/NetLuidIndex", QSettings::NativeFormat).toInt();
    }
    qDebug() << QString("interface_12345").toInt();
	return 0;
}

