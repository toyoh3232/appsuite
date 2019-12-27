#include "FileCopyWidget.h"
#include "ui_FileCopyWidget.h"

FileCopyWidget::FileCopyWidget(int maxValue, QWidget *parent, int minVaule) :
    QWidget(parent),
    _ui(new Ui::FileCopyWidget)
{
    _ui->setupUi(this);
    _ui->progressBar->setRange(minVaule, maxValue);

    connect(this, &FileCopyWidget::increase, this, &FileCopyWidget::progressBar_inc);
    connect(this, &FileCopyWidget::decrease, this, &FileCopyWidget::progressBar_dec);
}

FileCopyWidget::~FileCopyWidget()
{
    delete _ui;
}

void FileCopyWidget::progressBar_inc()
{
    int v = _ui->progressBar->value();
    _ui->progressBar->setValue(v + 1);
}

void FileCopyWidget::progressBar_dec()
{
    int v = _ui->progressBar->value();
    _ui->progressBar->setValue(v - 1);
}

void FileCopyWidget::setlabelText(QString text)
{
    _ui->label->setText(text);
}
