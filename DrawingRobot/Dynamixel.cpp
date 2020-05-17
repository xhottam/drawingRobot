/*
 * SerialPort.cpp
 *
 *  Created on: Jun 20, 2011
 *      Author: jose
 */

//#include "stdafx.h"
#include "stdio.h"
#include "Dynamixel.h"


Dynamixel::Dynamixel()
{
	cleanBuffers();
}

Dynamixel::~Dynamixel()
{
	
}


void Dynamixel::cleanBuffers()
{
	memset(buffer,0,BufferSize);
	memset(bufferIn,0,BufferSize);
}


void Dynamixel::toHexHLConversion(short pos, byte *hexH, byte *hexL)
{    
    *hexH = (byte)(pos >> 8);
    *hexL = (byte)pos;
}

/**short Dynamixel::fromHexHLConversion(byte hexH, byte hexL)
{
    return (short)((hexL << 8) + hexH);
}*/

short Dynamixel::fromHexHLConversion(byte hexL, byte hexH)
{
	return (short)((hexH << 8) + hexL);
}

byte Dynamixel::checkSumatory(byte  data[], int length)
{
    int cs = 0;
    for (int i = 2; i < length; i++)
    {
        cs += data[i];
    }            
    return (byte)~cs;
}

bool Dynamixel::sentTossModeCommand(SerialPort *serialPort)
{
	bool result = false;

	byte tossModeCommandBuffer[15];
	tossModeCommandBuffer[0]='t';
	tossModeCommandBuffer[1]='\n';
	tossModeCommandBuffer[2]=0;

	int n=serialPort->sendArray(tossModeCommandBuffer, 2);
	Sleep(200);	
	memset(bufferIn, 0, 15);
	n = serialPort->getArray(bufferIn, 15);
	serialPort->clear();
	Sleep(5);

	std::string s(reinterpret_cast<const char *>(bufferIn), sizeof bufferIn);
	size_t found = s.find("Toss Mode");
	if (found != std::string::npos) {
		result = true;
	}
	
	return result;
}

int Dynamixel::dxl_read_byte(SerialPort *serialPort,int id, int address)
{
	int n = getbyte(id,address);
	long l = serialPort->sendArray(buffer, n);
	Sleep(waitTime);
	memset(bufferIn, 0, BufferSize);
	//DEFAULT_RETURN_PACKET_SIZE 6 + Read length	
	n = serialPort->getArray(bufferIn, DEFAULT_RETURN_PACKET_SIZE + 1);
	Sleep(waitTime);
	serialPort->clear();
	Sleep(waitTime);

	return bufferIn[5];
}
int Dynamixel::getbyte(int id, int address) 
{
	int pos = 0;

	buffer[pos++] = 0xff;
	buffer[pos++] = 0xff;
	buffer[pos++] = id;

	// length = 4
	buffer[pos++] = 4;

	//the instruction, read => 2
	buffer[pos++] = INST_READ_DATA;

	// Reading Address
	buffer[pos++] = address;

	//Read Length
	buffer[pos++] = 1;

	byte checksum = checkSumatory(buffer, pos);
	buffer[pos++] = checksum;

	return pos;
}

void Dynamixel::dxl_write_byte(SerialPort *serialPort,int id, int address, int value)
{
	int n = setbyte(id,address,value);
	long l = serialPort->sendArray(buffer, n);
	Sleep(waitTime);
	serialPort->clear();

	//return n;
}

int Dynamixel::setbyte(int id,int address, int value) {
	
	int pos = 0;
	byte numberOfParameters = 0;
	//OXFF 0XFF ID LENGTH INSTRUCTION PARAMETER1 …PARAMETER N CHECK SUM

	buffer[pos++] = 0xff;
	buffer[pos++] = 0xff;
	buffer[pos++] = id;

	//// bodyLength
	buffer[pos++] = 0; //place holder

	////the instruction, query => 3
	buffer[pos++] = INST_WRITE_DATA;

	//// goal registers 30 and 31
	buffer[pos++] = address;

	buffer[pos++] = value;
	numberOfParameters++;
		   	  
	// bodyLength
	buffer[3] = (byte)(numberOfParameters + 3);

	byte checksum = checkSumatory(buffer, pos);
	buffer[pos++] = checksum;

	return pos;

}

