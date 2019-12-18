#include <QtWidgets/QWizard>
#include <QtWidgets/QMessageBox>

#include <QAbstractButton>

#include "TestSettingsWizard.h"

#include "HostSettingsWizardPage.h"

TestSettingsWizard::TestSettingsWizard(QWidget* parent) : 
    Wizard(parent)
{
	setPage(Page_HostSettings, new HostSettingsWizardPage);
	
	setStartId(Page_HostSettings);
}


