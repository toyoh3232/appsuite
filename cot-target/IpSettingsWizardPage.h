#ifndef IPSETTINGSWIZARDPAGE_H
#define IPSETTINGSWIZARDPAGE_H

#include "WizardPage.h"
#include "NetworkInterface.h"

namespace Ui {
    class IpSettingsWizardPage;
}

class IpSettingsWizardPage : public WizardPage
{
	Q_OBJECT

public:
    explicit IpSettingsWizardPage(QWidget *parent = nullptr);
    ~IpSettingsWizardPage() override;
	
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
    Ui::IpSettingsWizardPage* _ui;
	
};
#endif//IPSETTINGSWIZARDPAGE_H
