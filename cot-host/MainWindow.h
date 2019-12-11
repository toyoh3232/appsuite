#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "TestSettingsWizard.h"

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent=nullptr);
	~MainWindow();

private slots:
	void newSettings();

private:
	Ui::MainWindow* _ui;
	TestSettingsWizard* _wizard;
	
};


#endif // MAINWINDOW_H