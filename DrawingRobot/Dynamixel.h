/*
 * SerialPort.cpp
 *
 *  Created on: Jun 20, 2011
 *      Author: jose
 */

#ifndef DYNAMIXEL_H_
#define DYNAMIXEL_H_

typedef unsigned char byte;

#include <fstream> 
#include "SerialPort.h"



class Dynamixel {

	private:

		int id_hombro = 1;
		int id_codo = 2;
		int id_pencil = 3;

		static const int BufferSize=1024;
		static const int waitTime=16;

		byte buffer[BufferSize];
		byte bufferIn[BufferSize];

		void cleanBuffers();
		void toHexHLConversion(short pos, byte *hexH, byte *hexL);
		short fromHexHLConversion(byte hexH, byte hexL);
		byte checkSumatory(byte  data[], int length);

		int Dynamixel::setbyte(int id,int address, int value);
		int Dynamixel::getbyte(int id, int address);
		int Dynamixel::setWord(int id, int address, int value);
		int Dynamixel::getWord(int id, int address);
		int Dynamixel::setMoveDrawingArm(int hombro, int codo);
		int Dynamixel::controlTable(int id);


	public:
		Dynamixel();
		~Dynamixel();
		struct eeprom {
			int MODEL_NUMBER;
			int FIRMWARE_VERSION;
			int ID;
			int BAUD_RATE;
			int RETURN_DELAY_TIME;
			int CW_ANGLE_LIMIT;
			int CCW_ANGLE_LIMIT;
			int SYSTEM_DATA2;
			int HIGHEST_LIMIT_TEMPERATURE;
			int LOWEST_LIMIT_VOLTAGE;
			int HIGHEST_LIMIT_VOLTAGE;
			int MAX_TORQUE;
			int STATUS_RETURN_LEVEL;
			int ALARM_LED;
			int ALARM_SHUTDOWN;
			int OPERATING_MODE;
			int DOWN_CALIBRATION;
			int UP_CALIBRATION;
		};
		struct ram {
			int TORQUE_ENABLE;
			int LED;
			int CW_COMPLIANCE_MARGIN;
			int CCW_COMPLIANCE_MARGIN;
			int CW_COMPLIANCE_SLOPE;
			int CCW_COMPLIANCE_SLOPE;
			int GOAL_POSITION;
			int MOVING_SPEED;
			int TORQUE_LIMIT;
			int PRESENT_POSITION;
			int PRESENT_SPEED;
			int PRESENT_LOAD;
			int PRESENT_VOLTAGE;
			int PRESENT_TEMPERATURE;
			int REGISTERED_INSTRUCTION;
			int PAUSE_TIME;
			int MOVING;
			int LOCK;
			int PUNCH;
		};
		struct ControlTable {
			eeprom eeprom;
			ram ram;			
		}_controlTable;
		
		// Universal address table
		#define P_MODEL_NUMBER_L                0
		#define P_MODEL_NUMBER_H                1
		#define P_FIRMWARE_VERSION              2
		#define P_ID                            3
		#define P_BAUD_RATE                     4
		#define P_RETURN_DELAY_TIME             5
		#define P_STATUS_RETURN_LEVEL           16
		//#define P_LED                           25  // AX-12+, AX-18F, and AX-S20
		//#define P_REGISTERED_INSTRUCTION        44

		#define DEFAULT_RETURN_PACKET_SIZE 6
		#define DEFAULT_OFFSET_STATUS_PACKET 5

