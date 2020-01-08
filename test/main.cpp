#include <QApplication>
#include <QMessageBox>

#include "MainWindow2.h"

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    QApplication app(argc, argv);
    MainWindow2 w;
    w.show();
    return app.exec();
}
