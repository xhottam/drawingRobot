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

private:
	Ui::Qt_Dynamixel ui;

public slots:
	void on_pushButton_clicked();
	bool Qt_Dynamixel::availablePorts();

signals:
	void onDynamixelReady_signal(bool, SerialPort &);

};
