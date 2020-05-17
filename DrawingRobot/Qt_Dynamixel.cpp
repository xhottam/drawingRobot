#include "Qt_Dynamixel.h"
#include <iostream>
#include <QObject>
#include <QSerialPortInfo>
#include <QLabel>
#include <string> 




Qt_Dynamixel::Qt_Dynamixel(QWidget *parent)
	: QDialog(parent)
{
	bool _hombro, _codo, _pencil;
	ui.setupUi(this);
	if (availablePorts()) {
		if (dynamixel.doping(&serial, _id_hombro) == DEFAULT_RETURN_PACKET_SIZE) {
			_hombro = true;
			paintShoulder(dynamixel.readControlTable(&serial, _id_hombro));
			allowPushButtons_hombro();
		}
		if (dynamixel.doping(&serial, _id_codo) == DEFAULT_RETURN_PACKET_SIZE) {
			_codo = true;
			paintElbow(dynamixel.readControlTable(&serial, _id_codo));
			allowPushButtons_codo();
		}
		if (dynamixel.doping(&serial, _id_pencil) == DEFAULT_RETURN_PACKET_SIZE) {
			_pencil = true;
			paintHand(dynamixel.readControlTable(&serial, _id_pencil));
			allowPushButtons_pencil();
		}
		
		//if (_hombro && _codo && _pencil) {
		if (_hombro && _codo && _pencil) {
			//all servos are ready to go
			serial._servosReady = true;
			ui.setHand->setEnabled(true);
		}else {
			serial._servosReady = false;
			emit onDynamixelReady_signal(false, serial, 512);
		}
		
	}else {
	
	}
}

Qt_Dynamixel::~Qt_Dynamixel()
{
}

void Qt_Dynamixel::allowPushButtons_hombro() {
	ui.shoulder_ccw_write->setEnabled(true);
	ui.shoulder_lLimitVoltage_write->setEnabled(true);
	ui.shoulder_ccw_read->setEnabled(true);
	ui.shoulder_lLimiitVoltage_read->setEnabled(true);
	ui.shoulder_maxTorque_write->setEnabled(true);
	ui.shoulder_baudRate_write->setEnabled(true);
	ui.shoulder_hLimitTemp_read->setEnabled(true);
	ui.shoulder_hLimitVoltage_write->setEnabled(true);
	ui.shoulder_maxTorque_read->setEnabled(true);
	ui.shoulder_statusReturn_read->setEnabled(true);
	ui.shoulder_alarmShutdown_read->setEnabled(true);
	ui.shoulder_cw_read->setEnabled(true);
	ui.shoulder_cw_write->setEnabled(true);
	ui.shoulder_alarmLed_read->setEnabled(true);
	ui.shoulder_alarmLed_write->setEnabled(true);
	ui.shoulder_hLimitTemp_write->setEnabled(true);
	ui.shoulder_statusReturn_write->setEnabled(true);
	ui.shoulder_hLimitVoltage_read->setEnabled(true);
	ui.shoulder_alarmShutdown_write->setEnabled(true);
	ui.shoulder_returnDelay_read->setEnabled(true);
	ui.shoulder_baudRate_read->setEnabled(true);
	ui.shoulder_returnDelay_write->setEnabled(true);
	ui.shoulder_goalPosition_read->setEnabled(true);
	ui.shoulder_lock_write->setEnabled(true);
	ui.shoulder_presentLoad_read->setEnabled(true);
	ui.shoulder_presentPosition_read->setEnabled(true);
	ui.shoulder_lock_read->setEnabled(true);
	ui.shoulder_presentTemp_read->setEnabled(true);
	ui.shoulder_register_read->setEnabled(true);
	ui.shoulder_torqueLimit_read->setEnabled(true);
	ui.shoulder_presentSpeed_read->setEnabled(true);
	ui.shoulder_ccwSlope_read->setEnabled(true);
	ui.shoulder_cwSlope_read->setEnabled(true);
	ui.shoulder_ccwMargin_read->setEnabled(true);
	ui.shoulder_cwMargin_read->setEnabled(true);
	ui.shoulder_punch_read->setEnabled(true);
	ui.shoulder_movingSpeed_read->setEnabled(true);
	ui.shoulder_torqueLimit_write->setEnabled(true);
	ui.shoulder_movingSpeed_write->setEnabled(true);
	ui.shoulder_ccwSlope_write->setEnabled(true);
	ui.shoulder_cwSlope_write->setEnabled(true);
	ui.shoulder_punch_write->setEnabled(true);
	ui.shoulder_ccwMargin_write->setEnabled(true);
	ui.shoulder_cwMargin_write->setEnabled(true);
	ui.shoulder_goalPosition_write->setEnabled(true);
	ui.shoulder_register_write->setEnabled(true);
}
void Qt_Dynamixel::allowPushButtons_codo() {
	ui.elbow_alarmLed_read->setEnabled(true);
	ui.elbow_cw_write->setEnabled(true);
	ui.elbow_maxTorque_write->setEnabled(true);
	ui.elbow_hLimitVoltage_read->setEnabled(true);
	ui.elbow_lLimiitVoltage_read->setEnabled(true);
	ui.elbow_hLimitVoltage_write->setEnabled(true);
	ui.elbow_returnDelay_write->setEnabled(true);
	ui.elbow_alarmShutdown_write->setEnabled(true);
	ui.elbow_statusReturn_read->setEnabled(true);
	ui.elbow_ccw_write->setEnabled(true);
	ui.elbow_alarmShutdown_read->setEnabled(true);
	ui.elbow_maxTorque_read->setEnabled(true);
	ui.elbow_alarmLed_write->setEnabled(true);
	ui.elbow_statusReturn_write->setEnabled(true);
	ui.elbow_hLimitTemp_read->setEnabled(true);
	ui.elbow_hLimitTemp_write->setEnabled(true);
	ui.elbow_returnDelay_read->setEnabled(true);
	ui.elbow_cw_read->setEnabled(true);
	ui.elbow_ccw_read->setEnabled(true);
	ui.elbow_lLimitVoltage_write->setEnabled(true);
	ui.elbow_baudRate_read->setEnabled(true);
	ui.elbow_baudRate_write->setEnabled(true);
	ui.elbow_goalPosition_read->setEnabled(true);
	ui.elbow_lock_write->setEnabled(true);
	ui.elbow_presentLoad_read->setEnabled(true);
	ui.elbow_presentPosition_read->setEnabled(true);
	ui.elbow_lock_read->setEnabled(true);
	ui.elbow_presentTemp_read->setEnabled(true);
	ui.elbow_register_read->setEnabled(true);
	ui.elbow_torqueLimit_read->setEnabled(true);
	ui.elbow_presentSpeed_read->setEnabled(true);
	ui.elbow_ccwSlope_read->setEnabled(true);
	ui.elbow_cwSlope_read->setEnabled(true);
	ui.elbow_ccwMargin_read->setEnabled(true);
	ui.elbow_cwMargin_read->setEnabled(true);
	ui.elbow_punch_read->setEnabled(true);
	ui.elbow_movingSpeed_read->setEnabled(true);
	ui.elbow_torqueLimit_write->setEnabled(true);
	ui.elbow_movingSpeed_write->setEnabled(true);
	ui.elbow_ccwSlope_write->setEnabled(true);
	ui.elbow_cwSlope_write->setEnabled(true);
	ui.elbow_punch_write->setEnabled(true);
	ui.elbow_ccwMargin_write->setEnabled(true);
	ui.elbow_cwMargin_write->setEnabled(true);
	ui.elbow_goalPosition_write->setEnabled(true);
	ui.elbow_register_write->setEnabled(true);
}
void Qt_Dynamixel::allowPushButtons_pencil() {
	ui.hand_goalPosition_write->setEnabled(true);
	ui.hand_maxTorque_read->setEnabled(true);
	ui.hand_goalPosition_read->setEnabled(true);
	ui.hand_maxTorque_write->setEnabled(true);
	ui.hand_movingSpeed_read->setEnabled(true);
	ui.hand_movingSpeed_write->setEnabled(true);
}

