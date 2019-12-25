#ifndef WIZARDPAGE_H
#define WIZARDPAGE_H

#include <QWizardPage>
#include <QRegExpValidator>

#define OLDSTYLE "background-color: rgb(240, 240, 240);"
#define NEWSTYLE "background-color: rgb(240, 240, 240); color: rgb(255, 0, 0);"

class WizardPage : public QWizardPage
{
	Q_OBJECT
public:
    WizardPage(QWidget* parent = nullptr);

protected:
    QRegExpValidator* _ipValidator;

protected:
    void error(const QString& title, const QString& msg);
    void waitingBox(int interval);
    void setStyle(QWidget* parent,  const QString& widgetClassName, const QString& style);
    void clearText(QWidget* parent, const QString& widgetClassName);
    void setHidden(QWidget* parent, bool hidden);
};

#endif // WIZARDPAGE_H