		// AX-12+/18F address table
		enum {
			AXM_MODEL_NUMBER_L = 0,
			AXM_MODEL_NUMBER_H = 1,
			AXM_FIRMWARE_VERSION = 2,
			AXM_ID = 3,
			AXM_BAUD_RATE = 4,
			AXM_RETURN_DELAY_TIME = 5,
			AXM_CW_ANGLE_LIMIT_L = 6,
			AXM_CW_ANGLE_LIMIT_H = 7,
			AXM_CCW_ANGLE_LIMIT_L = 8,
			AXM_CCW_ANGLE_LIMIT_H = 9,
			AXM_SYSTEM_DATA2 = 10,
			AXM_HIGHEST_LIMIT_TEMPERATURE = 11,
			AXM_LOWEST_LIMIT_VOLTAGE = 12,
			AXM_HIGHEST_LIMIT_VOLTAGE = 13,
			AXM_MAX_TORQUE_L = 14,
			AXM_MAX_TORQUE_H = 15,
			AXM_STATUS_RETURN_LEVEL = 16,
			AXM_ALARM_LED = 17,
			AXM_ALARM_SHUTDOWN = 18,
			AXM_OPERATING_MODE = 19,
			AXM_DOWN_CALIBRATION_L = 20,
			AXM_DOWN_CALIBRATION_H = 21,
			AXM_UP_CALIBRATION_L = 22,
			AXM_UP_CALIBRATION_H = 23,
			AXM_TORQUE_ENABLE = 24,
			AXM_LED = 25,
			AXM_CW_COMPLIANCE_MARGIN = 26,
			AXM_CCW_COMPLIANCE_MARGIN = 27,
			AXM_CW_COMPLIANCE_SLOPE = 28,
			AXM_CCW_COMPLIANCE_SLOPE = 29,
			AXM_GOAL_POSITION_L = 30,
			AXM_GOAL_POSITION_H = 31,
			AXM_MOVING_SPEED_L = 32,
			AXM_MOVING_SPEED_H = 33,
			AXM_TORQUE_LIMIT_L = 34,
			AXM_TORQUE_LIMIT_H = 35,
			AXM_PRESENT_POSITION_L = 36,
			AXM_PRESENT_POSITION_H = 37,
			AXM_PRESENT_SPEED_L = 38,
			AXM_PRESENT_SPEED_H = 39,
			AXM_PRESENT_LOAD_L = 40,
			AXM_PRESENT_LOAD_H = 41,
			AXM_PRESENT_VOLTAGE = 42,
			AXM_PRESENT_TEMPERATURE = 43,
			AXM_REGISTERED_INSTRUCTION = 44,
			AXM_PAUSE_TIME = 45,
			AXM_MOVING = 46,
			AXM_LOCK = 47,
			AXM_PUNCH_L = 48,
			AXM_PUNCH_H = 49
		};

		// Expanded Dynamixel SDK TX/RX Error code bits
		enum {
			DXL_TXSUCCESS = 0x0001,
			DXL_RXSUCCESS = 0x0002,
			DXL_TXFAIL = 0x0004,
			DXL_RXFAIL = 0x0008,
			DXL_TXERROR = 0x0010,
			DXL_BAD_INST = 0x0020,
			DXL_BAD_ID = 0x0040,
			DXL_NULL_DATA = 0x0080,
			DXL_NULL_SIZE = 0x0100,
			DXL_RXWAITING = 0x0200,
			DXL_RXTIMEOUT = 0x0400,
			DXL_RXLENGTH = 0x0800,
			DXL_RXCHECKSUM = 0x1000
		};

		// Error bits of Status Packet's ERROR byte
		enum {
			ERRBIT_INSTRUCTION = 0x40,
			// Set to 1 if undefined instruction or register is without REG_WRITE

			ERRBIT_OVERLOAD = 0x20,
			// Set to 1 if specified max torque cannot handle load

			ERRBIT_CHECKSUM = 0x10,
			// Set to 1 if checksum of packet is incorrect

			ERRBIT_RANGE = 0x08,
			// Set to 1 if the instruction sent is out of range

			ERRBIT_OVERHEAT = 0x04,
			// Set to 1 if the module temp is above operating temp defined in control table

			ERRBIT_ANGLE = 0x02,
			// Set to 1 if the Goal position is set out of range

			ERRBIT_VOLTAGE = 0x01
			// Set to 1 if the input voltage is out of range
		};

		// Instruction set
	// PARAMETERS // TASK
		enum {
			INST_PING = 0x01,
			// 0        Get status packet

			INST_READ_DATA = 0x02,
			// 2        Read value from device Control Table

			INST_WRITE_DATA = 0x03,
			// 2~       Write value into device Control Table

			INST_REG_WRITE = 0x04,
			// 2~       Write value in standby mode (wait for REG_WRITE)

			INST_ACTION = 0x05,
			// 0        Execute REG_WRITE

			INST_RESET = 0x06,
			// 0        Set all Control Table values to default?

			INST_DIGITAL_RESET = 0x07,
			// ?        From HaViMo2 - Embedded-C example