void Qt_Dynamixel::paintShoulder(Dynamixel::ControlTable table)
{
	
	//eeprom
	ui.shoulder_modelNumber->setValue(table.eeprom.MODEL_NUMBER);
	ui.shoulder_firmware->setValue(table.eeprom.FIRMWARE_VERSION);
	ui.shoulder_id->setValue(table.eeprom.ID);	
    ui.shoulder_baudRate->setCurrentIndex(ui.shoulder_baudRate->findText(QString::number(table.eeprom.BAUD_RATE)));
	ui.shoulder_returnDelay->setValue(table.eeprom.RETURN_DELAY_TIME);
	ui.shoulder_cw->setValue(table.eeprom.CW_ANGLE_LIMIT);
	ui.shoulder_ccw->setValue(table.eeprom.CCW_ANGLE_LIMIT);
	ui.shoulder_hLimitTemp->setValue(table.eeprom.HIGHEST_LIMIT_TEMPERATURE);
	ui.shoulder_hLimitVoltage->setValue(table.eeprom.HIGHEST_LIMIT_VOLTAGE);
	ui.shoulder_lLimitVoltage->setValue(table.eeprom.LOWEST_LIMIT_VOLTAGE);
	ui.shoulder_maxTorque->setValue(table.eeprom.MAX_TORQUE);
	ui.shoulder_statusReturn->setValue(table.eeprom.STATUS_RETURN_LEVEL);
	ui.shoulder_alarmLed->setValue(table.eeprom.ALARM_LED);
	ui.shoulder_alarmShutdown->setValue(table.eeprom.ALARM_SHUTDOWN);
	//ram
	ui.shoulder_cwMargin->setValue(table.ram.CW_COMPLIANCE_MARGIN);
	ui.shoulder_ccwMargin->setValue(table.ram.CCW_COMPLIANCE_MARGIN);
	ui.shoulder_cwSlope->setCurrentIndex(ui.shoulder_cwSlope->findText(QString::number(table.ram.CW_COMPLIANCE_SLOPE)));
	ui.shoulder_ccwSlope->setCurrentIndex(ui.shoulder_ccwSlope->findText(QString::number(table.ram.CCW_COMPLIANCE_SLOPE)));
	ui.shoulder_goalPosition->setValue(table.ram.GOAL_POSITION);
	ui.shoulder_movingSpeed->setValue(table.ram.MOVING_SPEED);
	ui.shoulder_torqueLimit->setValue(table.ram.TORQUE_LIMIT);
	ui.shoulder_presentPosition->setValue(table.ram.PRESENT_POSITION);
	ui.shoulder_presentSpeed->setValue(table.ram.PRESENT_SPEED);
	ui.shoulder_presentLoad->setValue(table.ram.PRESENT_LOAD);
	ui.shoulder_presentTemp->setValue(table.ram.PRESENT_TEMPERATURE);
	ui.shoulder_register->setValue(table.ram.REGISTERED_INSTRUCTION);
	ui.shoulder_lock->setValue(table.ram.LOCK);
	ui.shoulder_punch->setValue(table.ram.PUNCH);	
}
void Qt_Dynamixel::paintElbow(Dynamixel::ControlTable table)
{
	//eeprom
	ui.elbow_modelNumber->setValue(table.eeprom.MODEL_NUMBER);
	ui.elbow_firmware->setValue(table.eeprom.FIRMWARE_VERSION);
	ui.elbow_id->setValue(table.eeprom.ID);
	ui.elbow_baudRate->setCurrentIndex(ui.elbow_baudRate->findText(QString::number(table.eeprom.BAUD_RATE)));	
	ui.elbow_returnDelay->setValue(table.eeprom.RETURN_DELAY_TIME);
	ui.elbow_cw->setValue(table.eeprom.CW_ANGLE_LIMIT);
	ui.elbow_ccw->setValue(table.eeprom.CCW_ANGLE_LIMIT);
	ui.elbow_hLimitTemp->setValue(table.eeprom.HIGHEST_LIMIT_TEMPERATURE);
	ui.elbow_hLimitVoltage->setValue(table.eeprom.HIGHEST_LIMIT_VOLTAGE);
	ui.elbow_lLimitVoltage->setValue(table.eeprom.LOWEST_LIMIT_VOLTAGE);
	ui.elbow_maxTorque->setValue(table.eeprom.MAX_TORQUE);
	ui.elbow_statusReturn->setValue(table.eeprom.STATUS_RETURN_LEVEL);
	ui.elbow_alarmLed->setValue(table.eeprom.ALARM_LED);
	ui.elbow_alarmShutdown->setValue(table.eeprom.ALARM_SHUTDOWN);
	//ram
	ui.elbow_cwMargin->setValue(table.ram.CW_COMPLIANCE_MARGIN);
	ui.elbow_ccwMargin->setValue(table.ram.CCW_COMPLIANCE_MARGIN);
	ui.elbow_cwSlope->setCurrentIndex(ui.elbow_cwSlope->findText(QString::number(table.ram.CW_COMPLIANCE_SLOPE)));
	ui.elbow_ccwSlope->setCurrentIndex(ui.elbow_ccwSlope->findText(QString::number(table.ram.CCW_COMPLIANCE_SLOPE)));
	ui.elbow_goalPosition->setValue(table.ram.GOAL_POSITION);
	ui.elbow_movingSpeed->setValue(table.ram.MOVING_SPEED);
	ui.elbow_torqueLimit->setValue(table.ram.TORQUE_LIMIT);
	ui.elbow_presentPosition->setValue(table.ram.PRESENT_POSITION);
	ui.elbow_presentSpeed->setValue(table.ram.PRESENT_SPEED);
	ui.elbow_presentLoad->setValue(table.ram.PRESENT_LOAD);
	ui.elbow_presentTemp->setValue(table.ram.PRESENT_TEMPERATURE);
	ui.elbow_register->setValue(table.ram.REGISTERED_INSTRUCTION);
	ui.elbow_lock->setValue(table.ram.LOCK);
	ui.elbow_punch->setValue(table.ram.PUNCH);
}
void Qt_Dynamixel::paintHand(Dynamixel::ControlTable table) {
	ui.hand_id->setValue(table.eeprom.ID);
	ui.hand_maxTorque->setValue(table.eeprom.MAX_TORQUE);
	ui.hand_goalPosition->setValue(table.ram.GOAL_POSITION);
	ui.hand_movingSpeed->setValue(table.ram.MOVING_SPEED);
}

