#include <QCoreApplication>
#include <QSettings>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QSettings sets("TOSHIBA","test");
    sets.setValue("key", "value");
    sets.sync();
	return 0;
}

