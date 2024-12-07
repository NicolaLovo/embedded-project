#ifndef __SENSOR_HW_H__
#define __SENSOR_HW_H__

#include "tools/HAL_I2C.h" //support I2C
#include "tools/HAL_TMP006.h"

#define SENSOR_IRQn


//init sensor
void climate_sensor_hw_init(void);

//read temperature of sensor 
int climate_sensor_hw_readTemperature(void);

//ISR: INTERRUPT
void climate_sensor_PORT4_IRQHandler(void);

/*
//first climate sensor interrupt handling
perchè è strano che in una casa ci siano cambi improvvisi di temperatura 

void climate_sensor_hw_configureInterrupt(void);
void climate_sensor_hw_handleInterrupt(void);
*/

#endif