void Qt_Dynamixel::on_setDynamixel_clicked() {
	//emit onDynamixelReady_signal(availablePorts(), serial);
	emit onDynamixelReady_signal(true, serial,handPosition);
	this->close();
}
void Qt_Dynamixel::on_setHand_clicked() {
	//emit onDynamixelReady_signal(availablePorts(), serial);
	handPosition = ui.hand_goalPosition->text().toInt();
	ui.setDynamixel->setEnabled(true);
}

bool Qt_Dynamixel::availablePorts() {

	bool _result = false;
	if (serial._connect == true) {
		_result = serial._connect;
		//dynamixel.readControlTable(&serial, 1);
		//dynamixel.dxl_write_word(&serial, 1, Dynamixel::AXM_GOAL_POSITION_L, 512);
		//dynamixel.dxl_write_word(&serial, 2, Dynamixel::AXM_GOAL_POSITION_L, 512);
		//while (dynamixel.dxl_read_byte(&serial, 1, Dynamixel::AXM_MOVING) || dynamixel.dxl_read_byte(&serial, 2, Dynamixel::AXM_MOVING)) {}
		//dynamixel.moveDrawingArm(&serial, 1023, 1023);
		//dynamixel.dxl_write_word(&serial, 1, Dynamixel::AXM_GOAL_POSITION_L,10);
		return _result;
	}

	
	const auto infos = QSerialPortInfo::availablePorts();
	for (const QSerialPortInfo &info : infos) {
		QString s = QObject::tr("Port: ") + info.portName() + "\n"
			+ QObject::tr("Location: ") + info.systemLocation() + "\n"
			+ QObject::tr("Description: ") + info.description() + "\n"
			+ QObject::tr("Manufacturer: ") + info.manufacturer() + "\n"
			+ QObject::tr("Serial number: ") + info.serialNumber() + "\n"
			+ QObject::tr("Vendor Identifier: ") + (info.hasVendorIdentifier() ? QString::number(info.vendorIdentifier(), 16) : QString()) + "\n"
			+ QObject::tr("Product Identifier: ") + (info.hasProductIdentifier() ? QString::number(info.productIdentifier(), 16) : QString()) + "\n"
			+ QObject::tr("Busy: ") + (info.isBusy() ? QObject::tr("Yes") : QObject::tr("No")) + "\n";

		auto label = new QLabel(s);

		auto archiveWString = info.systemLocation().toStdWString();
		auto archive = const_cast<wchar_t *>(archiveWString.c_str());
		if (serial.connect(archive) == 0) {
			if (dynamixel.sentTossModeCommand(&serial) == true) {
				std::cout << s.toStdString() << std::endl;
				_result = true;
				//serial._connect = _result;
				break;
			}
			else {
				serial.disconnect();
			}

		}
	}
	return _result;
}

