#include <QApplication>
#include <QTranslator>
#include <QLocale>

#include "RunGuard.h"
#include "MainWindow.h"

int main(int argc, char *argv[])
{

    QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    QApplication app(argc, argv);
	QTranslator translator;
	if (translator.load(QLocale(), QString(""), QString(""), QLatin1String(":/translations")))
        app.installTranslator(&translator);
	MainWindow w;
	w.show();
    return app.exec();
}


