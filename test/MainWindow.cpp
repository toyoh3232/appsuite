#include <QFileDialog>
#include <QDir>
#include <QThread>
#include <QFile>
#include <QTextEdit>

#include "FileCopyThread.h"
#include "FileCopyWidget.h"
#include "MainWindow.h"
#include "ui_MainWindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    FileCopyThreadController* controler = new FileCopyThreadController;
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
    connect(ui->pushButton_start, &QPushButton::clicked, controler,[=]
            {
                QDir src(ui->lineEdit_o->text());
                auto widget = new FileCopyWidget(src.entryList(QDir::Files).size(), this);
                this->ui->verticalLayout->addWidget(widget);
                connect(controler, &FileCopyThreadController::copyStarted, widget, &FileCopyWidget::setlabelText);
                emit controler->operate(ui->lineEdit_o->text(), ui->lineEdit_n->text());
            });

}

MainWindow::~MainWindow()
{
    delete ui;
}
