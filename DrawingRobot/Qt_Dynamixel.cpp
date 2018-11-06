#include "Qt_Dynamixel.h"
#include <iostream>
#include <QObject>
#include <QSerialPortInfo>
#include <QLabel>



Qt_Dynamixel::Qt_Dynamixel(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

Qt_Dynamixel::~Qt_Dynamixel()
{
}

void Qt_Dynamixel::on_pushButton_clicked() {
	emit onDynamixelReady_signal(availablePorts(), serial);
	this->close();
}

bool Qt_Dynamixel::availablePorts() {

	bool _result = false;
	if (serial._connect == true) {
		_result = serial._connect;
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
				serial._connect = _result;
				break;
			}
			else {
				serial.disconnect();
			}

		}
	}
	return _result;
}