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
    _wizard(new TestSettingsWizard(this)),
    _s(this)
{
	_ui->setupUi(this);
    connect(_ui->pushButton_set,&QPushButton::clicked, this, &MainWindow::buttonSet_click);
    connect(_ui->pushButton_start,&QPushButton::clicked, this, &MainWindow::buttonStart_click);
	connect(_ui->pushButton_exit,&QPushButton::clicked, this, &QWidget::close);
    //initialize logger
    auto logDevice = new TextEditIODevice(_ui->textEdit_lg,this);
    Logger::setDevice(logDevice);
    // initialize running guard

}

MainWindow::~MainWindow()
{
	delete _ui;
	delete _wizard;
}

void MainWindow::buttonSet_click()
{
	_wizard->setWindowModality(Qt::WindowModal);
    _wizard->show();
}

void MainWindow::buttonStart_click()
{
    logger() << "clicked";
    connect(&_s, &TcpSocket::arrived, this, [](SettingsEntity& se)
    {
        foreach(auto& key, se.allKeys())
        {
            logger() << "start:" <<se[key].toString();
        }
    });
    _s.connectTo("127.0.0.1",20000);
    _s.request(RequestType::ASK_INFOMATION);
}

