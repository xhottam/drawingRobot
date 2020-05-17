/********************************************************************************
** Form generated from reading UI file 'DrawingRobot.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAWINGROBOT_H
#define UI_DRAWINGROBOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>
#include <oglwidget.h>

QT_BEGIN_NAMESPACE

class Ui_DrawingRobotClass
{
public:
    QAction *fileOpen;
    QAction *actionExit;
    QAction *dynamixelOpen;
    QWidget *centralWidget;
    QTreeView *treeView;
    QListWidget *listWidget;
    QListWidget *listWidget_2;
    QGraphicsView *graphicsView;
    OGLWidget *openGLWidget;
    QListWidget *listWidget_3;
    QSlider *horizontalSlider_OFFSET_X;
    QSlider *verticalSlider_OFFSET_Y;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QMenuBar *menuBar;
    QMenu *menuOpen;
    QMenu *menuDynamixel;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DrawingRobotClass)
    {
        if (DrawingRobotClass->objectName().isEmpty())
            DrawingRobotClass->setObjectName(QString::fromUtf8("DrawingRobotClass"));
        DrawingRobotClass->setWindowModality(Qt::ApplicationModal);
        DrawingRobotClass->resize(903, 710);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DrawingRobotClass->sizePolicy().hasHeightForWidth());
        DrawingRobotClass->setSizePolicy(sizePolicy);
        DrawingRobotClass->setMaximumSize(QSize(911, 710));
        fileOpen = new QAction(DrawingRobotClass);
        fileOpen->setObjectName(QString::fromUtf8("fileOpen"));
        actionExit = new QAction(DrawingRobotClass);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        dynamixelOpen = new QAction(DrawingRobotClass);
        dynamixelOpen->setObjectName(QString::fromUtf8("dynamixelOpen"));
        centralWidget = new QWidget(DrawingRobotClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        treeView = new QTreeView(centralWidget);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setGeometry(QRect(20, 10, 121, 641));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(500, 40, 121, 611));
        listWidget_2 = new QListWidget(centralWidget);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));
        listWidget_2->setGeometry(QRect(630, 40, 121, 611));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(160, 14, 325, 311));
        openGLWidget = new OGLWidget(centralWidget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));
        openGLWidget->setGeometry(QRect(160, 330, 325, 321));
        listWidget_3 = new QListWidget(centralWidget);
        listWidget_3->setObjectName(QString::fromUtf8("listWidget_3"));
        listWidget_3->setGeometry(QRect(760, 40, 121, 611));
        horizontalSlider_OFFSET_X = new QSlider(centralWidget);
        horizontalSlider_OFFSET_X->setObjectName(QString::fromUtf8("horizontalSlider_OFFSET_X"));
        horizontalSlider_OFFSET_X->setGeometry(QRect(210, 160, 101, 22));
        horizontalSlider_OFFSET_X->setMaximum(200);
        horizontalSlider_OFFSET_X->setValue(50);
        horizontalSlider_OFFSET_X->setOrientation(Qt::Horizontal);
        horizontalSlider_OFFSET_X->setTickPosition(QSlider::TicksBelow);
        verticalSlider_OFFSET_Y = new QSlider(centralWidget);
        verticalSlider_OFFSET_Y->setObjectName(QString::fromUtf8("verticalSlider_OFFSET_Y"));
        verticalSlider_OFFSET_Y->setGeometry(QRect(180, 70, 22, 191));
        verticalSlider_OFFSET_Y->setMinimum(100);
        verticalSlider_OFFSET_Y->setMaximum(200);
        verticalSlider_OFFSET_Y->setValue(150);
        verticalSlider_OFFSET_Y->setOrientation(Qt::Vertical);
        verticalSlider_OFFSET_Y->setInvertedAppearance(false);
        verticalSlider_OFFSET_Y->setInvertedControls(false);
        verticalSlider_OFFSET_Y->setTickPosition(QSlider::TicksBelow);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(510, 20, 111, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(640, 20, 111, 20));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(790, 20, 51, 20));
        DrawingRobotClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DrawingRobotClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 903, 21));
        menuOpen = new QMenu(menuBar);
        menuOpen->setObjectName(QString::fromUtf8("menuOpen"));
        menuDynamixel = new QMenu(menuBar);
        menuDynamixel->setObjectName(QString::fromUtf8("menuDynamixel"));
        DrawingRobotClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DrawingRobotClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        DrawingRobotClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(DrawingRobotClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        DrawingRobotClass->setStatusBar(statusBar);

        menuBar->addAction(menuOpen->menuAction());
        menuBar->addAction(menuDynamixel->menuAction());
        menuOpen->addAction(fileOpen);
        menuOpen->addSeparator();
        menuOpen->addAction(actionExit);
        menuOpen->addSeparator();
        menuDynamixel->addAction(dynamixelOpen);

        retranslateUi(DrawingRobotClass);

        QMetaObject::connectSlotsByName(DrawingRobotClass);
    } // setupUi

    void retranslateUi(QMainWindow *DrawingRobotClass)
    {
        DrawingRobotClass->setWindowTitle(QCoreApplication::translate("DrawingRobotClass", "DrawingRobot", nullptr));
        fileOpen->setText(QCoreApplication::translate("DrawingRobotClass", "Open", nullptr));
        actionExit->setText(QCoreApplication::translate("DrawingRobotClass", "Exit", nullptr));
        dynamixelOpen->setText(QCoreApplication::translate("DrawingRobotClass", "Open", nullptr));
#if QT_CONFIG(tooltip)
        horizontalSlider_OFFSET_X->setToolTip(QCoreApplication::translate("DrawingRobotClass", "OFFSET_X", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        verticalSlider_OFFSET_Y->setToolTip(QCoreApplication::translate("DrawingRobotClass", "OFFSET_Y", nullptr));
#endif // QT_CONFIG(tooltip)
        label->setText(QCoreApplication::translate("DrawingRobotClass", "Absolute coordinates", nullptr));
        label_2->setText(QCoreApplication::translate("DrawingRobotClass", "Dynamixel degrees", nullptr));
        label_3->setText(QCoreApplication::translate("DrawingRobotClass", " Angles", nullptr));
        menuOpen->setTitle(QCoreApplication::translate("DrawingRobotClass", "File", nullptr));
        menuDynamixel->setTitle(QCoreApplication::translate("DrawingRobotClass", "Dynamixel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DrawingRobotClass: public Ui_DrawingRobotClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAWINGROBOT_H
