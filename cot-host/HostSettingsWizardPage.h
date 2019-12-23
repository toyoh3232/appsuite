#ifndef ONOFFSETTINGWIZARD_H
#define ONOFFSETTINGWIZARD_H

#include <QWizardPage>
#include "NetworkInterface.h"

namespace Ui {
	class HostSettingsWizardPage;
}

class HostSettingsWizardPage : public QWizardPage
{
	Q_OBJECT

public:
	explicit HostSettingsWizardPage(QWidget *parent = nullptr);
    ~HostSettingsWizardPage() override;
	
public slots:
	void lockButton_click();
	void lineEdit_textChanged();
	void setButton_click();
	void fillButton_click();

protected:
    void initializePage() override;
	void cleanupPage() override;
	bool isComplete() const override;

private:
	void setHidden(QWidget* parent,bool hidden);
	void clearText(QWidget* parent, QString widgetClassName);
	void setStyle(QWidget* parent, QString widgetClassName, QString style);
	
private:
	Ui::HostSettingsWizardPage* _ui;
	
};
#endif//ONOFFSETTINGWIZARD_H
