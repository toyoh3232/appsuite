#include <QMessageBox>
#include <QTimer>
#include <QBitmap>

#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Logger.h"
#include "Settings.h"
#include "TextEditIODevice.h"
#include "RunGuard.h"

MainWindow::MainWindow(QWidget* parent) :
	QMainWindow(parent),
	_ui(new Ui::MainWindow),
    _w(new TestSettingsWizard(this))
{
	_ui->setupUi(this);
    // set button click event
    connect(_ui->pushButton_set, &QPushButton::clicked, this, &MainWindow::setButton_click);
    connect(_ui->pushButton_exit, &QPushButton::clicked, this, &QWidget::close);
    connect(_ui->pushButton_start, &QPushButton::clicked, this, &MainWindow::startButton_click);
    connect(_w->button(QWizard::WizardButton::FinishButton), &QAbstractButton::clicked,[=]
    {
        _ui->pushButton_set->setEnabled(false);
        _ui->pushButton_start->setEnabled(true);
    });
    // initalize settings
//    if (Settings::instance().isNew())
//        emit _ui->pushButton_set->clicked();
    // initialize logger
    auto logDevice = new TextEditIODevice(_ui->textEdit_lg, this);
    Logger::setDevice(logDevice);
}

MainWindow::~MainWindow()
{
	delete _ui;
    delete _w;
}

void MainWindow::setButton_click()
{
    _w->setWindowModality(Qt::WindowModal);
    _w->show();
}

void MainWindow::startButton_click()
{
    _s.listen("127.0.0.1",20000);
}
