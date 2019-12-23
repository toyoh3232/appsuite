
#include <QFileInfo>

#include "RunGuard.h"
#include "Logger.h"

RunGuard::RunGuard(QString key) :
    _sharedMem(key)
{

}

RunGuard& RunGuard::instance()
{
    static RunGuard rg(QCoreApplication::applicationName());
    return rg;
}

bool RunGuard::isNewRun()
{
   if(!_sharedMem.create(1))
   {
       logger() << "error";
       return false;
   }
   return true;
}
