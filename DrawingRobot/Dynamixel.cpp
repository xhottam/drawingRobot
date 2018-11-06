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

short Dynamixel::fromHexHLConversion(byte hexH, byte hexL)
{
    return (short)((hexL << 8) + hexH);
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
	memset(bufferIn, 0, BufferSize);
	//DEFAULT_RETURN_PACKET_SIZE 6 
	n = serialPort->getArray(bufferIn, DEFAULT_RETURN_PACKET_SIZE);
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
	Sleep(waitTime);
	memset(bufferIn, 0, BufferSize);
	//DEFAULT_RETURN_PACKET_SIZE 6 + Read length	
	n = serialPort->getArray(bufferIn, DEFAULT_RETURN_PACKET_SIZE + 2);
	Sleep(waitTime);
	serialPort->clear();
	Sleep(waitTime);

	return fromHexHLConversion(bufferIn[4], bufferIn[5]);
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
void Dynamixel::moveDrawingArm(SerialPort *serialPort, int hombro, int codo)
{
	
	int n = setMoveDrawingArm(hombro,codo);
	long l = serialPort->sendArray(buffer, n);
	Sleep(waitTime);
	memset(bufferIn, 0, BufferSize);
	//DEFAULT_RETURN_PACKET_SIZE 6 
	n = serialPort->getArray(bufferIn, DEFAULT_RETURN_PACKET_SIZE);
	Sleep(waitTime);
	serialPort->clear();
	Sleep(waitTime);
}
int Dynamixel::setMoveDrawingArm(int hombro, int codo)
{
	int pos = 0;
	
	buffer[pos++] = 0xff;
	buffer[pos++] = 0xff;
	buffer[pos++] = 0XFE;

	// bodyLength
	buffer[pos++] = 0; //place holder

	//sync_write
	buffer[pos++] = 0X83;

	// goal registers 30 and 31
	buffer[pos++] = 0x1E;// 30

	// longuitud parametros por id
	buffer[pos++] = 2;// 30

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
	//(L + 1) * N + 4 (L: Data length for each Dynamixel actuator, N: The number of Dynamixel actuators) 	buffer[3] = (byte)(10);
	byte checksum = checkSumatory(buffer, pos);
	buffer[pos++] = checksum;

	return pos;

	return 0;
}
void Dynamixel::readControlTable(SerialPort * serialPort, int id)
{
	
	int n = controlTable(id);
	long l = serialPort->sendArray(buffer, n);
	Sleep(waitTime);
	memset(bufferIn, 0, BufferSize);
	n = serialPort->getArray(bufferIn, 55);
	Sleep(waitTime);
	serialPort->clear();
	Sleep(waitTime);
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