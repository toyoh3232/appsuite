#include <QRegExpValidator>
#include <QRegExp>
#include <QMessageBox>
#include <QMetaObject>
#include <QTimer>


#include "HostSettingsWizardPage.h"
#include "ui_HostSettingsWizardPage.h"

#include "Wizard.h"
#include "SettingsEntity.h"

#define OLDSTYLE "background-color: rgb(240, 240, 240);"
#define NEWSTYLE "background-color: rgb(240, 240, 240); color: rgb(255, 0, 0);"

HostSettingsWizardPage::HostSettingsWizardPage(QWidget *parent) :
	QWizardPage(parent),
	_ui(new Ui::HostSettingsWizardPage),
	_interface(nullptr),
	_interfaces( )
{
	_ui->setupUi(this);
	QString ipRange = "(?:[0-1]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])";
	QRegExp ipRegex ("^" + ipRange
                 + "\\." + ipRange
                 + "\\." + ipRange
                 + "\\." + ipRange + "$");
	QRegExpValidator *ipValidator = new QRegExpValidator(ipRegex, this);
	_ui->lineEdit_ip->setValidator(ipValidator);
	_ui->lineEdit_sm->setValidator(ipValidator);
	_ui->lineEdit_dg->setValidator(ipValidator);
	_ui->lineEdit_ip->setPlaceholderText("0.0.0.0");
	_ui->lineEdit_sm->setPlaceholderText("0.0.0.0");
	_ui->lineEdit_dg->setPlaceholderText(tr("not necessary"));

    registerField("host_ip",_ui->lineEdit_oldip);
	connect(_ui->pushButton_lock, &QPushButton::clicked, this, &HostSettingsWizardPage::lockButton_click);
	connect(_ui->pushButton_set, &QPushButton::clicked, this, &HostSettingsWizardPage::setButton_click);
	
	connect(_ui->pushButton_set, &QPushButton::clicked, this, &QWizardPage::completeChanged);
	
	connect(_ui->pushButton_fill, &QPushButton::clicked, this, &HostSettingsWizardPage::fillButton_click);
	connect(_ui->lineEdit_ip, &QLineEdit::textChanged, this, &HostSettingsWizardPage::lineEdit_textChanged);
	connect(_ui->lineEdit_sm, &QLineEdit::textChanged, this, &HostSettingsWizardPage::lineEdit_textChanged);
	connect(_ui->lineEdit_dg, &QLineEdit::textChanged, this, &HostSettingsWizardPage::lineEdit_textChanged);
}

HostSettingsWizardPage::~HostSettingsWizardPage()
{
	delete _ui;
}

void HostSettingsWizardPage::initializePage()
{
	_interfaces = NetworkInterface::allActiveInterfaces();
	foreach (NetworkInterface interface, _interfaces)
	{
        _ui->comboBox->addItem(interface.deviceName(), QVariant(interface.name()));
	}
    _ui->comboBox->setEnabled(true);
	_ui->pushButton_lock->setEnabled(true);
	setHidden(_ui->groupBox_newset,true);
	setHidden(_ui->groupBox_oldset,true);
	setStyle(_ui->groupBox_oldset, "QLineEdit", OLDSTYLE);
}

void HostSettingsWizardPage::cleanupPage()
{
	_ui->comboBox->clear();
}

void HostSettingsWizardPage::lockButton_click()
{
	_ui->comboBox->setEnabled(false);
	_ui->pushButton_lock->setEnabled(false);

	//get newest interface by name
	_interfaces = NetworkInterface::allActiveInterfaces();
	for (int i=0;i<_interfaces.count();i++)
	{
		if (_interfaces[i].name() == _ui->comboBox->currentText())
			_interface = &_interfaces[i];
	}
	_ui->lineEdit_oldip->setText(_interface->ipv4Addr());
	_ui->lineEdit_oldsm->setText(_interface->netmask());
	
	clearText(_ui->groupBox_newset, "QLineEdit");
	setHidden(_ui->groupBox_newset,false);
	setHidden(_ui->groupBox_oldset,false);
}

void HostSettingsWizardPage::setHidden(QWidget* parent,bool hidden)
{
	QList<QWidget*> widgets = parent->findChildren<QWidget *>();
	foreach(QWidget* w, widgets)
	{
		w->setHidden(hidden);
	}
	parent->setHidden(hidden);
}

void HostSettingsWizardPage::clearText(QWidget* parent, QString widgetClassName)
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

void HostSettingsWizardPage::setStyle(QWidget* parent, QString widgetClassName, QString style)
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

void HostSettingsWizardPage::lineEdit_textChanged()
{
	bool valid1 = _ui->lineEdit_ip->hasAcceptableInput();
	bool valid2 = _ui->lineEdit_sm->hasAcceptableInput();
	bool valid3 = _ui->lineEdit_dg->hasAcceptableInput() || _ui->lineEdit_dg->text().isEmpty();
	if (valid1 && valid2 && valid3)
		_ui->pushButton_set->setEnabled(true);
	else
		_ui->pushButton_set->setEnabled(false);
}

void HostSettingsWizardPage::setButton_click()
{
	QString ip      = _ui->lineEdit_ip->text();
	QString mask    = _ui->lineEdit_sm->text();
	QString gateway = _ui->lineEdit_dg->text();
	ErrorHandler* handler = _interface->setIpv4Property(ip, mask,gateway);
	if (handler == nullptr)
	{
		
		QMessageBox *msgBox = new QMessageBox();
		msgBox->setWindowTitle(tr("information"));
		msgBox->setIcon(QMessageBox::Information);
		msgBox->setText(tr("please wait for 3 secs..."));
		msgBox->setStandardButtons(QMessageBox::NoButton);
        msgBox->show();
        QTimer::singleShot(3000, msgBox, SLOT(hide()));
        QTimer::singleShot(3200,this,[=]
                           {
                               setStyle(_ui->groupBox_oldset, "QLineEdit", NEWSTYLE);
                               emit this->completeChanged();
                               emit _ui->pushButton_lock->clicked();
                           });

		
		
	}
	else
		QMessageBox::critical(this,handler->errorModuleName(),handler->errorMessage());
}

void HostSettingsWizardPage::fillButton_click()
{
	_ui->lineEdit_ip->setText("133.113.87.48");
	_ui->lineEdit_sm->setText("255.255.255.0");
	_ui->lineEdit_dg->setText("133.113.87.1");
}

bool HostSettingsWizardPage::isComplete() const
{
	return !_ui->pushButton_lock->isEnabled();
}

