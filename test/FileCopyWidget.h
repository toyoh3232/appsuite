#ifndef FILECOPYWIDGET_H
#define FILECOPYWIDGET_H

#include <QWidget>

namespace Ui {
class FileCopyWidget;
}

class FileCopyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FileCopyWidget(int maxValue, QWidget *parent, int minVaule = 0);
    ~FileCopyWidget();

public slots:
    void label_update(const QString& caption);

protected slots:
    void progressBar_inc();
    void progressBar_dec();

signals:
    void update(const QString& caption);
    void increase();
    void decrease();

private:
    Ui::FileCopyWidget* _ui;
};

#endif // FILECOPYWIDGET_H
