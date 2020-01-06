#include <QFileDialog>
#include <QDir>
#include <QThread>
#include <QFile>
#include <QTextEdit>

#include "FileCCDThread.h"
#include "FileCCDWidget.h"
#include "TextEditIODevice.h"
#include "Logger.h"
#include "MainWindow.h"

#include "ui_MainWindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _widget(new FileCCDWidget(this))
{
    ui->setupUi(this);
    ui->verticalLayout->addWidget(_widget);
    _widget->setHidden(true);
    //initialize logger
    auto logDevice = new TextEditIODevice(ui->textEdit,this);
    Logger::setDevice(logDevice);
    FileCCDThreadController* controller = new FileCCDThreadController(ErrorHandlingPolicy::ContinueAnyway);
    connect(controller, &FileCCDThreadController::filePrepared, this, [=](QString name)
            {
                _widget->nameLabel_setText(name);
                _widget->progressBar_inc();
            });
    connect(controller, &FileCCDThreadController::stateUpdated, this, [=](FileCCDState s)
            {
                switch(s)
                {
                case FileCCDState::Copying:
                    _widget->stateLabel_setText("copy");
                    break;
                case FileCCDState::Comparing:
                    _widget->stateLabel_setText("comparing");
                    break;
                case FileCCDState::Deleting:
                    _widget->stateLabel_setText("deleting");
                    break;
                }
            });
    connect(ui->pushButton_o, &QPushButton::clicked, this, [=]
            {
                ui->lineEdit_o->setText(QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                                "",
                                                                QFileDialog::ShowDirsOnly
                                                                            | QFileDialog::DontResolveSymlinks));
            });
    connect(ui->pushButton_n, &QPushButton::clicked, this, [=]
            {
                ui->lineEdit_n->setText(QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                                        "",
                                                                        QFileDialog::ShowDirsOnly
                                                                            | QFileDialog::DontResolveSymlinks));
            });
    connect(controller, &FileCCDThreadController::finished, this,[=]
            {
                logger() << "finished";
                ui->pushButton_start->setText("Start");
                _widget->setVisible(false);
            });
    connect(ui->pushButton_start, &QPushButton::clicked, controller,[=]
            {
                auto button = ui->pushButton_start;
                if (button->isChecked())
                {
                    QDir src(ui->lineEdit_o->text());
                    _widget->setRange(0, src.entryList(QDir::Files).size());
                    _widget->setVisible(true);
                    button->setText("Stop");
                    emit controller->operate(ui->lineEdit_o->text(), ui->lineEdit_n->text());
                }
                else
                {
                    logger() << "stop";
                    controller->end();
                }
            });

}

MainWindow::~MainWindow()
{
    delete ui;
}
