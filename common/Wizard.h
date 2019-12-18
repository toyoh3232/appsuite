#ifndef WIZARD_H
#define WIZARD_H

#include <QtWidgets/QWizard>

class Wizard : public QWizard
{
	Q_OBJECT

public:
    explicit Wizard(QWidget* parent=nullptr);

};


#endif//WIZARD_H
