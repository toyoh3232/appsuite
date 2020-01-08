#ifndef MULTITARGETSETTINGS_H
#define MULTITARGETSETTINGS_H

#include <QWidget>

namespace Ui {
class MultiTargetSettingsWidget;
}

class MultiTargetSettingsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MultiTargetSettingsWidget(QWidget *parent = nullptr);
    ~MultiTargetSettingsWidget();

private:
    Ui::MultiTargetSettingsWidget *ui;
};

#endif // MULTITARGETSETTINGS_H