//elbow
void Qt_Dynamixel::on_elbow_alarmLed_read_clicked() {
	ui.elbow_alarmLed->setValue(dynamixel.dxl_read_byte(&serial, _id_codo, Dynamixel::AXM_ALARM_LED));
}
void Qt_Dynamixel::on_elbow_cw_write_clicked() {
	dynamixel.dxl_write_word(&serial, _id_codo, Dynamixel::AXM_CW_ANGLE_LIMIT_L, ui.elbow_cw->text().toInt());
}
void Qt_Dynamixel::on_elbow_maxTorque_write_clicked() {
	dynamixel.dxl_write_word(&serial, _id_codo, Dynamixel::AXM_MAX_TORQUE_L, ui.elbow_maxTorque->text().toInt());
}
void Qt_Dynamixel::on_elbow_hLimitVoltage_read_clicked() {
	ui.elbow_hLimitVoltage->setValue(dynamixel.dxl_read_byte(&serial, _id_codo, Dynamixel::AXM_HIGHEST_LIMIT_VOLTAGE));
}
void Qt_Dynamixel::on_elbow_lLimiitVoltage_read_clicked() {
	ui.elbow_lLimitVoltage->setValue(dynamixel.dxl_read_byte(&serial, _id_codo, Dynamixel::AXM_LOWEST_LIMIT_VOLTAGE));
}
void Qt_Dynamixel::on_elbow_hLimitVoltage_write_clicked() {
	dynamixel.dxl_write_byte(&serial, _id_codo, Dynamixel::AXM_HIGHEST_LIMIT_VOLTAGE, ui.elbow_hLimitVoltage->text().toInt());
}
void Qt_Dynamixel::on_elbow_returnDelay_write_clicked() {
	dynamixel.dxl_write_byte(&serial, _id_codo, Dynamixel::AXM_RETURN_DELAY_TIME, ui.elbow_returnDelay->text().toInt());
}
void Qt_Dynamixel::on_elbow_alarmShutdown_write_clicked() {
	dynamixel.dxl_write_byte(&serial, _id_codo, Dynamixel::AXM_ALARM_SHUTDOWN, ui.elbow_alarmShutdown->text().toInt());
}
void Qt_Dynamixel::on_elbow_statusReturn_read_clicked() {
	ui.elbow_statusReturn->setValue(dynamixel.dxl_read_byte(&serial, _id_codo, Dynamixel::AXM_STATUS_RETURN_LEVEL));
}
void Qt_Dynamixel::on_elbow_ccw_write_clicked() {
	dynamixel.dxl_write_word(&serial, _id_codo, Dynamixel::AXM_CCW_ANGLE_LIMIT_L, ui.elbow_ccw->text().toInt());
}
void Qt_Dynamixel::on_elbow_alarmShutdown_read_clicked() {
	ui.elbow_alarmShutdown->setValue(dynamixel.dxl_read_byte(&serial, _id_codo, Dynamixel::AXM_ALARM_SHUTDOWN));
}
void Qt_Dynamixel::on_elbow_maxTorque_read_clicked() {
	ui.elbow_maxTorque->setValue(dynamixel.dxl_read_word(&serial, _id_codo, Dynamixel::AXM_MAX_TORQUE_L));
}
void Qt_Dynamixel::on_elbow_alarmLed_write_clicked() {
	dynamixel.dxl_write_byte(&serial, _id_codo, Dynamixel::AXM_ALARM_LED, ui.elbow_alarmLed->text().toInt());
}
void Qt_Dynamixel::on_elbow_statusReturn_write_clicked() {
	dynamixel.dxl_write_byte(&serial, _id_codo, Dynamixel::AXM_STATUS_RETURN_LEVEL, ui.elbow_statusReturn->text().toInt());
}
void Qt_Dynamixel::on_elbow_hLimitTemp_read_clicked() {
	ui.elbow_hLimitTemp->setValue(dynamixel.dxl_read_byte(&serial, _id_codo, Dynamixel::AXM_HIGHEST_LIMIT_TEMPERATURE));
}
void Qt_Dynamixel::on_elbow_hLimitTemp_write_clicked() {
	dynamixel.dxl_write_byte(&serial, _id_codo, Dynamixel::AXM_HIGHEST_LIMIT_VOLTAGE, ui.elbow_hLimitTemp->text().toInt());
}
void Qt_Dynamixel::on_elbow_returnDelay_read_clicked() {
	ui.elbow_returnDelay->setValue(dynamixel.dxl_read_byte(&serial, _id_codo, Dynamixel::AXM_RETURN_DELAY_TIME));
}
void Qt_Dynamixel::on_elbow_cw_read_clicked() {
	ui.elbow_cw->setValue(dynamixel.dxl_read_word(&serial, _id_codo, Dynamixel::AXM_CW_ANGLE_LIMIT_L));
}
void Qt_Dynamixel::on_elbow_ccw_read_clicked() {
	ui.elbow_ccw->setValue(dynamixel.dxl_read_word(&serial, _id_codo, Dynamixel::AXM_CCW_ANGLE_LIMIT_L));
}
void Qt_Dynamixel::on_elbow_lLimitVoltage_write_clicked() {
	dynamixel.dxl_write_byte(&serial, _id_codo, Dynamixel::AXM_HIGHEST_LIMIT_VOLTAGE, ui.elbow_hLimitTemp->text().toInt());
}
void Qt_Dynamixel::on_elbow_goalPosition_read_clicked() {
	ui.elbow_goalPosition->setValue(dynamixel.dxl_read_word(&serial, _id_codo, Dynamixel::AXM_GOAL_POSITION_L));
}
void Qt_Dynamixel::on_elbow_lock_write_clicked() {
	dynamixel.dxl_write_byte(&serial, _id_codo, Dynamixel::AXM_LOCK, ui.elbow_lock->text().toInt());
}
void Qt_Dynamixel::on_elbow_presentLoad_read_clicked() {
	ui.elbow_presentLoad->setValue(dynamixel.dxl_read_word(&serial, _id_codo, Dynamixel::AXM_PRESENT_LOAD_L));
}
void Qt_Dynamixel::on_elbow_presentPosition_read_clicked() {
	ui.elbow_presentPosition->setValue(dynamixel.dxl_read_word(&serial, _id_codo, Dynamixel::AXM_PRESENT_POSITION_L));
}
void Qt_Dynamixel::on_elbow_lock_read_clicked() {
	ui.elbow_lock->setValue(dynamixel.dxl_read_byte(&serial, _id_codo, Dynamixel::AXM_LOCK));
}
void Qt_Dynamixel::on_elbow_presentTemp_read_clicked() {
	ui.elbow_presentTemp->setValue(dynamixel.dxl_read_byte(&serial, _id_codo, Dynamixel::AXM_PRESENT_TEMPERATURE));
}
void Qt_Dynamixel::on_elbow_register_read_clicked() {
	ui.elbow_register->setValue(dynamixel.dxl_read_byte(&serial, _id_codo, Dynamixel::AXM_REGISTERED_INSTRUCTION));
}
void Qt_Dynamixel::on_elbow_torqueLimit_read_clicked() {
	ui.elbow_torqueLimit->setValue(dynamixel.dxl_read_word(&serial, _id_codo, Dynamixel::AXM_TORQUE_LIMIT_L));
}
void Qt_Dynamixel::on_elbow_presentSpeed_read_clicked() {
	ui.elbow_presentSpeed->setValue(dynamixel.dxl_read_word(&serial, _id_codo, Dynamixel::AXM_PRESENT_SPEED_L));
}
void Qt_Dynamixel::on_elbow_ccwSlope_read_clicked() {

	ui.elbow_ccwSlope->setCurrentIndex(ui.elbow_ccwSlope->findText(QString::number(dynamixel.dxl_read_byte(&serial, _id_codo, Dynamixel::AXM_CCW_COMPLIANCE_SLOPE))));
}
void Qt_Dynamixel::on_elbow_cwSlope_read_clicked() {
	ui.elbow_ccwSlope->setCurrentIndex(ui.elbow_ccwSlope->findText(QString::number(dynamixel.dxl_read_byte(&serial, _id_codo, Dynamixel::AXM_CW_COMPLIANCE_SLOPE))));
}
void Qt_Dynamixel::on_elbow_baudRate_read_clicked() {
	ui.elbow_baudRate->setCurrentIndex(ui.elbow_ccwSlope->findText(QString::number(dynamixel.dxl_read_byte(&serial, _id_codo, Dynamixel::AXM_BAUD_RATE))));
}
void Qt_Dynamixel::on_elbow_ccwMargin_read_clicked() {
	ui.elbow_ccwMargin->setValue(dynamixel.dxl_read_byte(&serial, _id_codo, Dynamixel::AXM_CCW_COMPLIANCE_MARGIN));
}
void Qt_Dynamixel::on_elbow_cwMargin_read_clicked() {
	ui.elbow_cwMargin->setValue(dynamixel.dxl_read_byte(&serial, _id_codo, Dynamixel::AXM_CW_COMPLIANCE_MARGIN));
}
void Qt_Dynamixel::on_elbow_punch_read_clicked() {
	ui.elbow_punch->setValue(dynamixel.dxl_read_word(&serial, _id_codo, Dynamixel::AXM_PUNCH_L));
}
void Qt_Dynamixel::on_elbow_movingSpeed_read_clicked() {
	ui.elbow_movingSpeed->setValue(dynamixel.dxl_read_word(&serial, _id_codo, Dynamixel::AXM_MOVING_SPEED_L));
}
void Qt_Dynamixel::on_elbow_torqueLimit_write_clicked() {
	dynamixel.dxl_write_word(&serial, _id_codo, Dynamixel::AXM_TORQUE_LIMIT_L, ui.elbow_torqueLimit->text().toInt());
}
void Qt_Dynamixel::on_elbow_movingSpeed_write_clicked() {
	dynamixel.dxl_write_word(&serial, _id_codo, Dynamixel::AXM_MOVING_SPEED_L, ui.elbow_movingSpeed->text().toInt());
}
void Qt_Dynamixel::on_elbow_ccwSlope_write_clicked() {
	dynamixel.dxl_write_byte(&serial, _id_codo, Dynamixel::AXM_CCW_COMPLIANCE_SLOPE, ui.elbow_ccwSlope->currentText().toInt());
}
void Qt_Dynamixel::on_elbow_cwSlope_write_clicked() {
	dynamixel.dxl_write_byte(&serial, _id_codo, Dynamixel::AXM_CW_COMPLIANCE_SLOPE, ui.elbow_cwSlope->currentText().toInt());
}
void Qt_Dynamixel::on_elbow_baudRate_write_clicked() {
	dynamixel.dxl_write_byte(&serial, _id_codo, Dynamixel::AXM_BAUD_RATE, ui.elbow_baudRate->currentText().toInt());
}
void Qt_Dynamixel::on_elbow_punch_write_clicked() {
	dynamixel.dxl_write_word(&serial, _id_codo, Dynamixel::AXM_PUNCH_L, ui.elbow_punch->text().toInt());
}
void Qt_Dynamixel::on_elbow_ccwMargin_write_clicked() {
	dynamixel.dxl_write_byte(&serial, _id_codo, Dynamixel::AXM_CCW_COMPLIANCE_MARGIN, ui.elbow_ccwMargin->text().toInt());
}
void Qt_Dynamixel::on_elbow_cwMargin_write_clicked() {
	dynamixel.dxl_write_byte(&serial, _id_codo, Dynamixel::AXM_CW_COMPLIANCE_MARGIN, ui.elbow_cwMargin->text().toInt());
}
void Qt_Dynamixel::on_elbow_goalPosition_write_clicked() {
	dynamixel.dxl_write_word(&serial, _id_codo, Dynamixel::AXM_GOAL_POSITION_L, ui.elbow_goalPosition->text().toInt());
}
void Qt_Dynamixel::on_elbow_register_write_clicked() {
	dynamixel.dxl_write_byte(&serial, _id_codo, Dynamixel::AXM_REGISTERED_INSTRUCTION, ui.elbow_register->text().toInt());
}

