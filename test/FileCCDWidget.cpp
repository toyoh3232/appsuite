#include "FileCCDWidget.h"
#include "ui_FileCCDWidget.h"
#include "Logger.h"

FileCCDWidget::FileCCDWidget(QWidget *parent) :
    QWidget(parent),
    _ui(new Ui::FileCCDWidget)
{
    _ui->setupUi(this);
}

FileCCDWidget::~FileCCDWidget()
{
    delete _ui;
}

void FileCCDWidget::progressBar_inc()
{
    int v = _ui->progressBar->value();
    _ui->progressBar->setValue(v + 1);
}

void FileCCDWidget::progressBar_dec()
{
    int v = _ui->progressBar->value();
    _ui->progressBar->setValue(v - 1);
}

void FileCCDWidget::setRange(int min, int max)
{
    _ui->progressBar->setRange(min, max);
    _ui->progressBar->setValue(0);
}

void FileCCDWidget::stateLabel_setText(const QString& text)
{
    _ui->label_state->setText(text);
}

void FileCCDWidget::nameLabel_setText(const QString &file)
{
    _ui->label_name->setText(file);
}
