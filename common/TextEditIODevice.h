#ifndef TEXTEDITIODEVICE_H
#define TEXTEDITIODEVICE_H

#include <QIODevice>
#include <QTextEdit>
#include <QPointer>


class TextEditIODevice : public QIODevice 
{
    Q_OBJECT

public:
    TextEditIODevice(QTextEdit* textEdit, QObject* parent);
	
protected:
    qint64 readData(char *data, qint64 maxSize) override;
    qint64 writeData(const char *data, qint64 maxSize) override;
private:
    QPointer<QTextEdit> _textEdit;
};

#endif // TEXTEDITIODEVICE_H
