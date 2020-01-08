#include <QRegExpValidator>
#include <QRegExp>
#include <QMessageBox>

#include "TargetSettingsWizardPage.h"
#include "MultiTargetSettingsWidget.h"
#include "ui_TargetSettingsWizardPage.h"
#include "TcpSocket.h"
#include "Utility.h"
#include "Settings.h"

TargetSettingsWizardPage::TargetSettingsWizardPage(QWidget* parent) :
    WizardPage(parent),
	_ui(new Ui::TargetSettingsWizardPage)
{
	_ui->setupUi(this);
    connect(_ui->pushButton, &QPushButton::clicked, this, [=]
            {
                auto w = new MultiTargetSettingsWidget(this);
                _ui->verticalLayout->addWidget(w);
            });
}

TargetSettingsWizardPage::~TargetSettingsWizardPage()
{
	delete _ui;
}

void TargetSettingsWizardPage::lineEdit_textChanged()
{

}

void TargetSettingsWizardPage::dtButton_clicked()
{


}
