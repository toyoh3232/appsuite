#ifndef TESTSETINGSWIZARD_H
#define TESTSETINGSWIZARD_H

#include <QtWidgets/QWizard>
#include "Wizard.h"

class TestSettingsWizard : public Wizard
{
	Q_OBJECT

public:
	enum {Page_HostSettings, Page_TargetSettings};
	
	explicit TestSettingsWizard(QWidget* parent=nullptr);
};


#endif//TESTSETINGSWIZARD_H
