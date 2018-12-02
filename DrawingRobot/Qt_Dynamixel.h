#pragma once

#include <QDialog>
#include "ui_Qt_Dynamixel.h"
#include "SerialPort.h"
#include "Dynamixel.h"

class Qt_Dynamixel : public QDialog
{
	Q_OBJECT

public:
	Qt_Dynamixel(QWidget *parent = Q_NULLPTR);
	~Qt_Dynamixel();

	int handPosition;
	bool Qt_Dynamixel::availablePorts();

private:
	Ui::Qt_Dynamixel ui;
	void Qt_Dynamixel::paintShoulder(Dynamixel::ControlTable);
	void Qt_Dynamixel::paintElbow(Dynamixel::ControlTable);
	void Qt_Dynamixel::paintHand(Dynamixel::ControlTable);
	void Qt_Dynamixel::ablePushButtonsAll();

	int _id_hombro = 1;
	int _id_codo = 2;
	int _id_pencil = 4;
	

public slots:
	void on_setDynamixel_clicked();
	void on_setHand_clicked();
	void on_elbow_alarmLed_read_clicked();
	void on_elbow_cw_write_clicked();
	void on_elbow_maxTorque_write_clicked();
	void on_elbow_hLimitVoltage_read_clicked();
	void on_elbow_lLimiitVoltage_read_clicked();
	void on_elbow_hLimitVoltage_write_clicked();
	void on_elbow_returnDelay_write_clicked();
	void on_elbow_alarmShutdown_write_clicked();
	void on_elbow_statusReturn_read_clicked();
	void on_elbow_ccw_write_clicked();
	void on_elbow_alarmShutdown_read_clicked();
	void on_elbow_maxTorque_read_clicked();
	void on_elbow_alarmLed_write_clicked();
	void on_elbow_statusReturn_write_clicked();
	void on_elbow_hLimitTemp_read_clicked();
	void on_elbow_hLimitTemp_write_clicked();
	void on_elbow_returnDelay_read_clicked();
	void on_elbow_cw_read_clicked();
	void on_elbow_ccw_read_clicked();
	void on_elbow_lLimitVoltage_write_clicked();
	void on_elbow_baudRate_write_clicked();
	void on_elbow_baudRate_read_clicked();
	void on_elbow_goalPosition_read_clicked();
	void on_elbow_lock_write_clicked();
	void on_elbow_presentLoad_read_clicked();
	void on_elbow_presentPosition_read_clicked();
	void on_elbow_lock_read_clicked();
	void on_elbow_presentTemp_read_clicked();
	void on_elbow_register_read_clicked();
	void on_elbow_torqueLimit_read_clicked();
	void on_elbow_presentSpeed_read_clicked();
	void on_elbow_ccwSlope_read_clicked();
	void on_elbow_cwSlope_read_clicked();
	void on_elbow_ccwMargin_read_clicked();
	void on_elbow_cwMargin_read_clicked();
	void on_elbow_punch_read_clicked();
	void on_elbow_movingSpeed_read_clicked();
	void on_elbow_torqueLimit_write_clicked();
	void on_elbow_movingSpeed_write_clicked();
	void on_elbow_ccwSlope_write_clicked();
	void on_elbow_cwSlope_write_clicked();
	void on_elbow_punch_write_clicked();
	void on_elbow_ccwMargin_write_clicked();
	void on_elbow_cwMargin_write_clicked();
	void on_elbow_goalPosition_write_clicked();
	void on_elbow_register_write_clicked();
	void on_shoulder_ccw_write_clicked();
	void on_shoulder_lLimitVoltage_write_clicked();
	void on_shoulder_ccw_read_clicked();
	void on_shoulder_lLimiitVoltage_read_clicked();
	void on_shoulder_maxTorque_write_clicked();
	void on_shoulder_baudRate_write_clicked();
	void on_shoulder_hLimitTemp_read_clicked();
	void on_shoulder_hLimitVoltage_write_clicked();
	void on_shoulder_maxTorque_read_clicked();
	void on_shoulder_statusReturn_read_clicked();
	void on_shoulder_alarmShutdown_read_clicked();
	void on_shoulder_cw_read_clicked();
	void on_shoulder_cw_write_clicked();
	void on_shoulder_alarmLed_read_clicked();
	void on_shoulder_alarmLed_write_clicked();
	void on_shoulder_hLimitTemp_write_clicked();
	void on_shoulder_statusReturn_write_clicked();
	void on_shoulder_hLimitVoltage_read_clicked();
	void on_shoulder_alarmShutdown_write_clicked();
	void on_shoulder_returnDelay_read_clicked();
	void on_shoulder_baudRate_read_clicked();
	void on_shoulder_returnDelay_write_clicked();
	void on_shoulder_goalPosition_read_clicked();
	void on_shoulder_lock_write_clicked();
	void on_shoulder_presentLoad_read_clicked();
	void on_shoulder_presentPosition_read_clicked();
	void on_shoulder_lock_read_clicked();
	void on_shoulder_presentTemp_read_clicked();
	void on_shoulder_register_read_clicked();
	void on_shoulder_torqueLimit_read_clicked();
	void on_shoulder_presentSpeed_read_clicked();
	void on_shoulder_ccwSlope_read_clicked();
	void on_shoulder_cwSlope_read_clicked();
	void on_shoulder_ccwMargin_read_clicked();
	void on_shoulder_cwMargin_read_clicked();
	void on_shoulder_punch_read_clicked();
	void on_shoulder_movingSpeed_read_clicked();
	void on_shoulder_torqueLimit_write_clicked();
	void on_shoulder_movingSpeed_write_clicked();
	void on_shoulder_ccwSlope_write_clicked();
	void on_shoulder_cwSlope_write_clicked();
	void on_shoulder_punch_write_clicked();
	void on_shoulder_ccwMargin_write_clicked();
	void on_shoulder_cwMargin_write_clicked();
	void on_shoulder_goalPosition_write_clicked();
	void on_shoulder_register_write_clicked();
	void on_hand_goalPosition_write_clicked();
	void on_hand_maxTorque_read_clicked();
	void on_hand_goalPosition_read_clicked();
	void on_hand_maxTorque_write_clicked();
	void on_hand_movingSpeed_read_clicked();
	void on_hand_movingSpeed_write_clicked();



signals:
	void onDynamixelReady_signal(bool, SerialPort &,int);

};
