#include <QtWidgets/QWizard>
#include <QtWidgets/QMessageBox>

#include <QAbstractButton>

#include "Wizard.h"

Wizard::Wizard(QWidget* parent) :
	QWizard(parent)
{
	resize(510, 444);
    setMinimumSize(QSize(510, 444));
    setMaximumSize(QSize(510, 444));
    setWizardStyle(QWizard::ClassicStyle);
    setOptions(QWizard::NoBackButtonOnStartPage);
	setButtonText( QWizard::CancelButton, tr("Cancel"));
	setButtonText( QWizard::BackButton, tr("Back") );
	setButtonText( QWizard::NextButton, tr("Next") );
	setButtonText( QWizard::FinishButton, tr("Finish"));

    setWindowFlags(windowFlags()  | Qt::CustomizeWindowHint );
    setWindowFlags(windowFlags() & ~Qt::WindowCloseButtonHint);
}

