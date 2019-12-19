#include <QMessageBox>
#include <QTimer>

#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Logger.h"
#include "TextEditIODevice.h"
#include "RunGuard.h"

MainWindow::MainWindow(QWidget* parent) :
	QMainWindow(parent),
	_ui(new Ui::MainWindow),
    _w(new TestSettingsWizard(this)),
    _s(new TcpServer(this))
{
	_ui->setupUi(this);
    connect(_ui->pushButton_st,&QPushButton::clicked, this, &MainWindow::newSettings);
	connect(_ui->pushButton_exit,&QPushButton::clicked, this, &QWidget::close);
    connect(_w->button(QWizard::WizardButton::FinishButton), &QAbstractButton::clicked,[=]
    {
        _ui->pushButton_st->setEnabled(false);
        SettingsEntity e;
        e.port= 20000;
        e.ip = "127.0.0.1";
 //     e.ip = _w->field("host_ip").toString();
        _s->listen(e);
    });
    auto logDevice = new TextEditIODevice(_ui->textEdit_lg,this);
    Logger::setDevice(logDevice);
    // initialize running guard
    connect(RunGuard::instance(), &RunGuard::recreated,[=](QString errMsg)
    {
        QMessageBox::critical(this, "", errMsg);
        QTimer::singleShot(0, this, &MainWindow::close);
    });
}

MainWindow::~MainWindow()
{
	delete _ui;
    delete _w;
}

void MainWindow::newSettings()
{
    _w->setWindowModality(Qt::WindowModal);
    _w->show();
}

void MainWindow::showEvent(QShowEvent *event)
{
    RunGuard::instance()->run();
    QWidget::showEvent(event);
}