//shoulder
void Qt_Dynamixel::on_shoulder_alarmLed_read_clicked() {
	ui.shoulder_alarmLed->setValue(dynamixel.dxl_read_byte(&serial, _id_hombro, Dynamixel::AXM_ALARM_LED));
}
void Qt_Dynamixel::on_shoulder_cw_write_clicked() {
	dynamixel.dxl_write_word(&serial, _id_hombro, Dynamixel::AXM_CW_ANGLE_LIMIT_L, ui.shoulder_cw->text().toInt());
}
void Qt_Dynamixel::on_shoulder_maxTorque_write_clicked() {
	dynamixel.dxl_write_word(&serial, _id_hombro, Dynamixel::AXM_MAX_TORQUE_L, ui.shoulder_maxTorque->text().toInt());
}
void Qt_Dynamixel::on_shoulder_hLimitVoltage_read_clicked() {
	ui.shoulder_hLimitVoltage->setValue(dynamixel.dxl_read_byte(&serial, _id_hombro, Dynamixel::AXM_HIGHEST_LIMIT_VOLTAGE));
}
void Qt_Dynamixel::on_shoulder_lLimiitVoltage_read_clicked() {
	ui.shoulder_lLimitVoltage->setValue(dynamixel.dxl_read_byte(&serial, _id_hombro, Dynamixel::AXM_LOWEST_LIMIT_VOLTAGE));
}
void Qt_Dynamixel::on_shoulder_hLimitVoltage_write_clicked() {
	dynamixel.dxl_write_byte(&serial, _id_hombro, Dynamixel::AXM_HIGHEST_LIMIT_VOLTAGE, ui.shoulder_hLimitVoltage->text().toInt());
}
void Qt_Dynamixel::on_shoulder_returnDelay_write_clicked() {
	dynamixel.dxl_write_byte(&serial, _id_hombro, Dynamixel::AXM_RETURN_DELAY_TIME, ui.shoulder_returnDelay->text().toInt());
}
void Qt_Dynamixel::on_shoulder_alarmShutdown_write_clicked() {
	dynamixel.dxl_write_byte(&serial, _id_hombro, Dynamixel::AXM_ALARM_SHUTDOWN, ui.shoulder_alarmShutdown->text().toInt());
}
void Qt_Dynamixel::on_shoulder_statusReturn_read_clicked() {
	ui.shoulder_statusReturn->setValue(dynamixel.dxl_read_byte(&serial, _id_hombro, Dynamixel::AXM_STATUS_RETURN_LEVEL));
}
void Qt_Dynamixel::on_shoulder_ccw_write_clicked() {
	dynamixel.dxl_write_word(&serial, _id_hombro, Dynamixel::AXM_CCW_ANGLE_LIMIT_L, ui.shoulder_ccw->text().toInt());
}
void Qt_Dynamixel::on_shoulder_alarmShutdown_read_clicked() {
	ui.shoulder_alarmShutdown->setValue(dynamixel.dxl_read_byte(&serial, _id_hombro, Dynamixel::AXM_ALARM_SHUTDOWN));
}
void Qt_Dynamixel::on_shoulder_maxTorque_read_clicked() {
	ui.shoulder_maxTorque->setValue(dynamixel.dxl_read_word(&serial, _id_hombro, Dynamixel::AXM_MAX_TORQUE_L));
}
void Qt_Dynamixel::on_shoulder_alarmLed_write_clicked() {
	dynamixel.dxl_write_byte(&serial, _id_hombro, Dynamixel::AXM_ALARM_LED, ui.shoulder_alarmLed->text().toInt());
}
void Qt_Dynamixel::on_shoulder_statusReturn_write_clicked() {
	dynamixel.dxl_write_byte(&serial, _id_hombro, Dynamixel::AXM_STATUS_RETURN_LEVEL, ui.shoulder_statusReturn->text().toInt());
}
void Qt_Dynamixel::on_shoulder_hLimitTemp_read_clicked() {
	ui.shoulder_hLimitTemp->setValue(dynamixel.dxl_read_byte(&serial, _id_hombro, Dynamixel::AXM_HIGHEST_LIMIT_TEMPERATURE));
}
void Qt_Dynamixel::on_shoulder_hLimitTemp_write_clicked() {
	dynamixel.dxl_write_byte(&serial, _id_hombro, Dynamixel::AXM_HIGHEST_LIMIT_VOLTAGE, ui.shoulder_hLimitTemp->text().toInt());
}
void Qt_Dynamixel::on_shoulder_returnDelay_read_clicked() {
	ui.shoulder_returnDelay->setValue(dynamixel.dxl_read_byte(&serial, _id_hombro, Dynamixel::AXM_RETURN_DELAY_TIME));
}
void Qt_Dynamixel::on_shoulder_cw_read_clicked() {
	ui.shoulder_cw->setValue(dynamixel.dxl_read_word(&serial, _id_hombro, Dynamixel::AXM_CW_ANGLE_LIMIT_L));
}
void Qt_Dynamixel::on_shoulder_ccw_read_clicked() {
	ui.shoulder_ccw->setValue(dynamixel.dxl_read_word(&serial, _id_hombro, Dynamixel::AXM_CCW_ANGLE_LIMIT_L));
}
void Qt_Dynamixel::on_shoulder_lLimitVoltage_write_clicked() {
	dynamixel.dxl_write_byte(&serial, _id_hombro, Dynamixel::AXM_HIGHEST_LIMIT_VOLTAGE, ui.shoulder_hLimitTemp->text().toInt());
}
void Qt_Dynamixel::on_shoulder_goalPosition_read_clicked() {
	ui.shoulder_goalPosition->setValue(dynamixel.dxl_read_word(&serial, _id_hombro, Dynamixel::AXM_GOAL_POSITION_L));
}
void Qt_Dynamixel::on_shoulder_lock_write_clicked() {
	dynamixel.dxl_write_byte(&serial, _id_hombro, Dynamixel::AXM_LOCK, ui.shoulder_lock->text().toInt());
}
void Qt_Dynamixel::on_shoulder_presentLoad_read_clicked() {
	ui.shoulder_presentLoad->setValue(dynamixel.dxl_read_word(&serial, _id_hombro, Dynamixel::AXM_PRESENT_LOAD_L));
}
void Qt_Dynamixel::on_shoulder_presentPosition_read_clicked() {
	ui.shoulder_presentPosition->setValue(dynamixel.dxl_read_word(&serial, _id_hombro, Dynamixel::AXM_PRESENT_POSITION_L));
}
void Qt_Dynamixel::on_shoulder_lock_read_clicked() {
	ui.shoulder_lock->setValue(dynamixel.dxl_read_byte(&serial, _id_hombro, Dynamixel::AXM_LOCK));
}
void Qt_Dynamixel::on_shoulder_presentTemp_read_clicked() {
	ui.shoulder_presentTemp->setValue(dynamixel.dxl_read_byte(&serial, _id_hombro, Dynamixel::AXM_PRESENT_TEMPERATURE));
}
void Qt_Dynamixel::on_shoulder_register_read_clicked() {
	ui.shoulder_register->setValue(dynamixel.dxl_read_byte(&serial, _id_hombro, Dynamixel::AXM_REGISTERED_INSTRUCTION));
}
void Qt_Dynamixel::on_shoulder_torqueLimit_read_clicked() {
	ui.shoulder_torqueLimit->setValue(dynamixel.dxl_read_word(&serial, _id_hombro, Dynamixel::AXM_TORQUE_LIMIT_L));
}
void Qt_Dynamixel::on_shoulder_presentSpeed_read_clicked() {
	ui.shoulder_presentSpeed->setValue(dynamixel.dxl_read_word(&serial, _id_hombro, Dynamixel::AXM_PRESENT_SPEED_L));
}
void Qt_Dynamixel::on_shoulder_ccwSlope_read_clicked() {

	ui.shoulder_ccwSlope->setCurrentIndex(ui.shoulder_ccwSlope->findText(QString::number(dynamixel.dxl_read_byte(&serial, _id_hombro, Dynamixel::AXM_CCW_COMPLIANCE_SLOPE))));
}
void Qt_Dynamixel::on_shoulder_cwSlope_read_clicked() {
	ui.shoulder_ccwSlope->setCurrentIndex(ui.shoulder_ccwSlope->findText(QString::number(dynamixel.dxl_read_byte(&serial, _id_hombro, Dynamixel::AXM_CW_COMPLIANCE_SLOPE))));
}
void Qt_Dynamixel::on_shoulder_baudRate_read_clicked() {
	ui.shoulder_baudRate->setCurrentIndex(ui.shoulder_ccwSlope->findText(QString::number(dynamixel.dxl_read_byte(&serial, _id_hombro, Dynamixel::AXM_BAUD_RATE))));
}
void Qt_Dynamixel::on_shoulder_ccwMargin_read_clicked() {
	ui.shoulder_ccwMargin->setValue(dynamixel.dxl_read_byte(&serial, _id_hombro, Dynamixel::AXM_CCW_COMPLIANCE_MARGIN));
}
void Qt_Dynamixel::on_shoulder_cwMargin_read_clicked() {
	ui.shoulder_cwMargin->setValue(dynamixel.dxl_read_byte(&serial, _id_hombro, Dynamixel::AXM_CW_COMPLIANCE_MARGIN));
}
void Qt_Dynamixel::on_shoulder_punch_read_clicked() {
	ui.shoulder_punch->setValue(dynamixel.dxl_read_word(&serial, _id_hombro, Dynamixel::AXM_PUNCH_L));
}
void Qt_Dynamixel::on_shoulder_movingSpeed_read_clicked() {
	ui.shoulder_movingSpeed->setValue(dynamixel.dxl_read_word(&serial, _id_hombro, Dynamixel::AXM_MOVING_SPEED_L));
}
void Qt_Dynamixel::on_shoulder_torqueLimit_write_clicked() {
	dynamixel.dxl_write_word(&serial, _id_hombro, Dynamixel::AXM_TORQUE_LIMIT_L, ui.shoulder_torqueLimit->text().toInt());
}
void Qt_Dynamixel::on_shoulder_movingSpeed_write_clicked() {
	dynamixel.dxl_write_word(&serial, _id_hombro, Dynamixel::AXM_MOVING_SPEED_L, ui.shoulder_movingSpeed->text().toInt());
}
void Qt_Dynamixel::on_shoulder_ccwSlope_write_clicked() {
	dynamixel.dxl_write_byte(&serial, _id_hombro, Dynamixel::AXM_CCW_COMPLIANCE_SLOPE, ui.shoulder_ccwSlope->currentText().toInt());
}
void Qt_Dynamixel::on_shoulder_cwSlope_write_clicked() {
	dynamixel.dxl_write_byte(&serial, _id_hombro, Dynamixel::AXM_CW_COMPLIANCE_SLOPE, ui.shoulder_cwSlope->currentText().toInt());
}
void Qt_Dynamixel::on_shoulder_baudRate_write_clicked() {
	dynamixel.dxl_write_byte(&serial, _id_hombro, Dynamixel::AXM_BAUD_RATE, ui.shoulder_baudRate->currentText().toInt());
}
void Qt_Dynamixel::on_shoulder_punch_write_clicked() {
	dynamixel.dxl_write_word(&serial, _id_hombro, Dynamixel::AXM_PUNCH_L, ui.shoulder_punch->text().toInt());
}
void Qt_Dynamixel::on_shoulder_ccwMargin_write_clicked() {
	dynamixel.dxl_write_byte(&serial, _id_hombro, Dynamixel::AXM_CCW_COMPLIANCE_MARGIN, ui.shoulder_ccwMargin->text().toInt());
}
void Qt_Dynamixel::on_shoulder_cwMargin_write_clicked() {
	dynamixel.dxl_write_byte(&serial, _id_hombro, Dynamixel::AXM_CW_COMPLIANCE_MARGIN, ui.shoulder_cwMargin->text().toInt());
}
void Qt_Dynamixel::on_shoulder_goalPosition_write_clicked() {
	dynamixel.dxl_write_word(&serial, _id_hombro, Dynamixel::AXM_GOAL_POSITION_L, ui.shoulder_goalPosition->text().toInt());
}
void Qt_Dynamixel::on_shoulder_register_write_clicked() {
	dynamixel.dxl_write_byte(&serial, _id_hombro, Dynamixel::AXM_REGISTERED_INSTRUCTION, ui.shoulder_register->text().toInt());
}

