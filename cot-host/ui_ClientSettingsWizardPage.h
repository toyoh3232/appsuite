/********************************************************************************
** Form generated from reading UI file 'ClientSettingsWizardPage.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTSETTINGSWIZARDPAGE_H
#define UI_CLIENTSETTINGSWIZARDPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWizardPage>

QT_BEGIN_NAMESPACE

class Ui_ClientSettingsWizardPage
{
public:
    QGroupBox *groupBox;
    QLineEdit *lineEdit_ipstart;
    QLineEdit *lineEdit_ipend;
    QLabel *label_5;
    QPushButton *pushButton_dt;
    QGroupBox *groupBox_info;

    void setupUi(QWizardPage *ClientSettingsWizardPage)
    {
        if (ClientSettingsWizardPage->objectName().isEmpty())
            ClientSettingsWizardPage->setObjectName(QString::fromUtf8("ClientSettingsWizardPage"));
        ClientSettingsWizardPage->resize(510, 444);
        ClientSettingsWizardPage->setMinimumSize(QSize(510, 444));
        ClientSettingsWizardPage->setMaximumSize(QSize(510, 444));
        groupBox = new QGroupBox(ClientSettingsWizardPage);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(50, 70, 391, 81));
        lineEdit_ipstart = new QLineEdit(groupBox);
        lineEdit_ipstart->setObjectName(QString::fromUtf8("lineEdit_ipstart"));
        lineEdit_ipstart->setGeometry(QRect(10, 30, 113, 20));
        lineEdit_ipend = new QLineEdit(groupBox);
        lineEdit_ipend->setObjectName(QString::fromUtf8("lineEdit_ipend"));
        lineEdit_ipend->setGeometry(QRect(150, 30, 113, 20));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(130, 30, 31, 21));
        pushButton_dt = new QPushButton(groupBox);
        pushButton_dt->setObjectName(QString::fromUtf8("pushButton_dt"));
        pushButton_dt->setGeometry(QRect(290, 30, 75, 23));
        groupBox_info = new QGroupBox(ClientSettingsWizardPage);
        groupBox_info->setObjectName(QString::fromUtf8("groupBox_info"));
        groupBox_info->setGeometry(QRect(50, 179, 391, 171));

        retranslateUi(ClientSettingsWizardPage);

        QMetaObject::connectSlotsByName(ClientSettingsWizardPage);
    } // setupUi

    void retranslateUi(QWizardPage *ClientSettingsWizardPage)
    {
        ClientSettingsWizardPage->setWindowTitle(QCoreApplication::translate("ClientSettingsWizardPage", "WizardPage", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ClientSettingsWizardPage", "Client IP Range", nullptr));
        label_5->setText(QCoreApplication::translate("ClientSettingsWizardPage", "\357\275\236", nullptr));
        pushButton_dt->setText(QCoreApplication::translate("ClientSettingsWizardPage", "Detect", nullptr));
        groupBox_info->setTitle(QCoreApplication::translate("ClientSettingsWizardPage", "Infomation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientSettingsWizardPage: public Ui_ClientSettingsWizardPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTSETTINGSWIZARDPAGE_H
