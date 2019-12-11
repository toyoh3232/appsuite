#ifndef TESTSETINGSWIZARD_H
#define TESTSETINGSWIZARD_H

#include <QtWidgets/QWizard>

namespace Ui {
	class TestSettingsWizard;
}

class TestSettingsWizard : public QWizard
{
	Q_OBJECT

public:
	enum {Page_HostSettings, Page_TargetSettings};
	
	explicit TestSettingsWizard(QWidget* parent=nullptr);
	
private:
	Ui::TestSettingsWizard* _ui;
};


#endif//TESTSETINGSWIZARD_H