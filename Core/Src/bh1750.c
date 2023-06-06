/**
* Example template for BH1750 library
*/
#include "BH1750.h"
#include "i2c.h"
/**
* Initialize sensor BH1750
*/
void BH1750_Init(BH1750_HandleTypeDef* bh1750, char command)
{
	char start = BH1750_POWER_ON;
	HAL_I2C_Master_Transmit(bh1750 -> I2C, bh1750->Address, &start, 1, 1000);
	HAL_I2C_Master_Transmit(bh1750 -> I2C, bh1750->Address, &command, 1, 1000);
}
/**
* Read one sample form sensor BH1750
* @return value of sample in lx
*/
float BH1750_Read(BH1750_HandleTypeDef* bh1750)
{
	float light = 0.0;
	char sample[2];
	HAL_I2C_Master_Receive(bh1750 -> I2C, bh1750->Address, &sample, 2, 1000);
	uint16_t sample_u16 = sample[0];
	sample_u16 = sample_u16<<8;
	sample_u16 = sample_u16 | sample[1];
	light = ((float) sample_u16)/1.2;
	return light;
}
