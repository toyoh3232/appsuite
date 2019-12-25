#include <QMessageBox>
#include <QTimer>
#include <QLineEdit>

#include "WizardPage.h"


WizardPage::WizardPage(QWidget *parent) :
    QWizardPage(parent)
{
    QString ipRange = "(?:[0-1]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])";
    QRegExp ipRegex ("^" + ipRange
                    + "\\." + ipRange
                    + "\\." + ipRange
                    + "\\." + ipRange + "$");
    _ipValidator = new QRegExpValidator(ipRegex, this);
}

void WizardPage::error(const QString& title, const QString& msg)
{
    QMessageBox::critical(this, title, msg);
}

void WizardPage::waitingBox(int interval)
{
    QMessageBox *msgBox = new QMessageBox(this);
    msgBox->setWindowTitle(tr("information"));
    msgBox->setIcon(QMessageBox::Information);
    msgBox->setText(tr("please wait for ") + QString("%1 s").arg(interval/1000));
    msgBox->setStandardButtons(QMessageBox::NoButton);
    msgBox->show();
    QTimer::singleShot(3000, msgBox, &QWidget::hide);
}

void WizardPage::setStyle(QWidget *parent, const QString &widgetClassName, const QString &style)
{
    if (widgetClassName == QString("QLineEdit"))
    {
        QList<QLineEdit*> widgets = parent->findChildren<QLineEdit*>();
        foreach(QLineEdit* w, widgets)
        {
            w->setStyleSheet(style);
        }
    }
}

void WizardPage::clearText(QWidget *parent, const QString &widgetClassName)
{
    if (widgetClassName == QString("QLineEdit"))
    {
        QList<QLineEdit*> widgets = parent->findChildren<QLineEdit*>();
        foreach(QLineEdit* w, widgets)
        {
            w->clear();
        }
    }
}

void WizardPage::setHidden(QWidget *parent, bool hidden)
{
    QList<QWidget*> widgets = parent->findChildren<QWidget *>();
    foreach(QWidget* w, widgets)
    {
        w->setHidden(hidden);
    }
    parent->setHidden(hidden);
}
