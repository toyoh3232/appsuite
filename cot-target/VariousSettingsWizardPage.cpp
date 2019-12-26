#include "VariousSettingsWizardPage.h"
#include "ui_VariousSettingsWizardPage.h"

VariousSettingsWizardPage::VariousSettingsWizardPage(QWidget* parent) :
   WizardPage(parent),
    _ui(new Ui::VariousSettingsWizardPage)
{
    _ui->setupUi(this);
}

VariousSettingsWizardPage::~VariousSettingsWizardPage()
{
    delete _ui;
}
