#include <QRegExpValidator>
#include <QRegExp>
#include <QMessageBox>

#include "TargetSettingsWizardPage.h"
#include "ui_TargetSettingsWizardPage.h"
#include "TcpSocket.h"
#include "Utility.h"
#include "Settings.h"

TargetSettingsWizardPage::TargetSettingsWizardPage(QWidget* parent) :
    WizardPage(parent),
	_ui(new Ui::TargetSettingsWizardPage)
{
	_ui->setupUi(this);

    _ui->lineEdit_ip->setValidator(_ipValidator);
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
    waitingBox(2000);
    TcpSocket* socket = new TcpSocket(this);
    connect(socket, &TcpSocket::arrived, this, [=](SettingsEntity& se)
    {
        _ui->lineEdit_os->setText(se["target_os"].toString());
        _ui->lineEdit_mac->setText(se["target_mac"].toString());
        _ui->lineEdit_iprt->setText(se["target_ip"].toString());
        _ui->lineEdit_name->setText(se["target_name"].toString());
        _ui->pushButton_dt->setEnabled(false);
    });
    socket->connectTo(_ui->lineEdit_ip->text(), 20000);
    socket->request(RequestType::ASK_INFOMATION);

}