			INST_SYSTEM_READ = 0x0C,
			// ?        From HaViMo2 - Embedded-C example

			INST_SYSTEM_WRITE = 0x0D,
			// ?        From HaViMo2 - Embedded-C example

			INST_CAP_REGION = 0x0E,
			// 0        From HaViMo2 datasheet
			//          Initiates new image capture and processing
			//          No return packet generated and non-responsive during processing

			INST_RAW_SAMPLE = 0x0F,
			// 0        From HaViMo2 datasheet
			//          Sample the Raw Image (used by GUI)
			//          Response does not follow standard RoboPlust packet

			INST_LUT_MANAGE = 0x10,
			// 0        From HaViMo2 datasheet
			//          Enter LUT manage mode (used by GUI) (FOR CALIBRATION ONLY.
			//          NOT RECOMMENDED FOR USE WITH ANY BEHAVIOR/ALGORITHM IMPLEMENTATION)

			INST_RD_FILTHR = 0x11,
			// 2        From HaViMo2 datasheet
			//          Read noise threshold value (see datasheet for more detail)

			INST_WR_FILTHR = 0x12,
			// 2        From HaViMo2 datasheet
			//          Write noise threshold value (see datasheet for more detail)

			INST_RD_REGTHR = 0x13,
			// 2        From HaViMo2 datasheet
			//          Read region threshold value (see datasheet for more detail)

			INST_WR_REGTHR = 0x14,
			// 2        From HaViMo2 datasheet
			//          Write region threshold value (see datasheet for more detail)

			INST_CAP_GRID = 0x15,
			// 0        From HaViMo2 datasheet
			//          Invokes gridding algorithm (compresses image to 32*24 cells.
			//          Each cell given only one object index with lower indices dominating
			//          higher ['Ball==1' > 'Field==2' > .. > 'Unknown==0'].
			//          Each cell contains the number of pixels of the specified index.

			INST_READ_GRID = 0x16,
			// 2        From HaViMo2 datasheet
			//          Retrieve results of the gridded image (address internally
			//          multiplied by 16, so retrieve 16 bytes at a time to recover
			//          the entire image.  bits 0-3 are color index, 4-7 are pixel
			//          [15 is the maximum reported, but may be more]
			//          Why not bits 0-2 [0,7] for index and bits 3-7 [0,32] for pixels?
			//          Don't know, so don't ask.

			INST_SAMPLE_FAST = 0x17,
			// 0        From HaViMo2 datasheet
			//          Download an entire image from the module at 1Mbps

			INST_SYNC_WRITE = 0x83,
			// 4+       Write value to Control Table of multiple dynamixels

			INST_SYNC_REG_WRITE = 0x84,
			// ?        Write value to Control Table of multiple dynamixels
			//            in a standby mode?  From HaViMo2 - Embedded-C example?

			INST_BULK_READ = 0x92,
			// ?        Added to CM-730 in version v1.2.0 of the Darwin Framework

			INST_SYNC_READ = 0xD0
			// 2        Issues an INST_READ_DATA command for each servo in ID
			//            location and length of all reads same
		};

		// Dynamixel Packet byte array offsets
		enum {
			DXL_PKT_ID = 0x02,
			// Offset to ID byte of packet

			DXL_PKT_LEN = 0x03,
			// Offset to Length byte of packet

			DXL_PKT_INST = 0x04,
			// Offset to Instruction byte of command packet

			DXL_PKT_ERR = 0x04,
			// Offset to Error byte of return packet

			DXL_PKT_PARA = 0x05
			// Offset to first Parameter byte of packet
		};
		

		bool sentTossModeCommand(SerialPort *serialPort);		
		int dxl_read_byte(SerialPort *serialPort,int id, int address);
		void dxl_write_byte(SerialPort *serialPort,int id, int address, int value);
		int dxl_read_word(SerialPort *serialPort,int id, int address);
		void dxl_write_word(SerialPort *serialPort,int id, int address, int value);
		ControlTable readControlTable(SerialPort *serialPort, int id);
		void moveDrawingArm(SerialPort *serialPort,int hombro,int codo);
		bool isMoving(SerialPort *serialPort, int id);
			
			
};

static Dynamixel dynamixel;
#endif