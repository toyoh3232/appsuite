#include "ErrorHandler.h"

QString ErrorHandler::errorMessage()
{
	return _errMsg;
}

void ErrorHandler::setErrorMessage(QString mainMsg, QString extMsg)
{
	_errMsg = mainMsg + "\n" + extMsg;
}
