#ifndef TARGETSETTINGSWIZARDPAGE_H
#define TARGETSETTINGSWIZARDPAGE_H

#include <QWizardPage>
#include <QWidget>

namespace Ui{
	class TargetSettingsWizardPage;
}

class TargetSettingsWizardPage : public QWizardPage
{
	Q_OBJECT

public:
	explicit TargetSettingsWizardPage(QWidget* parent=nullptr);
	~TargetSettingsWizardPage();


public slots:
	void lineEdit_textChanged();
	void dtButton_clicked();


private:
	Ui::TargetSettingsWizardPage* _ui;

};

#endif //TARGETSETTINGSWIZARDPAGE_H