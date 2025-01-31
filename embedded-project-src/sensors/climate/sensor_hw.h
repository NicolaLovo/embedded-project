#ifndef __SENSOR_HW_H__
#define __SENSOR_HW_H__


#include "msp.h"
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>


#define SENSOR_IRQn

//init sensor
void climate_sensor_hw_init(void);

//read temperature of sensor 
float climate_sensor_hw_readTemperature(void);

#endif
