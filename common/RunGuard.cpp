#include <QCoreApplication>
#include <QFileInfo>

#include "RunGuard.h"
#include "Logger.h"

RunGuard::RunGuard(QString key) :
    _sharedMem(key)
{

}

RunGuard* RunGuard::instance()
{
    static RunGuard rg(QFileInfo(QCoreApplication::applicationFilePath()).fileName());
    return &rg;
}

void RunGuard::run()
{
   if(!_sharedMem.create(1))
   {
       logger() << "error";
       emit recreated(tr("Another program instance is already running!"));
   }
}
