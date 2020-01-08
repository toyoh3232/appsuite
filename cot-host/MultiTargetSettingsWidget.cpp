#include "MultiTargetSettingsWidget.h"
#include "ui_MultiTargetSettingsWidget.h"

MultiTargetSettingsWidget::MultiTargetSettingsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MultiTargetSettingsWidget)
{
    ui->setupUi(this);
}

MultiTargetSettingsWidget::~MultiTargetSettingsWidget()
{
    delete ui;
}
