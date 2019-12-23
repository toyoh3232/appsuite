#include <QApplication>
#include <QTranslator>
#include <QLocale>
#include <QMessageBox>

#include "MainWindow.h"
#include "RunGuard.h"

int main(int argc, char *argv[])
{
	QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    QApplication app(argc, argv);
	QTranslator translator;
	if (translator.load(QLocale(), QString(""), QString(""), QLatin1String(":/translations")))
        app.installTranslator(&translator);
    if (!RunGuard::instance().isNewRun())
    {
        QMessageBox::critical(nullptr, "", QApplication::tr("Another instance is arealy running!"));
        return 0;
    }
	MainWindow w;
	w.show();
    return app.exec();
}