//hand
void Qt_Dynamixel::on_hand_goalPosition_write_clicked() {
	dynamixel.dxl_write_word(&serial, _id_pencil, Dynamixel::AXM_GOAL_POSITION_L, ui.hand_goalPosition->text().toInt());
}
void Qt_Dynamixel::on_hand_maxTorque_read_clicked() {
	ui.hand_maxTorque->setValue(dynamixel.dxl_read_word(&serial, _id_pencil, Dynamixel::AXM_MAX_TORQUE_L));
}
void Qt_Dynamixel::on_hand_goalPosition_read_clicked() {
	ui.hand_goalPosition->setValue(dynamixel.dxl_read_word(&serial, _id_pencil, Dynamixel::AXM_GOAL_POSITION_L));
}
void Qt_Dynamixel::on_hand_maxTorque_write_clicked() {
	dynamixel.dxl_write_word(&serial, _id_pencil, Dynamixel::AXM_MAX_TORQUE_L, ui.hand_maxTorque->text().toInt());
}
void Qt_Dynamixel::on_hand_movingSpeed_read_clicked() {
	ui.hand_movingSpeed->setValue(dynamixel.dxl_read_word(&serial, _id_pencil, Dynamixel::AXM_MOVING_SPEED_L));
}
void Qt_Dynamixel::on_hand_movingSpeed_write_clicked() {
	dynamixel.dxl_write_word(&serial, _id_pencil, Dynamixel::AXM_MOVING_SPEED_L, ui.hand_movingSpeed->text().toInt());
}