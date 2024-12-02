#ifndef __SENSOR_HW_H__
#define __SENSOR_HW_H__

#include "HAL_I2C.h"
#include "HAL_OPT3001.h"

//init sensor
void climate_sensor_hw_init(void);

//read temperature of sensor 
int climate_sensor_hw_readTemperature(void);

/*SE VOGLIAMO FARLO MA NEL MIO CASO SEMBRA INUTILE -> climate sensor interrupt handling
perchè è strano che in una casa ci siano cambi improvvisi di temperatura 
*/
void climate_sensor_hw_configureInterrupt(void);
void climate_sensor_hw_handleInterrupt(void);


#endif