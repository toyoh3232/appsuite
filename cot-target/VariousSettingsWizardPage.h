#ifndef VARIOUSSETTINGSWIZARDPAGE_H
#define VARIOUSSETTINGSWIZARDPAGE_H

#include "WizardPage.h"

namespace Ui {
class VariousSettingsWizardPage;
}

class VariousSettingsWizardPage : WizardPage
{
    Q_OBJECT
public:
    VariousSettingsWizardPage(QWidget* parent=nullptr);
    ~VariousSettingsWizardPage() override;

private:
    Ui::VariousSettingsWizardPage* _ui;
};

#endif // VARIOUSSETTINGSWIZARDPAGE_H
