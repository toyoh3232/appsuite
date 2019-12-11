#include <QtWidgets/QWizard>
#include <QtWidgets/QMessageBox>

#include <QAbstractButton>

#include "TestSettingsWizard.h"
#include "ui_TestSettingsWizard.h"

#include "HostSettingsWizardPage.h"
#include "TargetSettingsWizardPage.h"

TestSettingsWizard::TestSettingsWizard(QWidget* parent) : 
	QWizard(parent),
	_ui(new Ui::TestSettingsWizard)
{
	_ui->setupUi(this);
	setButtonText( QWizard::CancelButton, tr("Cancel"));
	setButtonText( QWizard::BackButton, tr("Back") );
	setButtonText( QWizard::NextButton, tr("Next") );
	setButtonText( QWizard::FinishButton, tr("Finish"));

	setWindowFlags(windowFlags()); 
	setPage(Page_HostSettings, new HostSettingsWizardPage);
	setPage(Page_TargetSettings, new TargetSettingsWizardPage);
	
	setStartId(Page_HostSettings);
}

