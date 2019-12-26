#include <QApplication>
#include <QMessageBox>

#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    QApplication app(argc, argv);
    MainWindow w;
    w.show();
    return app.exec();
}
