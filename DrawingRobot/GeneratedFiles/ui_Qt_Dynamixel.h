/********************************************************************************
** Form generated from reading UI file 'Qt_Dynamixel.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_DYNAMIXEL_H
#define UI_QT_DYNAMIXEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Qt_Dynamixel
{
public:
    QGroupBox *elbow;
    QGroupBox *elbow_eeprom;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_20;
    QLabel *label_17;
    QLabel *label_16;
    QDoubleSpinBox *elbow_alarmLed;
    QLabel *label_14;
    QLabel *label_11;
    QLabel *label_13;
    QLabel *label_7;
    QLabel *label_19;
    QDoubleSpinBox *elbow_firmware;
    QDoubleSpinBox *elbow_modelNumber;
    QLabel *label_21;
    QLabel *label_18;
    QDoubleSpinBox *elbow_returnDelay;
    QDoubleSpinBox *elbow_alarmShutdown;
    QLabel *label_10;
    QLabel *label_12;
    QLabel *label_8;
    QDoubleSpinBox *elbow_cw;
    QDoubleSpinBox *elbow_hLimitTemp;
    QDoubleSpinBox *elbow_maxTorque;
    QDoubleSpinBox *elbow_hLimitVoltage;
    QDoubleSpinBox *elbow_statusReturn;
    QLabel *label_22;
    QDoubleSpinBox *elbow_lLimitVoltage;
    QDoubleSpinBox *elbow_ccw;
    QDoubleSpinBox *elbow_id;
    QComboBox *elbow_baudRate;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_3;
    QPushButton *elbow_alarmLed_read;
    QPushButton *elbow_cw_write;
    QPushButton *elbow_maxTorque_write;
    QPushButton *elbow_hLimitVoltage_read;
    QPushButton *elbow_lLimiitVoltage_read;
    QPushButton *elbow_hLimitVoltage_write;
    QPushButton *elbow_returnDelay_write;
    QPushButton *elbow_alarmShutdown_write;
    QPushButton *elbow_statusReturn_read;
    QPushButton *elbow_ccw_write;
    QPushButton *elbow_alarmShutdown_read;
    QPushButton *elbow_maxTorque_read;
    QPushButton *elbow_alarmLed_write;
    QPushButton *elbow_statusReturn_write;
    QPushButton *elbow_hLimitTemp_read;
    QPushButton *elbow_hLimitTemp_write;
    QPushButton *elbow_returnDelay_read;
    QPushButton *elbow_cw_read;
    QPushButton *elbow_ccw_read;
    QPushButton *elbow_lLimitVoltage_write;
    QPushButton *elbow_baudRate_read;
    QPushButton *elbow_baudRate_write;
    QGroupBox *elbow_ram;
    QWidget *gridLayoutWidget_5;
    QGridLayout *gridLayout_7;
    QPushButton *elbow_goalPosition_read;
    QPushButton *elbow_lock_write;
    QPushButton *elbow_presentLoad_read;
    QPushButton *elbow_presentPosition_read;
    QPushButton *elbow_lock_read;
    QPushButton *elbow_presentTemp_read;
    QPushButton *elbow_register_read;
    QPushButton *elbow_torqueLimit_read;
    QPushButton *elbow_presentSpeed_read;
    QPushButton *elbow_ccwSlope_read;
    QPushButton *elbow_cwSlope_read;
    QPushButton *elbow_ccwMargin_read;
    QPushButton *elbow_cwMargin_read;
    QPushButton *elbow_punch_read;
    QPushButton *elbow_movingSpeed_read;
    QPushButton *elbow_torqueLimit_write;
    QPushButton *elbow_movingSpeed_write;
    QPushButton *elbow_ccwSlope_write;
    QPushButton *elbow_cwSlope_write;
    QPushButton *elbow_punch_write;
    QPushButton *elbow_ccwMargin_write;
    QPushButton *elbow_cwMargin_write;
    QPushButton *elbow_goalPosition_write;
    QPushButton *elbow_register_write;
    QWidget *gridLayoutWidget_9;
    QGridLayout *gridLayout_10;
    QDoubleSpinBox *elbow_movingSpeed;
    QDoubleSpinBox *elbow_presentTemp;
    QLabel *label_65;
    QLabel *label_64;
    QDoubleSpinBox *elbow_torqueLimit;
    QDoubleSpinBox *elbow_lock;
    QDoubleSpinBox *elbow_register;
    QDoubleSpinBox *elbow_presentPosition;
    QDoubleSpinBox *elbow_presentSpeed;
    QDoubleSpinBox *elbow_presentLoad;
    QLabel *label_56;
    QLabel *label_54;
    QLabel *label_58;
    QLabel *label_57;
    QLabel *label_60;
    QDoubleSpinBox *elbow_punch;
    QDoubleSpinBox *elbow_cwMargin;
    QLabel *label_59;
    QLabel *label_62;
    QDoubleSpinBox *elbow_ccwMargin;
    QLabel *label_52;
    QLabel *label_53;
    QLabel *label_55;
    QLabel *label_63;
    QDoubleSpinBox *elbow_goalPosition;
    QLabel *label_66;
    QComboBox *elbow_cwSlope;
    QComboBox *elbow_ccwSlope;
    QGroupBox *shoulder;
    QGroupBox *shoulder_eeprom;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout_2;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QDoubleSpinBox *shoulder_alarmLed;
    QLabel *label_15;
    QLabel *label_26;
    QLabel *label_27;
    QLabel *label_9;
    QLabel *label_28;
    QDoubleSpinBox *shoulder_firmware;
    QDoubleSpinBox *shoulder_modelNumber;
    QLabel *label_29;
    QLabel *label_30;
    QDoubleSpinBox *shoulder_returnDelay;
    QDoubleSpinBox *shoulder_alarmShutdown;
    QLabel *label_31;
    QLabel *label_32;
    QLabel *label_33;
    QDoubleSpinBox *shoulder_cw;
    QDoubleSpinBox *shoulder_hLimitTemp;
    QDoubleSpinBox *shoulder_maxTorque;
    QDoubleSpinBox *shoulder_hLimitVoltage;
    QDoubleSpinBox *shoulder_statusReturn;
    QLabel *label_34;
    QDoubleSpinBox *shoulder_lLimitVoltage;
    QDoubleSpinBox *shoulder_ccw;
    QDoubleSpinBox *shoulder_id;
    QComboBox *shoulder_baudRate;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_4;
    QPushButton *shoulder_ccw_write;
    QPushButton *shoulder_lLimitVoltage_write;
    QPushButton *shoulder_ccw_read;
    QPushButton *shoulder_lLimiitVoltage_read;
    QPushButton *shoulder_maxTorque_write;
    QPushButton *shoulder_baudRate_write;
    QPushButton *shoulder_hLimitTemp_read;
    QPushButton *shoulder_hLimitVoltage_write;
    QPushButton *shoulder_maxTorque_read;
    QPushButton *shoulder_statusReturn_read;
    QPushButton *shoulder_alarmShutdown_read;
    QPushButton *shoulder_cw_read;
    QPushButton *shoulder_cw_write;
    QPushButton *shoulder_alarmLed_read;
    QPushButton *shoulder_alarmLed_write;
    QPushButton *shoulder_hLimitTemp_write;
    QPushButton *shoulder_statusReturn_write;
    QPushButton *shoulder_hLimitVoltage_read;
    QPushButton *shoulder_alarmShutdown_write;
    QPushButton *shoulder_returnDelay_read;
    QPushButton *shoulder_baudRate_read;
    QPushButton *shoulder_returnDelay_write;
    QGroupBox *shoulder_ram;
    QWidget *gridLayoutWidget_10;
    QGridLayout *gridLayout_11;
    QDoubleSpinBox *shoulder_movingSpeed;
    QDoubleSpinBox *shoulder_presentTemp;
    QLabel *label_67;
    QLabel *label_68;
    QDoubleSpinBox *shoulder_torqueLimit;
    QDoubleSpinBox *shoulder_lock;
    QDoubleSpinBox *shoulder_register;
    QDoubleSpinBox *shoulder_presentPosition;
    QDoubleSpinBox *shoulder_presentSpeed;
    QDoubleSpinBox *shoulder_presentLoad;
    QLabel *label_61;
    QLabel *label_69;
    QLabel *label_70;
    QLabel *label_71;
    QLabel *label_72;
    QDoubleSpinBox *shoulder_punch;
    QDoubleSpinBox *shoulder_cwMargin;
    QLabel *label_73;
    QLabel *label_74;
    QDoubleSpinBox *shoulder_ccwMargin;
    QLabel *label_75;
    QLabel *label_76;
    QLabel *label_77;
    QLabel *label_78;
    QDoubleSpinBox *shoulder_goalPosition;
    QLabel *label_79;
    QComboBox *shoulder_cwSlope;
    QComboBox *shoulder_ccwSlope;
    QWidget *gridLayoutWidget_6;
    QGridLayout *gridLayout_8;
    QPushButton *shoulder_goalPosition_read;
    QPushButton *shoulder_lock_write;
    QPushButton *shoulder_presentLoad_read;
    QPushButton *shoulder_presentPosition_read;
    QPushButton *shoulder_lock_read;
    QPushButton *shoulder_presentTemp_read;
    QPushButton *shoulder_register_read;
    QPushButton *shoulder_torqueLimit_read;
    QPushButton *shoulder_presentSpeed_read;
    QPushButton *shoulder_ccwSlope_read;
    QPushButton *shoulder_cwSlope_read;
    QPushButton *shoulder_ccwMargin_read;
    QPushButton *shoulder_cwMargin_read;
    QPushButton *shoulder_punch_read;
    QPushButton *shoulder_movingSpeed_read;
    QPushButton *shoulder_torqueLimit_write;
    QPushButton *shoulder_movingSpeed_write;
    QPushButton *shoulder_ccwSlope_write;
    QPushButton *shoulder_cwSlope_write;
    QPushButton *shoulder_punch_write;
    QPushButton *shoulder_ccwMargin_write;
    QPushButton *shoulder_cwMargin_write;
    QPushButton *shoulder_goalPosition_write;
    QPushButton *shoulder_register_write;
    QGroupBox *h;
    QGroupBox *groupBox_8;
    QWidget *gridLayoutWidget_7;
    QGridLayout *gridLayout_5;
    QSpinBox *hand_id;
    QSpinBox *hand_goalPosition;
    QLabel *label;
    QSpinBox *hand_maxTorque;
    QLabel *label_2;
    QSpinBox *hand_movingSpeed;
    QLabel *label_3;
    QLabel *label_4;
    QWidget *gridLayoutWidget_8;
    QGridLayout *gridLayout_6;
    QPushButton *hand_goalPosition_write;
    QPushButton *hand_maxTorque_read;
    QPushButton *hand_goalPosition_read;
    QPushButton *hand_maxTorque_write;
    QPushButton *hand_movingSpeed_read;
    QPushButton *hand_movingSpeed_write;
    QPushButton *setHand;
    QPushButton *setDynamixel;

    void setupUi(QDialog *Qt_Dynamixel)
    {
        if (Qt_Dynamixel->objectName().isEmpty())
            Qt_Dynamixel->setObjectName(QString::fromUtf8("Qt_Dynamixel"));
        Qt_Dynamixel->setWindowModality(Qt::NonModal);
        Qt_Dynamixel->resize(915, 710);
        elbow = new QGroupBox(Qt_Dynamixel);
        elbow->setObjectName(QString::fromUtf8("elbow"));
        elbow->setGeometry(QRect(320, 0, 271, 691));
        elbow->setStyleSheet(QString::fromUtf8(" QGroupBox {\n"
" background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                   stop: 0 #E0E0E0, stop: 1 #FFFFFF);\n"
" border: 2px solid gray;\n"
" border-radius: 5px;\n"
" margin-top: 1ex; /* leave space at the top for the title */\n"
"}"));
        elbow_eeprom = new QGroupBox(elbow);
        elbow_eeprom->setObjectName(QString::fromUtf8("elbow_eeprom"));
        elbow_eeprom->setGeometry(QRect(10, 20, 251, 321));
        gridLayoutWidget = new QWidget(elbow_eeprom);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 20, 137, 291));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetNoConstraint);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_20 = new QLabel(gridLayoutWidget);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setLayoutDirection(Qt::LeftToRight);
        label_20->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_20, 12, 0, 1, 1);

        label_17 = new QLabel(gridLayoutWidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setLayoutDirection(Qt::LeftToRight);
        label_17->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_17, 9, 0, 1, 1);

        label_16 = new QLabel(gridLayoutWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setLayoutDirection(Qt::LeftToRight);
        label_16->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_16, 8, 0, 1, 1);

        elbow_alarmLed = new QDoubleSpinBox(gridLayoutWidget);
        elbow_alarmLed->setObjectName(QString::fromUtf8("elbow_alarmLed"));
        elbow_alarmLed->setDecimals(0);
        elbow_alarmLed->setMaximum(127.000000000000000);

        gridLayout->addWidget(elbow_alarmLed, 12, 1, 1, 1);

        label_14 = new QLabel(gridLayoutWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setLayoutDirection(Qt::LeftToRight);
        label_14->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_14, 7, 0, 1, 1);

        label_11 = new QLabel(gridLayoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setLayoutDirection(Qt::LeftToRight);
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_11, 3, 0, 1, 1);

        label_13 = new QLabel(gridLayoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setLayoutDirection(Qt::LeftToRight);
        label_13->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_13, 5, 0, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setLayoutDirection(Qt::LeftToRight);
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_7, 2, 0, 1, 1);

        label_19 = new QLabel(gridLayoutWidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setLayoutDirection(Qt::LeftToRight);
        label_19->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_19, 11, 0, 1, 1);

        elbow_firmware = new QDoubleSpinBox(gridLayoutWidget);
        elbow_firmware->setObjectName(QString::fromUtf8("elbow_firmware"));
        elbow_firmware->setReadOnly(true);
        elbow_firmware->setButtonSymbols(QAbstractSpinBox::NoButtons);
        elbow_firmware->setDecimals(0);

        gridLayout->addWidget(elbow_firmware, 1, 1, 1, 1);

        elbow_modelNumber = new QDoubleSpinBox(gridLayoutWidget);
        elbow_modelNumber->setObjectName(QString::fromUtf8("elbow_modelNumber"));
        elbow_modelNumber->setReadOnly(true);
        elbow_modelNumber->setButtonSymbols(QAbstractSpinBox::NoButtons);
        elbow_modelNumber->setDecimals(0);

        gridLayout->addWidget(elbow_modelNumber, 0, 1, 1, 1);

        label_21 = new QLabel(gridLayoutWidget);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setLayoutDirection(Qt::LeftToRight);
        label_21->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_21, 13, 0, 1, 1);

        label_18 = new QLabel(gridLayoutWidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setLayoutDirection(Qt::LeftToRight);
        label_18->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_18, 10, 0, 1, 1);

        elbow_returnDelay = new QDoubleSpinBox(gridLayoutWidget);
        elbow_returnDelay->setObjectName(QString::fromUtf8("elbow_returnDelay"));
        elbow_returnDelay->setDecimals(0);
        elbow_returnDelay->setMaximum(254.000000000000000);

        gridLayout->addWidget(elbow_returnDelay, 4, 1, 1, 1);

        elbow_alarmShutdown = new QDoubleSpinBox(gridLayoutWidget);
        elbow_alarmShutdown->setObjectName(QString::fromUtf8("elbow_alarmShutdown"));
        elbow_alarmShutdown->setDecimals(0);
        elbow_alarmShutdown->setMaximum(127.000000000000000);

        gridLayout->addWidget(elbow_alarmShutdown, 13, 1, 1, 1);

        label_10 = new QLabel(gridLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setLayoutDirection(Qt::LeftToRight);
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_10, 1, 0, 1, 1);

        label_12 = new QLabel(gridLayoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setLayoutDirection(Qt::LeftToRight);
        label_12->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_12, 4, 0, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setLayoutDirection(Qt::LeftToRight);
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_8, 6, 0, 1, 1);

        elbow_cw = new QDoubleSpinBox(gridLayoutWidget);
        elbow_cw->setObjectName(QString::fromUtf8("elbow_cw"));
        elbow_cw->setDecimals(0);
        elbow_cw->setMaximum(1023.000000000000000);

        gridLayout->addWidget(elbow_cw, 5, 1, 1, 1);

        elbow_hLimitTemp = new QDoubleSpinBox(gridLayoutWidget);
        elbow_hLimitTemp->setObjectName(QString::fromUtf8("elbow_hLimitTemp"));
        elbow_hLimitTemp->setDecimals(0);
        elbow_hLimitTemp->setMinimum(0.000000000000000);
        elbow_hLimitTemp->setMaximum(99.000000000000000);
        elbow_hLimitTemp->setValue(0.000000000000000);

        gridLayout->addWidget(elbow_hLimitTemp, 7, 1, 1, 1);

        elbow_maxTorque = new QDoubleSpinBox(gridLayoutWidget);
        elbow_maxTorque->setObjectName(QString::fromUtf8("elbow_maxTorque"));
        elbow_maxTorque->setDecimals(0);
        elbow_maxTorque->setMaximum(255.000000000000000);

        gridLayout->addWidget(elbow_maxTorque, 10, 1, 1, 1);

        elbow_hLimitVoltage = new QDoubleSpinBox(gridLayoutWidget);
        elbow_hLimitVoltage->setObjectName(QString::fromUtf8("elbow_hLimitVoltage"));
        elbow_hLimitVoltage->setDecimals(0);
        elbow_hLimitVoltage->setMinimum(50.000000000000000);
        elbow_hLimitVoltage->setMaximum(250.000000000000000);

        gridLayout->addWidget(elbow_hLimitVoltage, 8, 1, 1, 1);

        elbow_statusReturn = new QDoubleSpinBox(gridLayoutWidget);
        elbow_statusReturn->setObjectName(QString::fromUtf8("elbow_statusReturn"));
        elbow_statusReturn->setDecimals(0);
        elbow_statusReturn->setMinimum(0.000000000000000);
        elbow_statusReturn->setMaximum(2.000000000000000);
        elbow_statusReturn->setSingleStep(1.000000000000000);

        gridLayout->addWidget(elbow_statusReturn, 11, 1, 1, 1);

        label_22 = new QLabel(gridLayoutWidget);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setLayoutDirection(Qt::LeftToRight);
        label_22->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_22, 0, 0, 1, 1);

        elbow_lLimitVoltage = new QDoubleSpinBox(gridLayoutWidget);
        elbow_lLimitVoltage->setObjectName(QString::fromUtf8("elbow_lLimitVoltage"));
        elbow_lLimitVoltage->setDecimals(0);
        elbow_lLimitVoltage->setMinimum(50.000000000000000);
        elbow_lLimitVoltage->setMaximum(250.000000000000000);

        gridLayout->addWidget(elbow_lLimitVoltage, 9, 1, 1, 1);

        elbow_ccw = new QDoubleSpinBox(gridLayoutWidget);
        elbow_ccw->setObjectName(QString::fromUtf8("elbow_ccw"));
        elbow_ccw->setDecimals(0);
        elbow_ccw->setMinimum(0.000000000000000);
        elbow_ccw->setMaximum(1023.000000000000000);
        elbow_ccw->setValue(0.000000000000000);

        gridLayout->addWidget(elbow_ccw, 6, 1, 1, 1);

        elbow_id = new QDoubleSpinBox(gridLayoutWidget);
        elbow_id->setObjectName(QString::fromUtf8("elbow_id"));
        elbow_id->setButtonSymbols(QAbstractSpinBox::NoButtons);
        elbow_id->setDecimals(0);
        elbow_id->setMinimum(1.000000000000000);
        elbow_id->setMaximum(253.000000000000000);

        gridLayout->addWidget(elbow_id, 2, 1, 1, 1);

        elbow_baudRate = new QComboBox(gridLayoutWidget);
        elbow_baudRate->addItem(QString());
        elbow_baudRate->addItem(QString());
        elbow_baudRate->addItem(QString());
        elbow_baudRate->addItem(QString());
        elbow_baudRate->addItem(QString());
        elbow_baudRate->addItem(QString());
        elbow_baudRate->addItem(QString());
        elbow_baudRate->addItem(QString());
        elbow_baudRate->addItem(QString());
        elbow_baudRate->setObjectName(QString::fromUtf8("elbow_baudRate"));

        gridLayout->addWidget(elbow_baudRate, 3, 1, 1, 1);

        gridLayoutWidget_2 = new QWidget(elbow_eeprom);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(160, 80, 81, 231));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        elbow_alarmLed_read = new QPushButton(gridLayoutWidget_2);
        elbow_alarmLed_read->setObjectName(QString::fromUtf8("elbow_alarmLed_read"));
        elbow_alarmLed_read->setEnabled(false);

        gridLayout_3->addWidget(elbow_alarmLed_read, 9, 0, 1, 1);

        elbow_cw_write = new QPushButton(gridLayoutWidget_2);
        elbow_cw_write->setObjectName(QString::fromUtf8("elbow_cw_write"));
        elbow_cw_write->setEnabled(false);

        gridLayout_3->addWidget(elbow_cw_write, 2, 1, 1, 1);

        elbow_maxTorque_write = new QPushButton(gridLayoutWidget_2);
        elbow_maxTorque_write->setObjectName(QString::fromUtf8("elbow_maxTorque_write"));
        elbow_maxTorque_write->setEnabled(false);

        gridLayout_3->addWidget(elbow_maxTorque_write, 7, 1, 1, 1);

        elbow_hLimitVoltage_read = new QPushButton(gridLayoutWidget_2);
        elbow_hLimitVoltage_read->setObjectName(QString::fromUtf8("elbow_hLimitVoltage_read"));
        elbow_hLimitVoltage_read->setEnabled(false);

        gridLayout_3->addWidget(elbow_hLimitVoltage_read, 5, 0, 1, 1);

        elbow_lLimiitVoltage_read = new QPushButton(gridLayoutWidget_2);
        elbow_lLimiitVoltage_read->setObjectName(QString::fromUtf8("elbow_lLimiitVoltage_read"));
        elbow_lLimiitVoltage_read->setEnabled(false);

        gridLayout_3->addWidget(elbow_lLimiitVoltage_read, 6, 0, 1, 1);

        elbow_hLimitVoltage_write = new QPushButton(gridLayoutWidget_2);
        elbow_hLimitVoltage_write->setObjectName(QString::fromUtf8("elbow_hLimitVoltage_write"));
        elbow_hLimitVoltage_write->setEnabled(false);

        gridLayout_3->addWidget(elbow_hLimitVoltage_write, 5, 1, 1, 1);

        elbow_returnDelay_write = new QPushButton(gridLayoutWidget_2);
        elbow_returnDelay_write->setObjectName(QString::fromUtf8("elbow_returnDelay_write"));
        elbow_returnDelay_write->setEnabled(false);

        gridLayout_3->addWidget(elbow_returnDelay_write, 1, 1, 1, 1);

        elbow_alarmShutdown_write = new QPushButton(gridLayoutWidget_2);
        elbow_alarmShutdown_write->setObjectName(QString::fromUtf8("elbow_alarmShutdown_write"));
        elbow_alarmShutdown_write->setEnabled(false);

        gridLayout_3->addWidget(elbow_alarmShutdown_write, 10, 1, 1, 1);

        elbow_statusReturn_read = new QPushButton(gridLayoutWidget_2);
        elbow_statusReturn_read->setObjectName(QString::fromUtf8("elbow_statusReturn_read"));
        elbow_statusReturn_read->setEnabled(false);

        gridLayout_3->addWidget(elbow_statusReturn_read, 8, 0, 1, 1);

        elbow_ccw_write = new QPushButton(gridLayoutWidget_2);
        elbow_ccw_write->setObjectName(QString::fromUtf8("elbow_ccw_write"));
        elbow_ccw_write->setEnabled(false);

        gridLayout_3->addWidget(elbow_ccw_write, 3, 1, 1, 1);

        elbow_alarmShutdown_read = new QPushButton(gridLayoutWidget_2);
        elbow_alarmShutdown_read->setObjectName(QString::fromUtf8("elbow_alarmShutdown_read"));
        elbow_alarmShutdown_read->setEnabled(false);

        gridLayout_3->addWidget(elbow_alarmShutdown_read, 10, 0, 1, 1);

        elbow_maxTorque_read = new QPushButton(gridLayoutWidget_2);
        elbow_maxTorque_read->setObjectName(QString::fromUtf8("elbow_maxTorque_read"));
        elbow_maxTorque_read->setEnabled(false);

        gridLayout_3->addWidget(elbow_maxTorque_read, 7, 0, 1, 1);

        elbow_alarmLed_write = new QPushButton(gridLayoutWidget_2);
        elbow_alarmLed_write->setObjectName(QString::fromUtf8("elbow_alarmLed_write"));
        elbow_alarmLed_write->setEnabled(false);

        gridLayout_3->addWidget(elbow_alarmLed_write, 9, 1, 1, 1);

        elbow_statusReturn_write = new QPushButton(gridLayoutWidget_2);
        elbow_statusReturn_write->setObjectName(QString::fromUtf8("elbow_statusReturn_write"));
        elbow_statusReturn_write->setEnabled(false);

        gridLayout_3->addWidget(elbow_statusReturn_write, 8, 1, 1, 1);

        elbow_hLimitTemp_read = new QPushButton(gridLayoutWidget_2);
        elbow_hLimitTemp_read->setObjectName(QString::fromUtf8("elbow_hLimitTemp_read"));
        elbow_hLimitTemp_read->setEnabled(false);

        gridLayout_3->addWidget(elbow_hLimitTemp_read, 4, 0, 1, 1);

        elbow_hLimitTemp_write = new QPushButton(gridLayoutWidget_2);
        elbow_hLimitTemp_write->setObjectName(QString::fromUtf8("elbow_hLimitTemp_write"));
        elbow_hLimitTemp_write->setEnabled(false);

        gridLayout_3->addWidget(elbow_hLimitTemp_write, 4, 1, 1, 1);

        elbow_returnDelay_read = new QPushButton(gridLayoutWidget_2);
        elbow_returnDelay_read->setObjectName(QString::fromUtf8("elbow_returnDelay_read"));
        elbow_returnDelay_read->setEnabled(false);

        gridLayout_3->addWidget(elbow_returnDelay_read, 1, 0, 1, 1);

        elbow_cw_read = new QPushButton(gridLayoutWidget_2);
        elbow_cw_read->setObjectName(QString::fromUtf8("elbow_cw_read"));
        elbow_cw_read->setEnabled(false);

        gridLayout_3->addWidget(elbow_cw_read, 2, 0, 1, 1);

        elbow_ccw_read = new QPushButton(gridLayoutWidget_2);
        elbow_ccw_read->setObjectName(QString::fromUtf8("elbow_ccw_read"));
        elbow_ccw_read->setEnabled(false);

        gridLayout_3->addWidget(elbow_ccw_read, 3, 0, 1, 1);

        elbow_lLimitVoltage_write = new QPushButton(gridLayoutWidget_2);
        elbow_lLimitVoltage_write->setObjectName(QString::fromUtf8("elbow_lLimitVoltage_write"));
        elbow_lLimitVoltage_write->setEnabled(false);

        gridLayout_3->addWidget(elbow_lLimitVoltage_write, 6, 1, 1, 1);

        elbow_baudRate_read = new QPushButton(gridLayoutWidget_2);
        elbow_baudRate_read->setObjectName(QString::fromUtf8("elbow_baudRate_read"));
        elbow_baudRate_read->setEnabled(false);

        gridLayout_3->addWidget(elbow_baudRate_read, 0, 0, 1, 1);

        elbow_baudRate_write = new QPushButton(gridLayoutWidget_2);
        elbow_baudRate_write->setObjectName(QString::fromUtf8("elbow_baudRate_write"));
        elbow_baudRate_write->setEnabled(false);

        gridLayout_3->addWidget(elbow_baudRate_write, 0, 1, 1, 1);

        elbow_ram = new QGroupBox(elbow);
        elbow_ram->setObjectName(QString::fromUtf8("elbow_ram"));
        elbow_ram->setGeometry(QRect(10, 350, 251, 331));
        gridLayoutWidget_5 = new QWidget(elbow_ram);
        gridLayoutWidget_5->setObjectName(QString::fromUtf8("gridLayoutWidget_5"));
        gridLayoutWidget_5->setGeometry(QRect(160, 20, 81, 301));
        gridLayout_7 = new QGridLayout(gridLayoutWidget_5);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        elbow_goalPosition_read = new QPushButton(gridLayoutWidget_5);
        elbow_goalPosition_read->setObjectName(QString::fromUtf8("elbow_goalPosition_read"));
        elbow_goalPosition_read->setEnabled(false);

        gridLayout_7->addWidget(elbow_goalPosition_read, 4, 0, 1, 1);

        elbow_lock_write = new QPushButton(gridLayoutWidget_5);
        elbow_lock_write->setObjectName(QString::fromUtf8("elbow_lock_write"));
        elbow_lock_write->setEnabled(false);

        gridLayout_7->addWidget(elbow_lock_write, 12, 1, 1, 1);

        elbow_presentLoad_read = new QPushButton(gridLayoutWidget_5);
        elbow_presentLoad_read->setObjectName(QString::fromUtf8("elbow_presentLoad_read"));
        elbow_presentLoad_read->setEnabled(false);

        gridLayout_7->addWidget(elbow_presentLoad_read, 9, 0, 1, 1);

        elbow_presentPosition_read = new QPushButton(gridLayoutWidget_5);
        elbow_presentPosition_read->setObjectName(QString::fromUtf8("elbow_presentPosition_read"));
        elbow_presentPosition_read->setEnabled(false);

        gridLayout_7->addWidget(elbow_presentPosition_read, 7, 0, 1, 1);

        elbow_lock_read = new QPushButton(gridLayoutWidget_5);
        elbow_lock_read->setObjectName(QString::fromUtf8("elbow_lock_read"));
        elbow_lock_read->setEnabled(false);

        gridLayout_7->addWidget(elbow_lock_read, 12, 0, 1, 1);

        elbow_presentTemp_read = new QPushButton(gridLayoutWidget_5);
        elbow_presentTemp_read->setObjectName(QString::fromUtf8("elbow_presentTemp_read"));
        elbow_presentTemp_read->setEnabled(false);

        gridLayout_7->addWidget(elbow_presentTemp_read, 10, 0, 1, 1);

        elbow_register_read = new QPushButton(gridLayoutWidget_5);
        elbow_register_read->setObjectName(QString::fromUtf8("elbow_register_read"));
        elbow_register_read->setEnabled(false);

        gridLayout_7->addWidget(elbow_register_read, 11, 0, 1, 1);

        elbow_torqueLimit_read = new QPushButton(gridLayoutWidget_5);
        elbow_torqueLimit_read->setObjectName(QString::fromUtf8("elbow_torqueLimit_read"));
        elbow_torqueLimit_read->setEnabled(false);

        gridLayout_7->addWidget(elbow_torqueLimit_read, 6, 0, 1, 1);

        elbow_presentSpeed_read = new QPushButton(gridLayoutWidget_5);
        elbow_presentSpeed_read->setObjectName(QString::fromUtf8("elbow_presentSpeed_read"));
        elbow_presentSpeed_read->setEnabled(false);

        gridLayout_7->addWidget(elbow_presentSpeed_read, 8, 0, 1, 1);

        elbow_ccwSlope_read = new QPushButton(gridLayoutWidget_5);
        elbow_ccwSlope_read->setObjectName(QString::fromUtf8("elbow_ccwSlope_read"));
        elbow_ccwSlope_read->setEnabled(false);

        gridLayout_7->addWidget(elbow_ccwSlope_read, 3, 0, 1, 1);

        elbow_cwSlope_read = new QPushButton(gridLayoutWidget_5);
        elbow_cwSlope_read->setObjectName(QString::fromUtf8("elbow_cwSlope_read"));
        elbow_cwSlope_read->setEnabled(false);

        gridLayout_7->addWidget(elbow_cwSlope_read, 2, 0, 1, 1);

        elbow_ccwMargin_read = new QPushButton(gridLayoutWidget_5);
        elbow_ccwMargin_read->setObjectName(QString::fromUtf8("elbow_ccwMargin_read"));
        elbow_ccwMargin_read->setEnabled(false);

        gridLayout_7->addWidget(elbow_ccwMargin_read, 1, 0, 1, 1);

        elbow_cwMargin_read = new QPushButton(gridLayoutWidget_5);
        elbow_cwMargin_read->setObjectName(QString::fromUtf8("elbow_cwMargin_read"));
        elbow_cwMargin_read->setEnabled(false);

        gridLayout_7->addWidget(elbow_cwMargin_read, 0, 0, 1, 1);

        elbow_punch_read = new QPushButton(gridLayoutWidget_5);
        elbow_punch_read->setObjectName(QString::fromUtf8("elbow_punch_read"));
        elbow_punch_read->setEnabled(false);

        gridLayout_7->addWidget(elbow_punch_read, 13, 0, 1, 1);

        elbow_movingSpeed_read = new QPushButton(gridLayoutWidget_5);
        elbow_movingSpeed_read->setObjectName(QString::fromUtf8("elbow_movingSpeed_read"));
        elbow_movingSpeed_read->setEnabled(false);

        gridLayout_7->addWidget(elbow_movingSpeed_read, 5, 0, 1, 1);

        elbow_torqueLimit_write = new QPushButton(gridLayoutWidget_5);
        elbow_torqueLimit_write->setObjectName(QString::fromUtf8("elbow_torqueLimit_write"));
        elbow_torqueLimit_write->setEnabled(false);

        gridLayout_7->addWidget(elbow_torqueLimit_write, 6, 1, 1, 1);

        elbow_movingSpeed_write = new QPushButton(gridLayoutWidget_5);
        elbow_movingSpeed_write->setObjectName(QString::fromUtf8("elbow_movingSpeed_write"));
        elbow_movingSpeed_write->setEnabled(false);

        gridLayout_7->addWidget(elbow_movingSpeed_write, 5, 1, 1, 1);

        elbow_ccwSlope_write = new QPushButton(gridLayoutWidget_5);
        elbow_ccwSlope_write->setObjectName(QString::fromUtf8("elbow_ccwSlope_write"));
        elbow_ccwSlope_write->setEnabled(false);

        gridLayout_7->addWidget(elbow_ccwSlope_write, 3, 1, 1, 1);

        elbow_cwSlope_write = new QPushButton(gridLayoutWidget_5);
        elbow_cwSlope_write->setObjectName(QString::fromUtf8("elbow_cwSlope_write"));
        elbow_cwSlope_write->setEnabled(false);

        gridLayout_7->addWidget(elbow_cwSlope_write, 2, 1, 1, 1);

        elbow_punch_write = new QPushButton(gridLayoutWidget_5);
        elbow_punch_write->setObjectName(QString::fromUtf8("elbow_punch_write"));
        elbow_punch_write->setEnabled(false);

        gridLayout_7->addWidget(elbow_punch_write, 13, 1, 1, 1);

        elbow_ccwMargin_write = new QPushButton(gridLayoutWidget_5);
        elbow_ccwMargin_write->setObjectName(QString::fromUtf8("elbow_ccwMargin_write"));
        elbow_ccwMargin_write->setEnabled(false);

        gridLayout_7->addWidget(elbow_ccwMargin_write, 1, 1, 1, 1);

        elbow_cwMargin_write = new QPushButton(gridLayoutWidget_5);
        elbow_cwMargin_write->setObjectName(QString::fromUtf8("elbow_cwMargin_write"));
        elbow_cwMargin_write->setEnabled(false);

        gridLayout_7->addWidget(elbow_cwMargin_write, 0, 1, 1, 1);

        elbow_goalPosition_write = new QPushButton(gridLayoutWidget_5);
        elbow_goalPosition_write->setObjectName(QString::fromUtf8("elbow_goalPosition_write"));
        elbow_goalPosition_write->setEnabled(false);

        gridLayout_7->addWidget(elbow_goalPosition_write, 4, 1, 1, 1);

        elbow_register_write = new QPushButton(gridLayoutWidget_5);
        elbow_register_write->setObjectName(QString::fromUtf8("elbow_register_write"));
        elbow_register_write->setEnabled(false);

        gridLayout_7->addWidget(elbow_register_write, 11, 1, 1, 1);

        gridLayoutWidget_9 = new QWidget(elbow_ram);
        gridLayoutWidget_9->setObjectName(QString::fromUtf8("gridLayoutWidget_9"));
        gridLayoutWidget_9->setGeometry(QRect(10, 20, 141, 301));
        gridLayout_10 = new QGridLayout(gridLayoutWidget_9);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setSizeConstraint(QLayout::SetNoConstraint);
        gridLayout_10->setContentsMargins(0, 0, 0, 0);
        elbow_movingSpeed = new QDoubleSpinBox(gridLayoutWidget_9);
        elbow_movingSpeed->setObjectName(QString::fromUtf8("elbow_movingSpeed"));
        elbow_movingSpeed->setDecimals(0);
        elbow_movingSpeed->setMaximum(1023.000000000000000);

        gridLayout_10->addWidget(elbow_movingSpeed, 5, 1, 1, 1);

        elbow_presentTemp = new QDoubleSpinBox(gridLayoutWidget_9);
        elbow_presentTemp->setObjectName(QString::fromUtf8("elbow_presentTemp"));
        elbow_presentTemp->setReadOnly(true);
        elbow_presentTemp->setButtonSymbols(QAbstractSpinBox::NoButtons);
        elbow_presentTemp->setDecimals(0);
        elbow_presentTemp->setMinimum(50.000000000000000);
        elbow_presentTemp->setMaximum(250.000000000000000);

        gridLayout_10->addWidget(elbow_presentTemp, 10, 1, 1, 1);

        label_65 = new QLabel(gridLayoutWidget_9);
        label_65->setObjectName(QString::fromUtf8("label_65"));
        label_65->setLayoutDirection(Qt::LeftToRight);
        label_65->setAlignment(Qt::AlignCenter);

        gridLayout_10->addWidget(label_65, 6, 0, 1, 1);

        label_64 = new QLabel(gridLayoutWidget_9);
        label_64->setObjectName(QString::fromUtf8("label_64"));
        label_64->setLayoutDirection(Qt::LeftToRight);
        label_64->setAlignment(Qt::AlignCenter);

        gridLayout_10->addWidget(label_64, 4, 0, 1, 1);

        elbow_torqueLimit = new QDoubleSpinBox(gridLayoutWidget_9);
        elbow_torqueLimit->setObjectName(QString::fromUtf8("elbow_torqueLimit"));
        elbow_torqueLimit->setDecimals(0);
        elbow_torqueLimit->setMinimum(0.000000000000000);
        elbow_torqueLimit->setMaximum(1023.000000000000000);
        elbow_torqueLimit->setValue(0.000000000000000);

        gridLayout_10->addWidget(elbow_torqueLimit, 6, 1, 1, 1);

        elbow_lock = new QDoubleSpinBox(gridLayoutWidget_9);
        elbow_lock->setObjectName(QString::fromUtf8("elbow_lock"));
        elbow_lock->setDecimals(0);
        elbow_lock->setMinimum(0.000000000000000);
        elbow_lock->setMaximum(1.000000000000000);
        elbow_lock->setSingleStep(1.000000000000000);

        gridLayout_10->addWidget(elbow_lock, 12, 1, 1, 1);

        elbow_register = new QDoubleSpinBox(gridLayoutWidget_9);
        elbow_register->setObjectName(QString::fromUtf8("elbow_register"));
        elbow_register->setDecimals(0);
        elbow_register->setMaximum(1.000000000000000);

        gridLayout_10->addWidget(elbow_register, 11, 1, 1, 1);

        elbow_presentPosition = new QDoubleSpinBox(gridLayoutWidget_9);
        elbow_presentPosition->setObjectName(QString::fromUtf8("elbow_presentPosition"));
        elbow_presentPosition->setReadOnly(true);
        elbow_presentPosition->setButtonSymbols(QAbstractSpinBox::NoButtons);
        elbow_presentPosition->setDecimals(0);
        elbow_presentPosition->setMinimum(0.000000000000000);
        elbow_presentPosition->setMaximum(1023.000000000000000);
        elbow_presentPosition->setValue(0.000000000000000);

        gridLayout_10->addWidget(elbow_presentPosition, 7, 1, 1, 1);

        elbow_presentSpeed = new QDoubleSpinBox(gridLayoutWidget_9);
        elbow_presentSpeed->setObjectName(QString::fromUtf8("elbow_presentSpeed"));
        elbow_presentSpeed->setButtonSymbols(QAbstractSpinBox::NoButtons);
        elbow_presentSpeed->setDecimals(0);
        elbow_presentSpeed->setMinimum(0.000000000000000);
        elbow_presentSpeed->setMaximum(1023.000000000000000);
        elbow_presentSpeed->setValue(0.000000000000000);

        gridLayout_10->addWidget(elbow_presentSpeed, 8, 1, 1, 1);

        elbow_presentLoad = new QDoubleSpinBox(gridLayoutWidget_9);
        elbow_presentLoad->setObjectName(QString::fromUtf8("elbow_presentLoad"));
        elbow_presentLoad->setButtonSymbols(QAbstractSpinBox::NoButtons);
        elbow_presentLoad->setDecimals(0);
        elbow_presentLoad->setMinimum(50.000000000000000);
        elbow_presentLoad->setMaximum(250.000000000000000);

        gridLayout_10->addWidget(elbow_presentLoad, 9, 1, 1, 1);

        label_56 = new QLabel(gridLayoutWidget_9);
        label_56->setObjectName(QString::fromUtf8("label_56"));
        label_56->setLayoutDirection(Qt::LeftToRight);
        label_56->setAlignment(Qt::AlignCenter);

        gridLayout_10->addWidget(label_56, 7, 0, 1, 1);

        label_54 = new QLabel(gridLayoutWidget_9);
        label_54->setObjectName(QString::fromUtf8("label_54"));
        label_54->setLayoutDirection(Qt::LeftToRight);
        label_54->setAlignment(Qt::AlignCenter);

        gridLayout_10->addWidget(label_54, 8, 0, 1, 1);

        label_58 = new QLabel(gridLayoutWidget_9);
        label_58->setObjectName(QString::fromUtf8("label_58"));
        label_58->setLayoutDirection(Qt::LeftToRight);
        label_58->setAlignment(Qt::AlignCenter);

        gridLayout_10->addWidget(label_58, 5, 0, 1, 1);

        label_57 = new QLabel(gridLayoutWidget_9);
        label_57->setObjectName(QString::fromUtf8("label_57"));
        label_57->setLayoutDirection(Qt::LeftToRight);
        label_57->setAlignment(Qt::AlignCenter);

        gridLayout_10->addWidget(label_57, 3, 0, 1, 1);

        label_60 = new QLabel(gridLayoutWidget_9);
        label_60->setObjectName(QString::fromUtf8("label_60"));
        label_60->setLayoutDirection(Qt::LeftToRight);
        label_60->setAlignment(Qt::AlignCenter);

        gridLayout_10->addWidget(label_60, 12, 0, 1, 1);

        elbow_punch = new QDoubleSpinBox(gridLayoutWidget_9);
        elbow_punch->setObjectName(QString::fromUtf8("elbow_punch"));
        elbow_punch->setDecimals(0);
        elbow_punch->setMinimum(32.000000000000000);
        elbow_punch->setMaximum(1023.000000000000000);

        gridLayout_10->addWidget(elbow_punch, 13, 1, 1, 1);

        elbow_cwMargin = new QDoubleSpinBox(gridLayoutWidget_9);
        elbow_cwMargin->setObjectName(QString::fromUtf8("elbow_cwMargin"));
        elbow_cwMargin->setDecimals(0);
        elbow_cwMargin->setMinimum(1.000000000000000);
        elbow_cwMargin->setMaximum(254.000000000000000);

        gridLayout_10->addWidget(elbow_cwMargin, 0, 1, 1, 1);

        label_59 = new QLabel(gridLayoutWidget_9);
        label_59->setObjectName(QString::fromUtf8("label_59"));
        label_59->setLayoutDirection(Qt::LeftToRight);
        label_59->setAlignment(Qt::AlignCenter);

        gridLayout_10->addWidget(label_59, 2, 0, 1, 1);

        label_62 = new QLabel(gridLayoutWidget_9);
        label_62->setObjectName(QString::fromUtf8("label_62"));
        label_62->setLayoutDirection(Qt::LeftToRight);
        label_62->setAlignment(Qt::AlignCenter);

        gridLayout_10->addWidget(label_62, 11, 0, 1, 1);

        elbow_ccwMargin = new QDoubleSpinBox(gridLayoutWidget_9);
        elbow_ccwMargin->setObjectName(QString::fromUtf8("elbow_ccwMargin"));
        elbow_ccwMargin->setDecimals(0);
        elbow_ccwMargin->setMinimum(1.000000000000000);
        elbow_ccwMargin->setMaximum(254.000000000000000);

        gridLayout_10->addWidget(elbow_ccwMargin, 1, 1, 1, 1);

        label_52 = new QLabel(gridLayoutWidget_9);
        label_52->setObjectName(QString::fromUtf8("label_52"));
        label_52->setLayoutDirection(Qt::LeftToRight);
        label_52->setAlignment(Qt::AlignCenter);

        gridLayout_10->addWidget(label_52, 13, 0, 1, 1);

        label_53 = new QLabel(gridLayoutWidget_9);
        label_53->setObjectName(QString::fromUtf8("label_53"));
        label_53->setLayoutDirection(Qt::LeftToRight);
        label_53->setAlignment(Qt::AlignCenter);

        gridLayout_10->addWidget(label_53, 10, 0, 1, 1);

        label_55 = new QLabel(gridLayoutWidget_9);
        label_55->setObjectName(QString::fromUtf8("label_55"));
        label_55->setLayoutDirection(Qt::LeftToRight);
        label_55->setAlignment(Qt::AlignCenter);

        gridLayout_10->addWidget(label_55, 9, 0, 1, 1);

        label_63 = new QLabel(gridLayoutWidget_9);
        label_63->setObjectName(QString::fromUtf8("label_63"));
        label_63->setLayoutDirection(Qt::LeftToRight);
        label_63->setAlignment(Qt::AlignCenter);

        gridLayout_10->addWidget(label_63, 1, 0, 1, 1);

        elbow_goalPosition = new QDoubleSpinBox(gridLayoutWidget_9);
        elbow_goalPosition->setObjectName(QString::fromUtf8("elbow_goalPosition"));
        elbow_goalPosition->setDecimals(0);
        elbow_goalPosition->setMaximum(1023.000000000000000);

        gridLayout_10->addWidget(elbow_goalPosition, 4, 1, 1, 1);

        label_66 = new QLabel(gridLayoutWidget_9);
        label_66->setObjectName(QString::fromUtf8("label_66"));
        label_66->setLayoutDirection(Qt::LeftToRight);
        label_66->setAlignment(Qt::AlignCenter);

        gridLayout_10->addWidget(label_66, 0, 0, 1, 1);

        elbow_cwSlope = new QComboBox(gridLayoutWidget_9);
        elbow_cwSlope->addItem(QString());
        elbow_cwSlope->addItem(QString());
        elbow_cwSlope->addItem(QString());
        elbow_cwSlope->addItem(QString());
        elbow_cwSlope->addItem(QString());
        elbow_cwSlope->addItem(QString());
        elbow_cwSlope->addItem(QString());
        elbow_cwSlope->setObjectName(QString::fromUtf8("elbow_cwSlope"));

        gridLayout_10->addWidget(elbow_cwSlope, 2, 1, 1, 1);

        elbow_ccwSlope = new QComboBox(gridLayoutWidget_9);
        elbow_ccwSlope->addItem(QString());
        elbow_ccwSlope->addItem(QString());
        elbow_ccwSlope->addItem(QString());
        elbow_ccwSlope->addItem(QString());
        elbow_ccwSlope->addItem(QString());
        elbow_ccwSlope->addItem(QString());
        elbow_ccwSlope->addItem(QString());
        elbow_ccwSlope->setObjectName(QString::fromUtf8("elbow_ccwSlope"));

        gridLayout_10->addWidget(elbow_ccwSlope, 3, 1, 1, 1);

        shoulder = new QGroupBox(Qt_Dynamixel);
        shoulder->setObjectName(QString::fromUtf8("shoulder"));
        shoulder->setGeometry(QRect(10, 0, 261, 691));
        shoulder->setStyleSheet(QString::fromUtf8(" QGroupBox {\n"
" background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                   stop: 0 #E0E0E0, stop: 1 #FFFFFF);\n"
" border: 2px solid gray;\n"
" border-radius: 5px;\n"
" margin-top: 1ex; /* leave space at the top for the title */\n"
"}"));
        shoulder_eeprom = new QGroupBox(shoulder);
        shoulder_eeprom->setObjectName(QString::fromUtf8("shoulder_eeprom"));
        shoulder_eeprom->setGeometry(QRect(10, 20, 241, 321));
        gridLayoutWidget_4 = new QWidget(shoulder_eeprom);
        gridLayoutWidget_4->setObjectName(QString::fromUtf8("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(10, 20, 133, 291));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_4);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetNoConstraint);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_23 = new QLabel(gridLayoutWidget_4);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setLayoutDirection(Qt::LeftToRight);
        label_23->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_23, 12, 0, 1, 1);

        label_24 = new QLabel(gridLayoutWidget_4);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setLayoutDirection(Qt::LeftToRight);
        label_24->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_24, 9, 0, 1, 1);

        label_25 = new QLabel(gridLayoutWidget_4);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setLayoutDirection(Qt::LeftToRight);
        label_25->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_25, 8, 0, 1, 1);

        shoulder_alarmLed = new QDoubleSpinBox(gridLayoutWidget_4);
        shoulder_alarmLed->setObjectName(QString::fromUtf8("shoulder_alarmLed"));
        shoulder_alarmLed->setDecimals(0);
        shoulder_alarmLed->setMaximum(127.000000000000000);

        gridLayout_2->addWidget(shoulder_alarmLed, 12, 1, 1, 1);

        label_15 = new QLabel(gridLayoutWidget_4);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setLayoutDirection(Qt::LeftToRight);
        label_15->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_15, 7, 0, 1, 1);

        label_26 = new QLabel(gridLayoutWidget_4);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setLayoutDirection(Qt::LeftToRight);
        label_26->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_26, 3, 0, 1, 1);

        label_27 = new QLabel(gridLayoutWidget_4);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setLayoutDirection(Qt::LeftToRight);
        label_27->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_27, 5, 0, 1, 1);

        label_9 = new QLabel(gridLayoutWidget_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setLayoutDirection(Qt::LeftToRight);
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_9, 2, 0, 1, 1);

        label_28 = new QLabel(gridLayoutWidget_4);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setLayoutDirection(Qt::LeftToRight);
        label_28->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_28, 11, 0, 1, 1);

        shoulder_firmware = new QDoubleSpinBox(gridLayoutWidget_4);
        shoulder_firmware->setObjectName(QString::fromUtf8("shoulder_firmware"));
        shoulder_firmware->setEnabled(true);
        shoulder_firmware->setReadOnly(true);
        shoulder_firmware->setButtonSymbols(QAbstractSpinBox::NoButtons);
        shoulder_firmware->setDecimals(0);

        gridLayout_2->addWidget(shoulder_firmware, 1, 1, 1, 1);

        shoulder_modelNumber = new QDoubleSpinBox(gridLayoutWidget_4);
        shoulder_modelNumber->setObjectName(QString::fromUtf8("shoulder_modelNumber"));
        shoulder_modelNumber->setEnabled(true);
        shoulder_modelNumber->setReadOnly(true);
        shoulder_modelNumber->setButtonSymbols(QAbstractSpinBox::NoButtons);
        shoulder_modelNumber->setDecimals(0);

        gridLayout_2->addWidget(shoulder_modelNumber, 0, 1, 1, 1);

        label_29 = new QLabel(gridLayoutWidget_4);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setLayoutDirection(Qt::LeftToRight);
        label_29->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_29, 13, 0, 1, 1);

        label_30 = new QLabel(gridLayoutWidget_4);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setLayoutDirection(Qt::LeftToRight);
        label_30->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_30, 10, 0, 1, 1);

        shoulder_returnDelay = new QDoubleSpinBox(gridLayoutWidget_4);
        shoulder_returnDelay->setObjectName(QString::fromUtf8("shoulder_returnDelay"));
        shoulder_returnDelay->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        shoulder_returnDelay->setDecimals(0);
        shoulder_returnDelay->setMaximum(254.000000000000000);

        gridLayout_2->addWidget(shoulder_returnDelay, 4, 1, 1, 1);

        shoulder_alarmShutdown = new QDoubleSpinBox(gridLayoutWidget_4);
        shoulder_alarmShutdown->setObjectName(QString::fromUtf8("shoulder_alarmShutdown"));
        shoulder_alarmShutdown->setDecimals(0);
        shoulder_alarmShutdown->setMaximum(127.000000000000000);

        gridLayout_2->addWidget(shoulder_alarmShutdown, 13, 1, 1, 1);

        label_31 = new QLabel(gridLayoutWidget_4);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setLayoutDirection(Qt::LeftToRight);
        label_31->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_31, 1, 0, 1, 1);

        label_32 = new QLabel(gridLayoutWidget_4);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setLayoutDirection(Qt::LeftToRight);
        label_32->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_32, 4, 0, 1, 1);

        label_33 = new QLabel(gridLayoutWidget_4);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setLayoutDirection(Qt::LeftToRight);
        label_33->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_33, 6, 0, 1, 1);

        shoulder_cw = new QDoubleSpinBox(gridLayoutWidget_4);
        shoulder_cw->setObjectName(QString::fromUtf8("shoulder_cw"));
        shoulder_cw->setDecimals(0);
        shoulder_cw->setMaximum(1023.000000000000000);

        gridLayout_2->addWidget(shoulder_cw, 5, 1, 1, 1);

        shoulder_hLimitTemp = new QDoubleSpinBox(gridLayoutWidget_4);
        shoulder_hLimitTemp->setObjectName(QString::fromUtf8("shoulder_hLimitTemp"));
        shoulder_hLimitTemp->setDecimals(0);
        shoulder_hLimitTemp->setMinimum(0.000000000000000);
        shoulder_hLimitTemp->setMaximum(99.000000000000000);
        shoulder_hLimitTemp->setValue(0.000000000000000);

        gridLayout_2->addWidget(shoulder_hLimitTemp, 7, 1, 1, 1);

        shoulder_maxTorque = new QDoubleSpinBox(gridLayoutWidget_4);
        shoulder_maxTorque->setObjectName(QString::fromUtf8("shoulder_maxTorque"));
        shoulder_maxTorque->setDecimals(0);
        shoulder_maxTorque->setMaximum(255.000000000000000);

        gridLayout_2->addWidget(shoulder_maxTorque, 10, 1, 1, 1);

        shoulder_hLimitVoltage = new QDoubleSpinBox(gridLayoutWidget_4);
        shoulder_hLimitVoltage->setObjectName(QString::fromUtf8("shoulder_hLimitVoltage"));
        shoulder_hLimitVoltage->setDecimals(0);
        shoulder_hLimitVoltage->setMinimum(50.000000000000000);
        shoulder_hLimitVoltage->setMaximum(250.000000000000000);

        gridLayout_2->addWidget(shoulder_hLimitVoltage, 8, 1, 1, 1);

        shoulder_statusReturn = new QDoubleSpinBox(gridLayoutWidget_4);
        shoulder_statusReturn->setObjectName(QString::fromUtf8("shoulder_statusReturn"));
        shoulder_statusReturn->setDecimals(0);
        shoulder_statusReturn->setMinimum(0.000000000000000);
        shoulder_statusReturn->setMaximum(2.000000000000000);
        shoulder_statusReturn->setSingleStep(1.000000000000000);

        gridLayout_2->addWidget(shoulder_statusReturn, 11, 1, 1, 1);

        label_34 = new QLabel(gridLayoutWidget_4);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setLayoutDirection(Qt::LeftToRight);
        label_34->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_34, 0, 0, 1, 1);

        shoulder_lLimitVoltage = new QDoubleSpinBox(gridLayoutWidget_4);
        shoulder_lLimitVoltage->setObjectName(QString::fromUtf8("shoulder_lLimitVoltage"));
        shoulder_lLimitVoltage->setDecimals(0);
        shoulder_lLimitVoltage->setMinimum(50.000000000000000);
        shoulder_lLimitVoltage->setMaximum(250.000000000000000);

        gridLayout_2->addWidget(shoulder_lLimitVoltage, 9, 1, 1, 1);

        shoulder_ccw = new QDoubleSpinBox(gridLayoutWidget_4);
        shoulder_ccw->setObjectName(QString::fromUtf8("shoulder_ccw"));
        shoulder_ccw->setDecimals(0);
        shoulder_ccw->setMinimum(0.000000000000000);
        shoulder_ccw->setMaximum(1023.000000000000000);
        shoulder_ccw->setValue(0.000000000000000);

        gridLayout_2->addWidget(shoulder_ccw, 6, 1, 1, 1);

        shoulder_id = new QDoubleSpinBox(gridLayoutWidget_4);
        shoulder_id->setObjectName(QString::fromUtf8("shoulder_id"));
        shoulder_id->setReadOnly(true);
        shoulder_id->setButtonSymbols(QAbstractSpinBox::NoButtons);
        shoulder_id->setDecimals(0);
        shoulder_id->setMinimum(1.000000000000000);
        shoulder_id->setMaximum(253.000000000000000);

        gridLayout_2->addWidget(shoulder_id, 2, 1, 1, 1);

        shoulder_baudRate = new QComboBox(gridLayoutWidget_4);
        shoulder_baudRate->addItem(QString());
        shoulder_baudRate->addItem(QString());
        shoulder_baudRate->addItem(QString());
        shoulder_baudRate->addItem(QString());
        shoulder_baudRate->addItem(QString());
        shoulder_baudRate->addItem(QString());
        shoulder_baudRate->addItem(QString());
        shoulder_baudRate->addItem(QString());
        shoulder_baudRate->addItem(QString());
        shoulder_baudRate->setObjectName(QString::fromUtf8("shoulder_baudRate"));

        gridLayout_2->addWidget(shoulder_baudRate, 3, 1, 1, 1);

        gridLayoutWidget_3 = new QWidget(shoulder_eeprom);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(150, 80, 81, 231));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        shoulder_ccw_write = new QPushButton(gridLayoutWidget_3);
        shoulder_ccw_write->setObjectName(QString::fromUtf8("shoulder_ccw_write"));
        shoulder_ccw_write->setEnabled(false);

        gridLayout_4->addWidget(shoulder_ccw_write, 3, 1, 1, 1);

        shoulder_lLimitVoltage_write = new QPushButton(gridLayoutWidget_3);
        shoulder_lLimitVoltage_write->setObjectName(QString::fromUtf8("shoulder_lLimitVoltage_write"));
        shoulder_lLimitVoltage_write->setEnabled(false);

        gridLayout_4->addWidget(shoulder_lLimitVoltage_write, 6, 1, 1, 1);

        shoulder_ccw_read = new QPushButton(gridLayoutWidget_3);
        shoulder_ccw_read->setObjectName(QString::fromUtf8("shoulder_ccw_read"));
        shoulder_ccw_read->setEnabled(false);

        gridLayout_4->addWidget(shoulder_ccw_read, 3, 0, 1, 1);

        shoulder_lLimiitVoltage_read = new QPushButton(gridLayoutWidget_3);
        shoulder_lLimiitVoltage_read->setObjectName(QString::fromUtf8("shoulder_lLimiitVoltage_read"));
        shoulder_lLimiitVoltage_read->setEnabled(false);

        gridLayout_4->addWidget(shoulder_lLimiitVoltage_read, 6, 0, 1, 1);

        shoulder_maxTorque_write = new QPushButton(gridLayoutWidget_3);
        shoulder_maxTorque_write->setObjectName(QString::fromUtf8("shoulder_maxTorque_write"));
        shoulder_maxTorque_write->setEnabled(false);

        gridLayout_4->addWidget(shoulder_maxTorque_write, 7, 1, 1, 1);

        shoulder_baudRate_write = new QPushButton(gridLayoutWidget_3);
        shoulder_baudRate_write->setObjectName(QString::fromUtf8("shoulder_baudRate_write"));
        shoulder_baudRate_write->setEnabled(false);

        gridLayout_4->addWidget(shoulder_baudRate_write, 0, 1, 1, 1);

        shoulder_hLimitTemp_read = new QPushButton(gridLayoutWidget_3);
        shoulder_hLimitTemp_read->setObjectName(QString::fromUtf8("shoulder_hLimitTemp_read"));
        shoulder_hLimitTemp_read->setEnabled(false);

        gridLayout_4->addWidget(shoulder_hLimitTemp_read, 4, 0, 1, 1);

        shoulder_hLimitVoltage_write = new QPushButton(gridLayoutWidget_3);
        shoulder_hLimitVoltage_write->setObjectName(QString::fromUtf8("shoulder_hLimitVoltage_write"));
        shoulder_hLimitVoltage_write->setEnabled(false);

        gridLayout_4->addWidget(shoulder_hLimitVoltage_write, 5, 1, 1, 1);

        shoulder_maxTorque_read = new QPushButton(gridLayoutWidget_3);
        shoulder_maxTorque_read->setObjectName(QString::fromUtf8("shoulder_maxTorque_read"));
        shoulder_maxTorque_read->setEnabled(false);

        gridLayout_4->addWidget(shoulder_maxTorque_read, 7, 0, 1, 1);

        shoulder_statusReturn_read = new QPushButton(gridLayoutWidget_3);
        shoulder_statusReturn_read->setObjectName(QString::fromUtf8("shoulder_statusReturn_read"));
        shoulder_statusReturn_read->setEnabled(false);

        gridLayout_4->addWidget(shoulder_statusReturn_read, 8, 0, 1, 1);

        shoulder_alarmShutdown_read = new QPushButton(gridLayoutWidget_3);
        shoulder_alarmShutdown_read->setObjectName(QString::fromUtf8("shoulder_alarmShutdown_read"));
        shoulder_alarmShutdown_read->setEnabled(false);

        gridLayout_4->addWidget(shoulder_alarmShutdown_read, 10, 0, 1, 1);

        shoulder_cw_read = new QPushButton(gridLayoutWidget_3);
        shoulder_cw_read->setObjectName(QString::fromUtf8("shoulder_cw_read"));
        shoulder_cw_read->setEnabled(false);

        gridLayout_4->addWidget(shoulder_cw_read, 2, 0, 1, 1);

        shoulder_cw_write = new QPushButton(gridLayoutWidget_3);
        shoulder_cw_write->setObjectName(QString::fromUtf8("shoulder_cw_write"));
        shoulder_cw_write->setEnabled(false);

        gridLayout_4->addWidget(shoulder_cw_write, 2, 1, 1, 1);

        shoulder_alarmLed_read = new QPushButton(gridLayoutWidget_3);
        shoulder_alarmLed_read->setObjectName(QString::fromUtf8("shoulder_alarmLed_read"));
        shoulder_alarmLed_read->setEnabled(false);

        gridLayout_4->addWidget(shoulder_alarmLed_read, 9, 0, 1, 1);

        shoulder_alarmLed_write = new QPushButton(gridLayoutWidget_3);
        shoulder_alarmLed_write->setObjectName(QString::fromUtf8("shoulder_alarmLed_write"));
        shoulder_alarmLed_write->setEnabled(false);

        gridLayout_4->addWidget(shoulder_alarmLed_write, 9, 1, 1, 1);

        shoulder_hLimitTemp_write = new QPushButton(gridLayoutWidget_3);
        shoulder_hLimitTemp_write->setObjectName(QString::fromUtf8("shoulder_hLimitTemp_write"));
        shoulder_hLimitTemp_write->setEnabled(false);

        gridLayout_4->addWidget(shoulder_hLimitTemp_write, 4, 1, 1, 1);

        shoulder_statusReturn_write = new QPushButton(gridLayoutWidget_3);
        shoulder_statusReturn_write->setObjectName(QString::fromUtf8("shoulder_statusReturn_write"));
        shoulder_statusReturn_write->setEnabled(false);

        gridLayout_4->addWidget(shoulder_statusReturn_write, 8, 1, 1, 1);

        shoulder_hLimitVoltage_read = new QPushButton(gridLayoutWidget_3);
        shoulder_hLimitVoltage_read->setObjectName(QString::fromUtf8("shoulder_hLimitVoltage_read"));
        shoulder_hLimitVoltage_read->setEnabled(false);

        gridLayout_4->addWidget(shoulder_hLimitVoltage_read, 5, 0, 1, 1);

        shoulder_alarmShutdown_write = new QPushButton(gridLayoutWidget_3);
        shoulder_alarmShutdown_write->setObjectName(QString::fromUtf8("shoulder_alarmShutdown_write"));
        shoulder_alarmShutdown_write->setEnabled(false);

        gridLayout_4->addWidget(shoulder_alarmShutdown_write, 10, 1, 1, 1);

        shoulder_returnDelay_read = new QPushButton(gridLayoutWidget_3);
        shoulder_returnDelay_read->setObjectName(QString::fromUtf8("shoulder_returnDelay_read"));
        shoulder_returnDelay_read->setEnabled(false);

        gridLayout_4->addWidget(shoulder_returnDelay_read, 1, 0, 1, 1);

        shoulder_baudRate_read = new QPushButton(gridLayoutWidget_3);
        shoulder_baudRate_read->setObjectName(QString::fromUtf8("shoulder_baudRate_read"));
        shoulder_baudRate_read->setEnabled(false);

        gridLayout_4->addWidget(shoulder_baudRate_read, 0, 0, 1, 1);

        shoulder_returnDelay_write = new QPushButton(gridLayoutWidget_3);
        shoulder_returnDelay_write->setObjectName(QString::fromUtf8("shoulder_returnDelay_write"));
        shoulder_returnDelay_write->setEnabled(false);

        gridLayout_4->addWidget(shoulder_returnDelay_write, 1, 1, 1, 1);

        shoulder_ram = new QGroupBox(shoulder);
        shoulder_ram->setObjectName(QString::fromUtf8("shoulder_ram"));
        shoulder_ram->setGeometry(QRect(10, 350, 241, 331));
        gridLayoutWidget_10 = new QWidget(shoulder_ram);
        gridLayoutWidget_10->setObjectName(QString::fromUtf8("gridLayoutWidget_10"));
        gridLayoutWidget_10->setGeometry(QRect(10, 20, 134, 301));
        gridLayout_11 = new QGridLayout(gridLayoutWidget_10);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setSizeConstraint(QLayout::SetNoConstraint);
        gridLayout_11->setContentsMargins(0, 0, 0, 0);
        shoulder_movingSpeed = new QDoubleSpinBox(gridLayoutWidget_10);
        shoulder_movingSpeed->setObjectName(QString::fromUtf8("shoulder_movingSpeed"));
        shoulder_movingSpeed->setDecimals(0);
        shoulder_movingSpeed->setMaximum(1023.000000000000000);

        gridLayout_11->addWidget(shoulder_movingSpeed, 5, 1, 1, 1);

        shoulder_presentTemp = new QDoubleSpinBox(gridLayoutWidget_10);
        shoulder_presentTemp->setObjectName(QString::fromUtf8("shoulder_presentTemp"));
        shoulder_presentTemp->setReadOnly(true);
        shoulder_presentTemp->setButtonSymbols(QAbstractSpinBox::NoButtons);
        shoulder_presentTemp->setDecimals(0);
        shoulder_presentTemp->setMinimum(50.000000000000000);
        shoulder_presentTemp->setMaximum(250.000000000000000);

        gridLayout_11->addWidget(shoulder_presentTemp, 10, 1, 1, 1);

        label_67 = new QLabel(gridLayoutWidget_10);
        label_67->setObjectName(QString::fromUtf8("label_67"));
        label_67->setLayoutDirection(Qt::LeftToRight);
        label_67->setAlignment(Qt::AlignCenter);

        gridLayout_11->addWidget(label_67, 6, 0, 1, 1);

        label_68 = new QLabel(gridLayoutWidget_10);
        label_68->setObjectName(QString::fromUtf8("label_68"));
        label_68->setLayoutDirection(Qt::LeftToRight);
        label_68->setAlignment(Qt::AlignCenter);

        gridLayout_11->addWidget(label_68, 4, 0, 1, 1);

        shoulder_torqueLimit = new QDoubleSpinBox(gridLayoutWidget_10);
        shoulder_torqueLimit->setObjectName(QString::fromUtf8("shoulder_torqueLimit"));
        shoulder_torqueLimit->setDecimals(0);
        shoulder_torqueLimit->setMinimum(0.000000000000000);
        shoulder_torqueLimit->setMaximum(1023.000000000000000);
        shoulder_torqueLimit->setValue(0.000000000000000);

        gridLayout_11->addWidget(shoulder_torqueLimit, 6, 1, 1, 1);

        shoulder_lock = new QDoubleSpinBox(gridLayoutWidget_10);
        shoulder_lock->setObjectName(QString::fromUtf8("shoulder_lock"));
        shoulder_lock->setDecimals(0);
        shoulder_lock->setMinimum(0.000000000000000);
        shoulder_lock->setMaximum(1.000000000000000);
        shoulder_lock->setSingleStep(1.000000000000000);

        gridLayout_11->addWidget(shoulder_lock, 12, 1, 1, 1);

        shoulder_register = new QDoubleSpinBox(gridLayoutWidget_10);
        shoulder_register->setObjectName(QString::fromUtf8("shoulder_register"));
        shoulder_register->setDecimals(0);
        shoulder_register->setMaximum(1.000000000000000);

        gridLayout_11->addWidget(shoulder_register, 11, 1, 1, 1);

        shoulder_presentPosition = new QDoubleSpinBox(gridLayoutWidget_10);
        shoulder_presentPosition->setObjectName(QString::fromUtf8("shoulder_presentPosition"));
        shoulder_presentPosition->setReadOnly(true);
        shoulder_presentPosition->setButtonSymbols(QAbstractSpinBox::NoButtons);
        shoulder_presentPosition->setDecimals(0);
        shoulder_presentPosition->setMinimum(0.000000000000000);
        shoulder_presentPosition->setMaximum(1023.000000000000000);
        shoulder_presentPosition->setValue(0.000000000000000);

        gridLayout_11->addWidget(shoulder_presentPosition, 7, 1, 1, 1);

        shoulder_presentSpeed = new QDoubleSpinBox(gridLayoutWidget_10);
        shoulder_presentSpeed->setObjectName(QString::fromUtf8("shoulder_presentSpeed"));
        shoulder_presentSpeed->setReadOnly(true);
        shoulder_presentSpeed->setButtonSymbols(QAbstractSpinBox::NoButtons);
        shoulder_presentSpeed->setDecimals(0);
        shoulder_presentSpeed->setMinimum(0.000000000000000);
        shoulder_presentSpeed->setMaximum(1023.000000000000000);
        shoulder_presentSpeed->setValue(0.000000000000000);

        gridLayout_11->addWidget(shoulder_presentSpeed, 8, 1, 1, 1);

        shoulder_presentLoad = new QDoubleSpinBox(gridLayoutWidget_10);
        shoulder_presentLoad->setObjectName(QString::fromUtf8("shoulder_presentLoad"));
        shoulder_presentLoad->setReadOnly(true);
        shoulder_presentLoad->setButtonSymbols(QAbstractSpinBox::NoButtons);
        shoulder_presentLoad->setDecimals(0);
        shoulder_presentLoad->setMinimum(50.000000000000000);
        shoulder_presentLoad->setMaximum(250.000000000000000);

        gridLayout_11->addWidget(shoulder_presentLoad, 9, 1, 1, 1);

        label_61 = new QLabel(gridLayoutWidget_10);
        label_61->setObjectName(QString::fromUtf8("label_61"));
        label_61->setLayoutDirection(Qt::LeftToRight);
        label_61->setAlignment(Qt::AlignCenter);

        gridLayout_11->addWidget(label_61, 7, 0, 1, 1);

        label_69 = new QLabel(gridLayoutWidget_10);
        label_69->setObjectName(QString::fromUtf8("label_69"));
        label_69->setLayoutDirection(Qt::LeftToRight);
        label_69->setAlignment(Qt::AlignCenter);

        gridLayout_11->addWidget(label_69, 8, 0, 1, 1);

        label_70 = new QLabel(gridLayoutWidget_10);
        label_70->setObjectName(QString::fromUtf8("label_70"));
        label_70->setLayoutDirection(Qt::LeftToRight);
        label_70->setAlignment(Qt::AlignCenter);

        gridLayout_11->addWidget(label_70, 5, 0, 1, 1);

        label_71 = new QLabel(gridLayoutWidget_10);
        label_71->setObjectName(QString::fromUtf8("label_71"));
        label_71->setLayoutDirection(Qt::LeftToRight);
        label_71->setAlignment(Qt::AlignCenter);

        gridLayout_11->addWidget(label_71, 3, 0, 1, 1);

        label_72 = new QLabel(gridLayoutWidget_10);
        label_72->setObjectName(QString::fromUtf8("label_72"));
        label_72->setLayoutDirection(Qt::LeftToRight);
        label_72->setAlignment(Qt::AlignCenter);

        gridLayout_11->addWidget(label_72, 12, 0, 1, 1);

        shoulder_punch = new QDoubleSpinBox(gridLayoutWidget_10);
        shoulder_punch->setObjectName(QString::fromUtf8("shoulder_punch"));
        shoulder_punch->setDecimals(0);
        shoulder_punch->setMinimum(32.000000000000000);
        shoulder_punch->setMaximum(1023.000000000000000);

        gridLayout_11->addWidget(shoulder_punch, 13, 1, 1, 1);

        shoulder_cwMargin = new QDoubleSpinBox(gridLayoutWidget_10);
        shoulder_cwMargin->setObjectName(QString::fromUtf8("shoulder_cwMargin"));
        shoulder_cwMargin->setDecimals(0);
        shoulder_cwMargin->setMinimum(1.000000000000000);
        shoulder_cwMargin->setMaximum(254.000000000000000);

        gridLayout_11->addWidget(shoulder_cwMargin, 0, 1, 1, 1);

        label_73 = new QLabel(gridLayoutWidget_10);
        label_73->setObjectName(QString::fromUtf8("label_73"));
        label_73->setLayoutDirection(Qt::LeftToRight);
        label_73->setAlignment(Qt::AlignCenter);

        gridLayout_11->addWidget(label_73, 2, 0, 1, 1);

        label_74 = new QLabel(gridLayoutWidget_10);
        label_74->setObjectName(QString::fromUtf8("label_74"));
        label_74->setLayoutDirection(Qt::LeftToRight);
        label_74->setAlignment(Qt::AlignCenter);

        gridLayout_11->addWidget(label_74, 11, 0, 1, 1);

        shoulder_ccwMargin = new QDoubleSpinBox(gridLayoutWidget_10);
        shoulder_ccwMargin->setObjectName(QString::fromUtf8("shoulder_ccwMargin"));
        shoulder_ccwMargin->setDecimals(0);
        shoulder_ccwMargin->setMinimum(1.000000000000000);
        shoulder_ccwMargin->setMaximum(254.000000000000000);

        gridLayout_11->addWidget(shoulder_ccwMargin, 1, 1, 1, 1);

        label_75 = new QLabel(gridLayoutWidget_10);
        label_75->setObjectName(QString::fromUtf8("label_75"));
        label_75->setLayoutDirection(Qt::LeftToRight);
        label_75->setAlignment(Qt::AlignCenter);

        gridLayout_11->addWidget(label_75, 13, 0, 1, 1);

        label_76 = new QLabel(gridLayoutWidget_10);
        label_76->setObjectName(QString::fromUtf8("label_76"));
        label_76->setLayoutDirection(Qt::LeftToRight);
        label_76->setAlignment(Qt::AlignCenter);

        gridLayout_11->addWidget(label_76, 10, 0, 1, 1);

        label_77 = new QLabel(gridLayoutWidget_10);
        label_77->setObjectName(QString::fromUtf8("label_77"));
        label_77->setLayoutDirection(Qt::LeftToRight);
        label_77->setAlignment(Qt::AlignCenter);

        gridLayout_11->addWidget(label_77, 9, 0, 1, 1);

        label_78 = new QLabel(gridLayoutWidget_10);
        label_78->setObjectName(QString::fromUtf8("label_78"));
        label_78->setLayoutDirection(Qt::LeftToRight);
        label_78->setAlignment(Qt::AlignCenter);

        gridLayout_11->addWidget(label_78, 1, 0, 1, 1);

        shoulder_goalPosition = new QDoubleSpinBox(gridLayoutWidget_10);
        shoulder_goalPosition->setObjectName(QString::fromUtf8("shoulder_goalPosition"));
        shoulder_goalPosition->setDecimals(0);
        shoulder_goalPosition->setMaximum(1023.000000000000000);

        gridLayout_11->addWidget(shoulder_goalPosition, 4, 1, 1, 1);

        label_79 = new QLabel(gridLayoutWidget_10);
        label_79->setObjectName(QString::fromUtf8("label_79"));
        label_79->setLayoutDirection(Qt::LeftToRight);
        label_79->setAlignment(Qt::AlignCenter);

        gridLayout_11->addWidget(label_79, 0, 0, 1, 1);

        shoulder_cwSlope = new QComboBox(gridLayoutWidget_10);
        shoulder_cwSlope->addItem(QString());
        shoulder_cwSlope->addItem(QString());
        shoulder_cwSlope->addItem(QString());
        shoulder_cwSlope->addItem(QString());
        shoulder_cwSlope->addItem(QString());
        shoulder_cwSlope->addItem(QString());
        shoulder_cwSlope->addItem(QString());
        shoulder_cwSlope->setObjectName(QString::fromUtf8("shoulder_cwSlope"));

        gridLayout_11->addWidget(shoulder_cwSlope, 2, 1, 1, 1);

        shoulder_ccwSlope = new QComboBox(gridLayoutWidget_10);
        shoulder_ccwSlope->addItem(QString());
        shoulder_ccwSlope->addItem(QString());
        shoulder_ccwSlope->addItem(QString());
        shoulder_ccwSlope->addItem(QString());
        shoulder_ccwSlope->addItem(QString());
        shoulder_ccwSlope->addItem(QString());
        shoulder_ccwSlope->addItem(QString());
        shoulder_ccwSlope->setObjectName(QString::fromUtf8("shoulder_ccwSlope"));

        gridLayout_11->addWidget(shoulder_ccwSlope, 3, 1, 1, 1);

        gridLayoutWidget_6 = new QWidget(shoulder_ram);
        gridLayoutWidget_6->setObjectName(QString::fromUtf8("gridLayoutWidget_6"));
        gridLayoutWidget_6->setGeometry(QRect(150, 20, 81, 301));
        gridLayout_8 = new QGridLayout(gridLayoutWidget_6);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        shoulder_goalPosition_read = new QPushButton(gridLayoutWidget_6);
        shoulder_goalPosition_read->setObjectName(QString::fromUtf8("shoulder_goalPosition_read"));
        shoulder_goalPosition_read->setEnabled(false);

        gridLayout_8->addWidget(shoulder_goalPosition_read, 4, 0, 1, 1);

        shoulder_lock_write = new QPushButton(gridLayoutWidget_6);
        shoulder_lock_write->setObjectName(QString::fromUtf8("shoulder_lock_write"));
        shoulder_lock_write->setEnabled(false);

        gridLayout_8->addWidget(shoulder_lock_write, 12, 1, 1, 1);

        shoulder_presentLoad_read = new QPushButton(gridLayoutWidget_6);
        shoulder_presentLoad_read->setObjectName(QString::fromUtf8("shoulder_presentLoad_read"));
        shoulder_presentLoad_read->setEnabled(false);

        gridLayout_8->addWidget(shoulder_presentLoad_read, 9, 0, 1, 1);

        shoulder_presentPosition_read = new QPushButton(gridLayoutWidget_6);
        shoulder_presentPosition_read->setObjectName(QString::fromUtf8("shoulder_presentPosition_read"));
        shoulder_presentPosition_read->setEnabled(false);

        gridLayout_8->addWidget(shoulder_presentPosition_read, 7, 0, 1, 1);

        shoulder_lock_read = new QPushButton(gridLayoutWidget_6);
        shoulder_lock_read->setObjectName(QString::fromUtf8("shoulder_lock_read"));
        shoulder_lock_read->setEnabled(false);

        gridLayout_8->addWidget(shoulder_lock_read, 12, 0, 1, 1);

        shoulder_presentTemp_read = new QPushButton(gridLayoutWidget_6);
        shoulder_presentTemp_read->setObjectName(QString::fromUtf8("shoulder_presentTemp_read"));
        shoulder_presentTemp_read->setEnabled(false);

        gridLayout_8->addWidget(shoulder_presentTemp_read, 10, 0, 1, 1);

        shoulder_register_read = new QPushButton(gridLayoutWidget_6);
        shoulder_register_read->setObjectName(QString::fromUtf8("shoulder_register_read"));
        shoulder_register_read->setEnabled(false);

        gridLayout_8->addWidget(shoulder_register_read, 11, 0, 1, 1);

        shoulder_torqueLimit_read = new QPushButton(gridLayoutWidget_6);
        shoulder_torqueLimit_read->setObjectName(QString::fromUtf8("shoulder_torqueLimit_read"));
        shoulder_torqueLimit_read->setEnabled(false);

        gridLayout_8->addWidget(shoulder_torqueLimit_read, 6, 0, 1, 1);

        shoulder_presentSpeed_read = new QPushButton(gridLayoutWidget_6);
        shoulder_presentSpeed_read->setObjectName(QString::fromUtf8("shoulder_presentSpeed_read"));
        shoulder_presentSpeed_read->setEnabled(false);

        gridLayout_8->addWidget(shoulder_presentSpeed_read, 8, 0, 1, 1);

        shoulder_ccwSlope_read = new QPushButton(gridLayoutWidget_6);
        shoulder_ccwSlope_read->setObjectName(QString::fromUtf8("shoulder_ccwSlope_read"));
        shoulder_ccwSlope_read->setEnabled(false);

        gridLayout_8->addWidget(shoulder_ccwSlope_read, 3, 0, 1, 1);

        shoulder_cwSlope_read = new QPushButton(gridLayoutWidget_6);
        shoulder_cwSlope_read->setObjectName(QString::fromUtf8("shoulder_cwSlope_read"));
        shoulder_cwSlope_read->setEnabled(false);

        gridLayout_8->addWidget(shoulder_cwSlope_read, 2, 0, 1, 1);

        shoulder_ccwMargin_read = new QPushButton(gridLayoutWidget_6);
        shoulder_ccwMargin_read->setObjectName(QString::fromUtf8("shoulder_ccwMargin_read"));
        shoulder_ccwMargin_read->setEnabled(false);

        gridLayout_8->addWidget(shoulder_ccwMargin_read, 1, 0, 1, 1);

        shoulder_cwMargin_read = new QPushButton(gridLayoutWidget_6);
        shoulder_cwMargin_read->setObjectName(QString::fromUtf8("shoulder_cwMargin_read"));
        shoulder_cwMargin_read->setEnabled(false);

        gridLayout_8->addWidget(shoulder_cwMargin_read, 0, 0, 1, 1);

        shoulder_punch_read = new QPushButton(gridLayoutWidget_6);
        shoulder_punch_read->setObjectName(QString::fromUtf8("shoulder_punch_read"));
        shoulder_punch_read->setEnabled(false);

        gridLayout_8->addWidget(shoulder_punch_read, 13, 0, 1, 1);

        shoulder_movingSpeed_read = new QPushButton(gridLayoutWidget_6);
        shoulder_movingSpeed_read->setObjectName(QString::fromUtf8("shoulder_movingSpeed_read"));
        shoulder_movingSpeed_read->setEnabled(false);

        gridLayout_8->addWidget(shoulder_movingSpeed_read, 5, 0, 1, 1);

        shoulder_torqueLimit_write = new QPushButton(gridLayoutWidget_6);
        shoulder_torqueLimit_write->setObjectName(QString::fromUtf8("shoulder_torqueLimit_write"));
        shoulder_torqueLimit_write->setEnabled(false);

        gridLayout_8->addWidget(shoulder_torqueLimit_write, 6, 1, 1, 1);

        shoulder_movingSpeed_write = new QPushButton(gridLayoutWidget_6);
        shoulder_movingSpeed_write->setObjectName(QString::fromUtf8("shoulder_movingSpeed_write"));
        shoulder_movingSpeed_write->setEnabled(false);

        gridLayout_8->addWidget(shoulder_movingSpeed_write, 5, 1, 1, 1);

        shoulder_ccwSlope_write = new QPushButton(gridLayoutWidget_6);
        shoulder_ccwSlope_write->setObjectName(QString::fromUtf8("shoulder_ccwSlope_write"));
        shoulder_ccwSlope_write->setEnabled(false);

        gridLayout_8->addWidget(shoulder_ccwSlope_write, 3, 1, 1, 1);

        shoulder_cwSlope_write = new QPushButton(gridLayoutWidget_6);
        shoulder_cwSlope_write->setObjectName(QString::fromUtf8("shoulder_cwSlope_write"));
        shoulder_cwSlope_write->setEnabled(false);

        gridLayout_8->addWidget(shoulder_cwSlope_write, 2, 1, 1, 1);

        shoulder_punch_write = new QPushButton(gridLayoutWidget_6);
        shoulder_punch_write->setObjectName(QString::fromUtf8("shoulder_punch_write"));
        shoulder_punch_write->setEnabled(false);

        gridLayout_8->addWidget(shoulder_punch_write, 13, 1, 1, 1);

        shoulder_ccwMargin_write = new QPushButton(gridLayoutWidget_6);
        shoulder_ccwMargin_write->setObjectName(QString::fromUtf8("shoulder_ccwMargin_write"));
        shoulder_ccwMargin_write->setEnabled(false);

        gridLayout_8->addWidget(shoulder_ccwMargin_write, 1, 1, 1, 1);

        shoulder_cwMargin_write = new QPushButton(gridLayoutWidget_6);
        shoulder_cwMargin_write->setObjectName(QString::fromUtf8("shoulder_cwMargin_write"));
        shoulder_cwMargin_write->setEnabled(false);

        gridLayout_8->addWidget(shoulder_cwMargin_write, 0, 1, 1, 1);

        shoulder_goalPosition_write = new QPushButton(gridLayoutWidget_6);
        shoulder_goalPosition_write->setObjectName(QString::fromUtf8("shoulder_goalPosition_write"));
        shoulder_goalPosition_write->setEnabled(false);

        gridLayout_8->addWidget(shoulder_goalPosition_write, 4, 1, 1, 1);

        shoulder_register_write = new QPushButton(gridLayoutWidget_6);
        shoulder_register_write->setObjectName(QString::fromUtf8("shoulder_register_write"));
        shoulder_register_write->setEnabled(false);

        gridLayout_8->addWidget(shoulder_register_write, 11, 1, 1, 1);

        h = new QGroupBox(Qt_Dynamixel);
        h->setObjectName(QString::fromUtf8("h"));
        h->setGeometry(QRect(640, 0, 241, 171));
        h->setStyleSheet(QString::fromUtf8(" QGroupBox {\n"
" background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                   stop: 0 #E0E0E0, stop: 1 #FFFFFF);\n"
" border: 2px solid gray;\n"
" border-radius: 5px;\n"
" margin-top: 1ex; /* leave space at the top for the title */\n"
"}"));
        groupBox_8 = new QGroupBox(h);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setGeometry(QRect(10, 20, 221, 101));
        gridLayoutWidget_7 = new QWidget(groupBox_8);
        gridLayoutWidget_7->setObjectName(QString::fromUtf8("gridLayoutWidget_7"));
        gridLayoutWidget_7->setGeometry(QRect(10, 10, 123, 81));
        gridLayout_5 = new QGridLayout(gridLayoutWidget_7);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        hand_id = new QSpinBox(gridLayoutWidget_7);
        hand_id->setObjectName(QString::fromUtf8("hand_id"));
        hand_id->setButtonSymbols(QAbstractSpinBox::NoButtons);
        hand_id->setMaximum(254);

        gridLayout_5->addWidget(hand_id, 0, 1, 1, 1);

        hand_goalPosition = new QSpinBox(gridLayoutWidget_7);
        hand_goalPosition->setObjectName(QString::fromUtf8("hand_goalPosition"));
        hand_goalPosition->setMaximum(1023);

        gridLayout_5->addWidget(hand_goalPosition, 2, 1, 1, 1);

        label = new QLabel(gridLayoutWidget_7);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label, 1, 0, 1, 1);

        hand_maxTorque = new QSpinBox(gridLayoutWidget_7);
        hand_maxTorque->setObjectName(QString::fromUtf8("hand_maxTorque"));
        hand_maxTorque->setMaximum(255);

        gridLayout_5->addWidget(hand_maxTorque, 1, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget_7);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_2, 0, 0, 1, 1);

        hand_movingSpeed = new QSpinBox(gridLayoutWidget_7);
        hand_movingSpeed->setObjectName(QString::fromUtf8("hand_movingSpeed"));
        hand_movingSpeed->setMaximum(1023);

        gridLayout_5->addWidget(hand_movingSpeed, 3, 1, 1, 1);

        label_3 = new QLabel(gridLayoutWidget_7);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_3, 2, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget_7);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_4, 3, 0, 1, 1);

        gridLayoutWidget_8 = new QWidget(groupBox_8);
        gridLayoutWidget_8->setObjectName(QString::fromUtf8("gridLayoutWidget_8"));
        gridLayoutWidget_8->setGeometry(QRect(140, 30, 71, 61));
        gridLayout_6 = new QGridLayout(gridLayoutWidget_8);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        hand_goalPosition_write = new QPushButton(gridLayoutWidget_8);
        hand_goalPosition_write->setObjectName(QString::fromUtf8("hand_goalPosition_write"));
        hand_goalPosition_write->setEnabled(false);

        gridLayout_6->addWidget(hand_goalPosition_write, 1, 1, 1, 1);

        hand_maxTorque_read = new QPushButton(gridLayoutWidget_8);
        hand_maxTorque_read->setObjectName(QString::fromUtf8("hand_maxTorque_read"));
        hand_maxTorque_read->setEnabled(false);

        gridLayout_6->addWidget(hand_maxTorque_read, 0, 0, 1, 1);

        hand_goalPosition_read = new QPushButton(gridLayoutWidget_8);
        hand_goalPosition_read->setObjectName(QString::fromUtf8("hand_goalPosition_read"));
        hand_goalPosition_read->setEnabled(false);

        gridLayout_6->addWidget(hand_goalPosition_read, 1, 0, 1, 1);

        hand_maxTorque_write = new QPushButton(gridLayoutWidget_8);
        hand_maxTorque_write->setObjectName(QString::fromUtf8("hand_maxTorque_write"));
        hand_maxTorque_write->setEnabled(false);

        gridLayout_6->addWidget(hand_maxTorque_write, 0, 1, 1, 1);

        hand_movingSpeed_read = new QPushButton(gridLayoutWidget_8);
        hand_movingSpeed_read->setObjectName(QString::fromUtf8("hand_movingSpeed_read"));
        hand_movingSpeed_read->setEnabled(false);

        gridLayout_6->addWidget(hand_movingSpeed_read, 2, 0, 1, 1);

        hand_movingSpeed_write = new QPushButton(gridLayoutWidget_8);
        hand_movingSpeed_write->setObjectName(QString::fromUtf8("hand_movingSpeed_write"));
        hand_movingSpeed_write->setEnabled(false);

        gridLayout_6->addWidget(hand_movingSpeed_write, 2, 1, 1, 1);

        setHand = new QPushButton(h);
        setHand->setObjectName(QString::fromUtf8("setHand"));
        setHand->setEnabled(false);
        setHand->setGeometry(QRect(20, 130, 81, 23));
        setDynamixel = new QPushButton(h);
        setDynamixel->setObjectName(QString::fromUtf8("setDynamixel"));
        setDynamixel->setEnabled(false);
        setDynamixel->setGeometry(QRect(150, 130, 81, 23));

        retranslateUi(Qt_Dynamixel);

        QMetaObject::connectSlotsByName(Qt_Dynamixel);
    } // setupUi

    void retranslateUi(QDialog *Qt_Dynamixel)
    {
        Qt_Dynamixel->setWindowTitle(QCoreApplication::translate("Qt_Dynamixel", "Qt_Dynamixel", nullptr));
        elbow->setTitle(QCoreApplication::translate("Qt_Dynamixel", "ELBOW", nullptr));
        elbow_eeprom->setTitle(QCoreApplication::translate("Qt_Dynamixel", "eeprom", nullptr));
        label_20->setText(QCoreApplication::translate("Qt_Dynamixel", "alarm led", nullptr));
        label_17->setText(QCoreApplication::translate("Qt_Dynamixel", "L limit voltage", nullptr));
        label_16->setText(QCoreApplication::translate("Qt_Dynamixel", "H limit voltage", nullptr));
        label_14->setText(QCoreApplication::translate("Qt_Dynamixel", "H limit temp", nullptr));
        label_11->setText(QCoreApplication::translate("Qt_Dynamixel", "baud rate", nullptr));
        label_13->setText(QCoreApplication::translate("Qt_Dynamixel", "cw", nullptr));
        label_7->setText(QCoreApplication::translate("Qt_Dynamixel", "id", nullptr));
        label_19->setText(QCoreApplication::translate("Qt_Dynamixel", "status return", nullptr));
        label_21->setText(QCoreApplication::translate("Qt_Dynamixel", "alarm shutdown", nullptr));
        label_18->setText(QCoreApplication::translate("Qt_Dynamixel", "max torque", nullptr));
        label_10->setText(QCoreApplication::translate("Qt_Dynamixel", "firmware", nullptr));
        label_12->setText(QCoreApplication::translate("Qt_Dynamixel", "return delay", nullptr));
        label_8->setText(QCoreApplication::translate("Qt_Dynamixel", "ccw", nullptr));
        label_22->setText(QCoreApplication::translate("Qt_Dynamixel", "model number", nullptr));
        elbow_baudRate->setItemText(0, QCoreApplication::translate("Qt_Dynamixel", "1", nullptr));
        elbow_baudRate->setItemText(1, QCoreApplication::translate("Qt_Dynamixel", "3", nullptr));
        elbow_baudRate->setItemText(2, QCoreApplication::translate("Qt_Dynamixel", "4", nullptr));
        elbow_baudRate->setItemText(3, QCoreApplication::translate("Qt_Dynamixel", "7", nullptr));
        elbow_baudRate->setItemText(4, QCoreApplication::translate("Qt_Dynamixel", "9", nullptr));
        elbow_baudRate->setItemText(5, QCoreApplication::translate("Qt_Dynamixel", "16", nullptr));
        elbow_baudRate->setItemText(6, QCoreApplication::translate("Qt_Dynamixel", "34", nullptr));
        elbow_baudRate->setItemText(7, QCoreApplication::translate("Qt_Dynamixel", "103", nullptr));
        elbow_baudRate->setItemText(8, QCoreApplication::translate("Qt_Dynamixel", "217", nullptr));

        elbow_alarmLed_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        elbow_cw_write->setText(QCoreApplication::translate("Qt_Dynamixel", "W", nullptr));
        elbow_maxTorque_write->setText(QCoreApplication::translate("Qt_Dynamixel", "W", nullptr));
        elbow_hLimitVoltage_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        elbow_lLimiitVoltage_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        elbow_hLimitVoltage_write->setText(QCoreApplication::translate("Qt_Dynamixel", "W", nullptr));
        elbow_returnDelay_write->setText(QCoreApplication::translate("Qt_Dynamixel", "W", nullptr));
        elbow_alarmShutdown_write->setText(QCoreApplication::translate("Qt_Dynamixel", "W", nullptr));
        elbow_statusReturn_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        elbow_ccw_write->setText(QCoreApplication::translate("Qt_Dynamixel", "W", nullptr));
        elbow_alarmShutdown_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        elbow_maxTorque_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        elbow_alarmLed_write->setText(QCoreApplication::translate("Qt_Dynamixel", "W", nullptr));
        elbow_statusReturn_write->setText(QCoreApplication::translate("Qt_Dynamixel", "W", nullptr));
        elbow_hLimitTemp_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        elbow_hLimitTemp_write->setText(QCoreApplication::translate("Qt_Dynamixel", "W", nullptr));
        elbow_returnDelay_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        elbow_cw_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        elbow_ccw_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        elbow_lLimitVoltage_write->setText(QCoreApplication::translate("Qt_Dynamixel", "W", nullptr));
        elbow_baudRate_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        elbow_baudRate_write->setText(QCoreApplication::translate("Qt_Dynamixel", "W", nullptr));
        elbow_ram->setTitle(QCoreApplication::translate("Qt_Dynamixel", "ram", nullptr));
        elbow_goalPosition_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        elbow_lock_write->setText(QCoreApplication::translate("Qt_Dynamixel", "W", nullptr));
        elbow_presentLoad_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        elbow_presentPosition_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        elbow_lock_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        elbow_presentTemp_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        elbow_register_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        elbow_torqueLimit_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        elbow_presentSpeed_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        elbow_ccwSlope_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        elbow_cwSlope_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        elbow_ccwMargin_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        elbow_cwMargin_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        elbow_punch_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        elbow_movingSpeed_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        elbow_torqueLimit_write->setText(QCoreApplication::translate("Qt_Dynamixel", "W", nullptr));
        elbow_movingSpeed_write->setText(QCoreApplication::translate("Qt_Dynamixel", "W", nullptr));
        elbow_ccwSlope_write->setText(QCoreApplication::translate("Qt_Dynamixel", "W", nullptr));
        elbow_cwSlope_write->setText(QCoreApplication::translate("Qt_Dynamixel", "W", nullptr));
        elbow_punch_write->setText(QCoreApplication::translate("Qt_Dynamixel", "W", nullptr));
        elbow_ccwMargin_write->setText(QCoreApplication::translate("Qt_Dynamixel", "W", nullptr));
        elbow_cwMargin_write->setText(QCoreApplication::translate("Qt_Dynamixel", "W", nullptr));
        elbow_goalPosition_write->setText(QCoreApplication::translate("Qt_Dynamixel", "W", nullptr));
        elbow_register_write->setText(QCoreApplication::translate("Qt_Dynamixel", "W", nullptr));
        label_65->setText(QCoreApplication::translate("Qt_Dynamixel", "torque limit", nullptr));
        label_64->setText(QCoreApplication::translate("Qt_Dynamixel", "goal position", nullptr));
        label_56->setText(QCoreApplication::translate("Qt_Dynamixel", "present position", nullptr));
        label_54->setText(QCoreApplication::translate("Qt_Dynamixel", "presente speed", nullptr));
        label_58->setText(QCoreApplication::translate("Qt_Dynamixel", "moving speed", nullptr));
        label_57->setText(QCoreApplication::translate("Qt_Dynamixel", "ccw slope", nullptr));
        label_60->setText(QCoreApplication::translate("Qt_Dynamixel", "lock", nullptr));
        label_59->setText(QCoreApplication::translate("Qt_Dynamixel", "cw slope", nullptr));
        label_62->setText(QCoreApplication::translate("Qt_Dynamixel", "register", nullptr));
        label_52->setText(QCoreApplication::translate("Qt_Dynamixel", "punch", nullptr));
        label_53->setText(QCoreApplication::translate("Qt_Dynamixel", "presem temp.", nullptr));
        label_55->setText(QCoreApplication::translate("Qt_Dynamixel", "presente load", nullptr));
        label_63->setText(QCoreApplication::translate("Qt_Dynamixel", "ccw margin", nullptr));
        label_66->setText(QCoreApplication::translate("Qt_Dynamixel", "cw margin", nullptr));
        elbow_cwSlope->setItemText(0, QCoreApplication::translate("Qt_Dynamixel", "2", nullptr));
        elbow_cwSlope->setItemText(1, QCoreApplication::translate("Qt_Dynamixel", "4", nullptr));
        elbow_cwSlope->setItemText(2, QCoreApplication::translate("Qt_Dynamixel", "8", nullptr));
        elbow_cwSlope->setItemText(3, QCoreApplication::translate("Qt_Dynamixel", "16", nullptr));
        elbow_cwSlope->setItemText(4, QCoreApplication::translate("Qt_Dynamixel", "32", nullptr));
        elbow_cwSlope->setItemText(5, QCoreApplication::translate("Qt_Dynamixel", "64", nullptr));
        elbow_cwSlope->setItemText(6, QCoreApplication::translate("Qt_Dynamixel", "128", nullptr));

        elbow_ccwSlope->setItemText(0, QCoreApplication::translate("Qt_Dynamixel", "2", nullptr));
        elbow_ccwSlope->setItemText(1, QCoreApplication::translate("Qt_Dynamixel", "4", nullptr));
        elbow_ccwSlope->setItemText(2, QCoreApplication::translate("Qt_Dynamixel", "8", nullptr));
        elbow_ccwSlope->setItemText(3, QCoreApplication::translate("Qt_Dynamixel", "16", nullptr));
        elbow_ccwSlope->setItemText(4, QCoreApplication::translate("Qt_Dynamixel", "32", nullptr));
        elbow_ccwSlope->setItemText(5, QCoreApplication::translate("Qt_Dynamixel", "64", nullptr));
        elbow_ccwSlope->setItemText(6, QCoreApplication::translate("Qt_Dynamixel", "128", nullptr));

        shoulder->setTitle(QCoreApplication::translate("Qt_Dynamixel", "SHOULDER", nullptr));
        shoulder_eeprom->setTitle(QCoreApplication::translate("Qt_Dynamixel", "eeprom", nullptr));
        label_23->setText(QCoreApplication::translate("Qt_Dynamixel", "alarm led", nullptr));
        label_24->setText(QCoreApplication::translate("Qt_Dynamixel", "L limit voltage", nullptr));
        label_25->setText(QCoreApplication::translate("Qt_Dynamixel", "H limit voltage", nullptr));
        label_15->setText(QCoreApplication::translate("Qt_Dynamixel", "H limit temp", nullptr));
        label_26->setText(QCoreApplication::translate("Qt_Dynamixel", "baud rate", nullptr));
        label_27->setText(QCoreApplication::translate("Qt_Dynamixel", "cw", nullptr));
        label_9->setText(QCoreApplication::translate("Qt_Dynamixel", "id", nullptr));
        label_28->setText(QCoreApplication::translate("Qt_Dynamixel", "status return", nullptr));
        label_29->setText(QCoreApplication::translate("Qt_Dynamixel", "alarm shutdown", nullptr));
        label_30->setText(QCoreApplication::translate("Qt_Dynamixel", "max torque", nullptr));
        label_31->setText(QCoreApplication::translate("Qt_Dynamixel", "firmware", nullptr));
        label_32->setText(QCoreApplication::translate("Qt_Dynamixel", "return delay", nullptr));
        label_33->setText(QCoreApplication::translate("Qt_Dynamixel", "ccw", nullptr));
        label_34->setText(QCoreApplication::translate("Qt_Dynamixel", "model number", nullptr));
        shoulder_baudRate->setItemText(0, QCoreApplication::translate("Qt_Dynamixel", "1", nullptr));
        shoulder_baudRate->setItemText(1, QCoreApplication::translate("Qt_Dynamixel", "3", nullptr));
        shoulder_baudRate->setItemText(2, QCoreApplication::translate("Qt_Dynamixel", "4", nullptr));
        shoulder_baudRate->setItemText(3, QCoreApplication::translate("Qt_Dynamixel", "7", nullptr));
        shoulder_baudRate->setItemText(4, QCoreApplication::translate("Qt_Dynamixel", "9", nullptr));
        shoulder_baudRate->setItemText(5, QCoreApplication::translate("Qt_Dynamixel", "16", nullptr));
        shoulder_baudRate->setItemText(6, QCoreApplication::translate("Qt_Dynamixel", "34", nullptr));
        shoulder_baudRate->setItemText(7, QCoreApplication::translate("Qt_Dynamixel", "103", nullptr));
        shoulder_baudRate->setItemText(8, QCoreApplication::translate("Qt_Dynamixel", "207", nullptr));

        shoulder_ccw_write->setText(QCoreApplication::translate("Qt_Dynamixel", "W", nullptr));
        shoulder_lLimitVoltage_write->setText(QCoreApplication::translate("Qt_Dynamixel", "W", nullptr));
        shoulder_ccw_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        shoulder_lLimiitVoltage_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        shoulder_maxTorque_write->setText(QCoreApplication::translate("Qt_Dynamixel", "W", nullptr));
        shoulder_baudRate_write->setText(QCoreApplication::translate("Qt_Dynamixel", "W", nullptr));
        shoulder_hLimitTemp_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        shoulder_hLimitVoltage_write->setText(QCoreApplication::translate("Qt_Dynamixel", "W", nullptr));
        shoulder_maxTorque_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        shoulder_statusReturn_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        shoulder_alarmShutdown_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        shoulder_cw_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        shoulder_cw_write->setText(QCoreApplication::translate("Qt_Dynamixel", "W", nullptr));
        shoulder_alarmLed_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        shoulder_alarmLed_write->setText(QCoreApplication::translate("Qt_Dynamixel", "W", nullptr));
        shoulder_hLimitTemp_write->setText(QCoreApplication::translate("Qt_Dynamixel", "W", nullptr));
        shoulder_statusReturn_write->setText(QCoreApplication::translate("Qt_Dynamixel", "W", nullptr));
        shoulder_hLimitVoltage_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        shoulder_alarmShutdown_write->setText(QCoreApplication::translate("Qt_Dynamixel", "W", nullptr));
        shoulder_returnDelay_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        shoulder_baudRate_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        shoulder_returnDelay_write->setText(QCoreApplication::translate("Qt_Dynamixel", "W", nullptr));
        shoulder_ram->setTitle(QCoreApplication::translate("Qt_Dynamixel", "ram", nullptr));
        label_67->setText(QCoreApplication::translate("Qt_Dynamixel", "torque limit", nullptr));
        label_68->setText(QCoreApplication::translate("Qt_Dynamixel", "goal position", nullptr));
        label_61->setText(QCoreApplication::translate("Qt_Dynamixel", "present position", nullptr));
        label_69->setText(QCoreApplication::translate("Qt_Dynamixel", "presente speed", nullptr));
        label_70->setText(QCoreApplication::translate("Qt_Dynamixel", "moving speed", nullptr));
        label_71->setText(QCoreApplication::translate("Qt_Dynamixel", "ccw slope", nullptr));
        label_72->setText(QCoreApplication::translate("Qt_Dynamixel", "lock", nullptr));
        label_73->setText(QCoreApplication::translate("Qt_Dynamixel", "cw slope", nullptr));
        label_74->setText(QCoreApplication::translate("Qt_Dynamixel", "register", nullptr));
        label_75->setText(QCoreApplication::translate("Qt_Dynamixel", "punch", nullptr));
        label_76->setText(QCoreApplication::translate("Qt_Dynamixel", "presem temp.", nullptr));
        label_77->setText(QCoreApplication::translate("Qt_Dynamixel", "presente load", nullptr));
        label_78->setText(QCoreApplication::translate("Qt_Dynamixel", "ccw margin", nullptr));
        label_79->setText(QCoreApplication::translate("Qt_Dynamixel", "cw margin", nullptr));
        shoulder_cwSlope->setItemText(0, QCoreApplication::translate("Qt_Dynamixel", "2", nullptr));
        shoulder_cwSlope->setItemText(1, QCoreApplication::translate("Qt_Dynamixel", "4", nullptr));
        shoulder_cwSlope->setItemText(2, QCoreApplication::translate("Qt_Dynamixel", "8", nullptr));
        shoulder_cwSlope->setItemText(3, QCoreApplication::translate("Qt_Dynamixel", "16", nullptr));
        shoulder_cwSlope->setItemText(4, QCoreApplication::translate("Qt_Dynamixel", "32", nullptr));
        shoulder_cwSlope->setItemText(5, QCoreApplication::translate("Qt_Dynamixel", "64", nullptr));
        shoulder_cwSlope->setItemText(6, QCoreApplication::translate("Qt_Dynamixel", "128", nullptr));

        shoulder_ccwSlope->setItemText(0, QCoreApplication::translate("Qt_Dynamixel", "2", nullptr));
        shoulder_ccwSlope->setItemText(1, QCoreApplication::translate("Qt_Dynamixel", "4", nullptr));
        shoulder_ccwSlope->setItemText(2, QCoreApplication::translate("Qt_Dynamixel", "8", nullptr));
        shoulder_ccwSlope->setItemText(3, QCoreApplication::translate("Qt_Dynamixel", "16", nullptr));
        shoulder_ccwSlope->setItemText(4, QCoreApplication::translate("Qt_Dynamixel", "32", nullptr));
        shoulder_ccwSlope->setItemText(5, QCoreApplication::translate("Qt_Dynamixel", "64", nullptr));
        shoulder_ccwSlope->setItemText(6, QCoreApplication::translate("Qt_Dynamixel", "128", nullptr));

        shoulder_goalPosition_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        shoulder_lock_write->setText(QCoreApplication::translate("Qt_Dynamixel", "W", nullptr));
        shoulder_presentLoad_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        shoulder_presentPosition_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        shoulder_lock_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        shoulder_presentTemp_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        shoulder_register_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        shoulder_torqueLimit_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        shoulder_presentSpeed_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        shoulder_ccwSlope_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        shoulder_cwSlope_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        shoulder_ccwMargin_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        shoulder_cwMargin_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        shoulder_punch_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        shoulder_movingSpeed_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        shoulder_torqueLimit_write->setText(QCoreApplication::translate("Qt_Dynamixel", "W", nullptr));
        shoulder_movingSpeed_write->setText(QCoreApplication::translate("Qt_Dynamixel", "W", nullptr));
        shoulder_ccwSlope_write->setText(QCoreApplication::translate("Qt_Dynamixel", "W", nullptr));
        shoulder_cwSlope_write->setText(QCoreApplication::translate("Qt_Dynamixel", "W", nullptr));
        shoulder_punch_write->setText(QCoreApplication::translate("Qt_Dynamixel", "W", nullptr));
        shoulder_ccwMargin_write->setText(QCoreApplication::translate("Qt_Dynamixel", "W", nullptr));
        shoulder_cwMargin_write->setText(QCoreApplication::translate("Qt_Dynamixel", "W", nullptr));
        shoulder_goalPosition_write->setText(QCoreApplication::translate("Qt_Dynamixel", "W", nullptr));
        shoulder_register_write->setText(QCoreApplication::translate("Qt_Dynamixel", "W", nullptr));
        h->setTitle(QCoreApplication::translate("Qt_Dynamixel", "HAND", nullptr));
        groupBox_8->setTitle(QString());
        label->setText(QCoreApplication::translate("Qt_Dynamixel", "max torque", nullptr));
        label_2->setText(QCoreApplication::translate("Qt_Dynamixel", "id", nullptr));
        label_3->setText(QCoreApplication::translate("Qt_Dynamixel", "goal position", nullptr));
        label_4->setText(QCoreApplication::translate("Qt_Dynamixel", "moving speed", nullptr));
        hand_goalPosition_write->setText(QCoreApplication::translate("Qt_Dynamixel", "W", nullptr));
        hand_maxTorque_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        hand_goalPosition_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        hand_maxTorque_write->setText(QCoreApplication::translate("Qt_Dynamixel", "W", nullptr));
        hand_movingSpeed_read->setText(QCoreApplication::translate("Qt_Dynamixel", "R", nullptr));
        hand_movingSpeed_write->setText(QCoreApplication::translate("Qt_Dynamixel", "W", nullptr));
        setHand->setText(QCoreApplication::translate("Qt_Dynamixel", "Set Hand", nullptr));
        setDynamixel->setText(QCoreApplication::translate("Qt_Dynamixel", "Set Dynamixel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Qt_Dynamixel: public Ui_Qt_Dynamixel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_DYNAMIXEL_H
