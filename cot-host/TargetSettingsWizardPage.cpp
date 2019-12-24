#include <QRegExpValidator>
#include <QRegExp>
#include <QMessageBox>

#include "TargetSettingsWizardPage.h"
#include "ui_TargetSettingsWizardPage.h"
#include "TcpSocket.h"
#include "Utility.h"
#include "Settings.h"

TargetSettingsWizardPage::TargetSettingsWizardPage(QWidget* parent) :
	QWizardPage(parent),
	_ui(new Ui::TargetSettingsWizardPage)
{
	_ui->setupUi(this);
	QString ipRange = "(?:[0-1]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])";
	QRegExp ipRegex ("^" + ipRange
                 + "\\." + ipRange
                 + "\\." + ipRange
                 + "\\." + ipRange + "$");
	QRegExpValidator *ipValidator = new QRegExpValidator(ipRegex, this);
	_ui->lineEdit_ip->setValidator(ipValidator);
	_ui->lineEdit_ip->setPlaceholderText("0.0.0.0");
	
	connect(_ui->lineEdit_ip, &QLineEdit::textChanged, this, &TargetSettingsWizardPage::lineEdit_textChanged);
	connect(_ui->pushButton_dt, &QPushButton::clicked, this, &TargetSettingsWizardPage::dtButton_clicked);
	
}

TargetSettingsWizardPage::~TargetSettingsWizardPage()
{
	delete _ui;
}

void TargetSettingsWizardPage::lineEdit_textChanged()
{
	bool valid = _ui->lineEdit_ip->hasAcceptableInput();
	if (valid)
		_ui->pushButton_dt->setEnabled(true);
	else
		_ui->pushButton_dt->setEnabled(false);
}

void TargetSettingsWizardPage::dtButton_clicked()
{
    if (!Utility::isReachable(_ui->lineEdit_ip->text()))
    {
		QMessageBox::information(this, tr("Information"),tr("Target IP is not reachable"));
        return;
    }
	_ui->lineEdit_mac->setText(Utility::searchArp(_ui->lineEdit_ip->text()));


}
