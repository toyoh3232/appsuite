#include "MainWindow2.h"
#include "MultiTargetSettingsWidget.h"
#include "ui_MainWindow2.h"

MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    ui->setupUi(this);
    connect(ui->pushButton,&QAbstractButton::clicked,this,[=]
            {
                auto w = new MultiTargetSettingsWidget(this);
                ui->verticalLayout->addWidget(w);
            });
}

MainWindow2::~MainWindow2()
{
    delete ui;
}
