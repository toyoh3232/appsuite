#include <QRegExpValidator>
#include <QRegExp>
#include <QMessageBox>
#include <QMetaObject>
#include <QTimer>


#include "IpSettingsWizardPage.h"
#include "ui_IpSettingsWizardPage.h"


#include "TestSettingsWizard.h"

#define OLDSTYLE "background-color: rgb(240, 240, 240);"
#define NEWSTYLE "background-color: rgb(240, 240, 240); color: rgb(255, 0, 0);"

IpSettingsWizardPage::IpSettingsWizardPage(QWidget *parent) :
    WizardPage(parent),
    _ui(new Ui::IpSettingsWizardPage)
{
	_ui->setupUi(this);
    registerField("target_ip", _ui->lineEdit_oldip);

    _ui->lineEdit_ip->setValidator(_ipValidator);
    _ui->lineEdit_sm->setValidator(_ipValidator);
    _ui->lineEdit_dg->setValidator(_ipValidator);
	_ui->lineEdit_ip->setPlaceholderText("0.0.0.0");
	_ui->lineEdit_sm->setPlaceholderText("0.0.0.0");
	_ui->lineEdit_dg->setPlaceholderText(tr("not necessary"));

    connect(_ui->pushButton_lock, &QPushButton::clicked, this, &IpSettingsWizardPage::lockButton_click);
    connect(_ui->pushButton_set, &QPushButton::clicked, this, &IpSettingsWizardPage::setButton_click);
	
	connect(_ui->pushButton_set, &QPushButton::clicked, this, &QWizardPage::completeChanged);
	
    connect(_ui->pushButton_fill, &QPushButton::clicked, this, &IpSettingsWizardPage::fillButton_click);
    connect(_ui->lineEdit_ip, &QLineEdit::textChanged, this, &IpSettingsWizardPage::lineEdit_textChanged);
    connect(_ui->lineEdit_sm, &QLineEdit::textChanged, this, &IpSettingsWizardPage::lineEdit_textChanged);
    connect(_ui->lineEdit_dg, &QLineEdit::textChanged, this, &IpSettingsWizardPage::lineEdit_textChanged);
}

IpSettingsWizardPage::~IpSettingsWizardPage()
{
	delete _ui;
}

void IpSettingsWizardPage::initializePage()
{
    foreach (NetworkInterface interface, NetworkInterface::allActiveInterfaces())
    {
        _ui->comboBox->addItem(interface.deviceName(), QVariant(interface.index()));
	}
    _ui->comboBox->setEnabled(true);
	_ui->pushButton_lock->setEnabled(true);
	setHidden(_ui->groupBox_newset,true);
	setHidden(_ui->groupBox_oldset,true);
	setStyle(_ui->groupBox_oldset, "QLineEdit", OLDSTYLE);
}

void IpSettingsWizardPage::cleanupPage()
{
	_ui->comboBox->clear();
}

void IpSettingsWizardPage::lockButton_click()
{
	_ui->comboBox->setEnabled(false);
	_ui->pushButton_lock->setEnabled(false);

    //get newest interface by name
    auto nic = NetworkInterface::interfaceFromIndex(_ui->comboBox->currentData().toInt());
    _ui->lineEdit_oldip->setText(nic.ipv4Addr());
    _ui->lineEdit_oldsm->setText(nic.netmask());
    _ui->lineEdit_mac->setText(nic.macAddr());
	
	clearText(_ui->groupBox_newset, "QLineEdit");
	setHidden(_ui->groupBox_newset,false);
	setHidden(_ui->groupBox_oldset,false);
}

void IpSettingsWizardPage::setHidden(QWidget* parent,bool hidden)
{
	QList<QWidget*> widgets = parent->findChildren<QWidget *>();
	foreach(QWidget* w, widgets)
	{
		w->setHidden(hidden);
	}
	parent->setHidden(hidden);
}

void IpSettingsWizardPage::clearText(QWidget* parent, QString widgetClassName)
{
	
	if (widgetClassName == QString("QLineEdit"))
	{
		QList<QLineEdit*> widgets = parent->findChildren<QLineEdit*>();
		foreach(QLineEdit* w, widgets)
		{
			w->clear();
		}
	}
}

void IpSettingsWizardPage::setStyle(QWidget* parent, QString widgetClassName, QString style)
{
	if (widgetClassName == QString("QLineEdit"))
	{
		QList<QLineEdit*> widgets = parent->findChildren<QLineEdit*>();
		foreach(QLineEdit* w, widgets)
		{
			w->setStyleSheet(style);
		}
	}
}

void IpSettingsWizardPage::lineEdit_textChanged()
{
	bool valid1 = _ui->lineEdit_ip->hasAcceptableInput();
	bool valid2 = _ui->lineEdit_sm->hasAcceptableInput();
	bool valid3 = _ui->lineEdit_dg->hasAcceptableInput() || _ui->lineEdit_dg->text().isEmpty();
	if (valid1 && valid2 && valid3)
		_ui->pushButton_set->setEnabled(true);
	else
		_ui->pushButton_set->setEnabled(false);
}

void IpSettingsWizardPage::setButton_click()
{
    QString ip      = _ui->lineEdit_ip->text();
    QString mask    = _ui->lineEdit_sm->text();
    QString gateway = _ui->lineEdit_dg->text();
    auto nic = NetworkInterface::interfaceFromIndex(_ui->comboBox->currentData().toInt());
    ErrorHandler* handler = nic.setIpv4Property(ip, mask,gateway);
    if (handler == nullptr)
    {
        waitingBox(3000);
        QTimer::singleShot(3200,this,[=]
                           {
                               setStyle(_ui->groupBox_oldset, "QLineEdit", NEWSTYLE);
                               emit this->completeChanged();
                               emit _ui->pushButton_lock->clicked();
                           });
    }
    else
        error(handler->errorModuleName(), handler->errorMessage());
}

void IpSettingsWizardPage::fillButton_click()
{
	_ui->lineEdit_ip->setText("133.113.87.48");
	_ui->lineEdit_sm->setText("255.255.255.0");
	_ui->lineEdit_dg->setText("133.113.87.1");
}

bool IpSettingsWizardPage::isComplete() const
{
	return !_ui->pushButton_lock->isEnabled();
}

