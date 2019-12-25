#include <QtWidgets/QWizard>
#include <QtWidgets/QMessageBox>

#include <QAbstractButton>

#include "TestSettingsWizard.h"

#include "IpSettingsWizardPage.h"

TestSettingsWizard::TestSettingsWizard(QWidget* parent) : 
    Wizard(parent)
{
    setPage(Page_HostSettings, new IpSettingsWizardPage);
	
	setStartId(Page_HostSettings);
}


