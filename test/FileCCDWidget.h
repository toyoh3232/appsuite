#ifndef FILECOPYWIDGET_H
#define FILECOPYWIDGET_H

#include <QWidget>
#include <QString>

namespace Ui {
class FileCCDWidget;
}

class FileCCDWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FileCCDWidget(QWidget *parent=nullptr);
    ~FileCCDWidget();

public slots:
    void stateLabel_setText(const QString& caption);
    void nameLabel_setText(const QString& file);

public slots:
    void progressBar_inc();
    void progressBar_dec();

public:
    void setRange(int min, int max);

private:
    Ui::FileCCDWidget* _ui;
};

#endif // FILECOPYWIDGET_H
