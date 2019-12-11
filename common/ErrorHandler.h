#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

#include <QString>

class ErrorHandler 
{
public:
	virtual ~ErrorHandler() = default;
	QString errorMessage();
	virtual QString errorModuleName() = 0;
	
protected:
	void setErrorMessage(QString mainMsg, QString extMsg);

private:
	QString _errMsg;
};


#endif //ERRORHANDLER_H