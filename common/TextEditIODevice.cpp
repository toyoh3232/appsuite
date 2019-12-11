#include "TextEditIODevice.h"

TextEditIODevice:: TextEditIODevice(QTextEdit* textEdit, QObject* parent) :
	QIODevice(parent),
	_textEdit(textEdit)
{
	open(QIODevice::WriteOnly|QIODevice::Text);

}

qint64 TextEditIODevice::readData(char *data, qint64 maxSize)
{
	if (data != nullptr && maxSize > 0 )
		return 0; 
	return -1;
}

qint64 TextEditIODevice::writeData(const char *data, qint64 maxSize)
{
    if(_textEdit != nullptr)
    {
		_textEdit->append(data);
    }
    return maxSize;
}