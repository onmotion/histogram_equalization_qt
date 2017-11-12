/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *chooseImagePB;
    QLabel *originalImageLabel;
    QLabel *resultImageLabel;
    QPushButton *processPB;
    QLabel *originalHistogramLabel;
    QFrame *line;
    QLabel *normalizedHistogramLabel;
    QSlider *lightFactorSlider;
    QLabel *label;
    QLabel *label_2;
    QLabel *heightLabel;
    QLabel *widthLabel;
    QMenuBar *menuBar;
    QMenu *menuImage_equalization;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1426, 609);
        MainWindow->setMinimumSize(QSize(1000, 400));
        MainWindow->setMaximumSize(QSize(1426, 609));
        MainWindow->setAcceptDrops(true);
        MainWindow->setUnifiedTitleAndToolBarOnMac(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        chooseImagePB = new QPushButton(centralWidget);
        chooseImagePB->setObjectName(QStringLiteral("chooseImagePB"));
        chooseImagePB->setGeometry(QRect(10, 440, 113, 32));
        originalImageLabel = new QLabel(centralWidget);
        originalImageLabel->setObjectName(QStringLiteral("originalImageLabel"));
        originalImageLabel->setGeometry(QRect(10, 20, 561, 411));
        originalImageLabel->setFrameShape(QFrame::Box);
        originalImageLabel->setFrameShadow(QFrame::Raised);
        originalImageLabel->setAlignment(Qt::AlignCenter);
        resultImageLabel = new QLabel(centralWidget);
        resultImageLabel->setObjectName(QStringLiteral("resultImageLabel"));
        resultImageLabel->setGeometry(QRect(580, 20, 561, 411));
        resultImageLabel->setFrameShape(QFrame::Box);
        resultImageLabel->setFrameShadow(QFrame::Raised);
        resultImageLabel->setAlignment(Qt::AlignCenter);
        processPB = new QPushButton(centralWidget);
        processPB->setObjectName(QStringLiteral("processPB"));
        processPB->setGeometry(QRect(10, 470, 113, 32));
        originalHistogramLabel = new QLabel(centralWidget);
        originalHistogramLabel->setObjectName(QStringLiteral("originalHistogramLabel"));
        originalHistogramLabel->setGeometry(QRect(1160, 20, 255, 200));
        originalHistogramLabel->setFrameShape(QFrame::Box);
        originalHistogramLabel->setFrameShadow(QFrame::Raised);
        originalHistogramLabel->setAlignment(Qt::AlignCenter);
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(1140, 20, 20, 611));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        normalizedHistogramLabel = new QLabel(centralWidget);
        normalizedHistogramLabel->setObjectName(QStringLiteral("normalizedHistogramLabel"));
        normalizedHistogramLabel->setGeometry(QRect(1160, 230, 255, 200));
        normalizedHistogramLabel->setFrameShape(QFrame::Box);
        normalizedHistogramLabel->setFrameShadow(QFrame::Raised);
        normalizedHistogramLabel->setAlignment(Qt::AlignCenter);
        lightFactorSlider = new QSlider(centralWidget);
        lightFactorSlider->setObjectName(QStringLiteral("lightFactorSlider"));
        lightFactorSlider->setEnabled(true);
        lightFactorSlider->setGeometry(QRect(1160, 450, 251, 22));
        lightFactorSlider->setAcceptDrops(false);
        lightFactorSlider->setLayoutDirection(Qt::LeftToRight);
        lightFactorSlider->setAutoFillBackground(false);
        lightFactorSlider->setMaximum(510);
        lightFactorSlider->setValue(255);
        lightFactorSlider->setTracking(true);
        lightFactorSlider->setOrientation(Qt::Horizontal);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(580, 440, 60, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(580, 460, 60, 16));
        heightLabel = new QLabel(centralWidget);
        heightLabel->setObjectName(QStringLiteral("heightLabel"));
        heightLabel->setGeometry(QRect(640, 440, 60, 16));
        widthLabel = new QLabel(centralWidget);
        widthLabel->setObjectName(QStringLiteral("widthLabel"));
        widthLabel->setGeometry(QRect(640, 460, 60, 16));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1426, 22));
        menuImage_equalization = new QMenu(menuBar);
        menuImage_equalization->setObjectName(QStringLiteral("menuImage_equalization"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuImage_equalization->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Image equalization", Q_NULLPTR));
        chooseImagePB->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214...", Q_NULLPTR));
        originalImageLabel->setText(QApplication::translate("MainWindow", "Original image", Q_NULLPTR));
        resultImageLabel->setText(QApplication::translate("MainWindow", "Result image", Q_NULLPTR));
        processPB->setText(QApplication::translate("MainWindow", "\320\236\320\261\321\200\320\260\320\261\320\276\321\202\320\260\321\202\321\214", Q_NULLPTR));
        originalHistogramLabel->setText(QApplication::translate("MainWindow", "Original histogram", Q_NULLPTR));
        normalizedHistogramLabel->setText(QApplication::translate("MainWindow", "Normalized histogram", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        lightFactorSlider->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lightFactorSlider->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        label->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\201\320\276\321\202\320\260:", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\320\250\320\270\321\200\320\270\320\275\320\260:", Q_NULLPTR));
        heightLabel->setText(QString());
        widthLabel->setText(QString());
        menuImage_equalization->setTitle(QApplication::translate("MainWindow", "Image equalization", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
