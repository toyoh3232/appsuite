#include <QtWidgets/QWizard>
#include <QtWidgets/QMessageBox>

#include <QAbstractButton>

#include "TestSettingsWizard.h"

#include "IpSettingsWizardPage.h"
#include "TargetSettingsWizardPage.h"

TestSettingsWizard::TestSettingsWizard(QWidget* parent) : 
    Wizard(parent)
{
    setPage(Page_HostSettings, new IpSettingsWizardPage);
	setPage(Page_TargetSettings, new TargetSettingsWizardPage);
	
    setStartId(Page_TargetSettings);
}

