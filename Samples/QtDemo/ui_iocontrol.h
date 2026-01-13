/********************************************************************************
** Form generated from reading UI file 'iocontrol.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IOCONTROL_H
#define UI_IOCONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_IOControl
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *cbIn;
    QCheckBox *cbOut;
    QPushButton *btnRefresh;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *cbEnableStrobe;
    QCheckBox *cbStrobePolarity;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *cbTriggerMode;
    QCheckBox *cbTriggerPolarity;
    QPushButton *btnTriggerShot;

    void setupUi(QDialog *IOControl)
    {
        if (IOControl->objectName().isEmpty())
            IOControl->setObjectName(QStringLiteral("IOControl"));
        IOControl->resize(224, 391);
        verticalLayout = new QVBoxLayout(IOControl);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(IOControl);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        cbIn = new QCheckBox(groupBox);
        cbIn->setObjectName(QStringLiteral("cbIn"));
        cbIn->setEnabled(false);
        cbIn->setCheckable(true);

        verticalLayout_2->addWidget(cbIn);

        cbOut = new QCheckBox(groupBox);
        cbOut->setObjectName(QStringLiteral("cbOut"));

        verticalLayout_2->addWidget(cbOut);

        btnRefresh = new QPushButton(groupBox);
        btnRefresh->setObjectName(QStringLiteral("btnRefresh"));

        verticalLayout_2->addWidget(btnRefresh);


        verticalLayout->addWidget(groupBox);

        groupBox_3 = new QGroupBox(IOControl);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_4 = new QVBoxLayout(groupBox_3);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        cbEnableStrobe = new QCheckBox(groupBox_3);
        cbEnableStrobe->setObjectName(QStringLiteral("cbEnableStrobe"));

        verticalLayout_4->addWidget(cbEnableStrobe);

        cbStrobePolarity = new QCheckBox(groupBox_3);
        cbStrobePolarity->setObjectName(QStringLiteral("cbStrobePolarity"));

        verticalLayout_4->addWidget(cbStrobePolarity);


        verticalLayout->addWidget(groupBox_3);

        groupBox_2 = new QGroupBox(IOControl);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        cbTriggerMode = new QCheckBox(groupBox_2);
        cbTriggerMode->setObjectName(QStringLiteral("cbTriggerMode"));

        verticalLayout_3->addWidget(cbTriggerMode);

        cbTriggerPolarity = new QCheckBox(groupBox_2);
        cbTriggerPolarity->setObjectName(QStringLiteral("cbTriggerPolarity"));

        verticalLayout_3->addWidget(cbTriggerPolarity);

        btnTriggerShot = new QPushButton(groupBox_2);
        btnTriggerShot->setObjectName(QStringLiteral("btnTriggerShot"));

        verticalLayout_3->addWidget(btnTriggerShot);


        verticalLayout->addWidget(groupBox_2);


        retranslateUi(IOControl);

        QMetaObject::connectSlotsByName(IOControl);
    } // setupUi

    void retranslateUi(QDialog *IOControl)
    {
        IOControl->setWindowTitle(QApplication::translate("IOControl", "IO Control", nullptr));
        groupBox->setTitle(QApplication::translate("IOControl", "IO", nullptr));
        cbIn->setText(QApplication::translate("IOControl", "IN", nullptr));
        cbOut->setText(QApplication::translate("IOControl", "OUT", nullptr));
        btnRefresh->setText(QApplication::translate("IOControl", "Refresh Input", nullptr));
        groupBox_3->setTitle(QApplication::translate("IOControl", "Strobe", nullptr));
        cbEnableStrobe->setText(QApplication::translate("IOControl", "Enable strobe", nullptr));
        cbStrobePolarity->setText(QApplication::translate("IOControl", "Invert strobe polarity", nullptr));
        groupBox_2->setTitle(QApplication::translate("IOControl", "Trigger", nullptr));
        cbTriggerMode->setText(QApplication::translate("IOControl", "Enter trigger mode", nullptr));
        cbTriggerPolarity->setText(QApplication::translate("IOControl", "Invert trigger polarity", nullptr));
        btnTriggerShot->setText(QApplication::translate("IOControl", "Trigger  Shot", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IOControl: public Ui_IOControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IOCONTROL_H
