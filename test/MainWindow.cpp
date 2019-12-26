#include <QFileDialog>
#include <QDir>
#include <QThread>
#include <QFile>
#include <QTextEdit>

#include "Controller.h"
#include "MainWindow.h"
#include "ui_MainWindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Controller* controler = new Controller;
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
                emit controler->operate(ui->lineEdit_o->text(), ui->lineEdit_n->text());
            });
    connect(controler, &Controller::resultReady, ui->textEdit, &QTextEdit::setText);

}

MainWindow::~MainWindow()
{
    delete ui;
}
