/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionIO_Controller;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_3;
    QGraphicsView *gvMain;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QPushButton *btnStart;
    QPushButton *btnStop;
    QComboBox *cmbDevice;
    QComboBox *cmbResolution;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label_3;
    QLineEdit *leRowStart;
    QLabel *label_8;
    QLineEdit *leColumnStart;
    QLabel *label_1;
    QLabel *label_9;
    QPushButton *btnROI;
    QLineEdit *leWidth;
    QLineEdit *leHeight;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *btnZoomIn;
    QPushButton *btnZoomOut;
    QPushButton *btnResetView;
    QHBoxLayout *horizontalLayout_10;
    QCheckBox *cbHFlip;
    QCheckBox *cbVFlip;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QSlider *hsGamma;
    QLabel *lblGamm;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_10;
    QSlider *hsContrast;
    QLabel *lblContrast;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *cbGain;
    QLabel *label;
    QSlider *hsGain;
    QLabel *lblGain;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *cbExposure;
    QLabel *label_2;
    QSlider *hsExposure;
    QLabel *lblExposure;
    QPushButton *btnWB;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_2;
    QRadioButton *rbGroup0;
    QRadioButton *rbGroup1;
    QPushButton *btnSaveParameter;
    QPushButton *btnIOControl;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1217, 790);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionIO_Controller = new QAction(MainWindow);
        actionIO_Controller->setObjectName(QStringLiteral("actionIO_Controller"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_3 = new QHBoxLayout(centralWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        gvMain = new QGraphicsView(centralWidget);
        gvMain->setObjectName(QStringLiteral("gvMain"));
        QBrush brush(QColor(127, 127, 127, 255));
        brush.setStyle(Qt::SolidPattern);
        gvMain->setBackgroundBrush(brush);

        horizontalLayout_3->addWidget(gvMain);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        btnStart = new QPushButton(centralWidget);
        btnStart->setObjectName(QStringLiteral("btnStart"));

        gridLayout->addWidget(btnStart, 0, 0, 1, 1);

        btnStop = new QPushButton(centralWidget);
        btnStop->setObjectName(QStringLiteral("btnStop"));

        gridLayout->addWidget(btnStop, 0, 1, 1, 1);

        cmbDevice = new QComboBox(centralWidget);
        cmbDevice->setObjectName(QStringLiteral("cmbDevice"));

        gridLayout->addWidget(cmbDevice, 1, 0, 1, 1);

        cmbResolution = new QComboBox(centralWidget);
        cmbResolution->setObjectName(QStringLiteral("cmbResolution"));

        gridLayout->addWidget(cmbResolution, 1, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        formLayout = new QFormLayout(groupBox);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        leRowStart = new QLineEdit(groupBox);
        leRowStart->setObjectName(QStringLiteral("leRowStart"));

        formLayout->setWidget(0, QFormLayout::FieldRole, leRowStart);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_8);

        leColumnStart = new QLineEdit(groupBox);
        leColumnStart->setObjectName(QStringLiteral("leColumnStart"));

        formLayout->setWidget(1, QFormLayout::FieldRole, leColumnStart);

        label_1 = new QLabel(groupBox);
        label_1->setObjectName(QStringLiteral("label_1"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_1);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_9);

        btnROI = new QPushButton(groupBox);
        btnROI->setObjectName(QStringLiteral("btnROI"));

        formLayout->setWidget(5, QFormLayout::FieldRole, btnROI);

        leWidth = new QLineEdit(groupBox);
        leWidth->setObjectName(QStringLiteral("leWidth"));

        formLayout->setWidget(4, QFormLayout::FieldRole, leWidth);

        leHeight = new QLineEdit(groupBox);
        leHeight->setObjectName(QStringLiteral("leHeight"));

        formLayout->setWidget(3, QFormLayout::FieldRole, leHeight);


        verticalLayout_3->addWidget(groupBox);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_2 = new QVBoxLayout(groupBox_3);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        btnZoomIn = new QPushButton(groupBox_3);
        btnZoomIn->setObjectName(QStringLiteral("btnZoomIn"));
        btnZoomIn->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_9->addWidget(btnZoomIn);

        btnZoomOut = new QPushButton(groupBox_3);
        btnZoomOut->setObjectName(QStringLiteral("btnZoomOut"));
        btnZoomOut->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_9->addWidget(btnZoomOut);

        btnResetView = new QPushButton(groupBox_3);
        btnResetView->setObjectName(QStringLiteral("btnResetView"));
        btnResetView->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_9->addWidget(btnResetView);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        cbHFlip = new QCheckBox(groupBox_3);
        cbHFlip->setObjectName(QStringLiteral("cbHFlip"));
        cbHFlip->setChecked(false);

        horizontalLayout_10->addWidget(cbHFlip);

        cbVFlip = new QCheckBox(groupBox_3);
        cbVFlip->setObjectName(QStringLiteral("cbVFlip"));

        horizontalLayout_10->addWidget(cbVFlip);


        verticalLayout_2->addLayout(horizontalLayout_10);


        verticalLayout_3->addWidget(groupBox_3);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout->addWidget(label_4);

        hsGamma = new QSlider(groupBox_2);
        hsGamma->setObjectName(QStringLiteral("hsGamma"));
        hsGamma->setMinimum(30);
        hsGamma->setMaximum(250);
        hsGamma->setValue(200);
        hsGamma->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(hsGamma);

        lblGamm = new QLabel(groupBox_2);
        lblGamm->setObjectName(QStringLiteral("lblGamm"));
        lblGamm->setMinimumSize(QSize(20, 0));

        horizontalLayout->addWidget(lblGamm);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_2->addWidget(label_10);

        hsContrast = new QSlider(groupBox_2);
        hsContrast->setObjectName(QStringLiteral("hsContrast"));
        hsContrast->setMinimum(30);
        hsContrast->setMaximum(200);
        hsContrast->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(hsContrast);

        lblContrast = new QLabel(groupBox_2);
        lblContrast->setObjectName(QStringLiteral("lblContrast"));
        lblContrast->setMinimumSize(QSize(20, 0));

        horizontalLayout_2->addWidget(lblContrast);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        cbGain = new QCheckBox(groupBox_2);
        cbGain->setObjectName(QStringLiteral("cbGain"));
        cbGain->setChecked(false);

        horizontalLayout_4->addWidget(cbGain);

        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_4->addWidget(label);

        hsGain = new QSlider(groupBox_2);
        hsGain->setObjectName(QStringLiteral("hsGain"));
        hsGain->setEnabled(true);
        hsGain->setMinimum(8);
        hsGain->setMaximum(63);
        hsGain->setValue(8);
        hsGain->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(hsGain);

        lblGain = new QLabel(groupBox_2);
        lblGain->setObjectName(QStringLiteral("lblGain"));
        lblGain->setMinimumSize(QSize(20, 0));

        horizontalLayout_4->addWidget(lblGain);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        cbExposure = new QCheckBox(groupBox_2);
        cbExposure->setObjectName(QStringLiteral("cbExposure"));
        cbExposure->setChecked(false);

        horizontalLayout_5->addWidget(cbExposure);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_5->addWidget(label_2);

        hsExposure = new QSlider(groupBox_2);
        hsExposure->setObjectName(QStringLiteral("hsExposure"));
        hsExposure->setEnabled(true);
        hsExposure->setMinimum(1);
        hsExposure->setMaximum(2000);
        hsExposure->setSliderPosition(8);
        hsExposure->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(hsExposure);

        lblExposure = new QLabel(groupBox_2);
        lblExposure->setObjectName(QStringLiteral("lblExposure"));
        lblExposure->setMinimumSize(QSize(20, 0));

        horizontalLayout_5->addWidget(lblExposure);


        verticalLayout->addLayout(horizontalLayout_5);

        btnWB = new QPushButton(groupBox_2);
        btnWB->setObjectName(QStringLiteral("btnWB"));

        verticalLayout->addWidget(btnWB);


        verticalLayout_3->addWidget(groupBox_2);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        gridLayout_2 = new QGridLayout(groupBox_4);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        rbGroup0 = new QRadioButton(groupBox_4);
        rbGroup0->setObjectName(QStringLiteral("rbGroup0"));
        rbGroup0->setChecked(true);

        gridLayout_2->addWidget(rbGroup0, 0, 0, 1, 1);

        rbGroup1 = new QRadioButton(groupBox_4);
        rbGroup1->setObjectName(QStringLiteral("rbGroup1"));

        gridLayout_2->addWidget(rbGroup1, 0, 1, 1, 1);

        btnSaveParameter = new QPushButton(groupBox_4);
        btnSaveParameter->setObjectName(QStringLiteral("btnSaveParameter"));

        gridLayout_2->addWidget(btnSaveParameter, 1, 0, 1, 2);


        verticalLayout_3->addWidget(groupBox_4);

        btnIOControl = new QPushButton(centralWidget);
        btnIOControl->setObjectName(QStringLiteral("btnIOControl"));

        verticalLayout_3->addWidget(btnIOControl);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout_3->addLayout(verticalLayout_3);

        horizontalLayout_3->setStretch(0, 1);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1217, 25));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setLayoutDirection(Qt::RightToLeft);
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionExit);
        menuFile->addAction(actionIO_Controller);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "QtDemo", nullptr));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        actionIO_Controller->setText(QApplication::translate("MainWindow", "IO Control", nullptr));
        btnStart->setText(QApplication::translate("MainWindow", "Start", nullptr));
        btnStop->setText(QApplication::translate("MainWindow", "Stop", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "ROI", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Row Start", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "Column Start", nullptr));
        label_1->setText(QApplication::translate("MainWindow", "Height", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "Width", nullptr));
        btnROI->setText(QApplication::translate("MainWindow", "Apply", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Zoom View", nullptr));
        btnZoomIn->setText(QApplication::translate("MainWindow", "+", nullptr));
        btnZoomOut->setText(QApplication::translate("MainWindow", "-", nullptr));
        btnResetView->setText(QApplication::translate("MainWindow", "=", nullptr));
        cbHFlip->setText(QApplication::translate("MainWindow", "H Flip", nullptr));
        cbVFlip->setText(QApplication::translate("MainWindow", "V Flip", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "ISP", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Gamma", nullptr));
        lblGamm->setText(QString());
        label_10->setText(QApplication::translate("MainWindow", "Contrast", nullptr));
        lblContrast->setText(QString());
        cbGain->setText(QApplication::translate("MainWindow", "Auto", nullptr));
        label->setText(QApplication::translate("MainWindow", "Gain", nullptr));
        lblGain->setText(QString());
        cbExposure->setText(QApplication::translate("MainWindow", "Auto", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Exposure", nullptr));
        lblExposure->setText(QString());
        btnWB->setText(QApplication::translate("MainWindow", "White Balance", nullptr));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Parameter", nullptr));
        rbGroup0->setText(QApplication::translate("MainWindow", "group 0", nullptr));
        rbGroup1->setText(QApplication::translate("MainWindow", "group 1", nullptr));
        btnSaveParameter->setText(QApplication::translate("MainWindow", "Save", nullptr));
        btnIOControl->setText(QApplication::translate("MainWindow", "IO Control", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