int Dynamixel::dxl_read_word(SerialPort *serialPort, int id, int address)
{
	int n = getWord(id, address);
	long l = serialPort->sendArray(buffer, n);
	Sleep(waitTime+ waitTime);
	memset(bufferIn, 0, BufferSize);
	//DEFAULT_RETURN_PACKET_SIZE 6 + Read length	
	n = serialPort->getArray(bufferIn, DEFAULT_RETURN_PACKET_SIZE + 2);
	Sleep(waitTime);
	serialPort->clear();
	Sleep(waitTime);

	return fromHexHLConversion(bufferIn[5], bufferIn[6]);
}
int Dynamixel::getWord(int id, int address) 
{
	int pos = 0;

	buffer[pos++] = 0xff;
	buffer[pos++] = 0xff;
	buffer[pos++] = id;

	// length = 4
	buffer[pos++] = 4;

	//the instruction, read => 2
	buffer[pos++] = INST_READ_DATA;

	// Reading Address
	buffer[pos++] = address;

	//Read Length
	buffer[pos++] = 2;

	byte checksum = checkSumatory(buffer, pos);
	buffer[pos++] = checksum;

	return pos;
}

void Dynamixel::dxl_write_word(SerialPort *serialPort,int id, int address, int value)
{
	int error = 0;
	int n = setWord(id,address,value);
	long l = serialPort->sendArray(buffer, n);
	Sleep(16);
	serialPort->clear();
	Sleep(5);
	
}
int Dynamixel::setWord(int id, int address, int value)
{
	int pos = 0;
	byte numberOfParameters = 0;
	//OXFF 0XFF ID LENGTH INSTRUCTION PARAMETER1 …PARAMETER N CHECK SUM

	buffer[pos++] = 0xff;
	buffer[pos++] = 0xff;
	buffer[pos++] = id;

	//// bodyLength
	buffer[pos++] = 0; //place holder

	////the instruction, query => 3
	buffer[pos++] = INST_WRITE_DATA;

	//// goal registers 30 and 31
	buffer[pos++] = address;


	////bytes to write
	byte hexH = 0;
	byte hexL = 0;
	hexH = 0;
	hexL = 0;
	toHexHLConversion(value, &hexH, &hexL);

	buffer[pos++] = hexL;
	numberOfParameters++;
	buffer[pos++] = hexH;
	numberOfParameters++;

	// bodyLength
	buffer[3] = (byte)(numberOfParameters + 3);

	byte checksum = checkSumatory(buffer, pos);
	buffer[pos++] = checksum;

	return pos;
}
void Dynamixel::moveDrawingArm(SerialPort *serialPort, int hombro, int codo,bool difference)
{
	
	int n = setMoveDrawingArm(hombro,codo);
	long l = serialPort->sendArray(buffer, n);
	Sleep(16);
	serialPort->clear();
	Sleep(16);
	/**if (hombro > codo) {
		while (dynamixel.isMoving(serialPort, 1)) {};
	}else {
		while (dynamixel.isMoving(serialPort, 2)) {};
	}*/
	
	//if (difference) { while (dynamixel.isMoving(serialPort, 1) || dynamixel.isMoving(serialPort, 2)) {} }
}
bool Dynamixel::isMoving(SerialPort * serialPort, int id)
{
	if (dynamixel.dxl_read_byte(serialPort, id, AXM_MOVING) == 1) {
		return true;
	}else { return false; }
	
}
void Dynamixel::penUP(SerialPort * serialPort, int position)
{
	int pencilOffset = 100;
	dynamixel.dxl_write_word(serialPort, id_pencil, AXM_GOAL_POSITION_L, (position - pencilOffset));
	while (dynamixel.isMoving(serialPort, id_pencil)) {}
}
void Dynamixel::penDown(SerialPort * serialPort, int position)
{
	dynamixel.dxl_write_word(serialPort, id_pencil,AXM_GOAL_POSITION_L, position);
	while (dynamixel.isMoving(serialPort, id_pencil)) {};
}
int Dynamixel::doping(SerialPort * serialPort, int id)
{
	int n = ping(id);
	long l = serialPort->sendArray(buffer, n);
	Sleep(waitTime);
	memset(bufferIn, 0, BufferSize);
	//DEFAULT_RETURN_PACKET_SIZE 6
	n = serialPort->getArray(bufferIn, DEFAULT_RETURN_PACKET_SIZE);
	Sleep(waitTime);
	serialPort->clear();
	Sleep(waitTime);

	return n;
}
/**int Dynamixel::setMoveDrawingArm(int hombro, int codo)
{
	int pos = 0;
	byte numberOfParameters = 0;

	buffer[pos++] = 0xff;
	buffer[pos++] = 0xff;
	buffer[pos++] = 0XFE;

	// bodyLength
	buffer[pos++] = 0; //place holder

	//sync_write
	buffer[pos++] = 0X83;

	// goal registers 30 and 31
	buffer[pos++] = 0x1E;

	// longuitud parametros por id
	buffer[pos++] = 0x02;

	byte hexH = 0;
	byte hexL = 0;
	toHexHLConversion(hombro, &hexH, &hexL);
	
	// id
	buffer[pos++] = 0x01;
	numberOfParameters++;
	//data
	buffer[pos++] = hexL;
	numberOfParameters++;
	buffer[pos++] = hexH;
	numberOfParameters++;
	
	hexH = 0;
	hexL = 0;
	toHexHLConversion(codo, &hexH, &hexL);	

	// id
	buffer[pos++] = 0x02;
	numberOfParameters++;
	//data
	buffer[pos++] = hexL;
	numberOfParameters++;
	buffer[pos++] = hexH;
	numberOfParameters++;

	// bodyLength
	//(L + 1) * N + 4 (L: Data length for each Dynamixel actuator, N: The number of Dynamixel actuators) 
	//buffer[3] = (byte)(numberOfParameters + 4);
	buffer[3] = (byte)(10);
	byte checksum = checkSumatory(buffer, pos);
	buffer[pos++] = checksum;

	return pos;
}*/
int Dynamixel::setMoveDrawingArm(int hombro, int codo)
{
	int pos = 0;
	

	buffer[pos++] = 0xff;
	buffer[pos++] = 0xff;
	buffer[pos++] = 0XFE;

	// bodyLength
	buffer[pos++] = 0; //place holder

	//sync_write
	buffer[pos++] = INST_SYNC_WRITE;

	// goal registers 30 and 31
	buffer[pos++] = AXM_GOAL_POSITION_L;

	// longuitud parametros por id
	buffer[pos++] = 2;

	byte hexH = 0;
	byte hexL = 0;
	toHexHLConversion(hombro, &hexH, &hexL);

	// id
	buffer[pos++] = id_hombro;
	//data
	buffer[pos++] = hexL;
	buffer[pos++] = hexH;
	
	hexH = 0;
	hexL = 0;
	toHexHLConversion(codo, &hexH, &hexL);

	// id
	buffer[pos++] = id_codo;
	//data
	buffer[pos++] = hexL;
	buffer[pos++] = hexH;
	
	// bodyLength
	//(L + 1) * N + 4 (L: Data length for each Dynamixel actuator, N: The number of Dynamixel actuators) 
	//buffer[3] = (byte)(numberOfParameters + 4);
	buffer[3] = (byte)(10);
	byte checksum = checkSumatory(buffer, pos);
	buffer[pos++] = checksum;

	return pos;
}
Dynamixel::ControlTable Dynamixel::readControlTable(SerialPort * serialPort, int id)
{
	
	int n = controlTable(id);
	long l = serialPort->sendArray(buffer, n);
	Sleep(waitTime+waitTime);
	memset(bufferIn, 0, BufferSize);
	n = serialPort->getArray(bufferIn, 55);
	Sleep(waitTime+waitTime);
	serialPort->clear();
	Sleep(waitTime);
	//Status Packet
	//OXFF 0XFF ID LENGTH ERROR PARAMETER1 PARAMETER2…PARAMETER N CHECK SUM
	//OFFSET +5
	_controlTable.eeprom.MODEL_NUMBER = fromHexHLConversion(bufferIn[AXM_MODEL_NUMBER_L+ DEFAULT_OFFSET_STATUS_PACKET], bufferIn[AXM_MODEL_NUMBER_H + DEFAULT_OFFSET_STATUS_PACKET]);
	_controlTable.eeprom.FIRMWARE_VERSION = (bufferIn[AXM_FIRMWARE_VERSION + DEFAULT_OFFSET_STATUS_PACKET] );
	_controlTable.eeprom.ID = (bufferIn[AXM_ID + DEFAULT_OFFSET_STATUS_PACKET]);
	_controlTable.eeprom.BAUD_RATE = (bufferIn[AXM_BAUD_RATE + DEFAULT_OFFSET_STATUS_PACKET]);
	_controlTable.eeprom.RETURN_DELAY_TIME= (bufferIn[AXM_RETURN_DELAY_TIME + DEFAULT_OFFSET_STATUS_PACKET] );
	_controlTable.eeprom.CW_ANGLE_LIMIT = fromHexHLConversion(bufferIn[AXM_CW_ANGLE_LIMIT_L + DEFAULT_OFFSET_STATUS_PACKET], bufferIn[AXM_CW_ANGLE_LIMIT_H + DEFAULT_OFFSET_STATUS_PACKET]);
	_controlTable.eeprom.CCW_ANGLE_LIMIT= fromHexHLConversion(bufferIn[AXM_CCW_ANGLE_LIMIT_L + DEFAULT_OFFSET_STATUS_PACKET], bufferIn[AXM_CCW_ANGLE_LIMIT_H + DEFAULT_OFFSET_STATUS_PACKET]);
	_controlTable.eeprom.HIGHEST_LIMIT_TEMPERATURE = (bufferIn[AXM_HIGHEST_LIMIT_TEMPERATURE + DEFAULT_OFFSET_STATUS_PACKET]);
	_controlTable.eeprom.HIGHEST_LIMIT_VOLTAGE= (bufferIn[AXM_HIGHEST_LIMIT_VOLTAGE + DEFAULT_OFFSET_STATUS_PACKET]);
	_controlTable.eeprom.LOWEST_LIMIT_VOLTAGE = (bufferIn[AXM_LOWEST_LIMIT_VOLTAGE + DEFAULT_OFFSET_STATUS_PACKET]);
	_controlTable.eeprom.MAX_TORQUE = fromHexHLConversion(bufferIn[AXM_MAX_TORQUE_L + DEFAULT_OFFSET_STATUS_PACKET], bufferIn[AXM_MAX_TORQUE_H + DEFAULT_OFFSET_STATUS_PACKET]);
	_controlTable.eeprom.STATUS_RETURN_LEVEL = (bufferIn[AXM_STATUS_RETURN_LEVEL + DEFAULT_OFFSET_STATUS_PACKET]);
	_controlTable.eeprom.ALARM_LED = (bufferIn[AXM_ALARM_LED + DEFAULT_OFFSET_STATUS_PACKET]);
	_controlTable.eeprom.ALARM_SHUTDOWN= (bufferIn[AXM_ALARM_SHUTDOWN + DEFAULT_OFFSET_STATUS_PACKET]);

	_controlTable.ram.TORQUE_ENABLE = (bufferIn[AXM_TORQUE_ENABLE + DEFAULT_OFFSET_STATUS_PACKET]);
	_controlTable.ram.LED = (bufferIn[AXM_LED + DEFAULT_OFFSET_STATUS_PACKET]);
	_controlTable.ram.CW_COMPLIANCE_MARGIN = (bufferIn[AXM_CW_COMPLIANCE_MARGIN  + DEFAULT_OFFSET_STATUS_PACKET]);
	_controlTable.ram.CCW_COMPLIANCE_MARGIN = (bufferIn[AXM_CCW_COMPLIANCE_MARGIN + DEFAULT_OFFSET_STATUS_PACKET]);
	_controlTable.ram.CW_COMPLIANCE_SLOPE = (bufferIn[AXM_CW_COMPLIANCE_SLOPE+ DEFAULT_OFFSET_STATUS_PACKET]);
	_controlTable.ram.CCW_COMPLIANCE_SLOPE = (bufferIn[AXM_CCW_COMPLIANCE_SLOPE + DEFAULT_OFFSET_STATUS_PACKET]);
	_controlTable.ram.GOAL_POSITION = fromHexHLConversion(bufferIn[AXM_GOAL_POSITION_L + DEFAULT_OFFSET_STATUS_PACKET], bufferIn[AXM_GOAL_POSITION_H + DEFAULT_OFFSET_STATUS_PACKET]);
	_controlTable.ram.MOVING_SPEED = fromHexHLConversion(bufferIn[AXM_MOVING_SPEED_L + DEFAULT_OFFSET_STATUS_PACKET], bufferIn[AXM_MOVING_SPEED_H + DEFAULT_OFFSET_STATUS_PACKET]);
	_controlTable.ram.TORQUE_LIMIT = fromHexHLConversion(bufferIn[AXM_TORQUE_LIMIT_L + DEFAULT_OFFSET_STATUS_PACKET], bufferIn[AXM_TORQUE_LIMIT_H + DEFAULT_OFFSET_STATUS_PACKET]);
	_controlTable.ram.PRESENT_POSITION = fromHexHLConversion(bufferIn[AXM_PRESENT_POSITION_L + DEFAULT_OFFSET_STATUS_PACKET], bufferIn[AXM_PRESENT_POSITION_H + DEFAULT_OFFSET_STATUS_PACKET]);
	_controlTable.ram.PRESENT_SPEED = fromHexHLConversion(bufferIn[AXM_PRESENT_SPEED_L + DEFAULT_OFFSET_STATUS_PACKET], bufferIn[AXM_PRESENT_SPEED_H + DEFAULT_OFFSET_STATUS_PACKET]);
	_controlTable.ram.PRESENT_LOAD = fromHexHLConversion(bufferIn[AXM_PRESENT_LOAD_L + DEFAULT_OFFSET_STATUS_PACKET], bufferIn[AXM_PRESENT_LOAD_H + DEFAULT_OFFSET_STATUS_PACKET]);
	_controlTable.ram.PRESENT_VOLTAGE = (bufferIn[AXM_PRESENT_VOLTAGE + DEFAULT_OFFSET_STATUS_PACKET]);
	_controlTable.ram.PRESENT_TEMPERATURE = (bufferIn[AXM_PRESENT_TEMPERATURE + DEFAULT_OFFSET_STATUS_PACKET]);
	_controlTable.ram.REGISTERED_INSTRUCTION = (bufferIn[AXM_REGISTERED_INSTRUCTION + DEFAULT_OFFSET_STATUS_PACKET]);
	_controlTable.ram.MOVING = (bufferIn[AXM_MOVING + DEFAULT_OFFSET_STATUS_PACKET]);
	_controlTable.ram.LOCK = (bufferIn[AXM_LOCK + DEFAULT_OFFSET_STATUS_PACKET]);
	//_controlTable.ram.PUNCH = fromHexHLConversion(bufferIn[AXM_PUNCH_L + DEFAULT_OFFSET_STATUS_PACKET ], bufferIn[AXM_PUNCH_H + DEFAULT_OFFSET_STATUS_PACKET ]);
	_controlTable.ram.PUNCH = dxl_read_word(serialPort, id, AXM_PUNCH_L);
	
	
	//int test = dxl_read_byte(serialPort, id, AXM_FIRMWARE_VERSION);
	//dxl_write_byte(serialPort, id, AXM_LED, 1);
	//dxl_write_word(serialPort, id, AXM_GOAL_POSITION_L, 1023);
	//moveDrawingArm(serialPort, 10, 10);

	return _controlTable;
}
int Dynamixel::controlTable(int id) {
	int pos = 0;

	buffer[pos++] = 0xff;
	buffer[pos++] = 0xff;
	buffer[pos++] = id;

	// length = 4
	buffer[pos++] = 4; 

	//the instruction, read => 2
	buffer[pos++] = INST_READ_DATA;

	// Reading Address
	buffer[pos++] = 0;

	//Read Length
	buffer[pos++] = 49;

	byte checksum = checkSumatory(buffer, pos);
	buffer[pos++] = checksum;

	return pos;
}

int Dynamixel::ping(int id) {
	int pos = 0;

	buffer[pos++] = 0xff;
	buffer[pos++] = 0xff;
	buffer[pos++] = id;

	// length = 4
	buffer[pos++] = 0x02;

	
	buffer[pos++] = INST_PING;	

	byte checksum = checkSumatory(buffer, pos);
	buffer[pos++] = checksum;

	return pos;
}