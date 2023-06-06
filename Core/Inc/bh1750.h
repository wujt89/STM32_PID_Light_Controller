/**
* Example template for BH1750 library
*/
//#ifndef __BH1750_H_
//#define __BH1750_H_
//--------------------------------------------------------------
// Includes
#include "i2c.h"
#include "stm32f7xx_hal.h"
//--------------------------------------------------------------
#define BH1750_I2CType I2C_HandleTypeDef*
typedef struct {
	BH1750_I2CType I2C;
	uint8_t Address;
	uint32_t Timeout;
} BH1750_HandleTypeDef;
//--------------------------------------------------------------
// Definition of address and commands of BH1750
//--------------------------------------------------------------
#define BH1750_ADDRESS (0x23 << 1)
#define BH1750_POWER_DOWN 			0x00
#define BH1750_POWER_ON				0x01
#define BH1750_RESET				0x07
#define BH1750_CONTINOUS_H_RES_MODE	0x10
#define BH1750_CONTINOUS_H_RES_MODE2	0x11
#define BH1750_CONTINOUS_L_RES_MODE		0x13
#define BH1750_ONE_TIME_H_RES_MODE		0x20
#define BH1750_ONE_TIME_H_RES_MODE2		0x21
#define BH1750_ONE_TIME_L_RES_MODE		0x23
//--------------------------------------------------------------
// Global function
//--------------------------------------------------------------
void BH1750_Init(BH1750_HandleTypeDef* bh1750, char command);
float BH1750_Read(BH1750_HandleTypeDef* bh1750);
//--------------------------------------------------------------
//#endif // __BH1750_H_
